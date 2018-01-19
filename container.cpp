#include "container.h"
#include "scoop.h"
#include <iostream>
#include <fstream>

void Container::set_Container(std::string cont)
{
    //container = cont;
}

int Container::get_max_Scoops()
{
    return maxScoops;
}

void Container::add_scoop(Scoop &s)
{
    ic_scoops.push_back(s);
}

int Container::getNumScoops()
{
    return ic_scoops.size();
}

std::vector<Scoop> Container::get_ic_scoops()
{
    return ic_scoops;
}

void Container::calcContainerPrice()
{
    double price = 0;
    for(int i = 0; i < ic_scoops.size(); i++)
    {
        ic_scoops[i].calcScoopPrice();
        price += ic_scoops[i].getRetailPrice();
    }
    price += retailPrice;
    retailPrice = price;
}

void Container::saveContainer()
{
    std::ofstream file;
    file.open("containers.txt",std::ios::app);
    file << name + "," + description + "," + std::to_string(wholesaleCost) + "," + std::to_string(retailPrice) + "," + std::to_string(stockRemaining) + "," + std::to_string(maxScoops) << std::endl;
    file.close();
}

void Container::calcWholesaleContainer()
{
    double price = 0;
    for(int i = 0; i < ic_scoops.size(); i++)
    {
        ic_scoops[i].calcScoopWholesale();
        price += ic_scoops[i].getWholesaleCost();
    }
    price += wholesaleCost;
    wholesaleCost = price;
}








