//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_POSITION_H
#define LIVL_POSITION_H

#include "interfaces/Serializable.h"

class Position: Serializable
{
public:
    int row;
    int col;

    Position(int row, int col): row(row), col(col) {};

    void serialize(std::ostream &stream) override;
    void deserialize(std::istream &stream) override;
};

#endif //LIVL_POSITION_H
