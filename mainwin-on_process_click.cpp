#include "mainwin.h"

void Mainwin::on_fill_click(){
     msg->set_text("");
    Gtk::Dialog *dialog = new Gtk::Dialog{"Select an Order to Fill", *this};

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
    dialog->add_button("Fill",2);
    dialog->show_all();

    int result; // of the dialog (1 = OK)

    while (true) {
        result = dialog->run();
        if (result == 0) {delete dialog; return;}
        l_current.set_text(_store.order_to_string(c_orders.get_active_row_number()));
        if(result == 2) {
            _store.filler(c_orders.get_active_row_number());
        } 
    }
}

void Mainwin::on_pay_click(){
     msg->set_text("$1000");
    Gtk::Dialog *dialog = new Gtk::Dialog{"Select an Order to Pay", *this};

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
    dialog->add_button("Pay", 2);
    dialog->show_all();

    int result; // of the dialog (1 = OK)

    while (true) {
        result = dialog->run();
        if (result == 0) {delete dialog; return;}
        l_current.set_text(_store.order_to_string(c_orders.get_active_row_number()));
         if(result == 2) {
            _store.payer(c_orders.get_active_row_number());
        } 
    }
    
}

void Mainwin::on_delete_click() {
     msg->set_text("");
    Gtk::Dialog *dialog = new Gtk::Dialog{"Select an Order to Discard", *this};

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
    dialog->add_button("Discard", 2);
    dialog->show_all();

    int result; // of the dialog (1 = OK)

    while (true) {
        result = dialog->run();
        if (result == 0) {delete dialog; return;}
        l_current.set_text(_store.order_to_string(c_orders.get_active_row_number()));
        if(result == 2){
             _store.remover(c_orders.get_active_row_number());
        }
    }
}