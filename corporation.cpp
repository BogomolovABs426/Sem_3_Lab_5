#include "corporation.h"
#include <iostream>

using namespace std;

Corporation::Corporation(const string& n, TradingStrategy* strat) 
    : name(n), strategy(strat) {}

void Corporation::update(const string& message) {
    cout << name << " получил уведомление: " << message << endl;
}

void Corporation::performBusiness() {
    cout << name << " бизнес-деятельность:" << endl;
    strategy->trade();
}

string Corporation::getName() const {
    return name;
}

LogisticsCompany::LogisticsCompany(const string& n) 
    : Corporation(n, new LogisticsStrategy()) {}

TechTrader::TechTrader(const string& n) 
    : Corporation(n, new TechTradingStrategy()) {}

MinerCompany::MinerCompany(const string& n) 
    : Corporation(n, new MiningStrategy()) {}
