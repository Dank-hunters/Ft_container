#include "vector.hpp"

int main()
{

    const int u  = 8;
    size_t o = 5;
    ft::vector<int> _default(9, 10);
    ft::vector<int> _default2(15, 666);
    ft::vector<int>::iterator ita = _default.begin();
    ft::vector<int>::iterator it = _default2.begin();
    ft::vector<int>::iterator ite = _default2.end();
    ft::vector<int> range(it, ite);
   // dprintf(1, "poute");
    ft::vector<int> copy(_default);
    _default.insert(ita, it, ite);
    
 /*   copy = _default2;
    //_default.resize(150, 111);
    std::cout << "default :" << _default << std::endl;
    std::cout << "default 2 " << _default2 << std::endl;
    std::cout << "range : " << range << std::endl;
    std::cout << "copy : " << copy << std::endl;

    _default.push_back(12);
    std::cout << "default  after push_back(12) :" << _default << std::endl;
    _default.pop_back();
    std::cout << "default  after pop_back() :" << _default << std::endl;
    std::cout << "is _default is empty ? " << _default.empty() << std::endl;
    
   */
    std::cout << "_default == _default2 : " << (_default == _default2) << std::endl; 
    std::cout << "_default != _default2 : " << (_default != _default2) << std::endl; 
    std::cout << "_default >= _default2 : " << (_default >= _default2) << std::endl; 
    std::cout << "_default <= _default2 : " << (_default <= _default2) << std::endl; 
    std::cout << "_default > _default2 : " << (_default > _default2) << std::endl ;
    std::cout << "_default < _default2 : " << (_default < _default2) << std::endl ;
    
    
    ft::vector<int>::iterator iter = _default.begin();
    ft::vector<int>::iterator iters = _default.begin();
    ft::vector<int>::iterator iter2 = _default2.begin();
    ft::vector<int>::iterator iters2 = _default2.begin();

    ft::vector<int> test(12, 12);
    //_default.resize(7, 155);
    //_default = _default2;
    iter ++; 
    iter ++; 
    iter ++; 
    iters2 += 18;
    _default.insert(iter, 100, 100);
    //_default.insert(iter, iter2, iters2);
    iter = _default.begin();
 /* //  _default.swap(_default2);
    std::cout << "default" << _default << std::endl;
   std::cout << "default 2 " << _default2 << std::endl;*/
  // std::cout << _default << std::endl;
    return(0);
}
