#include "product.h"
#include "donut.h"
#include "java.h"
int main(){
bool a = false;
    Donut d ("a", 5.0, 6.0, Frosting::chocolate_top,a,Filling::Bavarian);
    d.to_string();
    return 0;
}