#include "../vector/vector.hpp"

void  printvec(std::string name, TESTED_NAMESPACE::vector<TESTED_TYPE> &vec)
{
               std::cout << name << ":" << std::endl;
 					std::cout << "_start = " << *vec.begin() << std::endl;
					std::cout << "capacity : " << vec.capacity() << std::endl;
					std::cout << "size : " << vec.size() << std::endl;
					std::cout << "content :" << std::endl;
					
					TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator tmp = vec.begin();
					
					while (tmp != vec.end())
					{
						std::cout << *tmp++ << std::endl;
					}

}
void printSize(TESTED_NAMESPACE::vector<TESTED_TYPE> &vec)
{
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;
  TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator tmp = vec.begin();
			
			while (tmp != vec.end())
			{
				std::cout << *tmp++ << std::endl;
			}
}



int main()
{
    const int u  = 8;
    size_t o = 5;
    TESTED_NAMESPACE::vector<TESTED_TYPE> _default(9, 10);
    TESTED_NAMESPACE::vector<TESTED_TYPE> _default2(7, 666);
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator ita = _default.begin();
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = _default2.begin();
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator ite = _default2.end();
    TESTED_NAMESPACE::vector<TESTED_TYPE> range(it, ite);
   // dprintf(1, "poute");
    printvec("default :", _default);
    ita++;

  //  TESTED_NAMESPACE::vector<TESTED_TYPE> copy(_default);
    _default.insert(ita, it, ite);
    //_default.insert(ita, 2, 8);
    
    //copy = _default2;
    //_default.resize(150, 111);
    printvec("default :", _default);
    //printvec("default2 :", _default2);
   /// printvec("range :", range);
   // printvec("copy :", copy);

    _default.push_back(12);
        printvec("default  after push_back(12) :" , _default);
    _default.pop_back();
        printvec("default  after pop_back() :" , _default);
    std::cout << "is _default is empty ? " << _default.empty() << std::endl;
    
   
    std::cout << "_default == _default2 : " << (_default == _default2) << std::endl; 
    std::cout << "_default != _default2 : " << (_default != _default2) << std::endl; 
    std::cout << "_default >= _default2 : " << (_default >= _default2) << std::endl; 
    std::cout << "_default <= _default2 : " << (_default <= _default2) << std::endl; 
    std::cout << "_default > _default2 : " << (_default > _default2) << std::endl ;
    std::cout << "_default < _default2 : " << (_default < _default2) << std::endl ;
    
    
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator iter = _default.begin();
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator iters = _default.begin();
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator iter2 = _default2.begin();
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator iters2 = _default2.begin();

    TESTED_NAMESPACE::vector<TESTED_TYPE> test(12, 12);
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
