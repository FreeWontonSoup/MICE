#include "main_window.h"
#include "gtkmm.h"
#include "dialogs.h"
#include <vector>
#include <exception>



Main_window::Main_window(Controller_Gui &c) : controller{c}
{
    Main_window2();
}

void Main_window::Main_window2()
{
    set_default_size(600,400);
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);
    
    
    //vbox->set_border_width(5);
    
    Gtk::Label *l = Gtk::manage(new Gtk::Label("CSE 1325 Emporium Management System\n\tPlease select who you are!\n\nNOTE: SERVERS CAN ONLY SERVE CUSTOMERS THEY CREATE!!!\nCUSTOMERS NOT ASSIGNED CANNOT DO ANYTHING AT THE MOMENT!!!\n\nNOTE 2: IF YOU ARE CREATING A SERVING AND SELECT OK WHILST NOT CHOOSING ANYTHING,\nTHE PROGRAM HAS NOT HANDLED THAT!!!"));
    vbox->pack_start(*l,false,true,0);
    l->set_alignment(.5,.5);
    
    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    
    //     FILE
    // Create a FILE menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    
    //         SAVE
    // Append SAVE to the file menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save to file", true));
    menuitem_save->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::file_run), 1));
    filemenu->append(*menuitem_save);
    
    //         LOAD
    // Append LOAD to the file menu
    Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load from file", true));
    menuitem_load->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::file_run), 2));
    filemenu->append(*menuitem_load);
    
    //     OWNER
    // Create a OWNER menu and add to the menu bar
    Gtk::MenuItem *menuitem_owner = Gtk::manage(new Gtk::MenuItem("_Owner", true));
    menubar->append(*menuitem_owner);
    Gtk::Menu *ownermenu = Gtk::manage(new Gtk::Menu());
    menuitem_owner->set_submenu(*ownermenu);
    
    //         NAMED MANAGER
    // Append NAMED MANAGER to the owner menu
    Gtk::MenuItem *menuitem_namedm = Gtk::manage(new Gtk::MenuItem("_Create named manager", true));
    menuitem_namedm->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::owner_run), 1));
    ownermenu->append(*menuitem_namedm);
    
    //         VIEW MANAGER
    // Append VIEW MANAGER to the owner menu
    Gtk::MenuItem *menuitem_viewm = Gtk::manage(new Gtk::MenuItem("_View named manager", true));
    menuitem_viewm->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::owner_run), 2));
    ownermenu->append(*menuitem_viewm);
    
    //     MANAGER
    // Create a MANAGER menu and add to the menu bar
    Gtk::MenuItem *menuitem_manager = Gtk::manage(new Gtk::MenuItem("_Manager", true));
    menubar->append(*menuitem_manager);
    Gtk::Menu *managermenu = Gtk::manage(new Gtk::Menu());
    menuitem_manager->set_submenu(*managermenu);
    
    //         CREATE FLAVOR
    // Append create flavor to the manager menu
    Gtk::MenuItem *menuitem_createFlav = Gtk::manage(new Gtk::MenuItem("_Create new flavor", true));
    //.connect(sigc::bind<int>(sigc::mem_fun(*this, &NavPanel::OnButtonClick), i));
    menuitem_createFlav->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 1));
    managermenu->append(*menuitem_createFlav);
    
    //         LIST FLAVOR
    // Append LIST flavor to the manager menu
    Gtk::MenuItem *menuitem_listFlav = Gtk::manage(new Gtk::MenuItem("_List flavors", true));
    menuitem_listFlav->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 2));
    managermenu->append(*menuitem_listFlav);
    
    Gtk::MenuItem *menuitem_createCont = Gtk::manage(new Gtk::MenuItem("_Create container", true));
    menuitem_createCont->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 3));
    managermenu->append(*menuitem_createCont);
    
    Gtk::MenuItem *menuitem_listCont = Gtk::manage(new Gtk::MenuItem("_List containers", true));
    menuitem_listCont->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 4));
    managermenu->append(*menuitem_listCont);
    
    Gtk::MenuItem *menuitem_createTop = Gtk::manage(new Gtk::MenuItem("_Create Toppings", true));
    menuitem_createTop->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 5));
    managermenu->append(*menuitem_createTop);
    
    Gtk::MenuItem *menuitem_listTop = Gtk::manage(new Gtk::MenuItem("_List Toppings", true));
    menuitem_listTop->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 6));
    managermenu->append(*menuitem_listTop);
    
    Gtk::MenuItem *menuitem_createServer = Gtk::manage(new Gtk::MenuItem("_Create Server", true));
    menuitem_createServer->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 7));
    managermenu->append(*menuitem_createServer);
    
    Gtk::MenuItem *menuitem_listServers = Gtk::manage(new Gtk::MenuItem("_List Servers", true));
    menuitem_listServers->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 8));
    managermenu->append(*menuitem_listServers);
    
    Gtk::MenuItem *menuitem_listCustomers = Gtk::manage(new Gtk::MenuItem("_List Customers", true));
    menuitem_listCustomers->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 9));
    managermenu->append(*menuitem_listCustomers);
    
    //         VIEW ORDER
    // Append VIEW orders to the manager menu
    Gtk::MenuItem *menuitem_viewOrderm = Gtk::manage(new Gtk::MenuItem("_View Orders", true));
    menuitem_viewOrderm->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 10));
    managermenu->append(*menuitem_viewOrderm);
    
    //         CASH REGISTER
    // Append CASH REGISTER to the manager menu
    Gtk::MenuItem *menuitem_register = Gtk::manage(new Gtk::MenuItem("_Cash Register", true));
    menuitem_register->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 11));
    managermenu->append(*menuitem_register);
    
    //         STOCK ITEMS
    // Append STOCK ITEMS to the manager menu
    Gtk::MenuItem *menuitem_stockItems = Gtk::manage(new Gtk::MenuItem("_Stock Items", true));
    menuitem_stockItems->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 12));
    managermenu->append(*menuitem_stockItems);
    
    //         CHANGE SERVER SALARY
    // Append CHANGE SERVER SALARY to the manager menu
    Gtk::MenuItem *menuitem_sal = Gtk::manage(new Gtk::MenuItem("_Change Server Salary", true));
    menuitem_sal->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 13));
    managermenu->append(*menuitem_sal);
    
    //         EDIT ITEMS
    // Append EDIT ITEMS to the manager menu
    Gtk::MenuItem *menuitem_edit = Gtk::manage(new Gtk::MenuItem("_Edit Items", true));
    menuitem_edit->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 14));
    managermenu->append(*menuitem_edit);
    
    
    //     SERVER
    // Create a SERVER menu and add to the menu bar
    Gtk::MenuItem *menuitem_server = Gtk::manage(new Gtk::MenuItem("_Server", true));
    menubar->append(*menuitem_server);
    Gtk::Menu *servermenu = Gtk::manage(new Gtk::Menu());
    menuitem_server->set_submenu(*servermenu);
    
    //         CREATE SERVING
    // Append create serving to the server menu
    Gtk::MenuItem *menuitem_createServing = Gtk::manage(new Gtk::MenuItem("_Create new serving", true));
    menuitem_createServing->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::server_run), 1));
    servermenu->append(*menuitem_createServing);
    
    //create customer
    Gtk::MenuItem *menuitem_createCustomer = Gtk::manage(new Gtk::MenuItem("_Create new customer", true));
    menuitem_createCustomer->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::server_run), 2));
    servermenu->append(*menuitem_createCustomer);
    
    //view serving for server
    Gtk::MenuItem *menuitem_viewServServing = Gtk::manage(new Gtk::MenuItem("_View Servings", true));
    menuitem_viewServServing->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::server_run), 3));
    servermenu->append(*menuitem_viewServServing);
    
    //         CREATE ORDER
    // Append create order to the server menu
    Gtk::MenuItem *menuitem_createOrder = Gtk::manage(new Gtk::MenuItem("_Create new order", true));
    menuitem_createOrder->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::server_run), 4));
    servermenu->append(*menuitem_createOrder);
    
    //         VIEW ORDER
    // Append VIEW order to the server menu
    Gtk::MenuItem *menuitem_viewOrderS = Gtk::manage(new Gtk::MenuItem("_View order", true));
    menuitem_viewOrderS->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::server_run), 5));
    servermenu->append(*menuitem_viewOrderS);
    
    //     CUSTOMER
    // Create a CUSTOMER menu and add to the menu bar
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menubar->append(*menuitem_customer);
    Gtk::Menu *customermenu = Gtk::manage(new Gtk::Menu());
    menuitem_customer->set_submenu(*customermenu);
    
    //         VIEW SERVING
    // Append VIEW serving to the customer menu
    Gtk::MenuItem *menuitem_viewServing = Gtk::manage(new Gtk::MenuItem("_View Servings", true));
    menuitem_viewServing->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::customer_run), 1));
    customermenu->append(*menuitem_viewServing);
    
    //         VIEW ORDER
    // Append VIEW order to the customer menu
    Gtk::MenuItem *menuitem_viewOrder = Gtk::manage(new Gtk::MenuItem("_View Order", true));
    menuitem_viewOrder->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::customer_run), 2));
    customermenu->append(*menuitem_viewOrder);
    
    //         CREATE SERVING
    // Append CREATE serving to the customer menu
    Gtk::MenuItem *menuitem_createServingcust = Gtk::manage(new Gtk::MenuItem("_Create Serving", true));
    menuitem_createServingcust->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::customer_run), 4));
    customermenu->append(*menuitem_createServingcust);
    
    //         CREATE ORDER
    // Append CREATE order to the customer menu
    Gtk::MenuItem *menuitem_createOrdercust = Gtk::manage(new Gtk::MenuItem("_Create Order", true));
    menuitem_createOrdercust->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::customer_run), 3));
    customermenu->append(*menuitem_createOrdercust);
    
    //     CREDITS
    // Create a CREDITS menu and add to the menu bar
    Gtk::MenuItem *menuitem_credits = Gtk::manage(new Gtk::MenuItem("_Credits", true));
    menubar->append(*menuitem_credits);
    Gtk::Menu *creditsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_credits->set_submenu(*creditsmenu);
    
    //         VIRW LINKS
    // Append VIEW LINKS to the CREDITS menu
    Gtk::MenuItem *menuitem_viewc = Gtk::manage(new Gtk::MenuItem("_View Links", true));
    menuitem_viewc->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::credits_run), 1));
    creditsmenu->append(*menuitem_viewc);
    
    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);
    
    //     EXIT
    // Add a new exit icon
    Gtk::ToolButton *exit = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::CLOSE));
    exit->set_tooltip_markup("Exit the program");
    exit->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::end));
    toolbar->append(*exit);
    
    //     CREATE SERVER
    // Add a new server icon
    Gtk::ToolButton *newServer = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::CLEAR));
    newServer->set_tooltip_markup("As a manager, create a new server");
    newServer->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::manager_run), 7));
    toolbar->append(*newServer);
    
    //     CREATE SERVING
    // Add a new serving icon
    Gtk::ToolButton *newServing = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::INDEX));
    newServing->set_tooltip_markup("As a server, create a new serving");
    newServing->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_window::server_run), 1));
    toolbar->append(*newServing);
    
    //     HELP
    // Add a new help icon
    Gtk::ToolButton *help = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::DIALOG_QUESTION));
    help->set_tooltip_markup("Help");
    help->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::help));
    toolbar->append(*help);
    
    Gtk::Image* image1 = Gtk::manage(new Gtk::Image("mainmenu.jpg"));
    vbox->pack_start(*image1, true, true);
    
    /*
    Gtk::Button *b = Gtk::manage(new Gtk::Button());
    b->add_label("Manager");
    b->set_border_width(100);
    vbox->pack_start(*b);
    b->set_alignment(.5,0);
    b->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::manager_run));
    
    Gtk::Button *b2 = Gtk::manage(new Gtk::Button());
    b2->add_label("Customer (not functional yet)");
    b2->set_border_width(100);
    vbox->pack_start(*b2);
    b2->set_alignment(.5,0);
    b2->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::test2));
    
    Gtk::Button *b3 = Gtk::manage(new Gtk::Button());
    b3->add_label("Server (not functional yet)");
    b3->set_border_width(100);
    vbox->pack_start(*b3);
    b3->set_alignment(.5,0);
    b3->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::test2));
    
    Gtk::Button *b4 = Gtk::manage(new Gtk::Button());
    b4->add_label("Exit");
    b4->set_border_width(100);
    vbox->pack_start(*b4);
    b4->set_alignment(.5,0);
    b4->signal_clicked().connect(sigc::mem_fun(*this,&Main_window::end));
     */
    
    vbox->show_all();
    
}

