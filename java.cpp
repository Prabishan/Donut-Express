#include "java.h"

Java::Java(std::string name, double price, double cost, int darkness) : Product(name,price,cost), _darkness{darkness} {}

void add_shot(Shot shot){
    return;
}