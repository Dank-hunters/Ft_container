#include "../vector/vector.hpp"

void printSize(TESTED_NAMESPACE::vector<TESTED_TYPE> &vec)
{
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;
  TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator tmp = vec.begin();
			
			while (tmp != vec.end())
			{
				std::cout << *tmp++ << std::endl;
			}
}


int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	printSize(vct);

	vct.push_back("Hello");
	vct.push_back("Hi there");
	printSize(vct);

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");

	printSize(vct);
	vct.pop_back();
	vct.pop_back();
	printSize(vct);
	vct.pop_back();
	vct.pop_back();
	vct.pop_back();
	vct.pop_back();
	return (0);
}