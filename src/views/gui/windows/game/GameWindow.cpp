#include "GameWindow.h"

GameWindow::GameWindow(QWidget *parent) :
    ui(new Ui::GameWindow)
{
    this->parent = parent;
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    connect(ui->returnBackButton, &QPushButton::clicked, this, &GameWindow::onReturnBackButtonClicked);

}

GameWindow::~GameWindow()
{
    delete ui;
    free(playerLabels.data());
}

void GameWindow::createPlayers(const std::vector<std::shared_ptr<Player>>& players) {
    auto *layout = new QVBoxLayout();
    for (auto &player : players) {
        auto *playerLayout = new QHBoxLayout();
        Token *token = new Token(player->getId());

        auto *label = new QLabel();
        label->setAlignment(Qt::AlignCenter);
        label->setContentsMargins(10, 10, 10, 10);
        label->setObjectName("playerLabel"+QString::number(player->getId()));
        label->setText(QString::number(player->getId()) + " - " + QString::fromStdString(player->getName()));
        playerLayout->addWidget(label);

        auto *button = new QPushButton;
        button->setFixedSize(50, 50);
        button->setEnabled(false);
        button->setText(QString::fromStdString(token->getDisplayString()));
        std::string color = token->getDisplayColor();
        button->setStyleSheet("QPushButton { background-color: " + QString::fromStdString(color) + "; border: 1px solid #777; color: " + (color == "black" ? "white" : "black") + "; font: bold 14px; }");
        playerLayout->addWidget(button);

        layout->addLayout(playerLayout);
        this->playerLabels.append(label);}
    ui->playerListContainer->addLayout(layout);
}

void GameWindow::setActivePlayer(const PlayerId &playerId) {

    // Update player label
    ui->currentPlayerLabel->setText("It's player " + QString::number(playerId) + " turn");

    // Update in player list
   for(QLabel* label : this->playerLabels) {
        if (label != nullptr ) {
            if (label->objectName() == "playerLabel"+QString::number(playerId)) {
                label->setStyleSheet("QLabel { background-color : blue; color : white; font-weight: bold; }");
            } else {
                label->setStyleSheet("QLabel { background-color : transparent; color : black; font-weight: normal; }");
            }
        }
   }
}

void GameWindow::setInfoText(const std::string &message) {
    ui->infoLabel->setText(QString::fromStdString(message));
}

void GameWindow::createGrid(const Grid<Token> &grid) {
    std::function<void(Position)> callback = [this](Position pos){this->onGridClicked(pos);};
    gridComponent = std::make_shared<GridComponent>(this, callback);
    gridComponent->setObjectName("gridComponent");
    gridComponent->setGrid(grid);
    auto* container = new QWidget(this);
    container->setLayout(gridComponent->getGridLayout());
    ui->gridContainer->addWidget(container);
    ui->centralwidget->repaint();
}

void GameWindow::show() {
    QWidget::show();
}

void GameWindow::onGridClicked(const Position &value) {
    qDebug() << "GameWindow::onGridClicked()";
    if (controller != nullptr) {
        controller->onPositionSelected(value);
    } else {
        qDebug() << "GameWindow::onGridClicked() - controller is null";
    }
}

void GameWindow::updateError(const std::string &message) {
    setErrorText(message);
}

void GameWindow::updateMessage(const std::string &message) {
    setInfoText(message);
}

void GameWindow::updateRound(Round round, const std::shared_ptr<Player> &player) {
    ui->statusbar->showMessage("Round "+QString::number(round));
    setActivePlayer(player->getId());
    setErrorText("");
}

void GameWindow::updateGrid(const Grid<Token> &grid) {
    if (gridComponent == nullptr) {
        // Create grid if it doesn't exist already
        createGrid(grid);
    } else {
        // Update grid
        gridComponent->setGrid(grid);
    }
}

void GameWindow::updatePlayers(const std::vector<std::shared_ptr<Player>> &players) {
    if (playerLabels.size() != players.size()) {
        QObjectList children = ui->playerListContainer->children();
        children.clear();
        createPlayers(players);
    }
}

void GameWindow::updateGameName(const std::string &gameName) {
    ui->gameTitle->setText(QString::fromStdString(gameName));
}

void GameWindow::updateAskForPosition(const std::string &message, unsigned int numberOfValues) {
    setInfoText(message);
}

void GameWindow::setErrorText(const std::string &message) {

    ui->errorLabel->setText(QString::fromStdString(message));
}

void GameWindow::updateGameEnd(const std::string &message) {
    setInfoText(message);
    gridComponent->disableGridButtons();
}

void GameWindow::onReturnBackButtonClicked()
{
    int res = QMessageBox::warning(
            this,
            tr("Do you really want to leave your party ?"),
            tr("Your party will be automatically saved !"),
            QMessageBox::Yes | QMessageBox::No
    );

    if (res == QMessageBox::Yes) {
        this->parent->show();
        this->close();
    }

}

