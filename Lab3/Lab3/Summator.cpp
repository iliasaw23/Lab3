#include "Summator.h"

Summator::Summator(size_t n) : ExpressionEvaluator(n) {}

double Summator::calculate() const
{
    double sum = 0;
    for (size_t i = 0; i < n; ++i) {
        sum += operands[i];
    }
    return sum;
}

void Summator::logToScreen() const
{
    std::cout << "[Summator] Expression: " << n << " operands : ";
    for (size_t i = 0; i < n; ++i) {
        printOperand(std::cout, operands[i]);
        if (i < n - 1) {
            std::cout << " + ";
        }
    }
    std::cout << "\nResult: " << calculate() << std::endl;
}

void Summator::logToFile(const std::string& filename) const
{
    std::ofstream ofs(filename, std::ios_base::app); // Режим дозаписи
    if (ofs.is_open()) {
        ofs << "[Summator] Expression: " << n << " operands : ";
        for (size_t i = 0; i < n; ++i) {
            printOperand(ofs, operands[i]);
            if (i < n - 1) {
                ofs << " + ";
            }
        }
        ofs << "\nResult: " << calculate() << std::endl;
        ofs.close();
    }
}
