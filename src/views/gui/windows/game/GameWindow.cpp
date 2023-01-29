#include "GameWindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

GameWindow::~GameWindow()
{
    delete ui;
    free(playerLabels.data());
}

void GameWindow::createPlayers(const std::vector<std::shared_ptr<Player>>& players) {
    auto *layout = new QVBoxLayout();
    for (auto &player : players) {
        auto *label = new QLabel();
        label->setObjectName("playerLabel"+QString::number(player->getId()));
        label->setText(QString::number(player->getId()) + " - " + QString::fromStdString(player->getName()));
        layout->addWidget(label);
        this->playerLabels.append(label);
    }
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

void GameWindow::setInfoTextColor(const std::string &color) {
    ui->infoLabel->setStyleSheet("QLabel { color : "+QString::fromStdString(color)+"; }");
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
    setInfoText(message);
    setInfoTextColor("red");
}

void GameWindow::updateMessage(const std::string &message) {
    setInfoText(message);
    setInfoTextColor("black");
}

void GameWindow::updateRound(Round round, const std::shared_ptr<Player> &player) {
    ui->statusbar->showMessage("Round "+QString::number(round));
    setActivePlayer(player->getId());
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
