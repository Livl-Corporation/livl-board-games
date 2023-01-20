#include "MenuWindow.h"

MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
{
    QCoreApplication::applicationDirPath();
    ui->setupUi(this);

    connect(ui->playButton, &QPushButton::clicked, this, &MenuWindow::onPlayClicked);

    setPlayerList(MenuData::players);
    setGameList(MenuData::games);

}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::setGameList(const std::vector<std::string> &gameList) {
    for (const auto &gameName : gameList) {
        ui->gameSelectionBox->addItem(QString::fromStdString(gameName));
    }
}

void MenuWindow::setPlayerList(const std::vector<std::string> &playerList) {
    for (const auto &playerName : playerList) {
        ui->playerSelectionBox->addItem(QString::fromStdString(playerName));
    }
}

void MenuWindow::onPlayClicked() {
    auto gameSelection = static_cast<GameMode>(ui->gameSelectionBox->currentIndex() + 1);
    auto playerSelection = static_cast<PlayMode>(ui->playerSelectionBox->currentIndex() + 1);

    controller->onPlayClicked(gameSelection, playerSelection);

    close();

}