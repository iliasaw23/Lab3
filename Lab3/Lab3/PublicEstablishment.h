#pragma once
#include <string>

// Базовый класс: Заведение общепита
class PublicEstablishment
{
protected:
    std::string name;
    std::string address;
    int foundationYear;
    double rating;
    int monthlyVisitors;
    int seats; // Количество мест

public:
    PublicEstablishment(std::string name, std::string address, int year, double rating, int visitors, int seats);
    virtual ~PublicEstablishment() = default;

    // Геттеры для вывода информации (опционально, но полезно для логов)
    std::string getName() const { return name; }
    int getSeats() const { return seats; }
    double getRating() const { return rating; }
};
