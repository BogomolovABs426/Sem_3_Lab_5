#include "celestial.h"
#include <iostream>

CelestialBody::CelestialBody(const string& n, double xCoord, double yCoord)
    : name(n), x(xCoord), y(yCoord) {}

void CelestialBody::display() const {
    cout << name << " в координатах (" << x << ", " << y << ")" << endl;
}

string CelestialBody::getName() const {
    return name;
}

Planet::Planet(const string& n, double x, double y, double prod, 
               double dem, const string& res)
    : CelestialBody(n, x, y), productivity(prod), demand(dem), resource(res) {}

void Planet::display() const {
    CelestialBody::display();
    cout << "  Тип: Планета, Ресурс: " << resource 
              << ", Производительность: " << productivity 
              << ", Спрос: " << demand << endl;
}

double Planet::getProductivity() const {
    return productivity;
}

double Planet::getDemand() const {
    return demand;
}

string Planet::getResource() const {
    return resource;
}

Asteroid::Asteroid(const string& n, double x, double y, double cost)
    : CelestialBody(n, x, y), miningCost(cost) {}

void Asteroid::display() const {
    CelestialBody::display();
    cout << "  Тип: Астероид, Стоимость добычи: " << miningCost << endl;
}

double Asteroid::getMiningCost() const {
    return miningCost;
}
