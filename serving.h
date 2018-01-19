#ifndef serving_h
#define serving_h
#include <iostream>
#include "container.h"

class Serving
{
private:
    Container iceCream;
    double icPrice;
    std::string serverName;
    std::string customerName;
    double wholesalePrice;
public:
    Serving(Container c, double i) : iceCream{c}, icPrice{i} { calc_serv_price(); calcWholesale(); }
    void calc_serv_price();
    void set_serv_price(double i);
    double get_serv_price();
    void create_Container();
    std::string toString();
    void saveServing(std::string filename);
    void setServerName(std::string servName);
    void setCustomerName(std::string custName);
    void calcWholesale();
    double getWholesaleCost();
};

#endif
