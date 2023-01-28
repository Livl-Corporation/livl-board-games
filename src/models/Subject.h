//
// Created by Franck GUTMANN on 18/01/2023.
//

#ifndef LIVL_SUBJECT_H
#define LIVL_SUBJECT_H

#include <memory>
#include <vector>
#include <stdexcept>
#include "models/interfaces/Observer.h"
#include <algorithm>

template <typename T>
class Subject {
public:
    void attach(const std::shared_ptr<Observer<T>> &observer);
    void detach(const std::shared_ptr<Observer<T>> &observer);
    void notify(const T &value);

private:
    std::vector<std::shared_ptr<Observer<T>>> observers{};
};

#endif //LIVL_SUBJECT_H
