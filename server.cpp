#include "server.h"
#include "dialogs.h"
#include <exception>
#include <fstream>

std::string Server::get_Name()
{
    return name;
}

std::vector<Customer> Server::get_Customers()
{
    return customers;
}

void Server::add_serving(int i, Serving &s)
{
    customers[i].add_Cust_Serving(s);
}

void Server::add_my_serving(Serving &s)
{
    servings.push_back(s);
}

void Server::add_customer(Customer c)
{
    customers.push_back(c);
}

std::vector<Serving> Server::get_server_servings()
{
    return servings;
}

Customer Server::make_order(int i, Order *ord, bool isSelfCustServ)
{
    //std::cout << "in Server " << ord->toString() << std::endl;
    std::string id;
    std::vector<int> numsDel;
    if(isSelfCustServ == false)
    {
        ord->set_server(get_Name());
        if(customers[i].getCustOrders().getState() == "unfilled")
        {
            numOrders++;
            customers[i].setCustState();
            Dialogs::message("Order completed for customer!","Make Order");
            return customers[i];
        }
    }
    else
    {
        ord->set_server(customers[i].get_Name());
    }
    ord->set_customer(customers[i].get_Name());
    
    std::vector<Serving> custServings = customers[i].get_Cust_Servings();
    std::string s;
    
    Gtk::Dialog *dialog2 = new Gtk::Dialog();
    dialog2->set_title("Create Order");
    
    Gtk::HBox b_desc;
    
    Gtk::Label l_desc{"Order ID: "};
    l_desc.set_width_chars(20);
    b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
    
    Gtk::Entry e_desc;
    e_desc.set_max_length(50);
    b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
    dialog2->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
    
    dialog2->add_button("Cancel", 0);
    dialog2->add_button("OK", 1);
    dialog2->show_all();
    int cs = dialog2->run();
    dialog2->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    
    id = e_desc.get_text();
    
    if(cs == 1)
    {
        ord->set_orderID(id);
    }
    else
    {
        //throw std::runtime_error("");
    }
    
    for(int j = 0; j < custServings.size(); j++)
    {
        s += "Serving " + std::to_string(j+1) + "\n\n";
        s += custServings[j].toString();
    }
    Dialogs::message(s,"Current servings for customer: ");
    
    for(int k = 0; k < custServings.size(); k++)
    {
        Gtk::Dialog *dialog2 = new Gtk::Dialog();
        dialog2->set_title("Create Order");
        
        Gtk::HBox b_tops;
        
        Gtk::Label l_tops{"Do you want serving " + std::to_string(k+1) + " in this order?"};
        l_tops.set_width_chars(50);
        b_tops.pack_start(l_tops, Gtk::PACK_SHRINK);
        dialog2->get_vbox()->pack_start(b_tops, Gtk::PACK_SHRINK);
        dialog2->add_button("No", 0);
        dialog2->add_button("Yes", 1);
        dialog2->show_all();
        int topDecide = dialog2->run();
        dialog2->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        
        if(topDecide == 1)
        {
            ord->add_serving(custServings[k]);
            numsDel.push_back(k);
        }
    }
    
    if(isSelfCustServ == true)
    {
        Gtk::Dialog *dialog2 = new Gtk::Dialog();
        dialog2->set_title("Create Order");
        
        Gtk::HBox b_tops;
        
        Gtk::Label l_tops{"Is this an order request or a self-made order?"};
        l_tops.set_width_chars(50);
        b_tops.pack_start(l_tops, Gtk::PACK_SHRINK);
        dialog2->get_vbox()->pack_start(b_tops, Gtk::PACK_SHRINK);
        dialog2->add_button("Request", 1);
        dialog2->add_button("Self-made",3);
        dialog2->show_all();
        int topDecide = dialog2->run();
        dialog2->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        
        if(topDecide == 3)
        {
            ord->setState(topDecide);
        }

    }
    
    ord->calc_price();
    ord->calcOrderWholesale();
    customers[i].removeServing(numsDel);
    customers[i].set_order(ord);
    if(isSelfCustServ == false)
    {
        numOrders++;
    }
    return customers[i];
}

void Server::add_my_order(Order *ord)
{
    std::string id;
    std::vector<int> numsDel;
    ord->set_server(name);
    ord->set_customer(name);
    
    std::string s;
    
    Gtk::Dialog *dialog2 = new Gtk::Dialog();
    dialog2->set_title("Create Order");
    
    Gtk::HBox b_desc;
    
    Gtk::Label l_desc{"Order ID: "};
    l_desc.set_width_chars(20);
    b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
    
    Gtk::Entry e_desc;
    e_desc.set_max_length(50);
    b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
    dialog2->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
    
    dialog2->add_button("Cancel", 0);
    dialog2->add_button("OK", 1);
    dialog2->show_all();
    int cs = dialog2->run();
    dialog2->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    
    id = e_desc.get_text();
    
    if(cs == 1)
    {
        ord->set_orderID(id);
    }
    else
    {
        //throw std::runtime_error("");
    }
    
    for(int j = 0; j < servings.size(); j++)
    {
        s += "Serving " + std::to_string(j+1) + "\n\n";
        s += servings[j].toString();
    }
    Dialogs::message(s,"Current servings for server: ");
    
    for(int k = 0; k < servings.size(); k++)
    {
        Gtk::Dialog *dialog2 = new Gtk::Dialog();
        dialog2->set_title("Create Order");
        
        Gtk::HBox b_tops;
        
        Gtk::Label l_tops{"Do you want serving " + std::to_string(k+1) + " in this order?"};
        l_tops.set_width_chars(50);
        b_tops.pack_start(l_tops, Gtk::PACK_SHRINK);
        dialog2->get_vbox()->pack_start(b_tops, Gtk::PACK_SHRINK);
        dialog2->add_button("No", 0);
        dialog2->add_button("Yes", 1);
        dialog2->show_all();
        int topDecide = dialog2->run();
        dialog2->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        
        if(topDecide == 1)
        {
            ord->add_serving(servings[k]);
            numsDel.push_back(k);
        }
    }
    
    ord->setState(3);
    removeServing(numsDel);
    ord->calc_price();
    ord->calcOrderWholesale();
    serverOrder = *ord;
    numOrders++;
}

void Server::removeServing(std::vector<int> nums)
{
    std::vector<Serving> temp;
    for(int i = 0; i < nums.size(); i++)
    {
        servings[nums[i]].set_serv_price(-1);
    }
    
    for(int i = 0; i < servings.size(); i++)
    {
        if(servings[i].get_serv_price() != -1)
        {
            temp.push_back(servings[i]);
        }
    }
    servings = temp;

}

Order Server::getServerOrders()
{
    return serverOrder;
}

void Server::saveServer()
{
    std::ofstream file;
    file.open("servers.txt",std::ios::app);
    file << name + "," + employeeID + "," + std::to_string(numOrders) + "," + std::to_string(salary) << std::endl;
    
    if(customers.size() > 0)
    {
        for(int i = 0; i < customers.size()-1; i++)
        {
            file << customers[i].get_Name() + ",";
        }
        file << customers[customers.size()-1].get_Name() << std::endl;
    }
    else
    {
        file << " ," << std::endl;
    }
    //file << "$" << std::endl;
    file.close();
}

void Server::replaceCustomer(Customer c, int custNum)
{
    customers[custNum] = c;
}

void Server::set_Order(Order ord)
{
    serverOrder = ord;
}

void Server::setSalary(double newSalary)
{
    salary = newSalary;
}










