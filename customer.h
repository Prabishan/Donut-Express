#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <string>
#include <ostream>
#include <istream>
class Customer {
    public:
        Customer(std::string customer, std::string customer_phone);
        Customer();
        Customer(std::istream& ist);
        void save(std::ostream& ost);
        std::string to_string();
    private:
        std::string _customer;
        std::string customer_phone;
};
#endif