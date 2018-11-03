#ifndef _DONUT_H
#define _DONUT_H
#include "product.h" 
#include <string>

enum Frosting{Unfrosted, chocolate_top, Vanilla_top, Pink_top};
enum Filling {Unfilled, Creme, Bavarian, Strawberry};
class Donut: public Product {
public:
Donut(std::string name, double price, double cost, Frosting frosting, bool sprinkles, Filling filling);
virtual std::string to_string() override;
protected:
Frosting _frosting;
bool _sprinkles;
Filling _filling;
};
#endif