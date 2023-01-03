#include <map>
#include <iostream>
int main()
{
	//std::vector<int> test(5, 10);
	//std::vector<int>::iterator it = test.begin();
	//test.insert(15);
	//std::vector<int>::iterator ite = test.end();
	//std::cout << *ite << std::endl;

	_TN::map<std::string, int>	test;
	_TN::map<std::string, int>::iterator it;
	_TN::map<std::string, int>::iterator ite;
	std::cout << test.size() << std::endl;
	test.insert(_TN::pair<std::string, int>("lol", 5));
	test.insert(_TN::pair<std::string, int>("lolf", 10));
	test.insert(_TN::pair<std::string, int>("lolg", 15));
	test.insert(_TN::pair<std::string, int>("lohl", 20));
	test.insert(_TN::pair<std::string, int>("lolj", 25));
	test.insert(_TN::pair<std::string, int>("lokl", 220));
	std::cout << test.size() << std::endl;

	//printHelper(test.get_root(), "", true, true);
	//test.erase(_TN::pair<std::string, int>(12, 27));
	//test.erase(_TN::pair<std::string, int>(122, 120));
	_TN::map<std::string, int>::iterator itei;
	_TN::map<std::string, int>::iterator itee;

	itei = test.begin();
	itee = test.begin();

	itee++;
	itee++;
	itee++;
	itee++;
	_TN::map<std::string, int>	testi;
	//eestd::cout << "new" << std::endl;

	testi.insert(itei, itee);
    it = test.begin();
    ite = test.end();
    while(ite != it)
	{
	std::cout << "new" <<  it->first << std::endl;
		it++;
	}
//	printHelper(testi.get_root(), "", true, true);

    //it = test.insert(_TN::pair<std::string, int>(2, 8)).first;
	//std::cout << it->first << std::endl;
	/*
	ite = test.end();

	while(ite != it)
	{
		--ite;
	std::cout << ite->first << std::endl;
	}
*/
	return(0);
}