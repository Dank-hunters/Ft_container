#include "../map.hpp"

#define t1 int
#define t2 int

int main()
{
	TEST::map<t1, t2> m;

	for (int i = 0; i < 1000000; i++)
	{
	//	std::cout << i << std::endl;
		m.insert(TEST::make_pair<t1, t2>(i, 12));	
	}
	


}