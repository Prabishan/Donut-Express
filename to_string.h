#ifndef _TO_STRING_H
#define _TO_STRING_H

#include <ostream>
#include <sstream>

template<class T>
std::string to_string(const T& t) {
    std::ostringstream os;
    os<< t;
    return os.str();
}
#endif