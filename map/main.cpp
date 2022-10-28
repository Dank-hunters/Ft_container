#include "tree.hpp"
#include <iostream>

void printHelper(ft::tree<int>::node_ptr root, std::string indent, bool last, bool first) 
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

				std::cout << "(" << root->val << ")" << std::endl;
		        printHelper(root->left, indent, false, false);
		        printHelper(root->right, indent, true, false);
		        if (first)
		            std::cout << std::endl;
		    }
		    else if (first)
		        std::cout << "NULL" << std::endl << std::endl;
		}

int main()
{
	ft::tree<int> tamere;

	tamere.insert(25);
	tamere.insert(22);
	tamere.insert(23);
	tamere.insert(5);
	tamere.insert(7);
	tamere.insert(12);
	tamere.insert(26);
	tamere.insert(2545);
	tamere.insert(2895);
	tamere.insert(278535);
	tamere.insert(27685);
	tamere.insert(25178);
	tamere.insert(275);
	tamere.insert(2565);
	tamere.insert(2215);
	tamere.insert(225);
	tamere.insert(2538);
	tamere.insert(257);
	tamere.insert(25777);
	tamere.erase(25777);
	printHelper(tamere.get_root(), "", true, true);

}