//
// Created by Franck GUTMANN on 16/01/2023.
//

#include <QApplication>
#include "menuGuiInteractions.h"
#include "forms/menu/menu.h"

MenuGuiInteractions::MenuGuiInteractions() {
    int argc = 0;
    QApplication a(argc, nullptr);
    QApplication::setWindowIcon(QIcon(":/img/logo.png"));
    this->menuWindow = std::make_shared<Menu>();
    this->menuWindow->show();
    QApplication::exec();
}

void MenuGuiInteractions::printMenu(const std::vector<std::string> &gameList,
                                    const std::vector<std::string> &playerList) const {

    this->menuWindow->setGameList(gameList);
    this->menuWindow->setPlayerList(playerList);
}
