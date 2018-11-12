#ifndef __JAVA_H
#define __JAVA_H
#include "product.h"
#include <vector>
#include <ostream>

enum Shot {None, Chocolate, Vanilla, Peppermint, Hazelnut};
std::vector<std::string> shot_to_string = {"none", "chocolate", "vanilla", "peppermint", "hazelnut"};
class Java: public Product {
    public:
        Java(std::string name, double price, double cost, int darkness);
        void add_shot(Shot shot);
        std::string to_string() override;
    protected:
        int _darkness;
        std::vector<Shot> _shots;
};
#endif
