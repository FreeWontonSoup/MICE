#ifndef order_h
#define order_h
#include <iostream>
#include <vector>
#include "serving.h"

class Order
{
private:
    std::vector<Serving> servings;
    std::string orderID;
    double totalPrice;
    //enum states{unfilled,filled,paid,canceled};
    //states state = filled;
    std::string state = "unfilled";
    std::string customerName;
    std::string serverName;
    double totalWholesale;
public:
    Order(std::string o, double t, std::string c, std::string se) : orderID{o}, totalPrice{t}, customerName{c}, serverName{se} {}
    void add_serving(Serving s);
    void set_orderID(std::string id);
    void calc_price();
    void set_customer(std::string custName);
    void set_server(std::string servName);
    std::string toString();
    void saveOrder();
    double getTotalPrice();
    std::string getOrderID();
    void calcOrderWholesale();
    double getOrderWholesaleP();
    void setState(int i);
    std::string getState();
    std::string numServings_toString();
};

#endif
