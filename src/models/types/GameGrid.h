//
// Created by Franck GUTMANN on 31/01/2023.
//

#ifndef LIVL_GAMEGRID_H
#define LIVL_GAMEGRID_H

#include <memory>
#include "models/Token.h"
#include "models/Grid.h"

template <typename T> require std::is_base_of<Token, T>::value;
using GameGrid = Grid<std::shared_ptr<T>>;

#endif //LIVL_GAMEGRID_H
