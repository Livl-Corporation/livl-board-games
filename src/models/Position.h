//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_POSITION_H
#define LIVL_POSITION_H

#include "interfaces/Serializable.h"

class Position: Serializable
{
public:
    int x;
    int y;

    Position(int x, int y): x(x), y(y) {};

    void serialize(std::ostream &stream) override;
    void deserialize(std::istream &stream) override;
};

#endif //LIVL_POSITION_H
