#include "Cafe.h"
#include <iostream>

Cafe::Cafe(std::string name, std::string address, int year, double rating, int visitors, int seats)
    : PublicEstablishment(name, address, year, rating, visitors, seats)
{
}

void Cafe::reserve()
{
    if (seats > 0) {
        seats--;
        rating += 0.1;
        std::cout << "Кафе \"" << name << "\": Столик забронирован. Мест осталось: " << seats 
                  << ". Рейтинг вырос до: " << rating << std::endl;
    } else {
        std::cout << "Кафе \"" << name << "\": Нет свободных мест!" << std::endl;
    }
}
