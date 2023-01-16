//
// Created by Franck GUTMANN on 16/01/2023.
//

#ifndef LIVL_MENUINTERACTIONS_H
#define LIVL_MENUINTERACTIONS_H

#include <string>
#include <vector>

class MenuInteractions {

public:
    virtual void printMenu() const = 0;
    virtual void printGameSelection(const std::vector<std::string> &gameList) const = 0;
    virtual void printPlayerSelection(const std::vector<std::string> &playerList) const = 0;
};

#endif //LIVL_MENUINTERACTIONS_H
