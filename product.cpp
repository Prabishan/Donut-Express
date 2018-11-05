#include "product.h"


Product::Product(std::string name, double price, double cost): _name{name}, _price{price}, _cost{cost}{ }

std::string Product::name(){
    return _name;
}

std::string Product::to_string(){

}

