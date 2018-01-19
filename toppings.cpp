#include "toppings.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Toppings::saveTops()
{
    std::ofstream file;
    file.open("toppings.txt",std::ios::app);
    file << name + "," + description + "," + std::to_string(wholesaleCost) + "," + std::to_string(retailPrice) + "," + std::to_string(stockRemaining) + "," + quantity << std::endl;
    file.close();
}














