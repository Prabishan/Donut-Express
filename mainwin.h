#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include "store.h"
#include <iostream>
#include <sstream>

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_save_click();
        void on_load_click(); 
        void on_quit_click();            // Exit the program
        void on_view_orders_click();     // Select an order to view
        void on_view_products_click();   // view all products
        void on_fill_click();            // fill a order   
        void on_pay_click();             // pay a order
        void on_delete_click();          // delete a order
        void on_create_order_click();    // Create new order
        void on_create_coffee_click();   // Create a new coffee product
        void on_create_donut_click();    // Create a new donut product
        void on_list_customers_click();  // List all customers
        void on_new_customer_click();    // Create a new customer
        void on_select_role_click();      // Select New Role
        void on_about_click();           // About dialog

        int select_from_vector(std::vector<std::string> names, std::string title);
    private:
        Store _store;
        Gtk::Label *msg;                      // Status message display
       /* Gtk::MenuItem *menuitem_new_order;    // Create -> Order
        Gtk::MenuItem *menuitem_new_coffee;   // Create -> Coffee
        Gtk::MenuItem *menuitem_new_donut;    // Create -> Donut
        Gtk::MenuItem *menuitem_fill;         // Process -> Fill
        Gtk::MenuItem *menuitem_pay;          // Process -> Pay  
        Gtk::MenuItem *menuitem_delete;       // Process -> Delete
*/          Gtk::MenuItem *menuitem_file;
            Gtk::MenuItem *menuitem_save ;
			Gtk::MenuItem *menuitem_load ;
            Gtk::MenuItem *menuitem_quit ;
            
			Gtk::MenuItem *menuitem_view ;
			Gtk::MenuItem *menuitem_all_orders ;
			Gtk::MenuItem *menuitem_all_products ;
			Gtk::MenuItem *menuitem_list_customers;

			Gtk::MenuItem *menuitem_create;
			Gtk::MenuItem *menuitem_new_orders;
			Gtk::MenuItem *menuitem_new_coffee;
			Gtk::MenuItem *menuitem_new_donut;

			Gtk::MenuItem *menuitem_new_customer;
			Gtk::MenuItem *menuitem_process;
			Gtk::MenuItem *menuitem_fill;
			Gtk::MenuItem *menuitem_pay;
            Gtk::MenuItem *menuitem_delete;

            Gtk::MenuItem *menuitem_about;

            Gtk::MenuItem *view_orders_button;
            Gtk::MenuItem *create_order_button;
            Gtk::MenuItem *fill_order_button;
            Gtk::MenuItem *pay_order_button;
            Gtk::MenuItem *delete_order_button;
            Gtk::MenuItem *view_all_button;
            Gtk::MenuItem *new_java_button;
            Gtk::MenuItem *new_donut_button;
            Gtk::MenuItem *list_customers_button;
            Gtk::MenuItem *new_customer_button;
            Gtk::MenuItem *select_role_button;			
};
#endif 