void Main_window::credits_run(int cmd)
{
    std::string s;
    s += "Menu image: https://wallpaperscraft.com/image/tsubasa_reservoir_chronicle_mokona_anime_bunny_ice_cream_34016_2560x1600.jpg\n";
    s += "Container image: https://www.zak.com/assets/images/cat/cat-og/cat_zak_ice_cream_keeper.jpg\n";
    s += "Strawberry flavor: https://www.braums.com/wp-content/uploads/2012/02/2132-strawberry.png\n";
    s += "Scooper: https://upload.wikimedia.org/wikipedia/commons/thumb/a/a4/Kitchen-Scooper-Large.jpg/1200px-Kitchen-Scooper-Large.jpg\n";
    s += "Sprinkles: http://cdn.shopify.com/s/files/1/0949/0582/products/sprinkle-medleys-all-kinds-of-happy-sprinkle-medley-1_grande.jpg?v=1478916371\n";
    Dialogs::message(s, "Image sources");
}

void Main_window::end()
{
    exit(0);
}

void Main_window::server_run(int cmd)
{
    try
    {
        controller.server_cmd(cmd);
    }
    catch(exception& e)
    {
        Dialogs::message(e.what(), "ERROR");
    }
}

void Main_window::manager_run(int cmd)
{
    controller.manager_cmd(cmd);
}

void Main_window::customer_run(int cmd)
{
    try
    {
        controller.customer_cmd(cmd);
    }
    catch(exception& e)
    {
        Dialogs::message(e.what(), "ERROR");
    }
}

void Main_window::file_run(int cmd)
{
    controller.file_cmd(cmd);
}

void Main_window::owner_run(int cmd)
{
    controller.owner_cmd(cmd);
}

void Main_window::help()
{
    controller.help();
}

AboutWindow::AboutWindow()
{
    this->set_default_size(100, 100);
    this->set_title("About");
    
    lbl_.set_label("About label");
    this->add(lbl_);
    
    this->show_all_children();
}

AboutWindow::~AboutWindow()
{
    
}

void Main_window::test2()
{
    aboutw_ = new AboutWindow;
    //aboutw_->signal_hide().connect(sigc::mem_fun(*this, &Main_window::));
    aboutw_->show();
}



Main_window::~Main_window() { }
