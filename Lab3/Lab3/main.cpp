#include "Task1.h"
#include "Task2.h"
#include <iostream>
#include <windows.h> // Для SetConsoleOutputCP

int main()
{
    // Установка кодировки для корректного вывода русского текста
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Запуск Задания 1
    RunTask1();

    std::cout << "\n\n------------------------------------------------\n\n";

    // Запуск Задания 2
    RunTask2();

    std::cout << "\nНажмите Enter, чтобы выйти...";
    std::cin.get();

    return 0;
}
