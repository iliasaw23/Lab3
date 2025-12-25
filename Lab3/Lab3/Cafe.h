#pragma once
#include "PublicEstablishment.h"
#include "IReservable.h"

class Cafe : public PublicEstablishment, public IReservable
{
public:
    // Кафе использует те же поля, что и базовый класс, но имеет свою логику reserve
    // Дополнительных полей в задании явно не указано, распределяем общие
    Cafe(std::string name, std::string address, int year, double rating, int visitors, int seats);

    // Реализация бронирования: уменьшает места, увеличивает рейтинг на 0.1
    virtual void reserve() override;
};
