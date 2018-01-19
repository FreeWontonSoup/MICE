#include "controller.h"
#include "view.h"

void Controller::cli() {
    int cmd = -1;
    
    while (cmd != 0) {
        view.show_menu();
        std::cout << "What role are you?" << std::endl;
        std::cin >> cmd;
        //std::cin.ignore(); // consume \n
        pick_category(cmd);
    }
}

void Controller::manager_cmd()
{
    int cmd = -1;
    while(cmd != 0)
    {
        view.show_manager_menu();
        std::cout << "What would you like to do? ";
        std::cin >> cmd;
        std::cin.ignore(); // consume \n
        if(cmd == 1)
        {
            //create a new flavor
            std::string flav;
            std::cout << "Enter the name of the flavor to be added: " << std::endl;
            std::getline(std::cin,flav);
            //std::cin.ignore();
            //emp.create_flavor(flav);
        }
        else if(cmd == 2)
        {
            //list current flavors;
            view.list_flavors();
        }
        else if(cmd == 3)
        {
            //create a new container
            std::string container;
            std::cout << "Enter the name of the container to be added: " << std::endl;
            std::getline(std::cin,container);
            //emp.create_container(container);
        }
        else if(cmd == 4)
        {
            //list current containers
            view.list_containers();
        }
        else if(cmd == 5)
        {
            //create new topping
            std::string top;
            std::cout << "Enter the name of the topping to be added: " << std::endl;
            std::getline(std::cin,top);
            //emp.create_topping(top);
        }
        else if(cmd == 6)
        {
            //list current toppings
            view.list_toppings();
        }
        else if(cmd == 0)
        {
            break;
        }
    }
}

void Controller::pick_category(int cmd)
{
    
    if(cmd == 1)
    {
        //manager category
        manager_cmd();
    }
    else if(cmd == 0)
    {
        return;
    }
    
    
    
    /*
    if (cmd == 1)
    { // Add publication
        string title, author, copyright, isbn;
        int genre, media, age;
        
        cout << "Title? ";
        getline(cin, title);
        
        cout << "Author? ";
        getline(cin, author);
        
        cout << "Copyright date? ";
        getline(cin, copyright);
        
        for (int i = 0; i < Genre::num_genres; ++i)
            cout << "  " << i << ") " << Genre(i).to_string() << endl;
        cout << "Genre? ";
        cin >> genre;
        cin.ignore(); // consume \n
        
        for (int i = 0; i < Media::num_media; ++i)
            cout << "  " << i << ") " << Media(i).to_string() << endl;
        cout << "Media? ";
        cin >> media;
        cin.ignore(); // consume \n
        
        for (int i = 0; i < Age::num_ages; ++i)
            cout << "  " << i << ") " << Age(i).to_string() << endl;
        cout << "Age? ";
        cin >> age;
        cin.ignore(); // consume \n
        
        cout << "ISBN? ";
        getline(cin, isbn);
        
        library.add_publication(Publication(title, author, copyright, genre, media, age, isbn));
        
    }
    else if (cmd == 2)
    { // List all publications
        view.list_publications();
        
    } else if (cmd == 3) { // Check out publication
        int pub;
        string pat;
        string pat_phone;
        
        view.list_publications();
        cout << "Publication number? ";
        cin >> pub;
        cin.ignore(); // consume \n
        
        cout << "Patron name? ";
        getline(cin, pat);
        cout << "Patron phone? ";
        getline(cin, pat_phone);
        
        try {
            library.check_out(pub, pat, pat_phone);
        } catch(Publication::Invalid_transaction e) {
            cout << "ERROR: That publication is already checked out!" << endl;
        }
        
    } else if (cmd == 4) { // Check in publication
        int pub;
        view.list_publications();
        cout << "Publication number? ";
        cin >> pub;
        cin.ignore(); // consume \n
        
        try {
            library.check_in(pub);
        } catch(Publication::Invalid_transaction e) {
            cout << "ERROR: That publication is already checked in!" << endl;
        }
        
    } else if (cmd == 9) { // Help
        view.help();
    } else if (cmd == 0) { // Exit
    } else if (cmd == 99) { // Easter Egg
        library.easter_egg();
    } else {
        cerr << "**** Invalid command - type 9 for help" << endl << endl;
    }
     */
}

