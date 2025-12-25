#include "ExpressionEvaluator.h"

// Конструктор: выделяет память под n операндов и инициализирует их нулями
ExpressionEvaluator::ExpressionEvaluator(size_t n) : n(n)
{
    operands = new double[n];
    for (size_t i = 0; i < n; ++i) {
        operands[i] = 0.0;
    }
}

// Виртуальный деструктор: освобождает память
ExpressionEvaluator::~ExpressionEvaluator()
{
    if (operands) {
        delete[] operands;
        operands = nullptr;
    }
}

// Присвоить значение одному операнду на позиции pos
void ExpressionEvaluator::setOperand(size_t pos, double value)
{
    if (pos < n) {
        operands[pos] = value;
    }
    // Можно добавить вывод ошибки в else
}

// Заполнить сразу группу из n операндов
void ExpressionEvaluator::setOperands(double ops[], size_t count)
{
    for (size_t i = 0; i < count && i < n; ++i) {
        operands[i] = ops[i];
    }
}

// Вспомогательный метод для форматированного вывода операнда
void ExpressionEvaluator::printOperand(std::ostream& os, double val) const
{
    if (val < 0) {
        os << "(" << val << ")";
    } else {
        os << val;
    }
}
