#include "view_gui.h"
#include "dialogs.h"
#include <string>

void View_Gui::list_flavors()
{
    if(emp.flavors.size() > 0)
    {
        std::string t;
        int i;
        for(i = 0; i < emp.flavors.size(); i++)
        {
            t += "Flavor: " + emp.flavors[i].name + "\n";
            t += "Wholesale cost: " + std::to_string(emp.flavors[i].wholesaleCost) + "\n";
            t += "Retail price: " + std::to_string(emp.flavors[i].retailPrice) + "\n";
            t += "Stock remaining: " + std::to_string(emp.flavors[i].stockRemaining) + "\n\n\n";
        }
        //t += /*"and " + */emp.flavors[i].name + "\n";
        
        Dialogs::message(t,"Flavors");
    }
    else
    {
        Dialogs::message("No flavors added!","Flavors");
    }
}

void View_Gui::list_containers()
{
    if(emp.containers.size() > 0)
    {
        std::string t;
        int i;
        for(i = 0; i < emp.containers.size(); i++)
        {
            t += "Container: " + emp.containers[i].name + "\n";
            t += "Wholesale cost: " + std::to_string(emp.containers[i].wholesaleCost) + "\n";
            t += "Retail price: " + std::to_string(emp.containers[i].retailPrice) + "\n";
            t += "Stock remaining: " + std::to_string(emp.containers[i].stockRemaining) + "\n\n\n";
        }
        //t += /*"and " + */emp.containers[i].name + "\n";
        
        Dialogs::message(t,"Containers");
    }
    else
    {
        Dialogs::message("No containers added!","Containers");
    }
}

void View_Gui::list_toppings()
{
    if(emp.toppings.size() > 0)
    {
        std::string t;
        int i;
        for(i = 0; i < emp.toppings.size(); i++)
        {
            t += "Topping: " + emp.toppings[i].name + "\n";
            t += "Wholesale cost: " + std::to_string(emp.toppings[i].wholesaleCost) + "\n";
            t += "Retail price: " + std::to_string(emp.toppings[i].retailPrice) + "\n";
            t += "Stock remaining: " + std::to_string(emp.toppings[i].stockRemaining) + "\n\n\n";
        }
        //t += /*"and " + */emp.toppings[i].name + "\n";
        Dialogs::message(t,"Toppings");
    }
    else
    {
        Dialogs::message("No toppings added!","Toppings");
    }
    
}

void View_Gui::list_servers()
{
    if(emp.servers.size() > 0)
    {
        std::string s;
        int i;
        for(i = 0; i < emp.servers.size(); i++)
        {
            s += "Name: " + emp.servers[i].name + "\nNumber of orders made: " + std::to_string(emp.servers[i].numOrders);
            s += "\nSalary: " + std::to_string(emp.servers[i].salary) + "\n\n\n";
        }
        Dialogs::message(s,"Servers");
    }
    else
    {
        Dialogs::message("No servers!","Servers");
    }
}

void View_Gui::list_cust_servings(Customer &c)
{
    std::vector<Serving> servings = c.get_Cust_Servings();
    std::string s;
    
    for(int i = 0; i < servings.size(); i++)
    {
        s += "Serving " + std::to_string(i+1) + "\n\n";
        s += servings[i].toString();
    }
    Dialogs::message(s,"Servings");
}

void View_Gui::list_serv_servings(Server &serv)
{
    std::vector<Serving> servings = serv.get_server_servings();
    std::string s;
    
    for(int i = 0; i < servings.size(); i++)
    {
        s += "Serving " + std::to_string(i+1) + "\n\n";
        s += servings[i].toString();
    }
    Dialogs::message(s,"Servings");
}

void View_Gui::help()
{
    Dialogs::message("Icons for toolbar buttons are part of the provided gtkmm stock buttons.\nImages are from other resources that can be found in the Credits tab!","Help");
}

void View_Gui::list_cust_orders(Customer &c)
{
    Order ord = c.getCustOrders();
    std::string s;
    
    
    s += "Order: \n\n";
    s += ord.toString();
    s += "\n";
    
    Dialogs::message(s,"View Order");
}

void View_Gui::list_orders()
{
    std::string s;
    for(int i = 0; i < emp.orders.size(); i++)
    {
        s += "Order " + std::to_string(i) + " \n";
        s += emp.orders.at(i).toString() + " \n";
    }
    Dialogs::message(s,"View Order");
}

void View_Gui::list_serv_orders(Server &serv)
{
    std::string s;
    Order ord = serv.getServerOrders();
    s += "Order: \n\n";
    s += ord.toString();
    s += "\n";
    
    Dialogs::message(s,"View Order for YOURSELF");
}

void View_Gui::list_customers()
{
    std::string s;
    for(int i = 0; i < emp.customers.size(); i++)
    {
        s += emp.customers[i].toString() + "\n\n";
    }
    Dialogs::message(s,"Customers");
}

void View_Gui::show_register()
{
    emp.calcTotalRetail();
    emp.calcTotalWholesale();
    emp.calcProfit();
    std::string s;
    s += "Total wholesale cost of sold goods: " + std::to_string(emp.totalWholesale) + "\n";
    s += "Total retail price of sold good: " + std::to_string(emp.totalSaleOfGoods) + "\n";
    s += "Net profit: " + std::to_string(emp.netProfit) + "\n";
    Dialogs::message(s,"Cash Register");
}

void View_Gui::show_manager()
{
    Dialogs::message(emp.managerName,"Manager Name");
}













