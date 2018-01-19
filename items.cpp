#include "items.h"

std::string Items::get_Name()
{
    return name;
}

void Items::reduceStock()
{
    stockRemaining--;
}

int Items::getStock()
{
    return stockRemaining;
}

double Items::getRetailPrice()
{
    return retailPrice;
}

void Items::increaseStock(int i)
{
    stockRemaining += i;
}

double Items::getWholesaleCost()
{
    return wholesaleCost;
}

std::string Items::getDesc()
{
    return description;
}
