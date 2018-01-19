#include "controller_gui.h"
#include "dialogs.h"
#include "scoop.h"
#include "container.h"
#include <vector>
#include <string>
#include <regex>

void Controller_Gui::manager_cmd(int cmd)
{
    //while(cmd != 0)
    //{
        //view.show_manager_menu();
        //std::cout << "What would you like to do? ";
        //std::vector<std::string> buttons = {"Create a new flavor", "List current flavors","Create a new container","List current containers","Create new topping","List current toppings","Exit"};
        //cmd = Dialogs::question("What would you like to do?", "Manager",buttons);
        
        //std::cout << cmd << std::endl;
        //cmd++;
        
        //std::cin >> cmd;
        //std::cin.ignore(); // consume \n
        if(cmd == 1)
        {
            //create a new flavor
            std::string flav;
            std::string desc;
            double wholesaleCost;
            double retailPrice;
            std::string stockr;
            int stockRemaining;
            //std::cout << "Enter the name of the flavor to be added: " << std::endl;
            //std::getline(std::cin,flav);
            //std::cin.ignore();
            //flav = Dialogs::input("Enter the name of the flavor to be added: ");
            Gtk::Dialog *dialog = new Gtk::Dialog();
            dialog->set_title("Create new flavor");
            
            // flavor
            Gtk::HBox b_flavor;
            
            Gtk::Label l_flavor{"Flavor: "};
            l_flavor.set_width_chars(20);
            b_flavor.pack_start(l_flavor, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_flavor;
            e_flavor.set_max_length(50);
            b_flavor.pack_start(e_flavor, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_flavor, Gtk::PACK_SHRINK);
            
            // Description
            Gtk::HBox b_desc;
            
            Gtk::Label l_desc{"Description: "};
            l_desc.set_width_chars(20);
            b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_desc;
            e_desc.set_max_length(50);
            b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
            
            // Copyright date
            Gtk::HBox b_wholesaleCost;
            
            Gtk::Label l_wholesaleCost{"Wholesale Cost: "};
            l_wholesaleCost.set_width_chars(20);
            b_wholesaleCost.pack_start(l_wholesaleCost, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_wholesaleCost;
            e_wholesaleCost.set_max_length(50);
            b_wholesaleCost.pack_start(e_wholesaleCost, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_wholesaleCost, Gtk::PACK_SHRINK);
            
            Gtk::HBox b_retailCost;
            
            Gtk::Label l_retailCost{"Retail Cost: "};
            l_retailCost.set_width_chars(20);
            b_retailCost.pack_start(l_retailCost, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_retailCost;
            e_retailCost.set_max_length(50);
            b_retailCost.pack_start(e_retailCost, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_retailCost, Gtk::PACK_SHRINK);
            
            Gtk::HBox b_stock;
            
            Gtk::Label l_stock{"Stock remaining: "};
            l_stock.set_width_chars(20);
            b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_stock;
            e_stock.set_max_length(50);
            b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);
            
            
            //stockRemaining = (int)std::stoi(stockr);
            
            dialog->add_button("Cancel", 0);
            dialog->add_button("OK", 1);
            dialog->show_all();
            int result = dialog->run();

            
            dialog->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            
            //REGEX
            regex integer{"(\\+|-)?[[:digit:]]+"};
            if(!(regex_match(e_stock.get_text().c_str(),integer)))
            {
                Dialogs::message("Invalid input","Error");
                return;
            }

            flav = e_flavor.get_text();
            desc = e_desc.get_text();
            wholesaleCost = atof(e_wholesaleCost.get_text().c_str());
            retailPrice = atof(e_retailCost.get_text().c_str());
            stockRemaining = atoi(e_stock.get_text().c_str());
            
            if(result == 1)
            {
                Scoop s{flav, desc, wholesaleCost, retailPrice, stockRemaining};
                emp.create_flavor(s);
            }

        }
        else if(cmd == 2)
        {
            //list current flavors;
            view.list_flavors();
        }
        else if(cmd == 3)
        {
            //create a new container
            //std::string container;
            //std::cout << "Enter the name of the container to be added: " << std::endl;
            //std::getline(std::cin,container);
            //container = Dialogs::input("Enter the name of the container to be added: ");
            /*if(container != "CANCEL")
            {
                emp.create_container(container);
            }*/
           
            //create a new container
            std::string cont;
            std::string desc;
            double wholesaleCost;
            double retailPrice;
            std::string stockr;
            int stockRemaining;
            int maxscoops;
            //std::cout << "Enter the name of the flavor to be added: " << std::endl;
            //std::getline(std::cin,flav);
            //std::cin.ignore();
            //flav = Dialogs::input("Enter the name of the flavor to be added: ");
            Gtk::Dialog *dialog = new Gtk::Dialog();
            dialog->set_title("Create new container");
            
            // CONTAINER
            Gtk::HBox b_container;
            
            Gtk::Label l_container{"Container: "};
            l_container.set_width_chars(20);
            b_container.pack_start(l_container, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_container;
            e_container.set_max_length(50);
            b_container.pack_start(e_container, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
                
            // Description
            Gtk::HBox b_desc;
            
            Gtk::Label l_desc{"Description: "};
            l_desc.set_width_chars(20);
            b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_desc;
            e_desc.set_max_length(50);
            b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
            
            // whole sale
            Gtk::HBox b_wholesaleCost;
            
            Gtk::Label l_wholesaleCost{"Wholesale Cost: "};
            l_wholesaleCost.set_width_chars(20);
            b_wholesaleCost.pack_start(l_wholesaleCost, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_wholesaleCost;
            e_wholesaleCost.set_max_length(50);
            b_wholesaleCost.pack_start(e_wholesaleCost, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_wholesaleCost, Gtk::PACK_SHRINK);
            
            Gtk::HBox b_retailCost;
            
            Gtk::Label l_retailCost{"Retail Cost: "};
            l_retailCost.set_width_chars(20);
            b_retailCost.pack_start(l_retailCost, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_retailCost;
            e_retailCost.set_max_length(50);
            b_retailCost.pack_start(e_retailCost, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_retailCost, Gtk::PACK_SHRINK);
        
            Gtk::HBox b_stock;
            
            Gtk::Label l_stock{"Stock remaining: "};
            l_stock.set_width_chars(20);
            b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_stock;
            e_stock.set_max_length(50);
            b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);
            
            Gtk::HBox b_max;
            
            Gtk::Label l_max{"Max # of scoops: "};
            l_max.set_width_chars(20);
            b_max.pack_start(l_max, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_max;
            e_max.set_max_length(50);
            b_max.pack_start(e_max, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_max, Gtk::PACK_SHRINK);
            
            //stockRemaining = (int)std::stoi(stockr);
            
            dialog->add_button("Cancel", 0);
            dialog->add_button("OK", 1);
            dialog->show_all();
            int result = dialog->run();
            
            
            dialog->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            
            cont = e_container.get_text();
            desc = e_desc.get_text();
            wholesaleCost = atof(e_wholesaleCost.get_text().c_str());
            retailPrice = atof(e_retailCost.get_text().c_str());
            stockRemaining = atoi(e_stock.get_text().c_str());
            maxscoops = atoi(e_max.get_text().c_str());
                        
            if(result == 1)
            {
                Container c{cont, desc, wholesaleCost, retailPrice, stockRemaining, maxscoops};
                emp.create_container(c);
            }
        }
        else if(cmd == 4)
        {
            //list current containers
            view.list_containers();
        }
        else if(cmd == 5)
        {
            //create new topping
            //std::string top;
            //std::cout << "Enter the name of the topping to be added: " << std::endl;
            //std::getline(std::cin,top);
            //top = Dialogs::input("Enter the name of the topping to be added: ");
            /*if(top != "CANCEL")
            {
                emp.create_topping(top);
            }*/
            std::string top;
            std::string desc;
            double wholesaleCost;
            double retailPrice;
            std::string stockr;
            int stockRemaining;
            //std::cout << "Enter the name of the flavor to be added: " << std::endl;
            //std::getline(std::cin,flav);
            //std::cin.ignore();
            //flav = Dialogs::input("Enter the name of the flavor to be added: ");
            Gtk::Dialog *dialog = new Gtk::Dialog();
            dialog->set_title("Create new topping");
            
            // CONTAINER
            Gtk::HBox b_top;
            
            Gtk::Label l_top{"Topping: "};
            l_top.set_width_chars(20);
            b_top.pack_start(l_top, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_top;
            e_top.set_max_length(50);
            b_top.pack_start(e_top, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_top, Gtk::PACK_SHRINK);
            
            // Description
            Gtk::HBox b_desc;
            
            Gtk::Label l_desc{"Description: "};
            l_desc.set_width_chars(20);
            b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_desc;
            e_desc.set_max_length(50);
            b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
            
            // wholesalr 
            Gtk::HBox b_wholesaleCost;
            
            Gtk::Label l_wholesaleCost{"Wholesale Cost: "};
            l_wholesaleCost.set_width_chars(20);
            b_wholesaleCost.pack_start(l_wholesaleCost, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_wholesaleCost;
            e_wholesaleCost.set_max_length(50);
            b_wholesaleCost.pack_start(e_wholesaleCost, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_wholesaleCost, Gtk::PACK_SHRINK);
            
            Gtk::HBox b_retailCost;
            
            Gtk::Label l_retailCost{"Retail Cost: "};
            l_retailCost.set_width_chars(20);
            b_retailCost.pack_start(l_retailCost, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_retailCost;
            e_retailCost.set_max_length(50);
            b_retailCost.pack_start(e_retailCost, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_retailCost, Gtk::PACK_SHRINK);
            
            Gtk::HBox b_stock;
            
            Gtk::Label l_stock{"Stock remaining: "};
            l_stock.set_width_chars(20);
            b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_stock;
            e_stock.set_max_length(50);
            b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);
            
            //stockRemaining = (int)std::stoi(stockr);
            
            dialog->add_button("Cancel", 0);
            dialog->add_button("OK", 1);
            dialog->show_all();
            int result = dialog->run();
            
            
            dialog->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            
            top = e_top.get_text();
            desc = e_desc.get_text();
            wholesaleCost = atof(e_wholesaleCost.get_text().c_str());
            retailPrice = atof(e_retailCost.get_text().c_str());
            stockRemaining = atoi(e_stock.get_text().c_str());
            
            if(result == 1)
            {
                Toppings t{top,desc,wholesaleCost,retailPrice,stockRemaining};
                emp.create_topping(t);
            }

        }
        else if(cmd == 6)
        {
            //list current toppings
            view.list_toppings();
        }
        else if(cmd == 7)
        {
            //create a new server
            std::string name;
            std::string ID;
            int numOrders;
            double salary;
            
            Gtk::Dialog *dialog = new Gtk::Dialog();
            dialog->set_title("Create a new server");
            
            // name
            Gtk::HBox b_container;
            
            Gtk::Label l_container{"Name: "};
            l_container.set_width_chars(20);
            b_container.pack_start(l_container, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_container;
            e_container.set_max_length(50);
            b_container.pack_start(e_container, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
            
            // ID
            Gtk::HBox b_desc;
            
            Gtk::Label l_desc{"ID: "};
            l_desc.set_width_chars(20);
            b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_desc;
            e_desc.set_max_length(50);
            b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
            
            // salary
            Gtk::HBox b_wholesaleCost;
            
            Gtk::Label l_wholesaleCost{"Salary: "};
            l_wholesaleCost.set_width_chars(20);
            b_wholesaleCost.pack_start(l_wholesaleCost, Gtk::PACK_SHRINK);
            
            Gtk::Entry e_wholesaleCost;
            e_wholesaleCost.set_max_length(50);
            b_wholesaleCost.pack_start(e_wholesaleCost, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_wholesaleCost, Gtk::PACK_SHRINK);
            
            dialog->add_button("Cancel", 0);
            dialog->add_button("OK", 1);
            dialog->show_all();
            int result = dialog->run();
            
            
            dialog->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            
            name = e_container.get_text();
            ID = e_desc.get_text();
            salary = atof(e_wholesaleCost.get_text().c_str());
            
            if(result == 1)
            {
                //std::vector<Customer*> c;
                //std::vector<Order*> m;
                Order ord{"", -1, "", ""};
                Server serv{name, ID, -1, salary, ord};
                emp.create_server(serv);
            }
        }
        else if(cmd == 8)
        {
            //list servers
            view.list_servers();
        }
        else if(cmd == 9)
        {
            view.list_customers();
        }
        else if(cmd == 10)
        {
            view.list_orders();
        }
        else if(cmd == 11)
        {
            view.show_register();
        }
        else if(cmd == 12)
        {
            Gtk::Dialog *dialog = new Gtk::Dialog();
            dialog->set_title("Restock");
            
            Gtk::HBox b_media;
            
            Gtk::Label l_media{"Choose Item:"};
            l_media.set_width_chars(15);
            b_media.pack_start(l_media, Gtk::PACK_SHRINK);
            
            Gtk::ComboBoxText c_media;
            c_media.set_size_request(160);
            c_media.append("Flavor");
            c_media.append("Container");
            c_media.append("Toppings");
            b_media.pack_start(c_media, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_media, Gtk::PACK_SHRINK);
            
            dialog->add_button("Cancel", 0);
            dialog->add_button("OK", 1);
            dialog->show_all();
            int result = dialog->run();
            
            dialog->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            
            int item = c_media.get_active_row_number();
            
            if (result == 1)
            {
                if(item == 0)
                {
                    //stock the flavor
                    Gtk::Dialog *dialog = new Gtk::Dialog();
                    dialog->set_title("Restock");
                    
                    Gtk::HBox b_media;
                    
                    Gtk::Label l_media{"Choose Flavor:"};
                    l_media.set_width_chars(20);
                    b_media.pack_start(l_media, Gtk::PACK_SHRINK);
                    
                    Gtk::ComboBoxText c_media;
                    c_media.set_size_request(160);
                    
                    std::vector<Scoop> flavors = emp.get_Scoops();
                    for(int i = 0; i < flavors.size(); i++)
                    {
                        c_media.append(flavors[i].get_Name());
                    }
                    
                    b_media.pack_start(c_media, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_media, Gtk::PACK_SHRINK);
                    
                    dialog->add_button("Cancel", 0);
                    dialog->add_button("OK", 1);
                    dialog->show_all();
                    int result = dialog->run();
                    
                    dialog->close();
                    
                    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                    
                    int flavor = c_media.get_active_row_number();
                    
                    if(result == 1)
                    {
                        emp.restockFlavors(flavor);
                    }

                }
                else if(item == 1)
                {
                    //stock the containers
                    Gtk::Dialog *dialog = new Gtk::Dialog();
                    dialog->set_title("Restock");
                    
                    Gtk::HBox b_media;
                    
                    Gtk::Label l_media{"Choose Container:"};
                    l_media.set_width_chars(20);
                    b_media.pack_start(l_media, Gtk::PACK_SHRINK);
                    
                    Gtk::ComboBoxText c_media;
                    c_media.set_size_request(160);
                    
                    std::vector<Container> containers = emp.get_Containers();
                    for(int i = 0; i < containers.size(); i++)
                    {
                        c_media.append(containers[i].get_Name());
                    }
                    
                    b_media.pack_start(c_media, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_media, Gtk::PACK_SHRINK);
                    
                    dialog->add_button("Cancel", 0);
                    dialog->add_button("OK", 1);
                    dialog->show_all();
                    int result = dialog->run();
                    
                    dialog->close();
                    
                    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                    
                    int cont = c_media.get_active_row_number();
                    
                    if(result == 1)
                    {
                        emp.restockContainers(cont);
                    }

                }
                else if(item == 2)
                {
                    //stock the containers
                    Gtk::Dialog *dialog = new Gtk::Dialog();
                    dialog->set_title("Restock");
                    
                    Gtk::HBox b_media;
                    
                    Gtk::Label l_media{"Choose Topping:"};
                    l_media.set_width_chars(20);
                    b_media.pack_start(l_media, Gtk::PACK_SHRINK);
                    
                    Gtk::ComboBoxText c_media;
                    c_media.set_size_request(160);
                    
                    std::vector<Toppings> tops = emp.get_Toppings();
                    for(int i = 0; i < tops.size(); i++)
                    {
                        c_media.append(tops[i].get_Name());
                    }
                    
                    b_media.pack_start(c_media, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_media, Gtk::PACK_SHRINK);
                    
                    dialog->add_button("Cancel", 0);
                    dialog->add_button("OK", 1);
                    dialog->show_all();
                    int result = dialog->run();
                    
                    dialog->close();
                    
                    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                    
                    int top = c_media.get_active_row_number();
                    
                    if(result == 1)
                    {
                        emp.restockToppings(top);
                    }

                }
            }
        }
        else if(cmd == 13)
        {
            //make order
            Gtk::Dialog *dialog2 = new Gtk::Dialog();
            dialog2->set_title("Change Server Salary");
            
            Gtk::HBox b_s;
            
            Gtk::Label l_s{"Which server?"};
            l_s.set_width_chars(50);
            b_s.pack_start(l_s, Gtk::PACK_SHRINK);
            
            Gtk::ComboBoxText c_s;
            c_s.set_size_request(160);
            
            std::vector<Server> servers = emp.get_Servers();
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
            int servNum = c_s.get_active_row_number();
            
            if(s == 1)
            {
                double salary;
                //create a new server
                Gtk::Dialog *dialog = new Gtk::Dialog();
                dialog->set_title("Change Salary");
                
                // salary
                Gtk::HBox b_wholesaleCost;
                
                Gtk::Label l_wholesaleCost{"Enter new salary: "};
                l_wholesaleCost.set_width_chars(30);
                b_wholesaleCost.pack_start(l_wholesaleCost, Gtk::PACK_SHRINK);
                
                Gtk::Entry e_wholesaleCost;
                e_wholesaleCost.set_max_length(50);
                b_wholesaleCost.pack_start(e_wholesaleCost, Gtk::PACK_SHRINK);
                dialog->get_vbox()->pack_start(b_wholesaleCost, Gtk::PACK_SHRINK);
                
                dialog->add_button("Cancel", 0);
                dialog->add_button("OK", 1);
                dialog->show_all();
                int result = dialog->run();
                
                
                dialog->close();
                while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                
                salary = atof(e_wholesaleCost.get_text().c_str());
                
                if(result == 1)
                {
                    emp.changeServerSalary(servNum,salary);
                }
            }

        }
        else if(cmd == 14)
        {
            Gtk::Dialog *dialog2 = new Gtk::Dialog();
            dialog2->set_title("Edit Items");
            
            Gtk::HBox b_s;
            
            Gtk::Label l_s{"Which item?"};
            l_s.set_width_chars(50);
            b_s.pack_start(l_s, Gtk::PACK_SHRINK);
            
            Gtk::ComboBoxText c_s;
            c_s.set_size_request(160);
            
            
            c_s.append("Ice cream flavors");
            c_s.append("Containers");
            c_s.append("Toppings");
            
            b_s.pack_start(c_s, Gtk::PACK_SHRINK);
            
            dialog2->get_vbox()->pack_start(b_s, Gtk::PACK_SHRINK);
            dialog2->add_button("Cancel", 0);
            dialog2->add_button("OK", 1);
            dialog2->show_all();
            int d = dialog2->run();
            dialog2->close();
            
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            int s = c_s.get_active_row_number();
            
            if(s == 0 && d == 1)
            {
                //editing ice cream flavors
                Gtk::Dialog *dialog2 = new Gtk::Dialog();
                dialog2->set_title("Edit Items");
                
                Gtk::HBox b_s;
                
                Gtk::Label l_s{"Which flavor?"};
                l_s.set_width_chars(50);
                b_s.pack_start(l_s, Gtk::PACK_SHRINK);
                
                Gtk::ComboBoxText c_s;
                c_s.set_size_request(160);
                
                std::vector<Scoop> flavs = emp.get_Scoops();
                for(int i = 0; i < flavs.size(); i++)
                {
                    c_s.append(flavs[i].get_Name());
                }
                
                b_s.pack_start(c_s, Gtk::PACK_SHRINK);
                
                dialog2->get_vbox()->pack_start(b_s, Gtk::PACK_SHRINK);
                dialog2->add_button("Cancel", 0);
                dialog2->add_button("OK", 1);
                dialog2->show_all();
                int dd = dialog2->run();
                dialog2->close();
                
                while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                int c = c_s.get_active_row_number();
                
                if(dd == 1)
                {
                    Scoop orig = flavs[c];
                    std::string flav;
                    std::string desc;
                    double wholesaleCost;
                    double retailPrice;
                    std::string stockr;
                    int stockRemaining;
                    //std::cout << "Enter the name of the flavor to be added: " << std::endl;
                    //std::getline(std::cin,flav);
                    //std::cin.ignore();
                    //flav = Dialogs::input("Enter the name of the flavor to be added: ");
                    Gtk::Dialog *dialog = new Gtk::Dialog();
                    dialog->set_title("Edit flavor");
                    
                    
                    Gtk::HBox b_des;
                    Gtk::Label l_des{"FOR FIELDS YOU DON'T WANT TO CHANGE, ENTER A SPACE"};
                    l_des.set_width_chars(20);
                    b_des.pack_start(l_des, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_des, Gtk::PACK_SHRINK);
                    
                    // flavor
                    Gtk::HBox b_flavor;
                    
                    Gtk::Label l_flavor{"Flavor: "};
                    l_flavor.set_width_chars(20);
                    b_flavor.pack_start(l_flavor, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_flavor;
                    e_flavor.set_max_length(50);
                    b_flavor.pack_start(e_flavor, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_flavor, Gtk::PACK_SHRINK);
                    
                    // Description
                    Gtk::HBox b_desc;
                    
                    Gtk::Label l_desc{"Description: "};
                    l_desc.set_width_chars(20);
                    b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_desc;
                    e_desc.set_max_length(50);
                    b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
                    
                    // Copyright date
                    Gtk::HBox b_wholesaleCost;
                    
                    Gtk::Label l_wholesaleCost{"Wholesale Cost: "};
                    l_wholesaleCost.set_width_chars(20);
                    b_wholesaleCost.pack_start(l_wholesaleCost, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_wholesaleCost;
                    e_wholesaleCost.set_max_length(50);
                    b_wholesaleCost.pack_start(e_wholesaleCost, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_wholesaleCost, Gtk::PACK_SHRINK);
                    
                    Gtk::HBox b_retailCost;
                    
                    Gtk::Label l_retailCost{"Retail Cost: "};
                    l_retailCost.set_width_chars(20);
                    b_retailCost.pack_start(l_retailCost, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_retailCost;
                    e_retailCost.set_max_length(50);
                    b_retailCost.pack_start(e_retailCost, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_retailCost, Gtk::PACK_SHRINK);
                    
                    Gtk::HBox b_stock;
                    
                    Gtk::Label l_stock{"Stock remaining: "};
                    l_stock.set_width_chars(20);
                    b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_stock;
                    e_stock.set_max_length(50);
                    b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);
                    
                    
                    //stockRemaining = (int)std::stoi(stockr);
                    
                    dialog->add_button("Cancel", 0);
                    dialog->add_button("OK", 1);
                    dialog->show_all();
                    int result = dialog->run();
                    
                    
                    dialog->close();
                    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                    
                    auto stockS = e_stock.get_text();
                    
                    //REGEX
                    regex integer{"(\\+|-)?[[:digit:]]+"};
                    if(!(regex_match(e_stock.get_text().c_str(),integer)) && stockS != " ")
                    {
                        Dialogs::message("Invalid input","Error");
                        return;
                    }
                    
                    flav = e_flavor.get_text();
                    desc = e_desc.get_text();
                    auto wholesaleCostS = e_wholesaleCost.get_text();
                    auto retailCostS = e_retailCost.get_text();
                    
                    
                    if(result == 1)
                    {
                        if(flav == " ")
                        {
                            flav = orig.get_Name();
                        }
                        if(desc == " ")
                        {
                            desc = orig.getDesc();
                        }
                        if(wholesaleCostS == " ")
                        {
                            wholesaleCost = orig.getWholesaleCost();
                        }
                        else
                        {
                            wholesaleCost = atof(wholesaleCostS.c_str());
                        }
                        if(retailCostS == " ")
                        {
                            retailPrice = orig.getRetailPrice();
                        }
                        else
                        {
                            retailPrice = atof(retailCostS.c_str());
                        }
                        if(stockS == " ")
                        {
                            stockRemaining = orig.getStock();
                        }
                        else
                        {
                            stockRemaining = atoi(stockS.c_str());
                        }
                        Scoop s{flav, desc, wholesaleCost, retailPrice, stockRemaining};
                        emp.editFlavor(s,c);
                    }

                }
                
            }
            else if(s == 1 && d == 1)
            {
                //editing containers
                Gtk::Dialog *dialog2 = new Gtk::Dialog();
                dialog2->set_title("Edit Items");
                
                Gtk::HBox b_s;
                
                Gtk::Label l_s{"Which container?"};
                l_s.set_width_chars(50);
                b_s.pack_start(l_s, Gtk::PACK_SHRINK);
                
                Gtk::ComboBoxText c_s;
                c_s.set_size_request(160);
                
                std::vector<Container> contains = emp.get_Containers();
                for(int i = 0; i < contains.size(); i++)
                {
                    c_s.append(contains[i].get_Name());
                }
                
                b_s.pack_start(c_s, Gtk::PACK_SHRINK);
                
                dialog2->get_vbox()->pack_start(b_s, Gtk::PACK_SHRINK);
                dialog2->add_button("Cancel", 0);
                dialog2->add_button("OK", 1);
                dialog2->show_all();
                int dd = dialog2->run();
                dialog2->close();
                
                while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                int cnum = c_s.get_active_row_number();
                
                if(dd == 1)
                {
                    Container orig = contains[cnum];
                    //create a new container
                    //std::string container;
                    //std::cout << "Enter the name of the container to be added: " << std::endl;
                    //std::getline(std::cin,container);
                    //container = Dialogs::input("Enter the name of the container to be added: ");
                    /*if(container != "CANCEL")
                     {
                     emp.create_container(container);
                     }*/
                    
                    //create a new container
                    std::string cont;
                    std::string desc;
                    double wholesaleCost;
                    double retailPrice;
                    int stockr;
                    int stockRemaining;
                    int maxscoops;
                    //std::cout << "Enter the name of the flavor to be added: " << std::endl;
                    //std::getline(std::cin,flav);
                    //std::cin.ignore();
                    //flav = Dialogs::input("Enter the name of the flavor to be added: ");
                    Gtk::Dialog *dialog = new Gtk::Dialog();
                    dialog->set_title("Edit Container");
                    
                    
                    Gtk::HBox b_des;
                    Gtk::Label l_des{"FOR FIELDS YOU DON'T WANT TO CHANGE, ENTER A SPACE.\nLEAVING IT BLANK WILL NOT WORK."};
                    l_des.set_width_chars(20);
                    b_des.pack_start(l_des, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_des, Gtk::PACK_SHRINK);
                    
                    // CONTAINER
                    Gtk::HBox b_container;
                    
                    Gtk::Label l_container{"Container: "};
                    l_container.set_width_chars(20);
                    b_container.pack_start(l_container, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_container;
                    e_container.set_max_length(50);
                    b_container.pack_start(e_container, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
                    
                    // Description
                    Gtk::HBox b_desc;
                    
                    Gtk::Label l_desc{"Description: "};
                    l_desc.set_width_chars(20);
                    b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_desc;
                    e_desc.set_max_length(50);
                    b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
                    
                    // whole sale
                    Gtk::HBox b_wholesaleCost;
                    
                    Gtk::Label l_wholesaleCost{"Wholesale Cost: "};
                    l_wholesaleCost.set_width_chars(20);
                    b_wholesaleCost.pack_start(l_wholesaleCost, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_wholesaleCost;
                    e_wholesaleCost.set_max_length(50);
                    b_wholesaleCost.pack_start(e_wholesaleCost, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_wholesaleCost, Gtk::PACK_SHRINK);
                    
                    Gtk::HBox b_retailCost;
                    
                    Gtk::Label l_retailCost{"Retail Cost: "};
                    l_retailCost.set_width_chars(20);
                    b_retailCost.pack_start(l_retailCost, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_retailCost;
                    e_retailCost.set_max_length(50);
                    b_retailCost.pack_start(e_retailCost, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_retailCost, Gtk::PACK_SHRINK);
                    
                    Gtk::HBox b_stock;
                    
                    Gtk::Label l_stock{"Stock remaining: "};
                    l_stock.set_width_chars(20);
                    b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_stock;
                    e_stock.set_max_length(50);
                    b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);
                    
                    Gtk::HBox b_max;
                    
                    Gtk::Label l_max{"Max # of scoops: "};
                    l_max.set_width_chars(20);
                    b_max.pack_start(l_max, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_max;
                    e_max.set_max_length(50);
                    b_max.pack_start(e_max, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_max, Gtk::PACK_SHRINK);
                    
                    //stockRemaining = (int)std::stoi(stockr);
                    
                    dialog->add_button("Cancel", 0);
                    dialog->add_button("OK", 1);
                    dialog->show_all();
                    int result = dialog->run();
                    
                    
                    dialog->close();
                    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                    
                    cont = e_container.get_text();
                    desc = e_desc.get_text();
                    auto wholesaleCostS = e_wholesaleCost.get_text();
                    auto retailPriceS = e_retailCost.get_text();
                    auto stockRemainingS = e_stock.get_text();
                    auto maxscoopsS = e_max.get_text();
                    
                    if(result == 1)
                    {
                        if(cont == " ")
                        {
                            cont = orig.get_Name();
                        }
                        if(desc == " ")
                        {
                            desc = orig.getDesc();
                        }
                        if(wholesaleCostS == " ")
                        {
                            wholesaleCost = orig.getWholesaleCost();
                        }
                        else
                        {
                            wholesaleCost = atof(wholesaleCostS.c_str());
                        }
                        if(retailPriceS == " ")
                        {
                            retailPrice = orig.getRetailPrice();
                        }
                        else
                        {
                            retailPrice = atof(retailPriceS.c_str());
                        }
                        if(stockRemainingS == " ")
                        {
                            stockRemaining = orig.getStock();
                        }
                        else
                        {
                            stockRemaining = atoi(stockRemainingS.c_str());
                        }
                        if(maxscoopsS == " ")
                        {
                            maxscoops = orig.get_max_Scoops();
                        }
                        else
                        {
                            maxscoops = atoi(maxscoopsS.c_str());
                        }
                        Container c{cont, desc, wholesaleCost, retailPrice, stockRemaining, maxscoops};
                        emp.editContainer(c,cnum);
                    }

                }

            }
            else if(s == 2 && d == 1)
            {
                //editing toppings
                Gtk::Dialog *dialog2 = new Gtk::Dialog();
                dialog2->set_title("Edit Items");
                
                Gtk::HBox b_s;
                
                Gtk::Label l_s{"Which topping?"};
                l_s.set_width_chars(50);
                b_s.pack_start(l_s, Gtk::PACK_SHRINK);
                
                Gtk::ComboBoxText c_s;
                c_s.set_size_request(160);
                
                std::vector<Toppings> tops = emp.get_Toppings();
                for(int i = 0; i < tops.size(); i++)
                {
                    c_s.append(tops[i].get_Name());
                }
                
                b_s.pack_start(c_s, Gtk::PACK_SHRINK);
                
                dialog2->get_vbox()->pack_start(b_s, Gtk::PACK_SHRINK);
                dialog2->add_button("Cancel", 0);
                dialog2->add_button("OK", 1);
                dialog2->show_all();
                int dd = dialog2->run();
                dialog2->close();
                
                while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                int cnum = c_s.get_active_row_number();
                
                if(dd == 1)
                {
                    Toppings orig = tops[cnum];
                    std::string top;
                    std::string desc;
                    double wholesaleCost;
                    double retailPrice;
                    std::string stockr;
                    int stockRemaining;
                    //std::cout << "Enter the name of the flavor to be added: " << std::endl;
                    //std::getline(std::cin,flav);
                    //std::cin.ignore();
                    //flav = Dialogs::input("Enter the name of the flavor to be added: ");
                    Gtk::Dialog *dialog = new Gtk::Dialog();
                    dialog->set_title("Edit topping");
                    
                    
                    Gtk::HBox b_des;
                    Gtk::Label l_des{"FOR FIELDS YOU DON'T WANT TO CHANGE, ENTER A SPACE.\nLEAVING IT BLANK WILL NOT WORK."};
                    l_des.set_width_chars(20);
                    b_des.pack_start(l_des, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_des, Gtk::PACK_SHRINK);
                    
                    // CONTAINER
                    Gtk::HBox b_top;
                    
                    Gtk::Label l_top{"Topping: "};
                    l_top.set_width_chars(20);
                    b_top.pack_start(l_top, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_top;
                    e_top.set_max_length(50);
                    b_top.pack_start(e_top, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_top, Gtk::PACK_SHRINK);
                    
                    // Description
                    Gtk::HBox b_desc;
                    
                    Gtk::Label l_desc{"Description: "};
                    l_desc.set_width_chars(20);
                    b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_desc;
                    e_desc.set_max_length(50);
                    b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
                    
                    // wholesalr
                    Gtk::HBox b_wholesaleCost;
                    
                    Gtk::Label l_wholesaleCost{"Wholesale Cost: "};
                    l_wholesaleCost.set_width_chars(20);
                    b_wholesaleCost.pack_start(l_wholesaleCost, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_wholesaleCost;
                    e_wholesaleCost.set_max_length(50);
                    b_wholesaleCost.pack_start(e_wholesaleCost, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_wholesaleCost, Gtk::PACK_SHRINK);
                    
                    Gtk::HBox b_retailCost;
                    
                    Gtk::Label l_retailCost{"Retail Cost: "};
                    l_retailCost.set_width_chars(20);
                    b_retailCost.pack_start(l_retailCost, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_retailCost;
                    e_retailCost.set_max_length(50);
                    b_retailCost.pack_start(e_retailCost, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_retailCost, Gtk::PACK_SHRINK);
                    
                    Gtk::HBox b_stock;
                    
                    Gtk::Label l_stock{"Stock remaining: "};
                    l_stock.set_width_chars(20);
                    b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);
                    
                    Gtk::Entry e_stock;
                    e_stock.set_max_length(50);
                    b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
                    dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);
                    
                    //stockRemaining = (int)std::stoi(stockr);
                    
                    dialog->add_button("Cancel", 0);
                    dialog->add_button("OK", 1);
                    dialog->show_all();
                    int result = dialog->run();
                    
                    
                    dialog->close();
                    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                    
                    top = e_top.get_text();
                    desc = e_desc.get_text();
                    auto wholesaleCostS = e_wholesaleCost.get_text();
                    auto retailPriceS = e_retailCost.get_text();
                    auto stockRemainingS = e_stock.get_text();
                    
                    if(result == 1)
                    {
                        if(top == " ")
                        {
                            top = orig.get_Name();
                        }
                        if(desc == " ")
                        {
                            desc = orig.getDesc();
                        }
                        if(wholesaleCostS == " ")
                        {
                            wholesaleCost = orig.getWholesaleCost();
                        }
                        else
                        {
                            wholesaleCost = atof(wholesaleCostS.c_str());
                        }
                        if(retailPriceS == " ")
                        {
                            retailPrice = orig.getRetailPrice();
                        }
                        else
                        {
                            retailPrice = atof(retailPriceS.c_str());
                        }
                        if(stockRemainingS == " ")
                        {
                            stockRemaining = orig.getStock();
                        }
                        else
                        {
                            stockRemaining = atoi(stockRemainingS.c_str());
                        }
                        Toppings t{top,desc,wholesaleCost,retailPrice,stockRemaining};
                        emp.editTopping(t, cnum);
                    }

                }

            }
        }
        else if(cmd == 0)
        {
      //      break;
        }
        else
        {
      //      break;
        }
    //}
}

void Controller_Gui::server_cmd(int cmd)
{
    if(cmd == 1)
    {
        Gtk::Dialog *dialog2 = new Gtk::Dialog();
        dialog2->set_title("Create Serving");
        
        Gtk::HBox b_s;
        
        Gtk::Label l_s{"Which server are you?"};
        l_s.set_width_chars(50);
        b_s.pack_start(l_s, Gtk::PACK_SHRINK);
        
        Gtk::ComboBoxText c_s;
        c_s.set_size_request(160);
        
        
        std::vector<Server> servers = emp.get_Servers();
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
        int servNum = c_s.get_active_row_number();
        
        
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        
        Server *servingPerson = &(servers[servNum]);
        std::vector<Customer> i_customers = (*servingPerson).get_Customers();
        int custChoice;
        if(s == 1)
        {
            Gtk::Dialog *dialog2 = new Gtk::Dialog();
            dialog2->set_title("Create Serving");
            
            Gtk::HBox b_p;
            
            Gtk::Label l_p{"Which person are you serving?"};
            l_p.set_width_chars(50);
            b_p.pack_start(l_p, Gtk::PACK_SHRINK);
            
            Gtk::ComboBoxText c_p;
            c_p.set_size_request(160);
            
            c_p.append("Yourself");
            
            for(int i = 0; i < i_customers.size(); i++)
            {
                c_p.append(i_customers[i].get_Name());
            }
            b_p.pack_start(c_p, Gtk::PACK_SHRINK);
            
            dialog2->get_vbox()->pack_start(b_p, Gtk::PACK_SHRINK);
            dialog2->add_button("Cancel", 0);
            dialog2->add_button("OK", 1);
            dialog2->show_all();
            int cust = dialog2->run();
            dialog2->close();
            
            custChoice = c_p.get_active_row_number();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();

            if(cust == 0)
            {
                return;
            }

            
            //create new serving
            int numScoops;
            int price;
            
            //these will store info so we know what stock to reduce after creation
            std::vector<int> scoopsStock;
            int containerTypeStock;
            std::vector<int> topStock;
            
            Gtk::Dialog *dialog = new Gtk::Dialog();
            dialog->set_title("Create Serving: Choose Container");
            
            
            //containers
            Gtk::HBox b_cont;
            
            Gtk::Label l_cont{"Container:"};
            l_cont.set_width_chars(15);
            b_cont.pack_start(l_cont, Gtk::PACK_SHRINK);
            
            Gtk::ComboBoxText c_cont;
            c_cont.set_size_request(160);
            
            std::vector<Container> containers = emp.get_Containers();
            for(int i = 0; i < containers.size(); i++)
            {
                c_cont.append(containers[i].get_Name());
            }
            b_cont.pack_start(c_cont, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_cont, Gtk::PACK_SHRINK);
            
            dialog->add_button("Cancel", 0);
            dialog->add_button("OK", 1);
            dialog->show_all();
            int result = dialog->run();
            
            
            dialog->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            
            Container container{"", "", -1, -1, -1, -1};
            if(result == 1)
            {
                containerTypeStock = c_cont.get_active_row_number();
                if(emp.checkContainerStock(containerTypeStock) == false)
                {
                    throw std::runtime_error("Error: No containers of that type in stock!");
                }
                container = containers[containerTypeStock];
                Gtk::Dialog *dialog = new Gtk::Dialog();
                dialog->set_title("Create Serving: Choose Scoops");
                //scoops
                Gtk::HBox b_scoops;
                
                Gtk::Label l_scoops{"# of scoops:"};
                l_scoops.set_width_chars(15);
                b_scoops.pack_start(l_scoops, Gtk::PACK_SHRINK);
                
                Gtk::ComboBoxText c_scoops;
                c_scoops.set_size_request(160);
                
                int maxScoops = container.get_max_Scoops();
                for(int i = 1; i <= maxScoops; i++)
                {
                    c_scoops.append(std::to_string(i));
                }
                
                b_scoops.pack_start(c_scoops, Gtk::PACK_SHRINK);
                dialog->get_vbox()->pack_start(b_scoops, Gtk::PACK_SHRINK);
                
                
                dialog->add_button("Cancel", 0);
                dialog->add_button("OK", 1);
                dialog->show_all();
                int result = dialog->run();
                
                
                dialog->close();
                while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                
                numScoops = c_scoops.get_active_row_number() + 1;
                
                if(result == 1)
                {
                    //second dialog
                    
                    std::vector<Scoop> flavs = emp.get_Scoops();
                    
                    for(int i = 0; i < numScoops; i++)
                    {
                        Gtk::Dialog *dialog = new Gtk::Dialog();
                        dialog->set_title("Create Serving: Decide flavors");
                        
                        Gtk::HBox b_flav;
                        
                        Gtk::Label l_flav{"Flavor for scoop " + to_string(i+1) + " :"};
                        l_flav.set_width_chars(25);
                        b_flav.pack_start(l_flav, Gtk::PACK_SHRINK);
                        
                        Gtk::ComboBoxText c_flav;
                        c_flav.set_size_request(160);
                        
                        for(int j = 0; j < flavs.size(); j++)
                        {
                            c_flav.append(flavs[j].get_Name());
                        }
                        b_flav.pack_start(c_flav, Gtk::PACK_SHRINK);
                        dialog->get_vbox()->pack_start(b_flav, Gtk::PACK_SHRINK);
                        
                        dialog->add_button("Cancel", 0);
                        dialog->add_button("OK", 1);
                        dialog->show_all();
                        int result = dialog->run();
                        
                        dialog->close();
                        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                        
                        if(result == 1)
                        {
                            int scoopTypeNum = c_flav.get_active_row_number();
                            if(emp.checkFlavorStock(scoopTypeNum) == false)
                            {
                                throw std::runtime_error("Error: No more of that flavor in stock!");
                            }
                            scoopsStock.push_back(scoopTypeNum);
                            Scoop s = flavs[scoopTypeNum];
                            //add topping
                            Gtk::Dialog *dialog2 = new Gtk::Dialog();
                            dialog2->set_title("Add Topping");
                            
                            
                            Gtk::HBox b_t;
                            
                            Gtk::Label l_t{"Do you want toppings on this scoop?"};
                            l_t.set_width_chars(50);
                            b_t.pack_start(l_t, Gtk::PACK_SHRINK);
                            dialog2->get_vbox()->pack_start(b_t, Gtk::PACK_SHRINK);
                            dialog2->add_button("No", 0);
                            dialog2->add_button("Yes", 1);
                            dialog2->show_all();
                            int chooseTops = dialog2->run();
                            dialog2->close();
                            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                            
                            if(chooseTops == 1)
                            {
                                std::vector<Toppings> toppers = emp.get_Toppings();
                                
                                for(int k = 0; k < toppers.size(); k++)
                                {
                                    Toppings someTopper = toppers[k];
                                    Gtk::Dialog *dialog2 = new Gtk::Dialog();
                                    dialog2->set_title("Create Serving: Add toppings");
                                    
                                    Gtk::HBox b_tops;
                                    
                                    Gtk::Label l_tops{"Do you want " + someTopper.get_Name() + " on this scoop?"};
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
                                        if(emp.checkToppingStock(k) == false)
                                        {
                                            throw std::runtime_error("Error: No more of that topping left!");
                                        }
                                        s.add_toppings(someTopper);
                                        topStock.push_back(k);
                                    }
                                }
                            }
                            container.add_scoop(s);
                        }
                        else
                        {
                            break;
                        }
                        
                    }
                }
            }

            emp.create_Serving(servNum,-1,container,cust,custChoice);
            emp.manageStock(containerTypeStock,scoopsStock,topStock);
        }

    }
    else if(cmd == 2)
    {
        Gtk::Dialog *dialog = new Gtk::Dialog();
        dialog->set_title("Create Customer");
        
        
        //customer
        std::string custName;
        std::string phoneNumber;
        Gtk::HBox b_cust;
        
        Gtk::Label l_cust{"Name:"};
        l_cust.set_width_chars(15);
        b_cust.pack_start(l_cust, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_cust;
        e_cust.set_max_length(50);
        b_cust.pack_start(e_cust, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_cust, Gtk::PACK_SHRINK);
        Gtk::HBox b_phone;
        Gtk::Label l_phone{"Phone #:"};
        l_phone.set_width_chars(15);
        b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_phone;
        e_phone.set_max_length(50);
        b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);
        
        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();
        int result = dialog->run();
        
        custName = e_cust.get_text();
        phoneNumber = e_phone.get_text();
            
        dialog->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        
        if(result == 1)
        {
            Order ord{"", -1, "", ""};
            Customer cc{custName, phoneNumber, ord};
            Gtk::Dialog *dialog2 = new Gtk::Dialog();
            dialog2->set_title("Create Customer");
            
            
            Gtk::HBox b_t;
            
            Gtk::Label l_t{"Is this customer assigned to a server?"};
            l_t.set_width_chars(50);
            b_t.pack_start(l_t, Gtk::PACK_SHRINK);
            dialog2->get_vbox()->pack_start(b_t, Gtk::PACK_SHRINK);
            dialog2->add_button("No", 0);
            dialog2->add_button("Yes", 1);
            dialog2->add_button("Cancel", 2);
            dialog2->show_all();
            int choice = dialog2->run();
            dialog2->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            
            if(choice == 0 || choice == 1)
            {
                emp.add_customer(choice,cc);
            }
        }
    }
    else if(cmd == 3)
    {
        //view servings
        Gtk::Dialog *dialog2 = new Gtk::Dialog();
        dialog2->set_title("View Servings");
        
        Gtk::HBox b_s;
        
        Gtk::Label l_s{"Which server are you?"};
        l_s.set_width_chars(50);
        b_s.pack_start(l_s, Gtk::PACK_SHRINK);
        
        Gtk::ComboBoxText c_s;
        c_s.set_size_request(160);
        
        std::vector<Server> servers = emp.get_Servers();
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
        int servNum = c_s.get_active_row_number();
        
        
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        
        if(s == 1)
        {
            view.list_serv_servings(servers[servNum]);
        }

    }
    else if(cmd == 4)
    {
        //make order
        Gtk::Dialog *dialog2 = new Gtk::Dialog();
        dialog2->set_title("Create order");
        
        Gtk::HBox b_s;
        
        Gtk::Label l_s{"Which server are you?"};
        l_s.set_width_chars(50);
        b_s.pack_start(l_s, Gtk::PACK_SHRINK);
        
        Gtk::ComboBoxText c_s;
        c_s.set_size_request(160);
        
        std::vector<Server> servers = emp.get_Servers();
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
        int servNum = c_s.get_active_row_number();
        
        if(s == 1)
        {
            emp.create_Order_Serv(servNum);
        }
    }
    else if(cmd == 5)
    {
        //view order
        Gtk::Dialog *dialog2 = new Gtk::Dialog();
        dialog2->set_title("View Orders");
        
        Gtk::HBox b_s;
        
        Gtk::Label l_s{"Which server are you?"};
        l_s.set_width_chars(50);
        b_s.pack_start(l_s, Gtk::PACK_SHRINK);
        
        Gtk::ComboBoxText c_s;
        c_s.set_size_request(160);
        
        std::vector<Server> servers = emp.get_Servers();
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
        
        int servNum = c_s.get_active_row_number();
        
        if(s == 1)
        {
            Gtk::Dialog *dialog2 = new Gtk::Dialog();
            dialog2->set_title("View Orders");
            
            Gtk::HBox b_s;
            
            Gtk::Label l_s{"Do you want to see customer order requests?"};
            l_s.set_width_chars(50);
            b_s.pack_start(l_s, Gtk::PACK_SHRINK);
            dialog2->get_vbox()->pack_start(b_s, Gtk::PACK_SHRINK);
            
            dialog2->add_button("Yes", 0);
            dialog2->add_button("No", 1);
            dialog2->show_all();
            int d = dialog2->run();
            dialog2->close();
            
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            
            if(d == 1)
            {
                view.list_serv_orders(servers[servNum]);
            }
            else if(d == 0)
            {
                Gtk::Dialog *dialog2 = new Gtk::Dialog();
                dialog2->set_title("View Orders");
                
                Gtk::HBox b_s;
                
                Gtk::Label l_s{"Which customer?"};
                l_s.set_width_chars(50);
                b_s.pack_start(l_s, Gtk::PACK_SHRINK);
                
                Gtk::ComboBoxText c_s;
                c_s.set_size_request(160);
                
                int count = 0;
                std::vector<Customer> custs = emp.get_Servers()[servNum].get_Customers();
                for(int i = 0; i < custs.size(); i++)
                {
                    if(custs[i].getCustOrders().getState() == "unfilled")
                    {
                        c_s.append(custs[i].get_Name());
                        count++;
                    }
                }
                if(count == 0)
                {
                    Dialogs::message("No customers of yours with orders in the queue!");
                    return;
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
                    int custNum = c_s.get_active_row_number();
                    view.list_cust_orders(custs[custNum]);
                }
            }
            //std::cout << (customers[custNum].getCustOrders()).toString() << std::endl;
        }
    }
}

void Controller_Gui::customer_cmd(int cmd)
{
    if(cmd == 1)
    {
        //view servings
        Gtk::Dialog *dialog2 = new Gtk::Dialog();
        dialog2->set_title("View Servings");
        
        Gtk::HBox b_s;
        
        Gtk::Label l_s{"Which customer are you?"};
        l_s.set_width_chars(50);
        b_s.pack_start(l_s, Gtk::PACK_SHRINK);
        
        Gtk::ComboBoxText c_s;
        c_s.set_size_request(160);
        
        std::vector<Customer> customers = emp.get_Customers();
        for(int i = 0; i < customers.size(); i++)
        {
            c_s.append(customers[i].get_Name());
        }
        b_s.pack_start(c_s, Gtk::PACK_SHRINK);
        
        dialog2->get_vbox()->pack_start(b_s, Gtk::PACK_SHRINK);
        dialog2->add_button("Cancel", 0);
        dialog2->add_button("OK", 1);
        dialog2->show_all();
        int s = dialog2->run();
        dialog2->close();
        int custNum = c_s.get_active_row_number();
        
        
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        
        if(s == 1)
        {
            view.list_cust_servings(customers[custNum]);
        }

    }
    else if(cmd == 2)
    {
        //view order
        Gtk::Dialog *dialog2 = new Gtk::Dialog();
        dialog2->set_title("View Orders");
        
        Gtk::HBox b_s;
        
        Gtk::Label l_s{"Which customer are you?"};
        l_s.set_width_chars(50);
        b_s.pack_start(l_s, Gtk::PACK_SHRINK);
        
        Gtk::ComboBoxText c_s;
        c_s.set_size_request(160);
        
        std::vector<Customer> customers = emp.get_Customers();
        for(int i = 0; i < customers.size(); i++)
        {
            c_s.append(customers[i].get_Name());
        }
        b_s.pack_start(c_s, Gtk::PACK_SHRINK);
        
        dialog2->get_vbox()->pack_start(b_s, Gtk::PACK_SHRINK);
        dialog2->add_button("Cancel", 0);
        dialog2->add_button("OK", 1);
        dialog2->show_all();
        int s = dialog2->run();
        dialog2->close();
        
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        
        int custNum = c_s.get_active_row_number();
        
        if(s == 1)
        {
            //std::cout << (customers[custNum].getCustOrders()).toString() << std::endl;
            view.list_cust_orders(customers[custNum]);
        }
    }
    else if(cmd == 3)
    {
        //make order
        Gtk::Dialog *dialog2 = new Gtk::Dialog();
        dialog2->set_title("Create order");
        
        Gtk::HBox b_s;
        
        Gtk::Label l_s{"Which customer are you?"};
        l_s.set_width_chars(50);
        b_s.pack_start(l_s, Gtk::PACK_SHRINK);
        
        Gtk::ComboBoxText c_s;
        c_s.set_size_request(160);
        
        std::vector<Customer> customers = emp.get_Customers();
        for(int i = 0; i < customers.size(); i++)
        {
            c_s.append(customers[i].get_Name());
        }
        b_s.pack_start(c_s, Gtk::PACK_SHRINK);
        
        dialog2->get_vbox()->pack_start(b_s, Gtk::PACK_SHRINK);
        dialog2->add_button("Cancel", 0);
        dialog2->add_button("OK", 1);
        dialog2->show_all();
        int s = dialog2->run();
        dialog2->close();
        
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        int custNum = c_s.get_active_row_number();
        int custNumEmp = custNum;
        int servNum;
        
        int found = 0;
        
        if(s == 1)
        {
            std::vector<Server> servers = emp.get_Servers();
            for(int i = 0; i < servers.size(); i++)
            {
                std::vector<Customer> serv_customers = servers[i].get_Customers();
                for(int j = 0; j < serv_customers.size(); j++)
                {
                    //OPERATOR OVERLOADING
                    if(customers[custNum] == serv_customers[j])
                    {
                        servNum = i;
                        custNum = j;
                        found = 1;
                        break;
                    }
                }
            }
            emp.create_Order_Cust(servNum,custNum,custNumEmp,found);
        }
    }
    else if(cmd == 4)
    {
        //create serving
        
        std::vector<int> scoopsStock;
        int containerTypeStock;
        std::vector<int> topStock;
        
        Gtk::Dialog *dialog2 = new Gtk::Dialog();
        dialog2->set_title("Create Serving");
        
        Gtk::HBox b_s;
        
        Gtk::Label l_s{"Which customer are you?"};
        l_s.set_width_chars(50);
        b_s.pack_start(l_s, Gtk::PACK_SHRINK);
        
        Gtk::ComboBoxText c_s;
        c_s.set_size_request(160);
        
        std::vector<Customer> customers = emp.get_Customers();
        for(int i = 0; i < customers.size(); i++)
        {
            c_s.append(customers[i].get_Name());
        }
        b_s.pack_start(c_s, Gtk::PACK_SHRINK);
        
        dialog2->get_vbox()->pack_start(b_s, Gtk::PACK_SHRINK);
        dialog2->add_button("Cancel", 0);
        dialog2->add_button("OK", 1);
        dialog2->show_all();
        int s = dialog2->run();
        dialog2->close();
        
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        int custNum = c_s.get_active_row_number();
        
        if(s == 1)
        {
            int numScoops;
            int price;
            
            Gtk::Dialog *dialog = new Gtk::Dialog();
            dialog->set_title("Create Serving: Choose Container");
            
            
            //containers
            Gtk::HBox b_cont;
            
            Gtk::Label l_cont{"Container:"};
            l_cont.set_width_chars(15);
            b_cont.pack_start(l_cont, Gtk::PACK_SHRINK);
            
            Gtk::ComboBoxText c_cont;
            c_cont.set_size_request(160);
            
            Gtk::Image* image1 = Gtk::manage(new Gtk::Image("container.jpg"));
            dialog->get_vbox()->pack_start(*image1, true, true);
            
            std::vector<Container> containers = emp.get_Containers();
            for(int i = 0; i < containers.size(); i++)
            {
                c_cont.append(containers[i].get_Name());
            }
            b_cont.pack_start(c_cont, Gtk::PACK_SHRINK);
            dialog->get_vbox()->pack_start(b_cont, Gtk::PACK_SHRINK);
            
            dialog->add_button("Cancel", 0);
            dialog->add_button("OK", 1);
            dialog->show_all();
            int result = dialog->run();
            
            
            dialog->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            
            if(result == 1)
            {
                containerTypeStock = c_cont.get_active_row_number();
                if(emp.checkContainerStock(containerTypeStock) == false)
                {
                    throw std::runtime_error("Error: No containers of that type in stock!");
                }
                Container container = containers[containerTypeStock];
                Gtk::Dialog *dialog = new Gtk::Dialog();
                dialog->set_title("Create Serving: Choose Scoops");
                //scoops
                Gtk::HBox b_scoops;
                
                Gtk::Label l_scoops{"# of scoops:"};
                l_scoops.set_width_chars(15);
                b_scoops.pack_start(l_scoops, Gtk::PACK_SHRINK);

                Gtk::Image* image1 = Gtk::manage(new Gtk::Image("scoop.jpg"));
                dialog->get_vbox()->pack_start(*image1, true, true);
                
                Gtk::ComboBoxText c_scoops;
                c_scoops.set_size_request(160);
                
                int maxScoops = container.get_max_Scoops();
                for(int i = 1; i <= maxScoops; i++)
                {
                    c_scoops.append(std::to_string(i));
                }
                
                b_scoops.pack_start(c_scoops, Gtk::PACK_SHRINK);
                dialog->get_vbox()->pack_start(b_scoops, Gtk::PACK_SHRINK);
                
                
                dialog->add_button("Cancel", 0);
                dialog->add_button("OK", 1);
                dialog->show_all();
                int result = dialog->run();
                
                
                dialog->close();
                while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                
                numScoops = c_scoops.get_active_row_number() + 1;
                
                if(result == 1)
                {
                    //second dialog
                    
                    std::vector<Scoop> flavs = emp.get_Scoops();
                    
                    for(int i = 0; i < numScoops; i++)
                    {
                        Gtk::Dialog *dialog = new Gtk::Dialog();
                        dialog->set_title("Create Serving: Decide flavors");
                        
                        Gtk::HBox b_flav;
                        
                        Gtk::Label l_flav{"Flavor for scoop " + to_string(i+1) + " :"};
                        l_flav.set_width_chars(25);
                        b_flav.pack_start(l_flav, Gtk::PACK_SHRINK);
                        
                        Gtk::ComboBoxText c_flav;
                        c_flav.set_size_request(160);
                        
                        Gtk::Image* image1 = Gtk::manage(new Gtk::Image("strawberry.png"));
                        dialog->get_vbox()->pack_start(*image1, true, true);
                        
                        for(int j = 0; j < flavs.size(); j++)
                        {
                            c_flav.append(flavs[j].get_Name());
                        }
                        b_flav.pack_start(c_flav, Gtk::PACK_SHRINK);
                        dialog->get_vbox()->pack_start(b_flav, Gtk::PACK_SHRINK);
                        
                        dialog->add_button("Cancel", 0);
                        dialog->add_button("OK", 1);
                        dialog->show_all();
                        int result = dialog->run();
                        
                        dialog->close();
                        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                        
                        if(result == 1)
                        {
                            int scoopTypeNum = c_flav.get_active_row_number();
                            if(emp.checkFlavorStock(scoopTypeNum) == false)
                            {
                                throw std::runtime_error("Error: No more of that flavor in stock!");
                            }
                            scoopsStock.push_back(scoopTypeNum);
                            Scoop s = flavs[scoopTypeNum];
                            //add topping
                            Gtk::Dialog *dialog2 = new Gtk::Dialog();
                            dialog2->set_title("Add Topping");
                            
                            
                            Gtk::HBox b_t;
                            
                            Gtk::Label l_t{"Do you want toppings on this scoop?"};
                            l_t.set_width_chars(50);
                            b_t.pack_start(l_t, Gtk::PACK_SHRINK);
                            dialog2->get_vbox()->pack_start(b_t, Gtk::PACK_SHRINK);
                            dialog2->add_button("No", 0);
                            dialog2->add_button("Yes", 1);
                            dialog2->show_all();
                            int chooseTops = dialog2->run();
                            dialog2->close();
                            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                            
                            if(chooseTops == 1)
                            {
                                std::vector<Toppings> toppers = emp.get_Toppings();
                                
                                for(int k = 0; k < toppers.size(); k++)
                                {
                                    Toppings someTopper = toppers[k];
                                    Gtk::Dialog *dialog2 = new Gtk::Dialog();
                                    dialog2->set_title("Create Serving: Add toppings");
                                    
                                    Gtk::HBox b_tops;
                                    
                                    Gtk::Label l_tops{"Do you want " + someTopper.get_Name() + " on this scoop?"};
                                    l_tops.set_width_chars(50);
                                    b_tops.pack_start(l_tops, Gtk::PACK_SHRINK);
                                    dialog2->get_vbox()->pack_start(b_tops, Gtk::PACK_SHRINK);
                                    
                                    Gtk::Image* image1 = Gtk::manage(new Gtk::Image("sprinkles.jpg"));
                                    dialog2->get_vbox()->pack_start(*image1, true, true);
                                    
                                    dialog2->add_button("No", 0);
                                    dialog2->add_button("Yes", 1);
                                    dialog2->show_all();
                                    int topDecide = dialog2->run();
                                    dialog2->close();
                                    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                                    
                                    if(topDecide == 1)
                                    {
                                        if(emp.checkToppingStock(k) == false)
                                        {
                                            throw std::runtime_error("Error: No more of that topping in stock!");
                                        }
                                        s.add_toppings(someTopper);
                                        topStock.push_back(k);
                                    }
                                }
                            }
                            container.add_scoop(s);
                        }
                        else
                        {
                            break;
                        }
                        
                    }
                    
                    //find server for customer
                    int found = 0;
                    int theServNum;
                    std::vector<Server> servers = emp.get_Servers();
                    for(int n = 0; n < servers.size(); n++)
                    {
                        std::vector<Customer> serv_customers = servers[n].get_Customers();
                        for(int m = 0; m < serv_customers.size(); m++)
                        {
                            if(customers[custNum] == serv_customers[m])
                            {
                                //std::cout << "in loop found" << std::endl;
                                theServNum = n;
                                custNum = m;
                                found = 1;
                                break;
                            }
                        }
                    }
                    
                    if(found == 1)
                    {
                        //std::cout << "in found" << std::endl;
                        emp.create_Serving(theServNum,custNum,container,-1,-1,true);
                        emp.manageStock(containerTypeStock, scoopsStock, topStock);
                    }
                    else if(found == 0)
                    {
                        emp.create_Serving_NoServer(custNum, container);
                        emp.manageStock(containerTypeStock, scoopsStock, topStock);
                    }
                }
            }
            
        }

        }
}

void Controller_Gui::file_cmd(int cmd)
{
    if(cmd == 1)
    {
        //save toppings
        emp.saveFile();
    }
    else if(cmd == 2)
    {
        emp.loadFile();
    }
}

void Controller_Gui::help()
{
    view.help();
}

void Controller_Gui::owner_cmd(int cmd)
{
    if(cmd == 1)
    {
        //create named manager
        emp.setManagerName();
    }
    else if(cmd == 2)
    {
        //view manager
        view.show_manager();
    }
}




















