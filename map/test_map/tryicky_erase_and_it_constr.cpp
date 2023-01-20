#include <map>
#include <vector>
#include "common.hpp"
#include <iostream>


#define T1 std::string
#define T2 std::string

template <typename It>
void print_map(It first, It last)
{
    for (; first != last; ++first) {
        std::cout << "K: " << first->first << " V: " << first->second << " ";
    }
    std::cout << std::endl;
}

int main()
{
	TESTED_NAMESPACE::map<T1, T2>	m;
	TESTED_NAMESPACE::map<T1, T2>::const_iterator it;
	TESTED_NAMESPACE::map<T1, T2>::const_iterator ite;
	
	std::cout <<  "size before add" <<  m.size() << std::endl;
	
	m.erase("");

		m.insert(TESTED_NAMESPACE::make_pair("", "")); //del
        m.insert(TESTED_NAMESPACE::make_pair("123", "kjhgfdsdffghsfghdfgh"));//
        m.insert(TESTED_NAMESPACE::make_pair("1234", "gfdsadgg"));//
        m.insert(TESTED_NAMESPACE::make_pair("123456789123456789123456789", "49857459898674568464"));//
        m.insert(TESTED_NAMESPACE::make_pair("0", "2345456456456456"));//
        m.insert(TESTED_NAMESPACE::make_pair("", ""));//
        m.insert(TESTED_NAMESPACE::make_pair("", "9459845984598498"));//
        m.insert(TESTED_NAMESPACE::make_pair("000000000000000000000000", "1111111111111111111111111111"));

	m.erase("1");
	print_map(m.begin(), m.end());

	m.erase("123");
	print_map(m.begin(), m.end());

	m.erase("123");
	print_map(m.begin(), m.end());

	m.erase("");
	print_map(m.begin(), m.end());


	m.erase("1234");
	print_map(m.begin(), m.end());

	m.erase("123456789123456789123456789");
	print_map(m.begin(), m.end());
	 std::cout << "\nMap content:\n" << std::endl; 

	m.erase("000000000000000000000000");
	print_map(m.begin(), m.end());


	m.erase("0");
	print_map(m.begin(), m.end());
	m.erase("000000000000000000000000");
 
	return(0);
}
