#include "customer.h"

Customer::Customer(std::string customer, std::string customer_phone)
: _customer{customer}, customer_phone{customer_phone} {}
Customer::Customer() : Customer("","") { }
Customer::Customer(std::istream& ist) {
    std::getline(ist, _customer);
    std::getline(ist, customer_phone);
}

void Customer::save(std::ostream& ost) {
    ost << _customer << std::endl;
    ost << customer_phone << std::endl;    
}

std::string Customer::to_string() {
    return _customer + ", " + customer_phone;
}

