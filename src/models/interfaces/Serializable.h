//
// Created by tanguy on 30/01/23.
//

#ifndef LIVL_SERIALIZABLE_H
#define LIVL_SERIALIZABLE_H

#include <iostream>

struct Serializable {
    virtual void serialize(std::ostream &stream) = 0;
    virtual void deserialize(std::istream &stream) = 0;
};


#endif //LIVL_SERIALIZABLE_H
