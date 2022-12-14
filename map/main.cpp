//#include "map.hpp"
#include <map>
#include "map.hpp"
#include <iostream>
#include "../includes/pair.hpp"
#include "tree.hpp"
#include <iostream>

//void printHelper(ft::tree<std::string, int>::node_ptr root, std::string indent, bool last, bool first) 
void printHelper(ft::tree<std::string, int>::node_ptr root, std::string indent, bool last, bool first) 
        {
            if (root != nullptr) 
            {
                std::cout<<indent;
                if (first) {
                    std::cout<<"Root-";
                    indent += "     ";
                }
                else if (last) {
                    std::cout<<"R----";
                    indent += "     ";
                }
                else {
                    std::cout<<"L----";
                    indent += "|    ";
                }

                std::cout << "(" << root->val.second << ")" << std::endl;
                printHelper(root->left, indent, false, false);
                printHelper(root->right, indent, true, false);
            //    exit(0);
                if (first)
                    std::cout << std::endl;
            }
            else if (first)
                std::cout << "NULL" << std::endl << std::endl;
		}

int main()
{
//	ft::map<std::string, int> tamere;
	ft::tree<std::string, int> tamere;

	tamere.insert(ft::make_pair<std::string, int>("lol", 15));
	tamere.insert(ft::make_pair<std::string, int>("lo", 18));
	tamere.insert(ft::make_pair<std::string, int>("loli", 7));
	tamere.insert(ft::make_pair<std::string, int>("loly", 5));
	tamere.insert(ft::make_pair<std::string, int>("lold", 122));
	tamere.insert(ft::make_pair<std::string, int>("loldsf", 132));
	tamere.insert(ft::make_pair<std::string, int>("lolagau", 72));
	tamere.insert(ft::make_pair<std::string, int>("loqwlu", 646));
	tamere.insert(ft::make_pair<std::string, int>("loertlu", 55));
	tamere.insert(ft::make_pair<std::string, int>("lolru", 1));
	//tamere.insert(13);
	//tamere.insert(8);
tamere.erase("lol");
tamere.erase("lo");
tamere.erase("loli");
tamere.erase("loly");
tamere.erase("lold");
tamere.erase("lolagau");
tamere.erase("lolru");
tamere.erase("loldsf");
tamere.erase("loqwlu");
tamere.erase("loertlu");

/*
	tamere.insert(ft::make_pair<std::string, int>("lolru", 1));
*/
//tamere.erase(ft::make_pair<std::string, int>("lolu", 12));
//tamere.erase(ft::make_pair<std::string, int>("loli", 12));
printHelper(tamere.get_root(), "", true, true);

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
//	std::map<std::string, int>::iterator it = tamere.begin();
//	std::cout << it->first << std::endl;

}