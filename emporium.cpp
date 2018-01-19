#include "emporium.h"
#include "gtkmm.h"
#include <sqlite3.h>
#include <fstream>
#include <sstream>

/*
Emporium::Emporium(std::vector<Server> s, std::vector<Order> o, std::vector<Scoop> f, std::vector<Container> c, std::vector<Toppings> t, double n) : servers{s}, orders{o}, flavors{f}, containers{c}, toppings{t}, netProfit{n}
{
    Scoop s{"Strawberry",""}
    flavors.push_back()
}
 */

Emporium::Emporium()
{
    Order ord{"", -1, "", ""};
    Scoop s{"Strawberry","strawberry flavored ice cream",2,5,1000};
    flavors.push_back(s);
    Container c{"Cone","waffle cone",2,5,1000,3};
    containers.push_back(c);
    Toppings t{"Sprinkles","sprinkles of candy",2,5,1000};
    toppings.push_back(t);
    Server serv{"John Doe","0",0,7.50,ord};
    servers.push_back(serv);
    Customer cust{"Jane Doe","0",ord};
    customers.push_back(cust);
    /*
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sql;
    rc = sqlite3_open("empl.db",&db);
    if(rc)
    {
        std::cout << "Can't open database: " << sqlite3_errmsg(db);
    }
    else
    {
        std::cout << "Opened database successfully";
    }
    
    sql = "CREATE TABLE EMPORIUM("
          ""
     */
}

void Emporium::manageStock(int containerType, std::vector<int> scoops, std::vector<int> tops)
{
    containers[containerType].reduceStock();
    for(int i = 0; i < scoops.size(); i++)
    {
        flavors[scoops[i]].reduceStock();
    }
    
    for(int i = 0; i < tops.size(); i++)
    {
        toppings[tops[i]].reduceStock();
    }
}

void Emporium::create_server(Server &serv)
{
    servers.push_back(serv);
}

void Emporium::create_flavor(Scoop& s)
{
    flavors.push_back(s);
}

void Emporium::create_container(Container& c)
{
    containers.push_back(c);
}
void Emporium::create_topping(Toppings& t)
{
    toppings.push_back(t);
}

std::vector<Container> Emporium::get_Containers()
{
    return containers;
}

std::vector<Scoop> Emporium::get_Scoops()
{
    return flavors;
}

std::vector<Toppings> Emporium::get_Toppings()
{
    return toppings;
}

std::vector<Server> Emporium::get_Servers()
{
    return servers;
}

void Emporium::create_Serving(int servNum, int custNum, Container &container, int cust, int custChoice, bool isSelfServ)
{
    Server *servingPerson = &(servers[servNum]);
    std::vector<Customer> i_customers = (*servingPerson).get_Customers();
    //int custChoice;
    
    if(isSelfServ == false)
    {
                
        if(cust == 1 && custChoice == 0)
        {
            //chose yourself
            Serving s{container,0};
            s.setServerName((*servingPerson).get_Name());
            s.setCustomerName((*servingPerson).get_Name());
            (*servingPerson).add_my_serving(s);
            //SAVE SERVING RIGHT HERE
            //s.saveServing();
        }
        else if(cust == 1 && custChoice > 0)
        {
            //adding to a customer
            Serving s{container,0};
            s.setServerName((*servingPerson).get_Name());
            s.setCustomerName(i_customers[custChoice-1].get_Name());
            (*servingPerson).add_serving(custChoice-1,s);
            for(int k = 0; k < customers.size(); k++)
            {
                if(customers[k] == i_customers[custChoice-1])
                {
                    customers[k].add_Cust_Serving(s);
                }
            }
        }

    }
    else
    {
        Serving s{container,0};
        s.setServerName(i_customers[custNum].get_Name());
        s.setCustomerName(i_customers[custNum].get_Name());
        (*servingPerson).add_serving(custNum,s);
        for(int k = 0; k < customers.size(); k++)
        {
            if(customers[k] == i_customers[custNum])
            {
                customers[k].add_Cust_Serving(s);
            }
        }
    }
}

