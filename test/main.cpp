#include "../vector/vector.hpp"

void printSize(TESTED_NAMESPACE::vector<TESTED_TYPE> &vec)
{  
 				//	std::cout << "_start = " << *vec.begin() << std::endl;
					std::cout << "capacity : " << vec.capacity() << std::endl;
					std::cout << "size : " << vec.size() << std::endl;
					std::cout << "content :" << std::endl;
					
					TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator tmp = vec.begin();
					
					while (tmp != vec.end())
					{
						std::cout << *tmp++ << std::endl;
					}

}

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(8);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

	for (unsigned long int i = 0; i < vct.size(); ++i)
		it[i] = std::string((vct.size() - i), i + 65);
	printSize(vct);

	std::cout << "push_back():\n" << std::endl;

	vct.push_back("One long string");
	vct2.push_back("Another long string");

	printSize(vct);
	printSize(vct2);

	vct.pop_back();
	vct2.pop_back();

	printSize(vct);
	printSize(vct2);

	return (0);
}