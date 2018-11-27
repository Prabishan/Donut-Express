#include "mainwin.h"
#include "java.h"
#include "donut.h"
#include "customer.h"
#include <ostream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <regex>

Mainwin::Mainwin() : _store{Store{"JADE"}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_title("Java and Donut Express (JADE)");
    set_icon_from_file("window_logo.png");
    set_default_size(900, 600);

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
    
    //         S A V E
    // Append Save to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_save_click));
    filemenu->append(*menuitem_save);

    //         L O A D
    // Append Load to the File menu
    Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load", true));
    menuitem_load->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_load_click));
    filemenu->append(*menuitem_load);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    filemenu->append(*menuitem_quit);

    //     V I E W
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //         A L L   O R D E R S
    // Append All Orders to the File menu
    Gtk::MenuItem *menuitem_all_orders = Gtk::manage(new Gtk::MenuItem("All _Orders", true));
    menuitem_all_orders->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_orders_click));
    viewmenu->append(*menuitem_all_orders);

    //         A L L   P R O D U C T S
    // Append All Products to the File menu
    Gtk::MenuItem *menuitem_all_products = Gtk::manage(new Gtk::MenuItem("_All Products", true));
    menuitem_all_products->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_products_click));
    viewmenu->append(*menuitem_all_products);

    //         L I S T   C U S T O M E R S
    // Append List Customers to the View menu
    Gtk::MenuItem *menuitem_list_customers = Gtk::manage(new Gtk::MenuItem("_Customers", true));
    menuitem_list_customers->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_list_customers_click));
    viewmenu->append(*menuitem_list_customers);


    //     C R E A T E   
    // Create a Create menu and add to the menu bar
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*createmenu);

    //          N E W   O R D E R
    // Append Order to the Create menu
    Gtk::MenuItem *menuitem_new_orders = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_new_orders->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    createmenu->append(*menuitem_new_orders);

    //           N E W   C O F F E E
    // Append New Coffee to the Create menu
    menuitem_new_coffee = Gtk::manage(new Gtk::MenuItem("_Coffee", true));
    menuitem_new_coffee->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_coffee_click));
    createmenu->append(*menuitem_new_coffee);

    //           N E W   D O N U T
    // Append New Donut to the Create menu
    menuitem_new_donut = Gtk::manage(new Gtk::MenuItem("_Donut", true));
    menuitem_new_donut->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_donut_click));
    createmenu->append(*menuitem_new_donut);

    //           N E W   C U S T O M E R
    // Append New Customer to the Create menu
    Gtk::MenuItem *menuitem_new_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_new_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_new_customer_click));
    createmenu->append(*menuitem_new_customer);

    //           P R O C E S S
    // Create a Process menu and add to the menu bar
	Gtk::MenuItem *menuitem_process = Gtk::manage(new Gtk::MenuItem("_Process", true));
	menubar->append(*menuitem_process);
	Gtk::Menu *process_menu = Gtk::manage(new Gtk::Menu());
	menuitem_process->set_submenu(*process_menu);

	//Append Fill to the Process menu 
	menuitem_fill = Gtk::manage(new Gtk::MenuItem("_Fill Order", true));
	menuitem_fill->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_fill_click));
	process_menu->append(*menuitem_fill);

	//Append pay to the Process menu
	menuitem_pay = Gtk::manage(new Gtk::MenuItem("_Pay Order", true));
	menuitem_pay->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_pay_click));
	process_menu->append(*menuitem_pay);

    //Append Delete to the Process menu
	Gtk::MenuItem *menuitem_delete = Gtk::manage(new Gtk::MenuItem("_Delete Order", true));
	menuitem_delete->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_delete_click));
	process_menu->append(*menuitem_delete);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = 
        Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(
        sigc::mem_fun(*this, &Mainwin::on_about_click));
    helpmenu->append(*menuitem_about);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    // P R O D U C T S
    //

      //     V I E W   A L L   O R D E R S
    // View all orders currently defined
    Gtk::Image* view_orders_image = Gtk::manage(new Gtk::Image{"list_orders.png"});
    Gtk::ToolButton *view_orders_button = Gtk::manage(new Gtk::ToolButton{*view_orders_image});
    view_orders_button->set_tooltip_markup("View all orders");
    view_orders_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_view_orders_click));
    toolbar->append(*view_orders_button);

    //     C R E A T E   O R D E R
    // Create a new order
    Gtk::Image* create_order_image = Gtk::manage(new Gtk::Image{"create_order.png"});
    Gtk::ToolButton *create_order_button = Gtk::manage(new Gtk::ToolButton{*create_order_image});
    create_order_button->set_tooltip_markup("Create a new order");
    create_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    toolbar->append(*create_order_button);

    Gtk::SeparatorToolItem *sep0 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep0);

    //     F I L L   O R D E R
    // Fill a order
    Gtk::Image* fill_order_image = Gtk::manage(new Gtk::Image{"fill_order.png"});
    Gtk::ToolButton *fill_order_button = Gtk::manage(new Gtk::ToolButton{*fill_order_image});
    fill_order_button->set_tooltip_markup("Fill Order");
    fill_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_fill_click));
    toolbar->append(*fill_order_button);

    //     P A Y   O R D E R
    // Pay a order
    Gtk::Image* pay_order_image = Gtk::manage(new Gtk::Image{"pay_order.png"});
    Gtk::ToolButton *pay_order_button = Gtk::manage(new Gtk::ToolButton{*pay_order_image});
    pay_order_button->set_tooltip_markup("Pay Order");
    pay_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_pay_click));
    toolbar->append(*pay_order_button);

    //     D E l E T E   O R D E R
    // Delete a order
    Gtk::Image* delete_order_image = Gtk::manage(new Gtk::Image{"delete_order.png"});
    Gtk::ToolButton *delete_order_button = Gtk::manage(new Gtk::ToolButton{*delete_order_image});
    delete_order_button->set_tooltip_markup("Delete Order");
    delete_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_delete_click));
    toolbar->append(*delete_order_button);

    Gtk::SeparatorToolItem *sep2 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep2);

    //     V I E W   A L L   P R O D U C T S
    // View all products currently defined
    Gtk::Image* view_all_image = Gtk::manage(new Gtk::Image{"list_products.png"});
    Gtk::ToolButton *view_all_button = Gtk::manage(new Gtk::ToolButton{*view_all_image});
    view_all_button->set_tooltip_markup("View all products");
    view_all_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_view_products_click));
    toolbar->append(*view_all_button);

    //     N E W   J A V A
    // Create a new Java type
    Gtk::Image* new_java_image = Gtk::manage(new Gtk::Image{"new_java.png"});
    Gtk::ToolButton *new_java_button = Gtk::manage(new Gtk::ToolButton{*new_java_image});
    new_java_button->set_tooltip_markup("Create new Coffee");
    new_java_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_coffee_click));
    toolbar->append(*new_java_button);

    //     N E W   D O N U T
    // Create a new Donut type
    Gtk::Image* new_donut_image = Gtk::manage(new Gtk::Image{"new_donut.png"});
    Gtk::ToolButton *new_donut_button = Gtk::manage(new Gtk::ToolButton{*new_donut_image});
    new_donut_button->set_tooltip_markup("Create new Donut");
    new_donut_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_donut_click));
    toolbar->append(*new_donut_button);

    Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep1);

    // C U S T O M E R S
    //
    //      L I S T   C U S T O M E R S
    // List customers icon
    Gtk::Image *list_customers_image = Gtk::manage(new Gtk::Image{"list_customers.png"});
    Gtk::ToolButton *list_customers_button = Gtk::manage(new Gtk::ToolButton(*list_customers_image));
    list_customers_button->set_tooltip_markup("List all customers");
    list_customers_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_list_customers_click));
    toolbar->append(*list_customers_button);

    //     N E W   C U S T O M E R
    // Add a new customer icon
    Gtk::Image *new_customer_image = Gtk::manage(new Gtk::Image{"new_customer.png"});
    Gtk::ToolButton *new_customer_button = Gtk::manage(new Gtk::ToolButton(*new_customer_image));
    new_customer_button->set_tooltip_markup("Create a new customer");
    new_customer_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_new_customer_click));
    toolbar->append(*new_customer_button);

    Gtk::SeparatorToolItem *sep3 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep3);

    //     N E W   R O L E
    // Add a New Role Icon
    Gtk::Image *select_role_image = Gtk::manage(new Gtk::Image{"select_role.png"});
    Gtk::ToolButton *select_role_button = Gtk::manage(new Gtk::ToolButton(*select_role_image));
    select_role_button->set_tooltip_markup("Select New Role");
    select_role_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_select_role_click));
    toolbar->append(*select_role_button);

    // M A I N   A R E A
    Gtk::Label* main_area = Gtk::manage(new Gtk::Label);
    main_area->set_hexpand(true);    
    main_area->set_vexpand(true);
    vbox->add(*main_area);

    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for program messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->add(*msg);


    // Make the box and everything in it visible
    vbox->show_all();
    
    on_select_role_click();

    
    
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_view_orders_click() { // Select an order to view
    msg->set_text("");
    Gtk::Dialog *dialog = new Gtk::Dialog{"Select an Order", *this};

    // Show selected order 
    Gtk::Label l_current;
    dialog->get_vbox()->pack_start(l_current, Gtk::PACK_SHRINK);

    // List orders
    Gtk::HBox b_orders;

    Gtk::Label l_orders{"Order:"};
    l_orders.set_width_chars(15);
    b_orders.pack_start(l_orders, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_orders;
    for(int i=0; i<_store.number_of_orders(); ++i) {
        c_orders.append(std::to_string(i));
    }
    b_orders.pack_start(c_orders, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_orders, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Close", 0);
    dialog->add_button("Show", 1);
    dialog->show_all();

    int result; // of the dialog (1 = OK)

    while (true) {
        result = dialog->run();
        if (result == 0) {delete dialog; return;}
        l_current.set_text(_store.order_to_string(c_orders.get_active_row_number()));
    }
}

void Mainwin::on_view_products_click() { // View all products
    msg->set_text("");
    std::ostringstream oss;
    oss << _store << std::endl;
    Gtk::MessageDialog d{*this, "List of Products"}; 
    d.set_secondary_text(oss.str());
    int result = d.run();

}

void Mainwin::on_new_customer_click() {
    Gtk::Dialog *dialog = new Gtk::Dialog("Create a Customer", *this);

    // Name
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(15);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    // Phone Number
    Gtk::HBox b_phone;

    Gtk::Label l_phone{"Phone:"};
    l_phone.set_width_chars(15);
    b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

    Gtk::Entry e_phone;
    e_phone.set_max_length(50);
    b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("Create", 1);
    dialog->show_all();

    int result;
    std::string name, phone;
    std::regex re_phone{"[(]?(\\d{3,3}[-)])?\\d{3,3}-\\d{4,4}"};
    bool fail = true;  // set to true if any data is invalid

    while (fail) {
        fail = false;  // optimist!
        result = dialog->run();
        if (result != 1) {delete dialog; return;}
        name = e_name.get_text();
        if (name.size() == 0) {
            e_name.set_text("### Invalid ###");
            fail = true;
        }
        phone = e_phone.get_text();
        if(!std::regex_match(phone,re_phone)) {
            e_phone.set_text("### Invalid ###");
            fail = true;
        }        
    }
    Customer* customer = new Customer{name, phone};
    _store.add_customer(customer);

    delete dialog;
}

void Mainwin::on_list_customers_click() {
    msg->set_text("");
    std::ostringstream oss;
    for (int i=0; i<_store.number_of_customers(); ++i) {
        oss <<  _store.customer_to_string(i) << std::endl;
    }
    Gtk::MessageDialog d{*this, "List of Customers"};
    d.set_secondary_text(oss.str());
    int result = d.run();
}

void Mainwin::on_save_click() {

    Gtk::Dialog dlg{"Enter File Name", *this};
	dlg.set_default_size(250,10);
    Gtk::Entry e;
    dlg.get_vbox()->pack_start(e, Gtk::PACK_SHRINK);

    dlg.add_button("Save", 1);

    dlg.show_all();
    dlg.run();

	bool valid_data = false;

	while(!valid_data) {
		if(e.get_text()=="" || e.get_text() == "*Invalid Name*") {
			valid_data = false;
			e.set_text("*Invalid Name*");
			dlg.run();
		} else valid_data = true;
	}

    std::string s = e.get_text() + ".txt";

    dlg.close();

	try {
        std::ofstream ofs{s,std::ofstream::out};
        _store.save(ofs);
    } catch (std::exception& e) {
        Gtk::MessageDialog dialog{*this, "Unable to save "+ s};
        dialog.set_secondary_text(e.what());
        dialog.run();
        dialog.close();
    }


}

void Mainwin::on_load_click() {
	Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FILE_CHOOSER_ACTION_OPEN);
  	dialog.set_transient_for(*this);

  	//Add response buttons the the dialog:
  	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  	dialog.add_button("_Open", Gtk::RESPONSE_OK);

	//Show the dialog and wait for a user response:
	int result = dialog.run();
	std::string filename;

	//Handle the response:
	switch(result)
	{
	  case(Gtk::RESPONSE_OK):
	  {
		std::cout << "Open clicked." << std::endl;

		//Notice that this is a std::string, not a Glib::ustring.
		filename = dialog.get_filename();
		std::cout << "File selected: " <<  filename << std::endl;
		break;
	  }
	  case(Gtk::RESPONSE_CANCEL):
	  {
		std::cout << "Cancel clicked." << std::endl;
		break;
	  }
	  default:
	  {
		std::cout << "Unexpected button clicked." << std::endl;
		break;
	  }
	}

	try {
        std::ifstream ifs{filename, std::ifstream::in};
	//	all_pnl.push_back(emp.get_pnl_report());
		Store new_str{ifs};
        _store = new_str;
    } catch (std::exception& e) {
        Gtk::MessageDialog dialog{*this, "Unable to open file"};
        dialog.set_secondary_text(e.what());
        dialog.run();
        dialog.close();
    }

}

void Mainwin::on_select_role_click(){
    Glib::ustring s = "Active Person: ";

    std::vector<std::string> names;
	names.push_back("Owner");
	names.push_back("Manager");
	names.push_back("Server");
	names.push_back("Customer");

	int role = select_from_vector(names, "Role");
   // if(role == -1) close();
          /*  if(role == 0){
			s = s + "Owner";
			//menuitem_new->set_sensitive(true);;
            menuitem_file->set_sensitive(true);
			menuitem_save->set_sensitive(true);
			menuitem_load->set_sensitive(true);
            menuitem_quit->set_sensitive(true);
        
			menuitem_view->set_sensitive(true);;
			menuitem_all_orders->set_sensitive(true);
			menuitem_all_products->set_sensitive(true);
			menuitem_list_customers->set_sensitive(true);

			menuitem_create->set_sensitive(true);
			menuitem_new_orders->set_sensitive(true);
			menuitem_new_coffee->set_sensitive(true);
			menuitem_new_donut->set_sensitive(true);

			menuitem_new_customer->set_sensitive(true);
			menuitem_process->set_sensitive(true);
			menuitem_fill->set_sensitive(true);
			menuitem_pay->set_sensitive(true);
            menuitem_delete->set_sensitive(true);

            menuitem_about->set_sensitive(true);

            view_orders_button->set_sensitive(true);
            create_order_button->set_sensitive(true);
            fill_order_button->set_sensitive(true);
            pay_order_button->set_sensitive(true);
            delete_order_button->set_sensitive(true);
            view_all_button->set_sensitive(true);
            new_java_button->set_sensitive(true);
            new_donut_button->set_sensitive(true);
            list_customers_button->set_sensitive(true);
            new_customer_button->set_sensitive(true);
            select_role_button->set_sensitive(true);			
			//break;
		}/*
		case 1: {
			s += "Manager";

			//menuitem_new->set_sensitive(true);;
			menuitem_save->hide();
			menuitem_load->hide();
            menuitem_quit->set_sensitive(true);;

			menuitem_view->set_sensitive(true);;
			menuitem_all_orders->set_sensitive(true);;
			menuitem_all_products->set_sensitive(true);;
			menuitem_list_customers->set_sensitive(true);;

			menuitem_create->set_sensitive(true);;
			menuitem_new_orders->set_sensitive(true);;
			menuitem_new_coffee->set_sensitive(true);;
			menuitem_new_donut->set_sensitive(true);;
			menuitem_new_customer->set_sensitive(true);;

			menuitem_process->set_sensitive(true);;
			menuitem_fill->set_sensitive(true);;
			menuitem_pay->set_sensitive(true);;
            menuitem_delete->set_sensitive(true);;

            menuitem_about->set_sensitive(true);;

            view_orders_button->set_sensitive(true);;
            create_order_button->set_sensitive(true);;
            fill_order_button->set_sensitive(true);;
            pay_order_button->set_sensitive(true);;
            delete_order_button->set_sensitive(true);;
            view_all_button->set_sensitive(true);;
            new_java_button->set_sensitive(true);;
            new_donut_button->set_sensitive(true);;
            list_customers_button->set_sensitive(true);;
            new_customer_button->set_sensitive(true);;
            select_role_button->set_sensitive(true);;	

			break;
		}
		case 2: {
			s += "Server";

			//menuitem_new->set_sensitive(true);;
			menuitem_save->hide();
			menuitem_load->hide();
            menuitem_quit->set_sensitive(true);;

			menuitem_view->set_sensitive(true);;
			menuitem_all_orders->set_sensitive(true);;
			menuitem_all_products->set_sensitive(true);;
			menuitem_list_customers->set_sensitive(true);;

			menuitem_create->set_sensitive(true);;
			menuitem_new_orders->hide();
			menuitem_new_coffee->set_sensitive(true);;
			menuitem_new_donut->set_sensitive(true);;
			menuitem_new_customer->hide();
            
			menuitem_process->set_sensitive(true);;
			menuitem_fill->set_sensitive(true);;
			menuitem_pay->set_sensitive(true);;
            menuitem_delete->set_sensitive(true);;

            menuitem_about->set_sensitive(true);;

            view_orders_button->set_sensitive(true);;
            create_order_button->hide();
            fill_order_button->set_sensitive(true);;
            pay_order_button->set_sensitive(true);;
            delete_order_button->set_sensitive(true);;
            view_all_button->set_sensitive(true);;
            new_java_button->set_sensitive(true);;
            new_donut_button->set_sensitive(true);;
            list_customers_button->set_sensitive(true);;
            new_customer_button->hide();
            select_role_button->set_sensitive(true);;	

			break;
		}
		case 3: {
			s = "Customer";

			menuitem_save->hide();
			menuitem_load->hide();
            menuitem_quit->set_sensitive(true);;

			menuitem_view->set_sensitive(true);;
			menuitem_all_orders->hide();
			menuitem_all_products->set_sensitive(true);;
			menuitem_list_customers->hide();

			menuitem_create->hide();
			menuitem_new_orders->hide();
			menuitem_new_coffee->hide();
			menuitem_new_donut->hide();
			menuitem_new_customer->hide();
            
			menuitem_process->hide();
			menuitem_fill->hide();
			menuitem_pay->hide();
            menuitem_delete->hide();

            menuitem_about->set_sensitive(true);;

            view_orders_button->hide();
            create_order_button->hide();
            fill_order_button->hide();
            pay_order_button->hide();
            delete_order_button->hide();
            view_all_button->set_sensitive(true);;
            new_java_button->hide();
            new_donut_button->hide();
            list_customers_button->hide();
            new_customer_button->hide();
            select_role_button->set_sensitive(true);;

			break;
		}
		default : std::cerr << "Invalid Choice" << '\n'; break;
	}*/

}

// /////////
// Help Menu

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog{};
    dialog.set_transient_for(*this);
    dialog.set_program_name("Java and Donut Express");
    auto logo = Gdk::Pixbuf::create_from_file("logo.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 0.2.0");
    dialog.set_copyright("Copyright 2018");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"George F. Rice"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "JADE Logo is licensed under the Creative Commons Attribution Share-Alike 3.0 License by SaxDeux https://commons.wikimedia.org/wiki/File:Logo_JADE.png", 
        "Flat Coffee Cup Icon is licensed under the Creative Commons Attribution 3.0 License by superawesomevectors http://fav.me/dbf6otc",
        "Donut Icon is public domain by Hazmat2 via Hyju https://en.wikipedia.org/wiki/File:Simpsons_Donut.svg",
        "Person Icon is licensed under the Creative Commons 0 (Public Domain) License by Clker-Free-Vector-Images https://pixabay.com/en/man-user-profile-person-icon-42934/"
    };
    dialog.set_artists(artists);
    dialog.run();
}

void Mainwin::on_quit_click() {         // Exit the program
    close();
}

// /////////////////
// U T I L I T I E S
// /////////////////