void Emporium::create_Serving_NoServer(int custNum, Container &c)
{
    Serving s{c,0};
    s.setServerName(customers[custNum].get_Name());
    s.setCustomerName(customers[custNum].get_Name());
    customers[custNum].add_Cust_Serving(s);
}

void Emporium::add_customer(int choice, Customer &c)
{
    customers.push_back(c);
    //Customer origCust = customers[customers.size()-1];
    if(choice == 1)
    {
        Gtk::Dialog *dialog2 = new Gtk::Dialog();
        dialog2->set_title("Create Customer");
        
        Gtk::HBox b_s;
        
        Gtk::Label l_s{"Which server?"};
        l_s.set_width_chars(50);
        b_s.pack_start(l_s, Gtk::PACK_SHRINK);
        
        Gtk::ComboBoxText c_s;
        c_s.set_size_request(160);
        
        //std::vector<Server> servers = emp.get_Servers();
        for(int i = 0; i < servers.size(); i++)
        {
            c_s.append(servers[i].get_Name());
        }
        b_s.pack_start(c_s, Gtk::PACK_SHRINK);
        
        dialog2->get_vbox()->pack_start(b_s, Gtk::PACK_SHRINK);
        dialog2->add_button("Cancel", 0);
        dialog2->add_button("OK", 1);
        dialog2->show_all();
        int s = dialog2->run();
        dialog2->close();
        
        
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        
        if(s == 1)
        {
            servers[c_s.get_active_row_number()].add_customer(customers[customers.size()-1]);
            //emp.add_customerToServer(c_s.get_active_row_number(), origCust);
        }
    }
}

std::vector<Customer> Emporium::get_Customers()
{
    return customers;
}

void Emporium::create_Order_Serv(int servNum)
{
    Order ord{"",0,"",""};
    //orders.push_back(ord);
    //std::cout << "in Emporium " << ord.toString() << std::endl;
    //Order *realOrd = &(orders[orders.size()-1]);
    int custChoice;
    Server *servingPerson = &(servers[servNum]);
    Gtk::Dialog *dialog2 = new Gtk::Dialog();
    dialog2->set_title("Create Order");
    
    Gtk::HBox b_p;
    
    Gtk::Label l_p{"Which person are you making an order for?"};
    l_p.set_width_chars(50);
    b_p.pack_start(l_p, Gtk::PACK_SHRINK);
    
    Gtk::ComboBoxText c_p;
    c_p.set_size_request(160);
    
    c_p.append("Yourself");
    std::vector<Customer> serv_customers = (*servingPerson).get_Customers();
    for(int i = 0; i < serv_customers.size(); i++)
    {
        c_p.append(serv_customers[i].get_Name());
    }
    b_p.pack_start(c_p, Gtk::PACK_SHRINK);
    
    dialog2->get_vbox()->pack_start(b_p, Gtk::PACK_SHRINK);
    dialog2->add_button("Cancel", 0);
    dialog2->add_button("OK", 1);
    dialog2->show_all();
    int cust = dialog2->run();
    dialog2->close();
    
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    
    custChoice = c_p.get_active_row_number();
    
    if(cust == 1 && custChoice == 0)
    {
        //chose yourself
        (*servingPerson).add_my_order(&ord);
        //ord.saveOrder();
        orders.push_back(ord);
    }
    else if(cust == 1 && custChoice > 0)
    {
        //adding to a customer
        //try
        //{
           Customer changeC =(*servingPerson).make_order(custChoice-1,&ord);
        for(int k = 0; k < customers.size(); k++)
        {
            //OPERATOR OVERLOADING
            if(customers[k] == changeC)
            {
                customers[k] = changeC;
            }
        }
        orders.push_back(ord);
        
        
        //}
        //catch(std::exception &e)
        //{
        //    orders.pop_back();
        //    return;
        //}
    }
    else if(cust == 0)
    {
        //orders.pop_back();
    }

}

