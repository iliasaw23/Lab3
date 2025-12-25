#pragma once
#include "ExpressionEvaluator.h"

// Класс Сумматор: вычисляет сумму всех операндов
class Summator : public ExpressionEvaluator
{
public:
    Summator(size_t n);

    virtual double calculate() const override;
    virtual void logToScreen() const override;
    virtual void logToFile(const std::string& filename) const override;
};
