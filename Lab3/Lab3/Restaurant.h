#pragma once
#include "PublicEstablishment.h"
#include "IReservable.h"

class Restaurant : public PublicEstablishment, public IReservable
{
private:
    int menuItemsCount;
    double totalProfit;

public:
    Restaurant(std::string name, std::string address, int year, double rating, int visitors, int seats, int menuItems, double profit);

    // Реализация бронирования: уменьшает места, увеличивает прибыль на 100
    virtual void reserve() override;
    
    double getProfit() const { return totalProfit; }
};