void Emporium::create_Order_Cust(int servNum, int custNum, int custNumEmp, int found)
{
    Order ord{"",0,"",""};
    if(found == 1)
    {
        Server *servingPerson = &(servers[servNum]);
        Customer changedCustomer = (*servingPerson).make_order(custNum,&ord,true);
        customers[custNumEmp] = changedCustomer;
    }
    else if(found == 0)
    {
        customers[custNumEmp].self_order(&ord);
    }
    orders.push_back(ord);
}

bool Emporium::checkContainerStock(int contType)
{
    if(containers[contType].getStock() <= 0)
    {
        return false;
    }
    return true;
}

bool Emporium::checkFlavorStock(int flavType)
{
    if(flavors[flavType].getStock() <= 0)
    {
        return false;
    }
    return true;
}

bool Emporium::checkToppingStock(int topType)
{
    if(toppings[topType].getStock() <= 0)
    {
        return false;
    }
    return true;
}

void Emporium::saveServingsOrders()
{
    std::ofstream file;
    file.open("servings.txt",std::ofstream::out | std::ofstream::trunc);
    file.close();
    file.open("orders.txt",std::ofstream::out | std::ofstream::trunc);
    file.close();
    for(int i = 0; i < servers.size(); i++)
    {
        std::vector<Serving> serverServings = servers[i].get_server_servings();
        for(int j = 0; j < serverServings.size(); j++)
        {
            serverServings[j].saveServing("servings.txt");
        }
        if((int)servers[i].getServerOrders().getTotalPrice() != -1)
        {
            servers[i].getServerOrders().saveOrder();
        }
    }
    
    for(int i = 0; i < customers.size(); i++)
    {
        std::vector<Serving> customerServings = customers[i].get_Cust_Servings();
        for(int j = 0; j < customerServings.size(); j++)
        {
            customerServings[j].saveServing("servings.txt");
        }
        if((int)customers[i].getCustOrders().getTotalPrice() != -1)
        {
            customers[i].getCustOrders().saveOrder();
        }
    }
}

void Emporium::saveFile()
{
    //save toppings
    std::ofstream file;
    file.open("toppings.txt",std::ofstream::out | std::ofstream::trunc);
    file.close();
    for(int i = 0; i < toppings.size(); i++)
    {
        toppings[i].saveTops();
    }
    
    
    //save scoops
    file.open("scoops.txt",std::ofstream::out | std::ofstream::trunc);
    file.close();
    for(int i = 0; i < flavors.size(); i++)
    {
        flavors[i].saveScoop();
    }
    
    
    //save containers
    file.open("containers.txt",std::ofstream::out | std::ofstream::trunc);
    file.close();
    for(int i = 0; i < containers.size(); i++)
    {
        containers[i].saveContainer();
    }
    
    
    //save servers
    file.open("servers.txt",std::ofstream::out | std::ofstream::trunc);
    file.close();
    for(int i = 0; i < servers.size(); i++)
    {
        servers[i].saveServer();
    }
    
    
    file.open("customers.txt",std::ofstream::out | std::ofstream::trunc);
    file.close();
    for(int i = 0; i < customers.size(); i++)
    {
        customers[i].saveCustomer();
    }
    
    
    //save servings and orders
    saveServingsOrders();
    
    file.open("emporium.txt",std::ofstream::out | std::ofstream::trunc);
    file.close();
    saveEmp();
}

void Emporium::saveEmp()
{
    std::ofstream file;
    file.open("emporium.txt",std::ios::app);
    file << managerName;
    file.close();
}

void Emporium::loadEmp()
{
    std::string line;
    std::ifstream file("emporium.txt");
    if(file.is_open())
    {
        while(getline(file,line))
        {
            managerName = line;
        }
    }
}

