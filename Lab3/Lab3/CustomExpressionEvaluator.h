#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <algorithm> // для std::sort
#include <cmath>     // для std::abs

// Кастомный класс для Варианта 10: x1 - x2/x3 - x4/x5 ...
// Также реализует интерфейс IShuffle
class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle
{
public:
    CustomExpressionEvaluator(size_t n);

    virtual double calculate() const override;
    virtual void logToScreen() const override;
    virtual void logToFile(const std::string& filename) const override;

    // Реализация методов IShuffle
    virtual void shuffle() override;
    virtual void shuffle(size_t i, size_t j) override;
};
