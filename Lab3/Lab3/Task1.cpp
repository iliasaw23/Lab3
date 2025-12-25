#include "Task1.h"
#include "Summator.h"
#include "Multiplier.h"
#include "CustomExpressionEvaluator.h"
#include <iostream>

void RunTask1()
{
    std::cout << "=== ЗАПУСК ЗАДАНИЯ 1 (ВАРИАНТ 10) ===\n" << std::endl;

    // Создаем массив из трех указателей на базовый класс
    // В соответствии с вариантом: CustomExpressionEvaluator, Summator, Multiplier
    ExpressionEvaluator* evaluators[3];

    // 1. CustomExpressionEvaluator: 5 операндов, присвоить группой 1, -5, 2.5, 10, 8.
    evaluators[0] = new CustomExpressionEvaluator(5);
    double customOps[] = { 1, -5, 2.5, 10, 8 };
    evaluators[0]->setOperands(customOps, 5);

    // 2. Summator: 6 операндов, присвоить группой 15, -7.5, 3.2, 8.7, -1.5, -9.5.
    evaluators[1] = new Summator(6);
    double sumOps[] = { 15, -7.5, 3.2, 8.7, -1.5, -9.5 };
    evaluators[1]->setOperands(sumOps, 6);

    // 3. Multiplier: 3 операнда, присвоить поэлементно -8, 7, -0.5.
    evaluators[2] = new Multiplier(3);
    evaluators[2]->setOperand(0, -8);
    evaluators[2]->setOperand(1, 7);
    evaluators[2]->setOperand(2, -0.5);

    // Проход в цикле: вывод лога на консоль и в файл
    // Файл "log.txt" будет создан/дописан
    for (int i = 0; i < 3; ++i) {
        evaluators[i]->logToScreen();
        evaluators[i]->logToFile("log.txt");
    }

    std::cout << "\n--- Проверка IShuffle ---\n" << std::endl;

    // Проверка RTTI и IShuffle
    for (int i = 0; i < 3; ++i) {
        // Пытаемся привести к интерфейсу IShuffle
        IShuffle* shuffleObj = dynamic_cast<IShuffle*>(evaluators[i]);
        
        if (shuffleObj) {
            std::cout << "Объект #" << (i+1) << " поддерживает IShuffle. Выполняем сортировку..." << std::endl;
            // Сортируем все операнды (по модулю, согласно варианту 10)
            shuffleObj->shuffle();
            
            // Выводим результат после сортировки
            std::cout << "После перемешивания: ";
            evaluators[i]->logToScreen();
            
            // Можно также записать в файл if needed
            // evaluators[i]->logToFile("log.txt");
        } else {
            std::cout << "Объект #" << (i+1) << " НЕ поддерживает IShuffle." << std::endl;
        }
        std::cout << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < 3; ++i) {
        delete evaluators[i];
    }
}