void Emporium::loadToppings()
{
    std::vector<std::vector<std::string>> strings;
    std::string line;
    std::ifstream file("toppings.txt");
    int spot = 0;
    int count = 1;
    if(file.is_open())
    {
        while(getline(file,line))
        {
            std::vector<std::string> wholeLine;
            std::istringstream ss(line);
            std::string token;
            
            while(std::getline(ss, token, ','))
            {
                wholeLine.push_back(token);
                //std::cout << token << std::endl;
            }
            strings.push_back(wholeLine);
        }
    }
    
    std::vector<Toppings> newToppings;
    for(int i = 0; i < strings.size(); i++)
    {
        std::string name, description, quantity;
        double wholesaleCost, retailPrice;
        int stockRemaining;
        name = strings[i][0];
        //std::cout << "name: " + name << std::endl;
        description = strings[i][1];
        //std::cout << "desc: " + description << std::endl;
        //wholesaleCost
        std::stringstream ss;
        ss << strings[i][2];
        ss >> wholesaleCost;
        ss.clear();
        //std::cout << "wholesaleCost: " << wholesaleCost << std::endl;
        //retailPrice
        ss << strings[i][3];
        ss >> retailPrice;
        ss.clear();
        //std::cout << "retailPrice: " << retailPrice << std::endl;
        //stockRemaining
        ss << strings[i][4];
        ss >> stockRemaining;
        quantity = strings[i][5];
        //std::cout << "stockRemaining: " << stockRemaining << std::endl;
        
        //wholesaleCost
        
        
        //std::cout << std::endl;
        
        Toppings t{name, description, wholesaleCost, retailPrice, stockRemaining};
        newToppings.push_back(t);
    }
    toppings = newToppings;
}

void Emporium::loadScoops()
{
    std::vector<std::vector<std::string>> strings;
    std::string line;
    std::ifstream file("scoops.txt");
    int spot = 0;
    int count = 1;
    if(file.is_open())
    {
        while(getline(file,line))
        {
            std::vector<std::string> wholeLine;
            std::istringstream ss(line);
            std::string token;
            
            while(std::getline(ss, token, ','))
            {
                wholeLine.push_back(token);
                //std::cout << token << std::endl;
            }
            strings.push_back(wholeLine);
        }
    }
    
    std::vector<Scoop> newScoops;
    for(int i = 0; i < strings.size(); i++)
    {
        std::string name, description;
        double wholesaleCost, retailPrice;
        int stockRemaining;
        name = strings[i][0];
        //std::cout << "name: " + name << std::endl;
        description = strings[i][1];
        //std::cout << "desc: " + description << std::endl;
        //wholesaleCost
        std::stringstream ss;
        ss << strings[i][2];
        ss >> wholesaleCost;
        ss.clear();
        //std::cout << "wholesaleCost: " << wholesaleCost << std::endl;
        //retailPrice
        ss << strings[i][3];
        ss >> retailPrice;
        ss.clear();
        //std::cout << "retailPrice: " << retailPrice << std::endl;
        //stockRemaining
        ss << strings[i][4];
        ss >> stockRemaining;
        //std::cout << "stockRemaining: " << stockRemaining << std::endl;
        
        //std::cout << std::endl;
        
        Scoop s{name, description, wholesaleCost, retailPrice, stockRemaining};
        newScoops.push_back(s);
    }
    flavors = newScoops;
}

