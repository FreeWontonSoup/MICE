#ifndef controller_gui_h
#define controller_gui_h
#include <iostream>
#include "view_gui.h"
#include "emporium.h"

class Controller_Gui
{
private:
    Emporium &emp;
    View_Gui view;
public:
    Controller_Gui(Emporium &e) : emp{e}, view(View_Gui(emp)) {}
    void cli();
    void pick_category(int cmd);
    void manager_cmd(int cmd);
    void server_cmd(int cmd);
    void customer_cmd(int cmd);
    void file_cmd(int cmd);
    void owner_cmd(int cmd);
    void help();
    friend class Main_window;
};

#endif
