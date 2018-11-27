#pragma once
#include "product.h"
#include <vector>

class Order
{

  public:
    Order();
    int order_number() const;
    void add_product(Product *product);
    bool paid() const;
    void pay() const;
    bool filled() const;
    void fill() const;
    bool discarded() const;
    void discarded();
    bool pending();
    bool completed();
    double profit();
    friend std::ostream &operator<<(std::ostream &ost, const Order &order);

  private:
    static int _next_order_number;
    int _order_number;
    mutable bool _is_paid;
    mutable bool _is_filled;
    mutable bool _is_discarded;

  protected:
    std::vector<Product *> _products;
};

bool operator<(const Order &lhs, const Order &rhs);