#include "../data-structures-lib/vector.h"
#include <iostream>

int main()
{
    vector v = vector(4);
    std::cout << "vector size_t constructor : " << v.capacity() << std::endl;
    vector m = vector(v);
    std::cout << "vector copy constructor : " << m.capacity() << std::endl;
    m.push_back(3);
    std::cout << "vector at operator : " << m.at(1) << std::endl;
    return 0;
}