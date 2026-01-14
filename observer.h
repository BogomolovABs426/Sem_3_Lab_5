#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <vector>

using namespace std;

// Базовый класс Наблюдателя (паттерн Observer)
class Observer {
public:
    virtual void update(const string& message) = 0;
    virtual ~Observer() = default;
};

// Класс Наблюдаемого объекта (Subject в паттерне Observer)
class Observable {
private:
    vector<Observer*> observers;
public:
    void addObserver(Observer* obs);
    void notify(const string& message);
};

#endif
