#include "vector.hpp"

int main()
{

   const int u  = 8;
    size_t o = 5;
    ft::vector<int> _default(5, 10);
    ft::vector<int> _default2(30, 88);
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
    ft::vector<int>::iterator iter2 = _default2.begin();
    ft::vector<int>::iterator iters2 = _default2.begin();

    ft::vector<int> copy(_default);
    ft::vector<int> test(12, 12);
    //_default.resize(7, 155);
    //_default = _default2;
    std::cout << "empty ? " << test.empty() << std::endl;
    iter ++; 
    iter ++; 
    iter ++; 
    iters2 += 18;
    _default.insert(iter, 100, 2);
    //_default.insert(iter, iter2, iters2);
    iter = _default.begin();
    std::cout << (_default >= _default2); 
 /*  std::cout << "default" << _default << std::endl;
   std::cout << "default 2 " << _default2 << std::endl;
  //  _default.swap(_default2);
    std::cout << "default" << _default << std::endl;
   std::cout << "default 2 " << _default2 << std::endl;*/
  // std::cout << _default << std::endl;
    return(0);
}