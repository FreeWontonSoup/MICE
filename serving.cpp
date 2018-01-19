#include "serving.h"
#include <fstream>
#include <exception>

std::string Serving::toString()
{
    std::string s;
    int numScoops = iceCream.getNumScoops();
    s += "Container: " + iceCream.get_Name() + "\n";
    s += "Number of scoops: " + std::to_string(numScoops) + "\n";
    
    for(int i = 0; i < numScoops; i++)
    {
        s += "Scoop " + std::to_string(i+1) + " flavor: " + iceCream.get_ic_scoops()[i].get_Name() + "\n";
        s += "Scoop " + std::to_string(i+1) + " toppings: " + iceCream.get_ic_scoops()[i].getToppingsName() + "\n";
    }
    s += "Server: " + serverName + "\n";
    s += "Customer: " + customerName + "\n";
    s += "Serving Price: " + std::to_string(icPrice) + "\n";
    s += "Wholesale Price: " + std::to_string(wholesalePrice) + "\n\n\n";
    return s;
}

void Serving::set_serv_price(double i)
{
    icPrice = i;
}

double Serving::get_serv_price()
{
    return icPrice;
}

void Serving::calc_serv_price()
{
    iceCream.calcContainerPrice();
    icPrice = iceCream.getRetailPrice();
}

void Serving::setServerName(std::string servName)
{
    serverName = servName;
}

void Serving::setCustomerName(std::string custName)
{
    customerName = custName;
}

void Serving::saveServing(std::string filename)
{
    //int containerNum, numScoops;
    std::string contType = iceCream.get_Name();
    
    std::ofstream file;
    file.open(filename,std::ios::app);
    file << customerName + "," + serverName << std::endl;
    file << std::to_string(icPrice) << std::endl;
    file << iceCream.get_Name() << std::endl;
    file << iceCream.getNumScoops() << std::endl;
    
    std::vector<Scoop> scoops = iceCream.get_ic_scoops();
    for(int i = 0; i < scoops.size(); i++)
    {
        file << scoops[i].get_Name() + ",";
        
        std::vector<Toppings> tops = scoops[i].getToppings();
        if(tops.size() > 0)
        {
            for(int j = 0; j < tops.size()-1; j++)
            {
                file << tops[j].get_Name() + ",";
            }
            file << tops[tops.size()-1].get_Name() << std::endl;
        }
        else
        {
            file << " " << std::endl;
        }
        
    }
    //file << "$" << std::endl;
    
    file.close();
    
}

void Serving::calcWholesale()
{
    iceCream.calcWholesaleContainer();
    wholesalePrice = iceCream.getWholesaleCost();
}

double Serving::getWholesaleCost()
{
    return wholesalePrice;
}









