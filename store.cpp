#include "store.h"
#include "to_string.h"
#include <sstream>
#include <stdexcept>
#include <iostream>

Store::Store(std::string store_name) : _name{store_name} {}

Store::Store(std::istream &ist)
{

    std::string header1, header2;
    std::getline(ist, header1);
    std::getline(ist, header2);
    if (header1 != "JADE")
        throw std::runtime_error("NOT an Store file");
    if (header2 != "0.1")
        throw std::runtime_error("Incompatible file version");
}
std::string Store::name() { return _name; }

void Store::add_product(Product *product) { _products.push_back(product); }
int Store::number_of_products() { return _products.size(); }
Product *Store::get_product(int product) { return _products[product]; }

std::string Store::product_to_string(int product)
{
    std::ostringstream oss;
    oss << _products[product];
    return oss.str();
}

void Store::add_customer(Customer *customer) { _customers.push_back(customer); }
int Store::number_of_customers() { return _customers.size(); }
std::string Store::customer_to_string(int customer)
{
    std::ostringstream oss;
    oss << *_customers[customer];
    return oss.str();
}

void Store::place_order(Order order, int customer) { _orders[order] = *_customers[customer]; } // Places a new order
int Store::number_of_orders() { return _orders.size(); }                                       // # of orders defined
std::string Store::order_to_string(int order_number)
{
    //  for (auto it : _orders) if (it.first.order_number() == order_number) return to_string(it.first) + "\n" + to_string(it.second);
    for (auto it : _orders)
    {
        if ((it.first.filled() == true) && (it.first.paid() == true))
        {
            if (it.first.order_number() == order_number)
            {
                return "(filled) and (paid)" + to_string(it.first) + "\n" + to_string(it.second);
            }
        }
        else if ((it.first.filled() == true) && (it.first.paid() == false))
        {
            if (it.first.order_number() == order_number)
            {
                return "(filled) " + to_string(it.first) + "\n" + to_string(it.second);
            }
        }
        else if ((it.first.filled() == false) && (it.first.paid() == true))
        {
            if (it.first.order_number() == order_number)
            {
                return "(paid) " + to_string(it.first) + "\n" + to_string(it.second);
            }
        }
        else if (it.first.discarded() == true)
        {
            for (auto &itt : _orders)
            {
                if (itt.first.order_number() == order_number)
                {
                    it1 = _orders.begin();
                    _orders.erase(it1);
                }
            }
        }
        else if ((it.first.filled() == false) && (it.first.paid() == false))
        {
            if (it.first.order_number() == order_number)
            {
                return "Pending" + to_string(it.first) + "\n" + to_string(it.second);
            }
        }
    }
    throw std::runtime_error{"Order " + std::to_string(order_number) + " not found"};
} // string version of an order

void Store::filler(int order_number)
{
    for (auto &itt : _orders)
    {
        if (itt.first.order_number() == order_number)
        {
            (itt.first).Order::fill();
        }
    }
}

void Store::payer(int order_number)
{
    for (auto &itt : _orders)
    {
        if (itt.first.order_number() == order_number)
        {
            (itt.first).Order::pay();
        }
    }
}
void Store::remover(int order_number)
{
    
}
std::ostream &operator<<(std::ostream &ost, Store &store)
{
    ost << "Store " << store._name << std::endl
        << std::endl;
    ost << "Products: " << std::endl;
    for (auto p : store._products)
        ost << "  " << p->to_string() << std::endl;
    return ost;
}

void Store::save(std::ostream &ost)
{
    ost << "JADE" << std::endl
        << "0.1" << std::endl;
    //ost << _name << std::endl;
}
