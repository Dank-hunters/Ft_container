#include "map.hpp"
#include <map>

#define T1 int
#define T2 int

int main()
{
	TESTED_NAMESPACE::map<T1, T2> m;
	TESTED_NAMESPACE::map<T1, T2>::iterator it;
	TESTED_NAMESPACE::map<T1, T2>::iterator ite;

	/*for (int i = 0; i < 5; i++)
	{
		m.insert(TESTED_NAMESPACE::make_pair(i, 100));
	}
	it = m.begin();

	while(it != m.end())
	{
		std::cout << (++it)->first << std::endl;
	}*/
	
		m.insert(TESTED_NAMESPACE::make_pair(10, 100));
		m.insert(TESTED_NAMESPACE::make_pair(5, 100));
		m.insert(TESTED_NAMESPACE::make_pair(15, 100));
		m.insert(TESTED_NAMESPACE::make_pair(3, 100));
		m.insert(TESTED_NAMESPACE::make_pair(14, 100));
		m.insert(TESTED_NAMESPACE::make_pair(20, 100));
		m.insert(TESTED_NAMESPACE::make_pair(13, 100));
		m.insert(TESTED_NAMESPACE::make_pair(17, 100));
		m.insert(TESTED_NAMESPACE::make_pair(24, 100));
		m.insert(TESTED_NAMESPACE::make_pair(2, 100));
		m.insert(TESTED_NAMESPACE::make_pair(12, 100));
		m.insert(TESTED_NAMESPACE::make_pair(18, 100));
		m.insert(TESTED_NAMESPACE::make_pair(30, 100));
		//m.erase((--(--(--m.end()))), m.end());
	//	m.erase(10);
		m.erase((--(--(--(--(--(--m.end())))))), m.end());
		//m.insert(TESTED_NAMESPACE::make_pair(15, 100));

		it = m.begin();
		while(it != m.end())
		{
			std::cout << it->first << std::endl;
			it++;

		}
	//	m.erase(m.begin(), m.end());
	

}