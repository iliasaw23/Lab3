#pragma once
#include "ILoggable.h"
#include <iostream>
#include <iomanip>

// Абстрактный базовый класс для вычисления арифметических выражений
class ExpressionEvaluator : public ILoggable
{
protected:
    double* operands; // Массив операндов (динамическая память)
    size_t n;         // Количество операндов

public:
    // Конструктор: выделяет память под n операндов и инициализирует их нулями
    ExpressionEvaluator(size_t n);

    // Виртуальный деструктор: освобождает память
    virtual ~ExpressionEvaluator();

    // Присвоить значение одному операнду на позиции pos
    void setOperand(size_t pos, double value);

    // Заполнить сразу группу из n операндов
    void setOperands(double ops[], size_t count);

    // Чисто виртуальный метод вычисления результата
    virtual double calculate() const = 0;

protected:
    // Вспомогательный метод для форматированного вывода операнда (отрицательные в скобках)
    // Используется в методах logToScreen/logToFile наследников
    void printOperand(std::ostream& os, double val) const;
};
