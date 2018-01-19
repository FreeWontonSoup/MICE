#ifndef customer_h
#define customer_h
#include <iostream>
#include <vector>
#include "order.h"

class Customer
{
private:
    std::string name;
    std::string phoneNumber;
    Order customerOrder;
    std::vector<Serving> servings;
public:
    Customer(std::string n, std::string p, Order ord) : name{n}, phoneNumber{p}, customerOrder{ord} /*custOrders{c}*/ {}
    void set_state_cust();
    void set_order(Order *ord);
    std::vector<Serving> get_Cust_Servings();
    Order getCustOrders();
    void add_Cust_Serving(Serving &s);
    std::string get_Name();
    void removeServing(std::vector<int> nums);
    void self_order(Order *ord);
    void saveCustomer();
    std::string getPhoneNumber();
    std::string toString();
    void make_order(Order ord);
    void setCustState();
    
    //OPERATOR OVERLOADING
    friend bool operator==(Customer &c1,Customer &c2)
    {
        return c1.get_Name() == c2.get_Name();
    }
};

#endif
