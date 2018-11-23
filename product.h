#pragma once
#include <string>
#include <ostream>

class Product {
  public:
    Product(std::string name, double price, double cost);
    std::string name();
    virtual std::string to_string();
   // friend std::ostream& operator<<(std::ostream& ost, const Product& product);
  protected:
    std::string _name;
    double _price;
    double _cost;
};
