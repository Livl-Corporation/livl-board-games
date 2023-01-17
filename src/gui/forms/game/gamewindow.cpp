#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}



void GameWindow::setGameName(const std::string &gameName) {
    ui->gameTitle->setText(QString::fromStdString(gameName));
}

void GameWindow::createPlayers(const std::vector<Player>& players) {
    auto *layout = new QVBoxLayout();
    for (auto &player : players) {
        auto *label = new QLabel();
        label->setObjectName("playerLabel"+QString::number(player.getId()));
        label->setText(QString(Player::getPlayerChar(player.getId())));
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

void GameWindow::setGrid(const std::shared_ptr<Grid<PlayerId>> &grid) {
    auto *gridComponent = ui->gridContainer->findChild<GridComponent *>();

    if (gridComponent == nullptr) {
        gridComponent = new GridComponent(this);
        gridComponent->createGrid(grid);
        gridComponent->setObjectName("gridComponent");
        ui->gridContainer->addWidget(gridComponent);
    } else {
        gridComponent->updateGrid();
    }
}


