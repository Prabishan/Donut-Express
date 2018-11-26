#include "mainwin.h"


int Mainwin::select_from_vector(std::vector<std::string> names, std::string title) {

	Gtk::Dialog *dialog_index = new Gtk::Dialog{"Select " + title, *this};
	const int WIDTH = 15;

	// Container
	Gtk::HBox b_index;

	Gtk::Label l_index{title + ":"};
	l_index.set_width_chars(WIDTH);
	b_index.pack_start(l_index, Gtk::PACK_SHRINK);

	// Create dropdown list
	Gtk::ComboBoxText c_index;
	c_index.set_size_request(WIDTH*10);
	for (std::string s : names) c_index.append(s);
	b_index.pack_start(c_index, Gtk::PACK_SHRINK);
	dialog_index->get_vbox()->pack_start(b_index, Gtk::PACK_SHRINK);

	// Show dialog_index
	dialog_index->add_button("Cancel", 0);
	dialog_index->add_button("OK", 1);
	dialog_index->show_all();
    int result;
    while(true){
        result = dialog_index->run();
        if(result==0){ delete dialog_index; return -1;}
        return c_index.get_active_row_number();
    }
	/*if (dialog_index.run() != 1) return -1;

	int index = c_index.get_active_row_number();

	dialog_index.close();

	return index;*/
}