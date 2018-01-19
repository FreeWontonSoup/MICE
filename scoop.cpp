#include "scoop.h"
#include <iostream>
#include <fstream>

void Scoop::set_flavor(std::string flavor)
{
    name = flavor;
}

void Scoop::add_toppings(Toppings t)
{
    toppings.push_back(t);
}

std::string Scoop::getToppingsName()
{
    std::string s;
    
    for(int i = 0; i < toppings.size(); i++)
    {
        if(i == toppings.size() - 1)
        {
            s += toppings[i].get_Name();
            break;
        }
        s += toppings[i].get_Name() + ", ";
    }
    return s;
}

void Scoop::calcScoopPrice()
{
    double price = 0;
    for(int i = 0; i < toppings.size(); i++)
    {
        price += toppings[i].getRetailPrice();
    }
    price += retailPrice;
    retailPrice = price;
}

void Scoop::saveScoop()
{
    std::ofstream file;
    file.open("scoops.txt",std::ios::app);
    file << name + "," + description + "," + std::to_string(wholesaleCost) + "," + std::to_string(retailPrice) + "," + std::to_string(stockRemaining) << std::endl;
    file.close();
}

std::vector<Toppings> Scoop::getToppings()
{
    return toppings;
}

void Scoop::calcScoopWholesale()
{
    double price = 0;
    for(int i = 0; i < toppings.size(); i++)
    {
        price += toppings[i].getWholesaleCost();
    }
    price += wholesaleCost;
    wholesaleCost = price;
}








