#include <iostream>
#include "GameWindow.h"
#include "models/Subject.cpp"

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
    std::cout << "Setting game name to" << gameName << std::endl;
    ui->gameTitle->setText(QString::fromStdString(gameName));
    ui->gameTitle->repaint();
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
    ui->playerListContainer->update();
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

void GameWindow::createGrid(const std::shared_ptr<Grid<Token>> &grid) {
    gridComponent = std::make_shared<GridComponent>(this);
    gridComponent->setObjectName("gridComponent");
    gridComponent->createGrid(grid);
    auto* container = new QWidget(this);
    container->setLayout(gridComponent->getGridLayout());
    ui->gridContainer->addWidget(container);
    ui->centralwidget->repaint();
}

void GameWindow::attachToObserver()
{
    this->controller->getGame()->attach(shared_from_this());
}

void GameWindow::update(const std::shared_ptr<Game> &value) {
    setGameName(value->getName());
    setRound(value->getRound());
    setInfoText(value->getMessage());

    // Grid
    if (gridComponent == nullptr) {
        createGrid(value->getGrid());
        value->getGrid()->attach(gridComponent);
    }

    // Players
//    if (playerLabels.size() != value.getPlayers().size()) {
//        ui->playerListContainer->children().clear();
//        createPlayers(value.getPlayers());
//    }
    if (playerLabels.size() != value->getPlayers().size()) {
        QObjectList children = ui->playerListContainer->children();
        children.clear();
        createPlayers(value->getPlayers());
    }

}

void GameWindow::show() {
    QMainWindow::show();
}

