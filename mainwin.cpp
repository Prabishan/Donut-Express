#include "mainwin.h"
#include "java.h"
#include "donut.h"
#include <ostream>
#include <iostream>


Mainwin::Mainwin() : _store{Store{"JADE"}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////
    set_title("Java and Donut Express (JADE)");
    set_default_size(800, 600);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    filemenu->append(*menuitem_quit);
    
    //          V I E W
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //         A L L  P R O D U C T S
    // Append All-Products to the view menu
    Gtk::MenuItem *menuitem_allProduct = Gtk::manage(new Gtk::MenuItem("_All Product", true));
    menuitem_allProduct->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_all_click));
    viewmenu->append(*menuitem_allProduct);
    //         Customers menu 
    Gtk::MenuItem *menuitem_allCustomer = Gtk::manage(new Gtk::MenuItem("_All Customer", true));
    menuitem_allCustomer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_all_click));
    viewmenu->append(*menuitem_allCustomer);

    //          C R E A T E
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*createmenu);

    //         C O F F E E
    // Append coffee to the create menu
    Gtk::MenuItem *menuitem_coffee = Gtk::manage(new Gtk::MenuItem("_Coffee", true));
    menuitem_coffee->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    createmenu->append(*menuitem_coffee);

    //         D O N U T
    // Append Donut to the Create menu
    Gtk::MenuItem *menuitem_donut = Gtk::manage(new Gtk::MenuItem("_Donut", true));
    menuitem_donut->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    createmenu->append(*menuitem_donut);

    //        C U S T O M E R
    //      Append Customer to the create menu    
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    createmenu->append(*menuitem_customer);    
    //   S T A T U S    B A R   D I S P L A Y
    // Provide a status bar for program messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->add(*msg);
    
    // Make the box and everything in it visible
    vbox->show_all();
    }
Mainwin::~Mainwin() { }

void Mainwin::on_view_all_click(){
    std::ostringstream oss;
    oss << _store << std::endl;
    Gtk::MessageDialog d{*this, oss.str()};
    int result = d.run();
}

void Mainwin::on_create_donut_click() { // Create a new donut product
   Frosting frosting = (Frosting)(rand()%frosting_to_string.size());
   Filling filling = (Filling)(rand()%filling_to_string.size());
   Donut* d = new Donut{"Donut", 0.75, 0.25, frosting, true, filling};
   _store.add_product(d);
}
void Mainwin::on_quit_click(){
    close();
}