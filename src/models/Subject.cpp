//
// Created by Franck GUTMANN on 18/01/2023.
//

#include "Subject.h"

template <typename T>
void Subject<T>::notify(const T &value) {
    for (auto &observer : observers) {
        observer->update(value);
    }
}

template <typename T>
void Subject<T>::detach(const std::shared_ptr<Observer<T>> &observer) {
    throw std::logic_error("Not implemented");
}

template <typename T>
void Subject<T>::attach(const std::shared_ptr<Observer<T>> &observer) {
    observers.push_back(observer);
}