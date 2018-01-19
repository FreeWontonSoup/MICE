#ifndef view_gui_h
#define view_gui_h
#include <iostream>
#include "emporium.h"

class View_Gui
{
private:
    Emporium &emp;
public:
    View_Gui(Emporium &e) : emp{e} {}
    //void show_menu();
    //void show_manager_menu();
    void list_flavors();
    void list_containers();
    void list_toppings();
    void list_servers();
    void list_customers();
    void list_cust_servings(Customer &c);
    void list_serv_servings(Server &s);
    void list_cust_orders(Customer &c);
    void list_serv_orders(Server &serv);
    void list_orders();
    void show_manager();
    void show_register();
    void help();
};

#endif
