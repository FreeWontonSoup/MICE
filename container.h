#ifndef container_h
#define container_h
#include <iostream>
#include <vector>
#include "scoop.h"

class Container : public Items
{
protected:
    std::vector<Scoop> ic_scoops;
    int maxScoops;
public:
    Container(std::string n, std::string d, double w, double r, int s, int num) : Items(n,d,w,r,s), maxScoops{num} {}
    void add_scoop(Scoop &s);
    void set_Container(std::string cont);
    //virtual void set_type();
    //virtual std::string toString();
    int get_max_Scoops();
    int getNumScoops();
    std::vector<Scoop> get_ic_scoops();
    std::string get_Name() override { return name; }
    void calcContainerPrice();
    void saveContainer();
    void calcWholesaleContainer();
};

#endif
