#include <map>
#include <vector>
#include "map.hpp"
#include <iostream>

void printHelper(_TN::map<int, int>::trees_type *root, std::string indent, bool last, bool first) 
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

                std::cout << "(" << root->val.first << ")" << std::endl;
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
	//std::vector<int> test(5, 10);
	//std::vector<int>::iterator it = test.begin();
	//test.insert(15);
	//std::vector<int>::iterator ite = test.end();
	//std::cout << *ite << std::endl;

	_TN::map<int, int>	test;
	_TN::map<int, int>::iterator it;
	_TN::map<int, int>::iterator ite;
	std::cout << test.size() << std::endl;
	test.insert(_TN::pair<int, int>(100, 5));
	test.insert(_TN::pair<int, int>(15, 10));
	test.insert(_TN::pair<int, int>(11, 15));
	test.insert(_TN::pair<int, int>(122, 20));
	test.insert(_TN::pair<int, int>(12, 25));
	test.insert(_TN::pair<int, int>(111, 220));
	std::cout << test.size() << std::endl;
	printHelper(test.get_root(), "", true, true);
	//test.erase(_TN::pair<int, int>(12, 27));
	//test.erase(_TN::pair<int, int>(122, 120));
	_TN::map<int, int>::iterator itei;
	_TN::map<int, int>::iterator itee;

	itei = test.begin();
	itee = test.begin();

	itee++;
	itee++;
	itee++;
	itee++;
	_TN::map<int, int>	testi;
	//eestd::cout << "new" << std::endl;

	std::cout << "bite" << std::endl;
	testi.insert(itei, itee);
    it = testi.begin();
    ite = testi.end();
    while(ite != it)
	{
		//if (it == ite)
		//	return 0;
	std::cout << "new" <<  it->first << std::endl;
		it++;
	}
/*
it = test.insert(_TN::pair<int, int>(2, 8)).first;
	std::cout << it->first << std::endl;
	
	ite = test.end();

	while(ite != it)
	{
		--ite;
	std::cout << ite->first << std::endl;
	}
*/
	return(0);
}