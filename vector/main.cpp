#include <iostream>
#include "vector.hpp"

int main()
{

   const int u  = 8;
    size_t o = 5;
    ft::vector<int> _default(5, 10);
    ft::vector<int>::iterator it = _default.begin();
    ft::vector<int>::iterator ite = _default.end();
    ft::vector<int> range(it, ite);
    _default.push_back(12);
    _default.push_back(12);
    _default.pop_back();
    _default.pop_back();
    _default.pop_back();
    ft::vector<int>::iterator iter = _default.begin();
    ft::vector<int>::iterator iters = _default.begin();
    ft::vector<int> copy(_default);
    ft::vector<int> test(12, 12);
    _default.resize(7, 155);
    //i3 = f;
    std::cout << "empty ? " << test.empty() << std::endl;
    iter ++; 
    iter ++; 
    iter ++; 
    //iter = iter + iters;
    _default.insert(iter, 2, 4);
    iter = _default.begin();
    for (ft::vector<int>::iterator end = _default.end(); iter < end; iter++)
    {
        std::cout << *iter << std::endl;
    }
    return(0);
    //std::cout << std::string::npos  + 1 << std::endl;
}