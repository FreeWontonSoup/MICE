#ifndef scoop_h
#define scoop_h
#include <iostream>
#include <vector>
#include "toppings.h"
#include "items.h"

class Scoop : public Items
{
private:
    std::vector<Toppings> toppings;
public:
    Scoop(std::string n, std::string d, double w, double r, int s) : Items(n,d,w,r,s) { calcScoopPrice(); }
    void set_flavor(std::string flavor);
    void add_toppings(Toppings t);
    std::string getToppingsName();
    std::string get_Name() override { return name; }
    void calcScoopPrice();
    void saveScoop();
    std::vector<Toppings> getToppings();
    void calcScoopWholesale();
};

#endif
