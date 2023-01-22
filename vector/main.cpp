#include "vector.hpp"

#define T1 char

int main()
{
    TESTED_NAMESPACE::vector<T1> v;

        v.assign(0, 'c');
        v.assign(64, 'A');
        v.assign(32, '5');
        v.assign(49, '8');
        v.assign(77, '2');


    return(0);
}