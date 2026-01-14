#include "galaxy.h"
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

void displayMenu() {
    cout << "\n=== КОСМИЧЕСКАЯ СИМУЛЯЦИЯ ===" << endl;
    cout << "1. Выполнить ход" << endl;
    cout << "2. Создать путь" << endl;
    cout << "3. Очистить галактику" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите действие: ";
}

void addCelestialBodyInteractive(Galaxy& galaxy) {
    cout << "\n=== ДОБАВЛЕНИЕ НЕБЕСНОГО ТЕЛА ===" << endl;
    cout << "1. Планета" << endl;
    cout << "2. Астероид" << endl;
    cout << "0. Назад/Пропустить" << endl;
    
    int choice;
    cin >> choice;
    
    if (choice == 0) return;
    
    string name;
    double x, y;
    
    cout << "Название: ";
    cin.ignore();
    getline(cin, name);
    
    cout << "Координата X: ";
    cin >> x;
    
    cout << "Координата Y: ";
    cin >> y;
    
    if (choice == 1) { // Планета
        double productivity, demand;
        string resource;
        
        cout << "Производительность: ";
        cin >> productivity;
        
        cout << "Спрос: ";
        cin >> demand;
        
        cout << "Ресурс: ";
        cin.ignore();
        getline(cin, resource);
        
        galaxy.addBody(new Planet(name, x, y, productivity, demand, resource));
        cout << "Планета '" << name << "' добавлена!" << endl;
        
    } else if (choice == 2) { // Астероид
        double miningCost;
        
        cout << "Стоимость добычи: ";
        cin >> miningCost;
        
        galaxy.addBody(new Asteroid(name, x, y, miningCost));
        cout << "Астероид '" << name << "' добавлен!" << endl;
    }
}

void addCorporationInteractive(Galaxy& galaxy) {
    cout << "\n=== ДОБАВЛЕНИЕ КОРПОРАЦИИ ===" << endl;
    cout << "1. Логистическая компания" << endl;
    cout << "2. Технологический трейдер" << endl;
    cout << "3. Добывающая компания" << endl;
    cout << "0. Назад/Пропустить" << endl;
    
    int choice;
    cin >> choice;
    
    if (choice == 0) return;
    
    string name;
    cout << "Название корпорации: ";
    cin.ignore();
    getline(cin, name);
    
    switch (choice) {
        case 1:
            galaxy.addCorporation(new LogisticsCompany(name));
            cout << "Логистическая компания '" << name << "' зарегистрирована!" << endl;
            break;
        case 2:
            galaxy.addCorporation(new TechTrader(name));
            cout << "Технологический трейдер '" << name << "' зарегистрирован!" << endl;
            break;
        case 3:
            galaxy.addCorporation(new MinerCompany(name));
            cout << "Добывающая компания '" << name << "' зарегистрирована!" << endl;
            break;
    }
}

void addTradeRouteInteractive(Galaxy& galaxy) {
    cout << "\n=== ДОБАВЛЕНИЕ ТОРГОВОГО МАРШРУТА ===" << endl;
    
    string from, to;
    double cost;
    int security;
    
    cout << "Откуда (планета/астероид): ";
    cin.ignore();
    getline(cin, from);
    
    cout << "Куда (планета/астероид): ";
    getline(cin, to);
    
    cout << "Стоимость перевозки: ";
    cin >> cost;
    
    cout << "Уровень безопасности: ";
    cin >> security;
    
    galaxy.addRoute(TradeRoute(from, to, cost, security));
    cout << "Торговый маршрут '" << from << " -> " << to << "' добавлен!" << endl;
}


void clearGalaxy(Galaxy& galaxy) {
    galaxy = Galaxy();
    cout << "Галактика очищена!" << endl;
}

void simulation() {
    Galaxy galaxy;
    
    cout << "=== СИМУЛЯЦИЯ ГАЛАКТИКИ ===" << endl;
    cout << "Создайте галактику" << endl;
    
    bool running = true;
    
    while (running) {
        displayMenu();
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 0:
                cout << "Выход из программы..." << endl;
                running = false;
                break;
        
                
            case 1:
		galaxy.simulateTurn();
                cout << "\nБыло: \n" << endl;
		galaxy.displayAll();
		addCelestialBodyInteractive(galaxy);
		addCorporationInteractive(galaxy);
		cout << "\nСтало: \n" << endl;
		galaxy.displayAll();
                break;

	    case 2: 
		addTradeRouteInteractive(galaxy);
		break;
            case 3:
		clearGalaxy(galaxy);
		break;
                
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
                break;
        }
        
        cin.ignore();
        cin.get();
    }
}

int main() {
    
    simulation();
    return 0;
}
