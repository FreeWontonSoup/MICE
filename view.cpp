#include "view.h"
#include <iostream>
#include <string>

void View::show_menu()
{
    std::string menu = R"(
    =================================
    CSE1325 Mav’s Ice Cream Emporium
    =================================
    
    Roles
    ------------
    (1) Manager
    (2) Server
    (3) Customer
    
    Utilities
    ------------
    (0) Exit

    )";
    
    std::cout << menu << std::endl;
}

void View::list_containers()
{
    /*
    std::string t;
    int i;
    for(i = 0; i < emp.containers.size()-1; i++)
    {
        t += emp.containers[i] + ", ";
    }
    t += "and " + emp.containers[i] + "\n";
    std::cout << t << std::endl;
     */
}

void View::show_manager_menu()
{
    std::string menu = R"(
    Abilities
    ------------
    (1) Create new ice cream flavor
    (2) List current ice cream flavors
    (3) Create a new container
    (4) List current containers
    (5) Create a new topping
    (6) List current toppings
    
    Utilities
    ------------
    (0) Log out
    
    )";
    
    std::cout << menu << std::endl;
}

void View::list_flavors()
{
    /*
    std::string t;
    int i;
    for(i = 0; i < emp.flavors.size()-1; i++)
    {
        t += emp.flavors[i] + ", ";
    }
    t += "and " + emp.flavors[i] + "\n";
    std::cout << t << std::endl;
     */
}

void View::list_toppings()
{
    /*
    std::string t;
    int i;
    for(i = 0; i < emp.toppings.size()-1; i++)
    {
        t += emp.toppings[i] + ", ";
    }
    t += "and " + emp.toppings[i] + "\n";
    std::cout << t << std::endl;
     */
}
