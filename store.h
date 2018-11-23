#pragma once
#include "product.h"
#include "customer.h"
#include "order.h"
#include <vector>
#include <map>

   
  
class Store {
  public:
    Store(std::string store_name);
    Store(std::istream& ist);
    std::string name(); // Returns the store name

    void add_product(Product* product); // Add a new product to stock
    int number_of_products(); // # of products defined
    Product* get_product(int product);
    std::string product_to_string(int product); // string version of a product

    void add_customer(Customer* customer); // Add a new customer to the list
    int number_of_customers();  // # of customers on the list
    std::string customer_to_string(int customer); // string version of a customer

    void place_order(Order order, int customer); // place a new order
    int number_of_orders(); // number of order defined
    std::string order_to_string(int order_number); //string version of order
    void save(std::ostream& ost);
    //void add_productstr(int np);
    friend std::ostream& operator<<(std::ostream& ost, Store& store); 
  private:
    std::string _name;
    std::vector<Product*> _products;
    std::vector<Customer*> _customers;
    std::map<Order, Customer> _orders;
};
