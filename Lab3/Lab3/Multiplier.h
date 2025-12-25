#pragma once
#include "ExpressionEvaluator.h"

// Класс Умножитель: вычисляет произведение всех операндов
class Multiplier : public ExpressionEvaluator
{
public:
    Multiplier(size_t n);

    virtual double calculate() const override;
    virtual void logToScreen() const override;
    virtual void logToFile(const std::string& filename) const override;
};
