#ifndef toppings_h
#define toppings_h
#include <iostream>
#include "items.h"

class Toppings : public Items
{
private:
    /*
    enum quantities{light,normal,extra,drenched};
    quantities quantity;
     */
    std::string quantity;
public:
    Toppings(std::string n, std::string d, double w, double r, int s, std::string q = "light") : Items(n,d,w,r,s), quantity{q} {}
    void set_quantity();
    std::string get_Name() override { return name; }
    void saveTops();
    std::string quantities_toString();
};

#endif
