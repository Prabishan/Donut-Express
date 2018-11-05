#ifndef MAINWIN_H
#define MAINWIN_H
#include "store.h"

#include <gtkmm.h>

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_quit_click();
        void on_view_all_click();
        void on_create_coffee_click();
        void on_create_donut_click();
    private:
    
        Store _store;
        Gtk::Label* msg;
        Gtk::MenuItem* menuitem_new_coffee;
        Gtk::MenuItem* menuitem_new_donut;
};
#endif