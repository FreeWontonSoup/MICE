#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include "gtkmm.h"
#include "dialogs.h"
#include "controller.h"
#include "controller_gui.h"

class AboutWindow : public Gtk::Window
{
public:
    AboutWindow();
    ~AboutWindow();
    
protected:
    Gtk::Label lbl_;
};

class Main_window : public Gtk::Window
{
public:
    Main_window(Controller_Gui &c);
    void Main_window2();
    virtual ~Main_window();
protected:
    Gtk::Button m_button;
    void manager_run(int cmd);
    void server_run(int cmd);
    void customer_run(int cmd);
    void file_run(int cmd);
    void owner_run(int cmd);
    void credits_run(int cmd);
    void test2();
    void end();
    void help();
    AboutWindow* aboutw_;
private:
    Controller_Gui &controller;
};




#endif
