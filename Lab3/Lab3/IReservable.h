#pragma once

// Интерфейс для бронирования
class IReservable
{
public:
    virtual ~IReservable() = default;

    // Метод бронирования столика
    virtual void reserve() = 0;
};