void Emporium::loadContainers()
{
    std::vector<std::vector<std::string>> strings;
    std::string line;
    std::ifstream file("containers.txt");
    int spot = 0;
    int count = 1;
    if(file.is_open())
    {
        while(getline(file,line))
        {
            std::vector<std::string> wholeLine;
            std::istringstream ss(line);
            std::string token;
            
            while(std::getline(ss, token, ','))
            {
                wholeLine.push_back(token);
                //std::cout << token << std::endl;
            }
            strings.push_back(wholeLine);
        }
    }
    
    std::vector<Container> newContainers;
    for(int i = 0; i < strings.size(); i++)
    {
        std::string name, description;
        double wholesaleCost, retailPrice;
        int stockRemaining, maxScoops;
        name = strings[i][0];
        description = strings[i][1];
        //wholesaleCost
        std::stringstream ss;
        ss << strings[i][2];
        ss >> wholesaleCost;
        ss.clear();
        //retailPrice
        ss << strings[i][3];
        ss >> retailPrice;
        ss.clear();
        //stockRemaining
        ss << strings[i][4];
        ss >> stockRemaining;
        ss.clear();
        //maxScoops
        ss << strings[i][5];
        ss >> maxScoops;
        ss.clear();
        
        Container c{name, description, wholesaleCost, retailPrice, stockRemaining, maxScoops};
        newContainers.push_back(c);
    }
    containers = newContainers;
}

void Emporium::loadCustomers()
{
    std::vector<Customer> newCusts;
    
    std::string line;
    std::ifstream file("customers.txt");
    if(file.is_open())
    {
        while(getline(file,line))
        {
            std::vector<std::string> custInfo;
            std::string name;
            std::string phoneNumber;
            
            std::istringstream ss(line);
            std::string token;
            
            while(std::getline(ss, token, ','))
            {
                custInfo.push_back(token);
            }
            name = custInfo[0];
            phoneNumber = custInfo[1];
            Order o{"",-1,"",""};
            Customer c{name,phoneNumber,o};
            newCusts.push_back(c);
        }
    }
    customers = newCusts;
}

void Emporium::loadServers()
{
    std::vector<Server> newServers;
    
    std::string line;
    std::ifstream file("servers.txt");
    if(file.is_open())
    {
        while(getline(file,line))
        {
            std::vector<std::string> serverInfo;
            std::string name;
            std::string employeeID;
            int numOrders;
            double salary;
            //std::vector<std::string> wholeLine;
            std::istringstream ss(line);
            std::string token;
            
            while(std::getline(ss, token, ','))
            {
                serverInfo.push_back(token);
            }
            name = serverInfo[0];
            employeeID = serverInfo[1];
            
            //numOrder
            std::stringstream conv;
            conv << serverInfo[2];
            conv >> numOrders;
            conv.clear();
            
            //salary
            conv << serverInfo[3];
            conv >> salary;
            conv.clear();
            
            //go to next line for customers
            getline(file,line);
            std::istringstream ss2(line);
            std::string token2;
            
            Order o{"",-1,"",""};
            Server s{name,employeeID,numOrders,salary,o};
            
            std::vector<std::string> custNames;
            while(std::getline(ss2, token2, ','))
            {
                custNames.push_back(token2);
            }
            
            if(custNames[0] != " ")
            {
                for(int i = 0; i < custNames.size(); i++)
                {
                    for(int j = 0; j < customers.size(); j++)
                    {
                        if(custNames[i] == customers[j].get_Name())
                        {
                            Customer c{customers[j].get_Name(),customers[j].getPhoneNumber(),o};
                            s.add_customer(c);
                            break;
                        }
                    }
                }
            }
            newServers.push_back(s);
        }
    }
    servers = newServers;

}

Scoop Emporium::findScoop(std::string flavor)
{
    for(int i = 0; i < flavors.size(); i++)
    {
        if(flavor == flavors[i].get_Name())
        {
            return flavors[i];
        }
    }
}

Toppings Emporium::findToppings(std::string tops)
{
    for(int i = 0; i < toppings.size(); i++)
    {
        if(tops == toppings[i].get_Name())
        {
            return toppings[i];
        }
    }
}

Container Emporium::findContainer(std::string containerType)
{
    for(int i = 0; i < containers.size(); i++)
    {
        if(containerType == containers[i].get_Name())
        {
            return containers[i];
        }
    }
}

