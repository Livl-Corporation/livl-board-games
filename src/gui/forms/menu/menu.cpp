#include "menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    QCoreApplication::applicationDirPath();
    ui->setupUi(this);
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




