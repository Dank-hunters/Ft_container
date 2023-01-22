#include "map.hpp"
#include <map>

#define T1 int
#define T2 int
//#define T1 std::string
//#define T2 std::string
#define It TESTED_NAMESPACE::map<T1, T2>::iterator
	void	print(It ita, It ite)
	{
		while(ita != ite)
		{
			std::cout << ita->first ;
			ita++;

		}
	}

int main()
{
	TESTED_NAMESPACE::map<T1, T2> m;
	TESTED_NAMESPACE::map<T1, T2>::iterator it;
	TESTED_NAMESPACE::map<T1, T2>::iterator ite;
/*
	for (int i = 0; i < 50000; i++)
	{
		m.insert(TESTED_NAMESPACE::make_pair(i, 100));
	}
	it = m.begin();
	while(it != m.end())
	{
		std::cout << (++it)->first << std::endl;
	}*/
	
/*	m.insert(TESTED_NAMESPACE::make_pair(23, "23n"));
	m.insert(TESTED_NAMESPACE::make_pair(25, "asdasdfsdfsafdsf"));
	m.insert(TESTED_NAMESPACE::make_pair(1, "asdssdfdfdffffff"));
	m.insert(TESTED_NAMESPACE::make_pair(2, "dsfdffffdfdfdsdfdffa"));
	m.insert(TESTED_NAMESPACE::make_pair(3, "sssdfs"));
	m.insert(TESTED_NAMESPACE::make_pair(75, "dfse"));
	m.insert(TESTED_NAMESPACE::make_pair(30, "sefsadfasdfasdfsadfasdfsf"));
	m.insert(TESTED_NAMESPACE::make_pair(-22, "dfhkihgbnfbcx5reterjhd"));
	m.insert(TESTED_NAMESPACE::make_pair(-23, "sdffgdfgrefet34thfgheewt"));
	m.insert(TESTED_NAMESPACE::make_pair(0, "98y4rtuohwidsjusdossefsse"));
*/
		m.insert(TESTED_NAMESPACE::make_pair(23, 100));
		m.insert(TESTED_NAMESPACE::make_pair(25, 100));
		m.insert(TESTED_NAMESPACE::make_pair(1, 100));
		m.insert(TESTED_NAMESPACE::make_pair(2, 100));
		m.insert(TESTED_NAMESPACE::make_pair(3, 100));
		m.insert(TESTED_NAMESPACE::make_pair(20, 100));
		m.insert(TESTED_NAMESPACE::make_pair(13, 100));
		m.insert(TESTED_NAMESPACE::make_pair(17, 100));
		m.insert(TESTED_NAMESPACE::make_pair(24, 100));
		m.insert(TESTED_NAMESPACE::make_pair(2, 100));
		m.insert(TESTED_NAMESPACE::make_pair(12, 100));
		m.insert(TESTED_NAMESPACE::make_pair(18, 100));
		m.insert(TESTED_NAMESPACE::make_pair(30, 100));
		//m.erase((--(--(--m.end()))), m.end());
		//m.erase((--(--(--(--(--(--m.end())))))), m.end());
		//m.insert(TESTED_NAMESPACE::make_pair(15, 100));
    std::cout << "bite 1 ";
		m.erase(64);
		print(m.begin(), m.end());
    std::cout << "bite 2";
		m.erase(0);
		print(m.begin(), m.end());
    std::cout << "bite 3";
		m.erase(74);
		print(m.begin(), m.end());
    std::cout << "bite 3";
		m.erase(1);
		print(m.begin(), m.end());
    std::cout << "bite 4";
		m.erase(2);
		print(m.begin(), m.end());
    std::cout << "bite 5";
		m.erase(3);
		print(m.begin(), m.end());
    std::cout << "bite 6";
		m.erase(23);
    std::cout << "bite 7";
		print(m.begin(), m.end());
		m.erase(23);
    std::cout << "bite 8";
		print(m.begin(), m.end());
		m.erase(30);
    std::cout << "bite 9";
		print(m.begin(), m.end());
		m.erase(-22);
    std::cout << "bite 10";
		print(m.begin(), m.end());
		m.erase(-23);
    std::cout << "bite 11";
		print(m.begin(), m.end());
		m.erase(-23);
    std::cout << "bite 12";
		print(m.begin(), m.end());
		m.erase(25);
    std::cout << "bite 13";
		print(m.begin(), m.end());
		m.erase(-23);
    std::cout << "bite 14";
		print(m.begin(), m.end());
		m.erase(25);
    std::cout << "bite 15" ;
    /*std::cout << "bite " << std::endl;
    std::cout << "bite " << std::endl;
		
		m.insert(TESTED_NAMESPACE::make_pair("", ""));
        m.insert(TESTED_NAMESPACE::make_pair("123", "kjhgfdsdffghsfghdfgh"));
        m.insert(TESTED_NAMESPACE::make_pair("1234", "gfdsadgg"));
        m.insert(TESTED_NAMESPACE::make_pair("123456789123456789123456789", "49857459898674568464"));
        m.insert(TESTED_NAMESPACE::make_pair("0", "2345456456456456"));
        m.insert(TESTED_NAMESPACE::make_pair("", ""));
        m.insert(TESTED_NAMESPACE::make_pair("", "9459845984598498"));
        m.insert(TESTED_NAMESPACE::make_pair("000000000000000000000000", "1111111111111111111111111111"));
    std::cout << "bite " << std::endl;
		
		
		m.erase("1");
    std::cout << "bite " << std::endl;
		
		print(m.begin(), m.end());
    std::cout << "bite " << std::endl;
 		

		m.erase("123");
		print(m.begin(), m.end());
    std::cout << "bite " << std::endl;


		m.erase("123");
		print(m.begin(), m.end());
    std::cout << "bite " << std::endl;

		m.erase("");
		print(m.begin(), m.end());
    std::cout << "bite " << std::endl;

		m.erase("1234");
		print(m.begin(), m.end());
		m.erase("123456789123456789123456789");
    std::cout << "bite " << std::endl;

		print(m.begin(), m.end());
		m.erase("000000000000000000000000");
    std::cout << "biteddd " << std::endl;

		print(m.begin(), m.end());
		m.erase("0");
    std::cout << "bite " << std::endl;

		print(m.begin(), m.end());
		m.erase("000000000000000000000000");
    std::cout << "bite " << std::endl;

		print(m.begin(), m.end());
    std::cout << "bite de fin " << std::endl;*/

	//	m.erase(m.begin(), m.end());
	

}