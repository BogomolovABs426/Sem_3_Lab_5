#include "strategy.h"
#include <iostream>

using namespace std;

void LogisticsStrategy::trade() {
    cout << "  Логистика: Минимизация транспортных расходов." << endl;
}

void TechTradingStrategy::trade() {
    cout << "  Технологическая торговля: Работа только с высокотехнологичными ресурсами." << endl;
}

void MiningStrategy::trade() {
    cout << "  Добыча: Извлечение ресурсов с астероидов." << endl;
}
