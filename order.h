#pragma once
#include "product.h"
#include <vector>

class Order {


    public:
        Order();
        int order_number() const;
        void add_product(Product* product);
        bool paid() const;
        void pay();
        bool filled() const;
        void fill();
        friend std::ostream& operator<<(std::ostream& ost, const Order& order);
    private:
       static int _next_order_number;
        int _order_number;
        bool _is_paid;
        bool _is_filled;
    protected:
        std::vector<Product*> _products;
};
 
 bool operator<(const Order& lhs, const Order& rhs);