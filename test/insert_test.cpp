#include "../vector/vector.hpp"



void printSize(TESTED_NAMESPACE::vector<TESTED_TYPE> &vec)
{  
 				//	std::cout << "_start = " << *vec.begin() << std::endl;
					std::cout << "capacity : " << vec.capacity() << std::endl;
					std::cout << "size : " << vec.size() << std::endl;
					/*std::cout << "content :" << std::endl;
					
					TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator tmp = vec.begin();
					
					while (tmp != vec.end())
					{
						std::cout << *tmp++ << std::endl;
					}*/

}
int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	printSize(vct);

	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	printSize(vct2);

	vct2.insert(vct2.end() - 2, 42);
	printSize(vct2);

	vct2.insert(vct2.end(), 2, 84);
	printSize(vct2);

	vct2.resize(4);
	printSize(vct2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	printSize(vct2);

	printSize(vct);

	for (int i = 0; i < 5; ++i)
		vct3.insert(vct3.end(), i);
	vct3.insert(vct3.begin() + 1, 2, 111);
	printSize(vct3);

	return (0);
}