void Emporium::loadServing()
{
    std::string line;
    std::ifstream file("servings.txt");
    if(file.is_open())
    {
        while(getline(file,line))
        {
            std::istringstream ss(line);
            std::string token;
            
            std::vector<std::string> names;
            std::string custName;
            std::string servName;
            double icPrice, wholesale;
            while(std::getline(ss, token, ','))
            {
                names.push_back(token);
            }
            custName = names[0];
            servName = names[1];
            
            //std::cout << custName + "," + servName << std::endl;
            
            //get icPrice
            getline(file,line);
            std::stringstream str;
            //may be a problem here
            str << line;
            str >> icPrice;
            str.clear();
            
            
            //std::cout << icPrice << std::endl;
            
            //get container type
            getline(file,line);
            std::string containerType = line;
            
            //std::cout << containerType << std::endl;
            
            //number of scoops
            getline(file,line);
            int numScoops;
            str << line;
            str >> numScoops;
            str.clear();
            
            //std::cout << numScoops << std::endl;
            
            //scoop specifications
            std::vector<std::vector<std::string>> scoopInfo;
            for(int i = 0; i < numScoops; i++)
            {
                getline(file,line);
                std::istringstream ss2(line);
                std::vector<std::string> strings;
                while(std::getline(ss2, token, ','))
                {
                    strings.push_back(token);
                }
                scoopInfo.push_back(strings);
            }
            
            /*
            for(int i = 0; i < scoopInfo.size(); i++)
            {
                for(int j = 0; j < scoopInfo[i].size(); j++)
                {
                    std::cout << scoopInfo[i][j] + ",";
                }
                std::cout << std::endl;
            }
             */
            
            
            //set flavor and add toppings to each scoop
            Container c = findContainer(containerType);
            for(int i = 0; i < numScoops; i++)
            {
                //set flavor for scoop i
                std::string flavor = scoopInfo[i][0];
                Scoop sc = findScoop(flavor);
                if(scoopInfo[i][1] != " ")
                {
                    for(int j = 1; j < scoopInfo[i].size(); j++)
                    {
                        //add topping j for scoop i
                        Toppings t = findToppings(scoopInfo[i][j]);
                        sc.add_toppings(t);
                    }
                }
                c.add_scoop(sc);
            }
            Serving serv{c,icPrice};
            //std::cout << icPrice << std::endl;
            serv.setServerName(servName);
            serv.setCustomerName(custName);
            
            
            //add the serving to the customer
            Order o{"",-1,"",""};
            Customer cust{"","",o};
            for(int i = 0; i < customers.size(); i++)
            {
                if(customers[i].get_Name() == custName)
                {
                    customers[i].add_Cust_Serving(serv);
                    cust = customers[i];
                    break;
                }
            }
            
            //add serving to server (if server made their own order)
            if(servName == custName)
            {
                for(int i = 0; i < servers.size(); i++)
                {
                    if(servers[i].get_Name() == servName)
                    {
                        servers[i].add_my_serving(serv);
                        break;
                    }
                }
            }
            
            //check if customer exists within server already
            int addCust = 1;
            for(int i = 0; i < servers.size(); i++)
            {
                if(servers[i].get_Name() == servName)
                {
                    std::vector<Customer> checkCust = servers[i].get_Customers();
                    for(int j = 0; j < checkCust.size(); j++)
                    {
                        if(checkCust[j].get_Name() == cust.get_Name())
                        {
                            addCust = 0;
                            servers[i].replaceCustomer(cust,j);
                            break;
                        }
                    }
                    break;
                }
            }
            
            //add customer to server
            if(custName != servName && addCust == 1)
            {
                for(int i = 0; i < servers.size(); i++)
                {
                    if(servers[i].get_Name() == servName)
                    {
                        servers[i].add_customer(cust);
                        break;
                    }
                }
            }
        }
    }
}

