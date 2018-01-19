#ifndef emporium_h
#define emporium_h
#include <iostream>
#include "server.h"
#include "order.h"
#include "flavor.h"
#include <sqlite3.h>

class Emporium
{
private:
    std::vector<Server> servers;
    std::vector<Order> orders;
    std::vector<Scoop> flavors;
    std::vector<Container> containers;
    std::vector<Toppings> toppings;
    std::vector<Customer> customers;
    double netProfit;
    double totalWholesale;
    double totalSaleOfGoods;
    std::string managerName;
public:
    //Emporium(std::vector<Server> s, std::vector<Order> o, std::vector<Scoop> f, std::vector<Container> c, std::vector<Toppings> t, double n) : servers{s}, orders{o}, flavors{f}, containers{c}, toppings{t}, netProfit{n};
    Emporium();
    void create_flavor(Scoop& s);
    void create_container(Container& c);
    void create_topping(Toppings& t);
    void create_server(Server& serv);
    std::vector<Container> get_Containers();
    std::vector<Scoop> get_Scoops();
    std::vector<Toppings> get_Toppings();
    std::vector<Server> get_Servers();
    std::vector<Customer> get_Customers();
    void create_Serving(int servNum, int custNum, Container &c, int cust, int custChoice, bool isSelfServ = false);
    void create_Serving_NoServer(int custNum, Container &c);
    void create_Order_Serv(int servNum);
    void create_Order_Cust(int servNum, int custNum, int custNumEmp, int found);
    void add_server();
    void add_customer(int choice, Customer &c);
    void list_server_data();
    void list_customer_data();
    void list_inventory_data();
    void list_orders();
    void statement();
    void manageStock(int containerType, std::vector<int> scoops, std::vector<int> tops);
    bool checkContainerStock(int contType);
    bool checkFlavorStock(int flavType);
    bool checkToppingStock(int topType);
    void saveFile();
    void saveServingsOrders();
    void loadFile();
    void loadToppings();
    void loadScoops();
    void loadContainers();
    void loadCustomers();
    void loadServers();
    void loadServing();
    void loadOrder();
    void loadEmp();
    void restockFlavors(int spot);
    void restockContainers(int spot);
    void restockToppings(int spot);
    Container findContainer(std::string containerType);
    Scoop findScoop(std::string flavor);
    Toppings findToppings(std::string tops);
    void putOrderin(Order ord, std::string custName, std::string servName);
    void calcTotalWholesale();
    void calcTotalRetail();
    void calcProfit();
    double getProfit();
    void setManagerName();
    void saveEmp();
    void changeServerSalary(int servNum, double newSalary);
    void editFlavor(Scoop s, int spot);
    void editContainer(Container c, int spot);
    void editTopping(Toppings t, int spot);
    friend class View;
    friend class View_Gui;
};

#endif
