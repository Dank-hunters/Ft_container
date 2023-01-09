#include <map>
#include <vector>
#include "map.hpp"
#include <iostream>
/*
void printHelper(_TN::map<std::string, int>::trees_type *root, std::string indent, bool last, bool first) 
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

*//**/
int main()
{
	

	_TN::map<std::string, int>	test;
	_TN::map<std::string, int>::const_iterator it;
	_TN::map<std::string, int>::const_iterator ite;
	
	std::cout <<  "size before add" <<  test.size() << std::endl;
	
	test.insert(_TN::pair<std::string, int>("paa", 5));
	test.insert(_TN::pair<std::string, int>("pax", 10));
	test.insert(_TN::pair<std::string, int>("pas", 15));
	test.insert(_TN::pair<std::string, int>("paw", 20));
	test.insert(_TN::pair<std::string, int>("par", 25));
	test.insert(_TN::pair<std::string, int>("pay", 220));
	std::cout << "size after add dl |" << test.size() << "||" << std::endl;
	
	
	std::cout << "chelouuuuuuuuuu" << std::endl << std::endl;
	//printHelper(test.get_root(), "", true, true);


	_TN::map<std::string, int>::const_iterator itei;
	_TN::map<std::string, int>::const_iterator itee;

	itei = test.begin();
	itee = test.begin();

	itee++;
	itee++;
	itee++;
//	_TN::map<std::string, int>	testi;

//	testi.insert(itei, itee);
//    it = test.begin();
//	printHelper(testi.get_root(), "", true, true);
        it = test.begin();
    ite = test.end();
	//ite--;
	//ite--;
//	ite--;
	//ite--;
	//ite--;
//	std::cout << "ite --  " <<  ite->first << " end "<< std::endl;

	/*std::cout << "size de testi" << testi.size() << "||" <<  std::endl;
*/

    while(it != ite)
	{
	std::cout << "start  " <<  it->first << " end "<< std::endl;
		it++;
	}
	return(0);
}
