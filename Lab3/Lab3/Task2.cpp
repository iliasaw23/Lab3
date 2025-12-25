#include "Task2.h"
#include "Restaurant.h"
#include "Cafe.h"
#include <iostream>
#include <vector>

void RunTask2()
{
    std::cout << "=== ЗАПУСК ЗАДАНИЯ 2 (Ресторан/Кафе) ===\n" << std::endl;

    // Создаем вектор (или массив) указателей на интерфейс бронирования
    // В задании сказано создать 2 ресторана и 2 кафе
    std::vector<IReservable*> places;

    places.push_back(new Restaurant("Элитный", "ул. Пушкина, 10", 2010, 4.8, 500, 50, 40, 10000.0));
    places.push_back(new Restaurant("У Ашота", "ул. Ленина, 1", 2005, 3.5, 200, 20, 25, 5000.0));
    
    places.push_back(new Cafe("Кофейня №1", "пр. Мира, 5", 2018, 4.5, 300, 15));
    places.push_back(new Cafe("Утро", "пер. Тихий, 2", 2021, 4.9, 150, 10));

    std::cout << "--- Демонстрация бронирования (Полиморфизм) ---\n" << std::endl;

    for (auto place : places) {
        // Вызываем метод reserve() через интерфейс
        place->reserve();
    }

    std::cout << "\n--- Повторное бронирование для наглядности ---\n" << std::endl;
    // Бронируем еще раз, чтобы увидеть изменения
    for (auto place : places) {
        place->reserve();
    }

    // Освобождаем память
    // Так как IReservable имеет виртуальный деструктор (default), удаление корректно
    // Но нужно быть осторожным, т.к. наши объекты наследовали IReservable и PublicEstablishment.
    // Если удалять через IReservable*, деструктор PublicEstablishment вызовется только если правильно настроено наследование.
    // В данном случае IReservable - интерфейс. Restaurant : PublicEstablishment, IReservable.
    // Корректнее было бы хранить указатели на общий базовый класс или использовать умные указатели.
    // Но в рамках лабы просто удалим. 
    // Важно: чтобы вызвались все деструкторы, деструктор IReservable должен быть виртуальным (он такой и есть).
    
    for (auto place : places) {
        delete place;
    }
}
