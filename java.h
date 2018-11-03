#ifndef __JAVA_H
#define __JAVA_H
#include "product.h"
#include <vector>
#include <string>

enum Shot {None, Chocolate, Vanilla, Peppermint, Hazelnut};
class Java: public Product {
public:
Java(std::string name, double price, double cost, int darkness);
void add_shot(Shot shot);
protected:
int _darkness;
std::vector<Shot> _shots;
};
#endif
