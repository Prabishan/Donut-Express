#ifndef _STORE_H
#define _STORE_H
#include "product.h"
#include "customer.h"
#include <vector>
class Store{

    public:
        Store(std::string store_name);
        std::string name();
        //product functions
        void add_product(Product* product);
        int number_of_products();
        std::string product_to_string(int product);
        //customer functions
        void add_product(Customer* customer);
        int number_of_customers();
        std::string customer_to_string(int customer);
        friend std::ostream& operator<<(std::ostream& ost, Store& store);

    private:
        std::string _name;
        std::vector<Product*> _products;
        std::vector<Customer*> _customers;
};
#endif