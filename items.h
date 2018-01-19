#ifndef items_h
#define items_h
#include <iostream>

class Items
{
protected:
    std::string name;
    std::string description;
    double wholesaleCost;
    double retailPrice;
    int stockRemaining;
public:
    Items(std::string n, std::string d, double w, double r, int s) : name{n}, description{d}, wholesaleCost{w}, retailPrice{r}, stockRemaining{s} {}
    virtual std::string get_Name();
    int getStock();
    void reduceStock();
    double getRetailPrice();
    void increaseStock(int i);
    double getWholesaleCost();
    std::string getDesc();
    friend class View_Gui;
};

#endif
