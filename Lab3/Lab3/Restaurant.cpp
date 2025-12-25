#include "Restaurant.h"
#include <iostream>

Restaurant::Restaurant(std::string name, std::string address, int year, double rating, int visitors, int seats, int menuItems, double profit)
    : PublicEstablishment(name, address, year, rating, visitors, seats), menuItemsCount(menuItems), totalProfit(profit)
{
}

void Restaurant::reserve()
{
    if (seats > 0) {
        seats--;
        totalProfit += 100;
        std::cout << "Ресторан \"" << name << "\": Столик забронирован. Мест осталось: " << seats 
                  << ". Прибыль выросла до: " << totalProfit << " грн." << std::endl;
    } else {
        std::cout << "Ресторан \"" << name << "\": Нет свободных мест!" << std::endl;
    }
}
