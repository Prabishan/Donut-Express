#include "java.h"

Java::Java(std::string name, double price, double cost, int darkness) : Product{name,price,cost}, _darkness{darkness} {}

void Java::add_shot(Shot shot){
    _shots.push_back(shot);
}
std::string Java::to_string(){
    std::vector<std::string> darkness_to_string = {"Blonde", "Light", "Medium", "Dark", "Extra Dark"};
    std::string result = Product::to_string() + " (" + darkness_to_string[_darkness] + ") with";
    std::string seperator = "";
    for (auto s : _shots) {result += seperator + shot_to_string[s]; seperator = ", ";}
    return result;
}