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

void GameWindow::setGameName(const std::string &gameName) {
    ui->gameTitle->setText(QString::fromStdString(gameName));
}

void GameWindow::createPlayers(const std::vector<std::shared_ptr<Player>>& players) {
    auto *layout = new QVBoxLayout();
    for (auto &player : players) {
        auto *label = new QLabel();
        label->setObjectName("playerLabel"+QString::number(player->getId()));
        label->setText(QString::number(player->getId()));
        layout->addWidget(label);
        this->playerLabels.append(label);
    }
    ui->playerListContainer->addLayout(layout);
}

void GameWindow::setRound(unsigned int round) {
    ui->statusbar->showMessage("Round "+QString::number(round));
}

void GameWindow::setActivePlayer(const PlayerId &playerId) {
    for(QLabel* label : this->playerLabels) {
        if (label != nullptr ) {
            if (label->objectName() == "playerLabel"+QString::number(playerId)) {
                label->setStyleSheet("QLabel { background-color : red; color : white; font-weight: bold; }");
            } else {
                label->setStyleSheet("QLabel { background-color : white; color : black; font-weight: normal; }");
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
    gridComponent = std::make_shared<GridComponent>(this);
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

void GameWindow::update(const Game &value) {

    qDebug() << "GameWindow::update()";

    setGameName(value.getName());
    setRound(value.getRound());
    setInfoText(value.getMessage());

    if (gridComponent == nullptr) {
        // Create grid if it doesn't exist already
        createGrid(*value.getGrid());
    } else {
        // Update grid
        gridComponent->setGrid(*value.getGrid());
    }

    // Update players
    if (playerLabels.size() != value.getPlayers().size()) {
        QObjectList children = ui->playerListContainer->children();
        children.clear();
        createPlayers(value.getPlayers());
    }
}