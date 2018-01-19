#ifndef controller_h
#define controller_h
#include <iostream>
#include "view.h"
#include "emporium.h"

class Controller
{
private:
    Emporium &emp;
    View view;
public:
    Controller(Emporium &e) : emp{e}, view(View(emp)) {}
    void cli();
    void pick_category(int cmd);
    void manager_cmd();
    friend class Main_window;
};

#endif
