//#include "map.hpp"
#include <map>
#include "map.hpp"
#include <iostream>
#include "../includes/pair.hpp"
#include "tree.hpp"
#include <iostream>

//void printHelper(ft::tree<std::string, int>::node_ptr root, std::string indent, bool last, bool first) 
void printHelper(ft::tree<int, int>::node_ptr root, std::string indent, bool last, bool first) 
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
	//ft::tree<std::string, int> tamere;
	ft::tree<int, int> tamere;

	tamere.insert(ft::make_pair<int, int>(50, 50));
printHelper(tamere.get_root(), "", true, true);
	tamere.insert(ft::make_pair<int, int>(25, 25));
printHelper(tamere.get_root(), "", true, true);
	tamere.insert(ft::make_pair<int, int>(75, 75));
printHelper(tamere.get_root(), "", true, true);
	tamere.insert(ft::make_pair<int, int>(100, 100));
printHelper(tamere.get_root(), "", true, true);
	tamere.insert(ft::make_pair<int, int>(60, 60));
printHelper(tamere.get_root(), "", true, true);
//	tamere.settruc();
	tamere.insert(ft::make_pair<int, int>(65, 65));
printHelper(tamere.get_root(), "", true, true);
tamere.erase(60);	

}