#ifndef CELESTIAL_H
#define CELESTIAL_H

#include <string>

using namespace std;

class CelestialBody {
protected:
    string name;
    double x, y;
public:
    CelestialBody(const string& n, double xCoord, double yCoord);
    virtual void display() const;
    virtual ~CelestialBody() = default;
    string getName() const;
};

class Planet : public CelestialBody {
private:
    double productivity;
    double demand;
    string resource;
public:
    Planet(const string& n, double x, double y, double prod, 
           double dem, const string& res);
    void display() const override;
    double getProductivity() const;
    double getDemand() const;
    string getResource() const;
};

class Asteroid : public CelestialBody {
private:
    double miningCost;
public:
    Asteroid(const string& n, double x, double y, double cost);
    void display() const override;
    double getMiningCost() const;
};

#endif
