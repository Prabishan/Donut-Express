#include "order.h"

    int Order::_next_order_number =0;

    Order::Order() : _order_number {_next_order_number++}, _is_paid{false}, _is_filled{false} { }

    int Order::order_number() const{
        return _order_number;

    }

    void Order::add_product(Product* product) {
        _products.push_back(product);    
    }

    bool Order::paid() const{
        return _is_paid;
    }

    void Order::pay(){
        _is_paid = true;
    }

    bool Order::filled() const{
        return _is_filled;
    }

    void Order::fill(){
        _is_filled =true;
    }

    std::ostream& operator<<(std::ostream& ost, const Order& order) {
    ost << "Order #" << order._order_number << ":";
    std::string separator = "\n  ";
    for (auto p : order._products) {
        ost << separator << p->to_string();
    }
    return ost;
    }

    bool operator<(const Order& lhs, const Order& rhs) {
    return lhs.order_number() < rhs.order_number();
}
