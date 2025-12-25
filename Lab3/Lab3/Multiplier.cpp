#include "Multiplier.h"

Multiplier::Multiplier(size_t n) : ExpressionEvaluator(n) {}

double Multiplier::calculate() const
{
    if (n == 0) return 0;
    double prod = 1;
    for (size_t i = 0; i < n; ++i) {
        prod *= operands[i];
    }
    return prod;
}

void Multiplier::logToScreen() const
{
    std::cout << "[Multiplier] Expression: " << n << " operands : ";
    for (size_t i = 0; i < n; ++i) {
        printOperand(std::cout, operands[i]);
        if (i < n - 1) {
            std::cout << " * ";
        }
    }
    std::cout << "\nResult: " << calculate() << std::endl;
}

void Multiplier::logToFile(const std::string& filename) const
{
    std::ofstream ofs(filename, std::ios_base::app);
    if (ofs.is_open()) {
        ofs << "[Multiplier] Expression: " << n << " operands : ";
        for (size_t i = 0; i < n; ++i) {
            printOperand(ofs, operands[i]);
            if (i < n - 1) {
                ofs << " * ";
            }
        }
        ofs << "\nResult: " << calculate() << std::endl;
        ofs.close();
    }
}
