#ifndef server_h
#define server_h
#include <iostream>
#include "order.h"
#include "customer.h"

class Server
{
private:
    std::string name;
    std::string employeeID;
    int numOrders;
    double salary;
    std::vector<Serving> servings;
    std::vector<Customer> customers;
    Order serverOrder;
public:
    Server(std::string n, std::string e, int num, double s, Order ord) : name{n}, employeeID{e}, numOrders{num}, salary{s}, serverOrder{ord} {}
    void add_customer(Customer c);
    void set_state_serv(Order &ord);
    Customer make_order(int i, Order *ord, bool isSelfCustServ = false);
    void add_serving(int i, Serving &s);
    void add_my_serving(Serving &s);
    void add_my_order(Order *ord);
    void removeServing(std::vector<int> nums);
    Order getServerOrders();
    std::string get_Name();
    std::vector<Customer> get_Customers();
    std::vector<Serving> get_server_servings();
    void saveServer();
    void replaceCustomer(Customer c, int custNum);
    void set_Order(Order ord);
    void setSalary(double newSalary);
    friend class View_Gui;
};

#endif
