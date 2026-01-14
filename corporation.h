#ifndef CORPORATION_H
#define CORPORATION_H

#include <string>
#include <memory>
#include "observer.h"
#include "strategy.h"

using namespace std;

class Corporation : public Observer {
protected:
    string name;
    unique_ptr<TradingStrategy> strategy;
public:
    Corporation(const string& n, TradingStrategy* strat);
    void update(const string& message) override;
    void performBusiness();
    virtual ~Corporation() = default;
    string getName() const;
};

class LogisticsCompany : public Corporation {
public:
    LogisticsCompany(const string& n);
};

class TechTrader : public Corporation {
public:
    TechTrader(const string& n);
};

class MinerCompany : public Corporation {
public:
    MinerCompany(const string& n);
};

#endif
