#include "menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    QCoreApplication::applicationDirPath();
    ui->setupUi(this);

    connect(ui->playButton, &QPushButton::clicked, this, &Menu::onPlayClicked);

}

Menu::~Menu()
{
    delete ui;
}

void Menu::setGameList(const std::vector<std::string> &gameList) {
    for (const auto &gameName : gameList) {
        ui->gameSelectionBox->addItem(QString::fromStdString(gameName));
    }
}

void Menu::setPlayerList(const std::vector<std::string> &playerList) {
    for (const auto &playerName : playerList) {
        ui->playerSelectionBox->addItem(QString::fromStdString(playerName));
    }
}

void Menu::onPlayClicked() {
    int gameSelection = ui->gameSelectionBox->currentIndex()+1;
    int playerSelection = ui->playerSelectionBox->currentIndex()+1;

    close();

    GameFactory::startGame(gameSelection, playerSelection);
}


