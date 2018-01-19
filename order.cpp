#include "order.h"
#include <fstream>

void Order::add_serving(Serving s)
{
    servings.push_back(s);
}

void Order::set_server(std::string servName)
{
    serverName = servName;
}

void Order::set_customer(std::string custName)
{
    customerName = custName;
}

void Order::set_orderID(std::string id)
{
    orderID = id;
}

std::string Order::toString()
{
    std::string s;
    s += "Order ID: " + orderID + " \n";
    s += "Server: " + serverName + " \n";
    s += "Customer: " + customerName + " \n";
    s += "Price: " + std::to_string(totalPrice) + " \n";
    s += "Wholesale price: " + std::to_string(totalWholesale) + "\n";
    s += "State: " + state + "\n";
    s += "# of servings: " + std::to_string(servings.size()) + " \n";
    s += "Servings:\n\n";
    for(int i = 0; i < servings.size(); i++)
    {
        s += servings[i].toString();
    }
    
    return s;
}

void Order::saveOrder()
{
    std::ofstream file;
    file.open("orders.txt",std::ios::app);
    file << customerName + "," + serverName + "," + std::to_string(servings.size()) + "," + orderID + "," + std::to_string(totalPrice) << std::endl;
    for(int i = 0; i < servings.size(); i++)
    {
        servings[i].saveServing("orders.txt");
    }
    file.close();
}

double Order::getTotalPrice()
{
    return totalPrice;
}

std::string Order::getOrderID()
{
    return orderID;
}

void Order::calc_price()
{
    double p = 0;
    for(int i = 0; i < servings.size(); i++)
    {
        p += servings[i].get_serv_price();
    }
    totalPrice = p;
}

void Order::calcOrderWholesale()
{
    double p = 0;
    for(int i = 0; i < servings.size(); i++)
    {
        p += servings[i].getWholesaleCost();
    }
    totalWholesale = p;
}

double Order::getOrderWholesaleP()
{
    return totalWholesale;
}

void Order::setState(int i)
{
    //STATE MACHINE
    switch(i)
    {
        case 0: state = "unfilled";
            break;
        case 1: state = "filled";
            break;
        case 2: state = "canceled";
            break;
        case 3: state = "paid";
            break;
        default: state = "unfilled";
    }
}

std::string Order::getState()
{
    return state;
}

std::string Order::numServings_toString()
{
    std::string s;
    s += "Servings wanted in order: ";
    for(int i = 0; i < servings.size(); i++)
    {
        s += std::to_string(i) + " ";
    }
    return s;
}





