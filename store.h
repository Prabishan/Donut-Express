#ifndef _STORE_H
#define _STORE_H
#include "product.h"
#include <vector>
class Store{

    public:
        Store(std::string store_name);
        std::string name();
        void add_product(Product* product);
        int number_of_products();
        std::string product_to_string(int product);

        friend std::ostream& operator<<(std::ostream& ost, Store& store);

    private:
        std::string _name;
        std::vector<Product*> _products;
};
#endif