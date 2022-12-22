//#include "map.hpp"
#include <map>
//#include "map.hpp"
#include <iostream>
#include "../includes/pair.hpp"
#include "tree.hpp"
#include <iostream>

//void printHelper(ft::tree<std::string, int>::node_ptr root, std::string indent, bool last, bool first) 
void printHelper(ft::tree<ft::pair<int, int> >::node_ptr root, std::string indent, bool last, bool first) 
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
	ft::tree<ft::pair<int, int> > tamere;

	tamere.insert(ft::make_pair<int, int>(50, 50));
printHelper(tamere.get_root(), "", true, true);
	tamere.insert(ft::make_pair<int, int>(25, 25));
printHelper(tamere.get_root(), "", true, true);
	tamere.insert(ft::make_pair<int, int>(75, 75));
printHelper(tamere.get_root(), "", true, true);
	tamere.insert(ft::make_pair<int, int>(15, 15));
printHelper(tamere.get_root(), "", true, true);
	tamere.insert(ft::make_pair<int, int>(40, 40));
printHelper(tamere.get_root(), "", true, true);
//	tamere.settruc();
	tamere.insert(ft::make_pair<int, int>(60, 60));
printHelper(tamere.get_root(), "", true, true);
	tamere.insert(ft::make_pair<int, int>(80, 80));
	tamere.insert(ft::make_pair<int, int>(35, 35));
	tamere.insert(ft::make_pair<int, int>(55, 55));
	tamere.insert(ft::make_pair<int, int>(65, 65));
	tamere.insert(ft::make_pair<int, int>(90, 90));
	tamere.insert(ft::make_pair<int, int>(62, 62));
printHelper(tamere.get_root(), "", true, true);
tamere.erase(ft::make_pair<int, int>(90, 90));	
printHelper(tamere.get_root(), "", true, true);
tamere.clear();
printHelper(tamere.get_root(), "", true, true);
/*
tamere.erase(50);	
printHelper(tamere.get_root(), "", true, true);
tamere.erase(100);	
printHelper(tamere.get_root(), "", true, true);*/
return(0);

}