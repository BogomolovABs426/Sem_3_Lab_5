#ifndef GALAXY_H
#define GALAXY_H

#include <vector>
#include <memory>
#include "observer.h"
#include "celestial.h"
#include "corporation.h"

using namespace std;

class TradeRoute {
private:
    string from;
    string to;
    double cost;
    int securityLevel;
public:
    TradeRoute(const string& f, const string& t, double c, int sl);
    void display() const;
};

class Galaxy : public Observable {
private:
    vector<unique_ptr<CelestialBody>> bodies;
    vector<unique_ptr<Corporation>> corporations;
    vector<TradeRoute> routes;
public:
    void addBody(CelestialBody* body);
    void addCorporation(Corporation* corp);
    void addRoute(const TradeRoute& route);
    void displayAll() const;
    void simulateTurn();
};

#endif
