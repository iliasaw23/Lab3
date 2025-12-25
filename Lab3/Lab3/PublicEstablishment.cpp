#include "PublicEstablishment.h"

PublicEstablishment::PublicEstablishment(std::string name, std::string address, int year, double rating, int visitors, int seats)
    : name(name), address(address), foundationYear(year), rating(rating), monthlyVisitors(visitors), seats(seats)
{
}