void Emporium::putOrderin(Order ord, std::string custName, std::string servName)
{
    if(custName == servName)
    {
        for(int i = 0; i < servers.size(); i++)
        {
            if(servers[i].get_Name() == servName)
            {
                servers[i].set_Order(ord);
                break;
            }
        }
        
        for(int i = 0; i < customers.size(); i++)
        {
            if(customers[i].get_Name() == custName)
            {
                customers[i].make_order(ord);
            }
        }
    }
    else
    {
        for(int i = 0; i < customers.size(); i++)
        {
            if(customers[i].get_Name() == custName)
            {
                customers[i].make_order(ord);
                break;
            }
        }
        
        for(int i = 0; i < servers.size(); i++)
        {
            if(servers[i].get_Name() == servName)
            {
                std::vector<Customer> servCusts = servers[i].get_Customers();
                for(int j = 0; j < servCusts.size(); j++)
                {
                    if(servCusts[j].get_Name() == custName)
                    {
                        Customer c = servCusts[j];
                        c.make_order(ord);
                        servers[i].replaceCustomer(c, j);
                        break;
                    }
                }
                break;
            }
        }
    }
}

void Emporium::loadOrder()
{
    std::string line;
    std::ifstream file("orders.txt");
    if(file.is_open())
    {
        while(getline(file,line))
        {
            std::istringstream ss2(line);
            std::string token2;
            std::vector<std::string> orderInfo;
            int numOfServings;
            std::string orderID;
            double totalPrice;
            while(std::getline(ss2, token2, ','))
            {
                orderInfo.push_back(token2);
            }
            std::string ordCustName = orderInfo[0];
            std::string ordServName = orderInfo[1];
            
            //number of servings
            std::stringstream str;
            str << orderInfo[2];
            str >> numOfServings;
            str.clear();
            
            //orderId
            orderID = orderInfo[3];
            
            //totalPrice
            str << orderInfo[4];
            str >> totalPrice;
            str.clear();
            
            Order ord{orderID,totalPrice,ordCustName,ordServName};
            
            int k = 0;
            while(k < numOfServings && getline(file,line))
            {
                std::istringstream ss(line);
                std::string token;
                
                std::vector<std::string> names;
                std::string custName;
                std::string servName;
                double icPrice;
                while(std::getline(ss, token, ','))
                {
                    names.push_back(token);
                }
                custName = names[0];
                servName = names[1];
                
                //std::cout << custName + "," + servName << std::endl;
                
                //get icPrice
                getline(file,line);
                std::stringstream str;
                //may be a problem here
                str << line;
                str >> icPrice;
                str.clear();
                
                //std::cout << icPrice << std::endl;
                
                //get container type
                getline(file,line);
                std::string containerType = line;
                
                //std::cout << containerType << std::endl;
                
                //number of scoops
                getline(file,line);
                int numScoops;
                str << line;
                str >> numScoops;
                str.clear();
                
                //std::cout << numScoops << std::endl;
                
                //scoop specifications
                std::vector<std::vector<std::string>> scoopInfo;
                for(int i = 0; i < numScoops; i++)
                {
                    getline(file,line);
                    std::istringstream ss2(line);
                    std::vector<std::string> strings;
                    while(std::getline(ss2, token, ','))
                    {
                        strings.push_back(token);
                    }
                    scoopInfo.push_back(strings);
                }
                
                //set flavor and add toppings to each scoop
                Container c = findContainer(containerType);
                for(int i = 0; i < numScoops; i++)
                {
                    //set flavor for scoop i
                    std::string flavor = scoopInfo[i][0];
                    Scoop sc = findScoop(flavor);
                    if(scoopInfo[i][1] != " ")
                    {
                        for(int j = 1; j < scoopInfo[i].size(); j++)
                        {
                            //add topping j for scoop i
                            Toppings t = findToppings(scoopInfo[i][j]);
                            sc.add_toppings(t);
                        }
                    }
                    c.add_scoop(sc);
                }
                Serving serv{c,icPrice};
                //std::cout << icPrice << std::endl;
                serv.setServerName(servName);
                serv.setCustomerName(custName);
                ord.add_serving(serv);
                k++;
            }
            ord.calcOrderWholesale();
            orders.push_back(ord);
            putOrderin(ord, ordCustName, ordServName);
        }
    }
}

