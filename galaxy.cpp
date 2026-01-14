#include "galaxy.h"
#include <iostream>

using namespace std;

TradeRoute::TradeRoute(const string& f, const string& t, double c, int sl)
    : from(f), to(t), cost(c), securityLevel(sl) {}

void TradeRoute::display() const {
    cout << "Маршрут: " << from << " -> " << to 
              << ", Стоимость: " << cost 
              << ", Безопасность: " << securityLevel << endl;
}

void Galaxy::addBody(CelestialBody* body) {
    bodies.emplace_back(body);
    notify("Добавлено новое небесное тело: " + body->getName());
}

void Galaxy::addCorporation(Corporation* corp) {
    corporations.emplace_back(corp);
    addObserver(corp);
    notify("Зарегистрирована новая корпорация: " + corp->getName());
}

void Galaxy::addRoute(const TradeRoute& route) {
    routes.push_back(route);
    notify("Установлен новый торговый маршрут.");
}

void Galaxy::displayAll() const {
    cout << "=== НЕБЕСНЫЕ ТЕЛА ===" << endl;
    for (const auto& body : bodies) {
        body->display();
    }
    
    cout << "\n=== ТОРГОВЫЕ МАРШРУТЫ ===" << endl;
    for (const auto& route : routes) {
        route.display();
    }
    
    cout << "\n=== КОРПОРАЦИИ ===" << endl;
    for (const auto& corp : corporations) {
        corp->performBusiness();
    }
}

void Galaxy::simulateTurn() {
    cout << "\n=== СИМУЛЯЦИЯ ХОДА ===" << endl;
    notify("Начался новый ход.");
    for (const auto& corp : corporations) {
        corp->performBusiness();
    }
    notify("Ход завершен.");
}
