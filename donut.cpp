#include "donut.h"
#include <iostream>


Donut::Donut(std::string name, double price, double cost, Frosting frosting,bool sprinkles,Filling filling) 
    :Product(name,price,cost), _frosting{frosting}, _sprinkles{sprinkles}, _filling{filling} { }

std::string Donut::to_string() {
    return "a";
}