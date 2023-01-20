#include <map>
#include <list>
#include <iostream>
#include "common.hpp"
/*
#define T1 float
#define T2 foo<int>
typedef _pair<const T1, T2> T3;

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(2.5 + i, i + 1));

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<T1, T2>::iterator it(mp.begin());
	TESTED_NAMESPACE::map<T1, T2>::const_iterator ite(mp.begin());
	printSize(mp);

	printPair(++ite);
	printPair(ite++);
	printPair(ite++);
	printPair(++ite);

	it->second.m();
	std::cout << "ici " << std::endl;
	ite->second.m();

	printPair(++it);
	printPair(it++);
	printPair(it++);
	printPair(++it);

	printPair(--ite);
	printPair(ite--);
	printPair(--ite);
	printPair(ite--);

	(*it).second.m();
	(*ite).second.m();

	printPair(--it);
	printPair(it--);
	printPair(it--);
	printPair(--it);

	return (0);
}

*//*
#define T1 char
#define T2 int
typedef _pair<const T1, T2> T3;

template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp1;
	TESTED_NAMESPACE::map<T1, T2> mp2;

	mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
	mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

	cmp(mp1, mp1); // 0
	cmp(mp1, mp2); // 1

	mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

	cmp(mp1, mp2); // 2
	cmp(mp2, mp1); // 3

	(++(++mp1.begin()))->second = 42;

	cmp(mp1, mp2); // 4
	cmp(mp2, mp1); // 5

	swap(mp1, mp2);

	cmp(mp1, mp2); // 6
	cmp(mp2, mp1); // 7

	return (0);
}
*/

#define T1 int
#define T2 int
typedef _pair<const T1, T2> T3;

int		main(void)
{
				std::cout << "bite" << std::endl;

	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(lst_size - i, i));
				std::cout << "bite" << std::endl;

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
				std::cout << "bite" << std::endl;

	TESTED_NAMESPACE::map<T1, T2> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	TESTED_NAMESPACE::map<T1, T2> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(mp);
				std::cout << "bite" << std::endl;
	printSize(mp_range);
	printSize(mp_copy);

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);
	return (0);
}