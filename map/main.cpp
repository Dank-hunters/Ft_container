//#include "map.hpp"
#include <map>
#include "map.hpp"
#include <iostream>
#include "../includes/pair.hpp"
//#include "tree.hpp"
#include <iostream>

int main()
{
	std::map<std::string, int> tamere;
	ft::map<std::string, int> tamere2;

	tamere2.insert(ft::make_pair<std::string, int>("lol", 15));
	tamere.insert(std::make_pair<std::string, int>("loli", 7));
	tamere.insert(std::make_pair<std::string, int>("lolu", 12));
	//tamere.insert(13);
	//tamere.insert(8);
	//tamere.insert(28);
	/*tamere.insert(2);
	tamere.insert(5);
	tamere.insert(19);
	tamere.insert(9);
	tamere.insert(6);
	tamere.insert(10);
	tamere.insert(12);
	tamere.insert(5);
	tamere.insert(9);
	tamere.insert(7);
	tamere.insert(21);
	tamere.insert(21);
	tamere.insert(3);
	tamere.insert(27);
	tamere.insert(29);*/
	/*
	for (std::map<std::tring, int>::iterator i = tamere.begin(); ; i++)
	{
		dprintf(1, "%i\n", i);
	}*/
	// tamere.erase(15);
	std::map<std::string, int>::iterator it = tamere.begin();
	std::cout << it->first << std::endl;

}