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

	tamere.insert(1);
	tamere.insert(13);
	tamere.insert(8);
	tamere.insert(3);
	tamere.insert(28);
	tamere.insert(19);
	tamere.insert(9);
	tamere.insert(10);
	tamere.insert(12);
	tamere.insert(5);
	tamere.insert(25);
	tamere.insert(21);
	tamere.insert(21);
	tamere.insert(3);
	tamere.insert(27);
	tamere.insert(29);
	
	tamere.erase(28);
	printHelper(tamere.get_root(), "", true, true);

}