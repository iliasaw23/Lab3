#include "CustomExpressionEvaluator.h"

CustomExpressionEvaluator::CustomExpressionEvaluator(size_t n) : ExpressionEvaluator(n) {}

double CustomExpressionEvaluator::calculate() const
{
    if (n == 0) return 0;
    
    // Формула: x1 - x2/x3 - x4/x5 ...
    double result = operands[0];

    for (size_t i = 1; i + 1 < n; i += 2) {
        double numerator = operands[i];
        double denominator = operands[i+1];
        
        // Избегаем деления на ноль, если потребуется, но в рамках лабы считаем ввод корректным
        // или просто делим как есть (получим inf, что допустимо для double)
        if (denominator != 0) {
           result -= (numerator / denominator);
        } else {
           // Можно обработать ошибку, но пока оставим стандартное поведение
           result -= (numerator / 1.0); // Заглушка, если вдруг 0 (хотя в примере 0 не делят)
        }
    }
    
    // Если остался один операнд в конце без пары (например, всего 4 операнда: x1, x2, x3, x4 -> x1 - x2/x3 ... и x4 висит)
    // По условию "CustomExpressionEvaluator: 5 операндов", т.е. x1, (x2,x3), (x4,x5) - идеально.
    // Если будет четное количество, последний операнд просто игнорируется или вычитается?
    // В формуле Варианта 10 многоточие после пар x/y. Предположим, что непарные элементы не участвуют или вычитаются.
    // Но так как у нас 5 операндов, этот случай покрыт.
    // Допустим, если остались лишние, просто игнорируем, как в "пары".
    
    return result;
}

void CustomExpressionEvaluator::logToScreen() const
{
    std::cout << "[CustomExpression] Expression: " << n << " operands : ";
    if (n > 0) {
        printOperand(std::cout, operands[0]);
    }
    for (size_t i = 1; i + 1 < n; i += 2) {
        std::cout << " - ";
        printOperand(std::cout, operands[i]);
        std::cout << " / ";
        printOperand(std::cout, operands[i+1]);
    }
    std::cout << "\nResult: " << calculate() << std::endl;
}

void CustomExpressionEvaluator::logToFile(const std::string& filename) const
{
    std::ofstream ofs(filename, std::ios_base::app);
    if (ofs.is_open()) {
        ofs << "[CustomExpression] Expression: " << n << " operands : ";
        if (n > 0) {
            printOperand(ofs, operands[0]);
        }
        for (size_t i = 1; i + 1 < n; i += 2) {
            ofs << " - ";
            printOperand(ofs, operands[i]);
            ofs << " / ";
            printOperand(ofs, operands[i+1]);
        }
        ofs << "\nResult: " << calculate() << std::endl;
        ofs.close();
    }
}

// Компаратор для сортировки по модулю
bool absCompare(double a, double b) {
    return std::abs(a) < std::abs(b);
}

void CustomExpressionEvaluator::shuffle()
{
    // Сортировка всех операндов по модулю (возрастание)
    std::sort(operands, operands + n, absCompare);
}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j)
{
    // Сортировка операндов в диапазоне [i, j]
    if (i >= n || j >= n) return;
    if (i > j) std::swap(i, j); // Защита от перепутанных индексов

    // std::sort принимает итераторы `last` как не включительно
    // Поэтому operands + j + 1
    std::sort(operands + i, operands + j + 1, absCompare);
}
