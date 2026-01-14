#include "observer.h"
#include <iostream>

using namespace std;

void Observable::addObserver(Observer* obs) {
    observers.push_back(obs);
}

void Observable::notify(const string& message) {
    for (auto obs : observers) {
        obs->update(message);
    }
}
