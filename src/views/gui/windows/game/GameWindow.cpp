#include "GameWindow.h"

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
        label->setText(QString::number(player.getId()));
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

void GameWindow::createGrid(const std::shared_ptr<Grid<Token>> &grid) {
    gridComponent = new GridComponent(this);
    gridComponent->setObjectName("gridComponent");
    ui->gridContainer->addWidget(gridComponent);
}

void GameWindow::update(const Game &value) {
    setGameName(value.getName());
    setRound(value.getRound());
    setInfoText(value.getMessage());

    // Grid
    if (gridComponent == nullptr) {
        createGrid(value.getGrid());
        value.getGrid()->attach(gridComponent);
    }

    // Players
    if (playerLabels.size() != value.getPlayers().size()) {
        ui->playerListContainer->children().clear();
        createPlayers(value.getPlayers());
    }

}

