#ifndef STRATEGY_H
#define STRATEGY_H

// Абстрактный класс стратегии торговли (паттерн Strategy)
class TradingStrategy {
public:
    virtual void trade() = 0;
    virtual ~TradingStrategy() = default;
};

class LogisticsStrategy : public TradingStrategy {
public:
    void trade() override;
};

class TechTradingStrategy : public TradingStrategy {
public:
    void trade() override;
};

class MiningStrategy : public TradingStrategy {
public:
    void trade() override;
};

#endif
