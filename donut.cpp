#include "donut.h"


Donut::Donut(std::string name, double price, double cost, Frosting frosting,bool sprinkles,Filling filling) 
    :Product{name,price,cost}, _frosting{frosting}, _sprinkles{sprinkles}, _filling{filling} { }

std::string Donut::to_string() {
    std::string result = Product::to_string();
    std::string seperator = " (";
    std::string terminator = "";
    if(_frosting != Unfrosted) {
        result += seperator + "frosted with " + frosting_to_string[_frosting];
        if(_sprinkles) result += " and sprinkles";
        seperator =", ";
        terminator = ")"; 
    }
    if(_filling != Unfilled){
        result += seperator + "filled with " + filling_to_string[_filling];
        terminator = ")";
    }
    result+=terminator;
    return result;
}