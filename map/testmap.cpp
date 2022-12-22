#include <map>
#include "map.hpp"
#include <iostream>


int main()
{
	ft::map<int, int>	test;
	ft::map<int, int>::reverse_iterator it;
	ft::map<int, int>::reverse_iterator ite;
	test.insert(ft::pair<int, int>(100, 5));
	test.insert(ft::pair<int, int>(15, 10));
	test.insert(ft::pair<int, int>(11, 10));
	test.insert(ft::pair<int, int>(122, 20));
	test.insert(ft::pair<int, int>(12, 20));
	test.insert(ft::pair<int, int>(111, 20));
	test.erase(ft::pair<int, int>(12, 20));
	test.erase(ft::pair<int, int>(122, 20));

	it = test.rbegin();
	ite = test.rend();
	ite--;
	std::cout << ite->second << std::endl;
	ite--;
	std::cout << ite->second << std::endl;
//	while(ite != it)
//	{
	//	ite;
//	}
	return(0);
}