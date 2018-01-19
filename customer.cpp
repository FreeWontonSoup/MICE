#include "customer.h"
#include "gtkmm.h"
#include "dialogs.h"
#include <fstream>

std::vector<Serving> Customer::get_Cust_Servings()
{
    return servings;
}

void Customer::add_Cust_Serving(Serving &s)
{
    servings.push_back(s);
}

std::string Customer::get_Name()
{
    return name;
}

void Customer::set_order(Order *ord)
{
    customerOrder = *ord;
    //test1();
}

void Customer::removeServing(std::vector<int> nums)
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

Order Customer::getCustOrders()
{
    return customerOrder;
}

void Customer::self_order(Order *ord)
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
    Dialogs::message(s,"Current servings for you: ");
    
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
    
    /*
    Gtk::Dialog *dialog3 = new Gtk::Dialog();
    dialog3->set_title("Create Order");
    
    Gtk::HBox b_tops;
    
    Gtk::Label l_tops{"Is this an order request or a self-made order?"};
    l_tops.set_width_chars(50);
    b_tops.pack_start(l_tops, Gtk::PACK_SHRINK);
    dialog3->get_vbox()->pack_start(b_tops, Gtk::PACK_SHRINK);
    dialog3->add_button("Request", 1);
    dialog3->add_button("Self-made",3);
    dialog3->show_all();
    int topDecide = dialog3->run();
    dialog3->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    
    if(topDecide == 1 || 3)
    {
        ord->setState(topDecide);
    }
     */
    
    ord->setState(3);
    
    removeServing(numsDel);
    ord->calc_price();
    ord->calcOrderWholesale();
    customerOrder = *ord;
}

void Customer::saveCustomer()
{
    std::ofstream file;
    file.open("customers.txt",std::ios::app);
    file << name + "," + phoneNumber << std::endl;
    file.close();
}

std::string Customer::toString()
{
    std::string s;
    s += "Name: " + name + "\n";
    s += "Phone #: " + phoneNumber + "\n";
    s += "# of servings: " + std::to_string(servings.size()) + "\n";
    if(customerOrder.getTotalPrice() == -1)
    {
        s += "Current order ID: No order";
    }
    else
    {
        s += "Current order ID: " + customerOrder.getOrderID() + "\n";
    }
    return s;
}

std::string Customer::getPhoneNumber()
{
    return phoneNumber;
}

void Customer::make_order(Order ord)
{
    customerOrder = ord;
}

void Customer::setCustState()
{
    customerOrder.setState(3);
}









