#ifndef view_h
#define view_h
#include <iostream>
#include "emporium.h"

class View
{
private:
    Emporium &emp;
public:
    View(Emporium &e) : emp{e} {}
    void show_menu();
    void show_manager_menu();
    void list_flavors();
    void list_containers();
    void list_toppings();
};

#endif
