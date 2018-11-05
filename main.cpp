#include "mainwin.h"
#include <gtkmm.h>

int main(int argc, char *argv[]) {
   // Gtk::Main kit(argc, argv);
   auto app = Gtk::Application::create(argc,argv,"edu.uta.cse1325.de");
    
    Mainwin win;
    win.set_title("Java and Donut Express(JADE)");
    return app->run(win);
}