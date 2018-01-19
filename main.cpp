//
//  main.cpp
//  hw07
//
//  Created by Brandon Carter on 10/20/17.
//  Copyright © 2017 Brandon Carter. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "controller.h"
#include "emporium.h"
#include <gtkmm.h>
#include "dialogs.h"
#include "main_window.h"
#include "controller_gui.h"

int main(int argc, char * argv[])
{
    
    Emporium emp;
    Controller_Gui controller{emp};
    //controller.cli();
    
    Gtk::Main kit(argc, argv);
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "");
    Main_window win{controller};
    win.set_title("CSE1325 Emporium Management System");
    app->run(win);
    return 0;
}