void Emporium::loadFile()
{
    //load for toppings
    loadToppings();
    //load for scoops
    loadScoops();
    //load for containers
    loadContainers();
    //load for customers
    loadCustomers();
    //load for servers
    loadServers();
    //load servings
    loadServing();
    //load orders
    loadOrder();
    //load manager
    loadEmp();
}

void Emporium::restockFlavors(int spot)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Restock Flavor");
    
    // Title
    Gtk::HBox b_title;
    
    Gtk::Label l_title{"How much more:"};
    l_title.set_width_chars(20);
    b_title.pack_start(l_title, Gtk::PACK_SHRINK);
    
    Gtk::Entry e_title;
    e_title.set_max_length(50);
    b_title.pack_start(e_title, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_title, Gtk::PACK_SHRINK);
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    
    std::string snum = e_title.get_text();
    int num;
    
    std::stringstream ss;
    ss << snum;
    ss >> num;
    
    if (result == 1)
    {
        flavors[spot].increaseStock(num);
    }
}

void Emporium::restockContainers(int spot)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Restock Container");
    
    // Title
    Gtk::HBox b_title;
    
    Gtk::Label l_title{"How much more:"};
    l_title.set_width_chars(20);
    b_title.pack_start(l_title, Gtk::PACK_SHRINK);
    
    Gtk::Entry e_title;
    e_title.set_max_length(50);
    b_title.pack_start(e_title, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_title, Gtk::PACK_SHRINK);
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    
    std::string snum = e_title.get_text();
    int num;
    
    std::stringstream ss;
    ss << snum;
    ss >> num;
    
    if (result == 1)
    {
        containers[spot].increaseStock(num);
    }
}

void Emporium::restockToppings(int spot)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Restock Topping");
    
    // Title
    Gtk::HBox b_title;
    
    Gtk::Label l_title{"How much more:"};
    l_title.set_width_chars(20);
    b_title.pack_start(l_title, Gtk::PACK_SHRINK);
    
    Gtk::Entry e_title;
    e_title.set_max_length(50);
    b_title.pack_start(e_title, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_title, Gtk::PACK_SHRINK);
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    
    std::string snum = e_title.get_text();
    int num;
    
    std::stringstream ss;
    ss << snum;
    ss >> num;
    
    if (result == 1)
    {
        toppings[spot].increaseStock(num);
    }
}

void Emporium::calcTotalWholesale()
{
    double p = 0;
    for(int i = 0; i < orders.size(); i++)
    {
        p += orders[i].getOrderWholesaleP();
    }
    totalWholesale = p;
}

void Emporium::calcTotalRetail()
{
    double p = 0;
    for(int i = 0; i < orders.size(); i++)
    {
        p += orders[i].getTotalPrice();
    }
    totalSaleOfGoods = p;
}

void Emporium::calcProfit()
{
    netProfit = totalSaleOfGoods - totalWholesale;
}

double Emporium::getProfit()
{
    return netProfit;
}

void Emporium::setManagerName()
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Create named Manager");
    
    // Title
    Gtk::HBox b_title;
    
    Gtk::Label l_title{"Enter name:"};
    l_title.set_width_chars(20);
    b_title.pack_start(l_title, Gtk::PACK_SHRINK);
    
    Gtk::Entry e_title;
    e_title.set_max_length(50);
    b_title.pack_start(e_title, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_title, Gtk::PACK_SHRINK);
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    
    std::string snum = e_title.get_text();
    
    if(result == 1)
    {
        managerName = snum;
    }
}

void Emporium::changeServerSalary(int servNum, double newSalary)
{
    servers[servNum].setSalary(newSalary);
}

void Emporium::editFlavor(Scoop s, int spot)
{
    flavors[spot] = s;
}

void Emporium::editContainer(Container c, int spot)
{
    containers[spot] = c;
}

void Emporium::editTopping(Toppings t, int spot)
{
    toppings[spot] = t;
}





