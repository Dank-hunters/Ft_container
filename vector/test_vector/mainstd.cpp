#include "../vector.hpp"
#define TESTED_TYPE int
#define TESTED_TYPEE std::string
#define TESTED_NAMESPACE std


void printSize1(TESTED_NAMESPACE::vector<TESTED_TYPE> &vec)
{
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;
  TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator tmp = vec.begin();
			
			while (tmp != vec.end())
			{
				std::cout << *tmp++ << std::endl;
			}
}

int test_four()
{

		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_two(4);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_three;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	printSize1(vct);
	printSize1(vct_two);

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	std::cout << "\t### After assign(): ###" << std::endl;

	printSize1(vct);
	printSize1(vct_two);
	printSize1(vct_three);
	printSize1(vct_four);

	vct_four.assign(6, 84);
	printSize1(vct_four);

	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	printSize1(vct);
	vct.swap(vct_two);
	printSize1(vct);
	printSize1(vct_two);
    return(0);
}

void    printSize2(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct, bool print_content = true)
{
        const TESTED_TYPE size = vct.size();
        const TESTED_TYPE capacity = vct.capacity();
        const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
        // Cannot limit capacity's max value because it's implementation dependent

        std::cout << "size: " << size << std::endl;
        std::cout << "capacity: " << isCapacityOk << std::endl;
        std::cout << "max_size: " << vct.max_size() << std::endl;
        if (print_content)
        {
                TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it = vct.begin();
                TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.end();
                std::cout << std::endl << "Content is:" << std::endl;
                for (; it != ite; ++it)
                        std::cout << "- " << *it << std::endl;
        }
        std::cout << "###############################################" << std::endl;
}
template <class T, class Alloc>
void    cmp(const TESTED_NAMESPACE::vector<T, Alloc> &lhs, const TESTED_NAMESPACE::vector<T, Alloc> &rhs)
{
        static int i = 0;

        std::cout << "############### [" << i++ << "] ###############"  << std::endl;
        std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
        std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
        std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

void iterator_test(void)
{
        const int size = 5;
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(vct.rbegin());
        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite(vct.rend());
                TESTED_NAMESPACE::vector<TESTED_TYPE> vctd;
        std::cout << "empty ? :" << vct.empty() << std::endl;
        std::cout << "empty ? :" << vctd.empty() << std::endl;

        for (int i = 1; it != ite; ++i)
                *it++ = (i * 7);
        printSize2(vct, 1);

        it = vct.rbegin();
        ite = vct.rbegin();

        std::cout << *(++ite) << std::endl;
        std::cout << *(ite++) << std::endl;
        std::cout << *ite++ << std::endl;
        std::cout << *++ite << std::endl;

        //it->m();
        //ite->m();

        std::cout << *(++it) << std::endl;
        std::cout << *(it++) << std::endl;
        std::cout << *it++ << std::endl;
        std::cout << *++it << std::endl;

        std::cout << *(--ite) << std::endl;
        std::cout << *(ite--) << std::endl;
        std::cout << *--ite << std::endl;
        std::cout << *ite-- << std::endl;

        //(*it).m();
        //(*ite).m();

        std::cout << *(--it) << std::endl;
        std::cout << *(it--) << std::endl;
        std::cout << *it-- << std::endl;
        std::cout << *--it << std::endl;

}
void    insert_test(void)
{
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct3;

        for (unsigned long int i = 0; i < vct.size(); ++i)
                vct[i] = (vct.size() - i) * 3;
        printSize2(vct);

        vct2.insert(vct2.end(), 42);
        vct2.insert(vct2.begin(), 2, 21);
        printSize2(vct2);

        vct2.insert(vct2.end() - 2, 42);
        printSize2(vct2);

        vct2.insert(vct2.end(), 2, 84);
        printSize2(vct2);

        vct2.resize(4);
        printSize2(vct2);

        vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
        vct.clear();
        printSize2(vct2);

        printSize2(vct);

        for (int i = 0; i < 5; ++i)
                vct3.insert(vct3.end(), i);
        vct3.insert(vct3.begin() + 1, 2, 111);
        printSize2(vct3);

}
void    at_test(void)
{
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);


        for (unsigned long int i = 0; i < vct.size(); ++i)
        {
                vct.at(i) = (vct.size() - i) * 3;
                std::cout << "vct.at(): " << vct.at(i) << " | ";
                std::cout << "vct[]: " << vct[i] << std::endl;
        }
        printSize2(vct);

        TESTED_NAMESPACE::vector<TESTED_TYPE> const vct_c(vct);

        std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
        std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

        try {
                vct.at(10) = 42;
        }
        catch (std::out_of_range &e) {
                std::cout << "Catch out_of_range exception!" << std::endl;
        }
        catch (std::exception &e) {
                std::cout << "Catch exception: " << e.what() << std::endl;
        }
}
void    it_test(void)
{
        const int size = 5;
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

        for (int i = 0; i < size; ++i)
                it[i] = (size - i) * 5;

        it = it + 5;
        it = 1 + it;
        it = it - 4;
        std::cout << *(it += 2) << std::endl;
        std::cout << *(it -= 1) << std::endl;

        *(it -= 2) = 42;
        *(it += 2) = 21;

        std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

        std::cout << "(it == const_it): " << (ite == it) << std::endl;
        std::cout << "(const_ite - it): " << (ite - it) << std::endl;
        std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

        printSize2(vct, true);
}
template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
        std::cout << (first < second) << std::endl;
        std::cout << (first <= second) << std::endl;
        std::cout << (first > second) << std::endl;
        std::cout << (first >= second) << std::endl;
        if (redo)
                ft_eq_ope(second, first, 0);
}

void    ope_test(void)
{
        const int size = 5;
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_0(vct.rbegin());
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_1(vct.rend());
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_mid;

        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_0 = vct.rbegin();
        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_1;
        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_mid;

        for (int i = size; it_0 != it_1; --i)
                *it_0++ = i;
        printSize2(vct, 1);
        it_0 = vct.rbegin();
        cit_1 = vct.rend();
        it_mid = it_0 + 3;
        cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

        std::cout << std::boolalpha;
        std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

        std::cout << "\t\tft_eq_ope:" << std::endl;
        // regular it
        ft_eq_ope(it_0 + 3, it_mid);
        ft_eq_ope(it_0, it_1);
        ft_eq_ope(it_1 - 3, it_mid);
        // const it
        ft_eq_ope(cit_0 + 3, cit_mid);
        ft_eq_ope(cit_0, cit_1);
        ft_eq_ope(cit_1 - 3, cit_mid);
        // both it
        ft_eq_ope(it_0 + 3, cit_mid);
        ft_eq_ope(it_mid, cit_0 + 3);
        ft_eq_ope(it_0, cit_1);
        ft_eq_ope(it_1, cit_0);
        ft_eq_ope(it_1 - 3, cit_mid);
        ft_eq_ope(it_mid, cit_1 - 3);

}

int test_two()
{
        iterator_test();
        insert_test();
        at_test();
        ope_test();

        return(0);
}

void	printSizes(TESTED_NAMESPACE::vector<TESTED_TYPEE> const &vct, bool print_content = true)
{
	const size_t size = vct.size();
	const size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		TESTED_NAMESPACE::vector<TESTED_TYPEE>::const_iterator it = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPEE>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


void pop_test(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPEE> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	printSizes(vct);

	vct.push_back("Hello");
	vct.push_back("Hi there");
	printSizes(vct);

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");

	printSizes(vct);
	vct.pop_back();
	vct.pop_back();
	printSizes(vct);
	vct.pop_back();
	vct.pop_back();
	vct.pop_back();
	vct.pop_back();
}
void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPEE> const &vct,
					TESTED_NAMESPACE::vector<TESTED_TYPEE>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSizes(vct);
}

void erase_and_push(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPEE> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	printSizes(vct);

	checkErase(vct, vct.erase(vct.begin() + 2));

	checkErase(vct, vct.erase(vct.begin()));
	checkErase(vct, vct.erase(vct.end() - 1));

	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

	vct.push_back("Hello");
	vct.push_back("Hi there");
	printSizes(vct);
	checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");
	printSizes(vct);
	checkErase(vct, vct.erase(vct.begin(), vct.end()));

}

int test_one()
{
	pop_test();
	erase_and_push();
	return(0);
}

void  printvecs(std::string name, TESTED_NAMESPACE::vector<TESTED_TYPE> &vec)
{
               std::cout << name << ":" << std::endl;
 					std::cout << "_start = " << *vec.begin() << std::endl;
					std::cout << "capacity : " << vec.capacity() << std::endl;
					std::cout << "size : " << vec.size() << std::endl;
					std::cout << "content :" << std::endl;
					
					TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator tmp = vec.begin();
					
					while (tmp != vec.end())
					{
						std::cout << *tmp++ << std::endl;
					}

}

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

int test_three()
{
    TESTED_NAMESPACE::vector<TESTED_TYPE> _default(9, 10);
    TESTED_NAMESPACE::vector<TESTED_TYPE> _default2(7, 666);
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator ita = _default.begin();
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = _default2.begin();
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator ite = _default2.end();
    TESTED_NAMESPACE::vector<TESTED_TYPE> range(it, ite);
    TESTED_NAMESPACE::vector<TESTED_TYPE> copy(_default);
    printvecs("default :", _default);
    ita++;

    _default.insert(ita, it, ite);
    printvecs("copy", copy);
    printvecs("default :", _default);
    _default.push_back(12);
        printvecs("default  after push_back(12) :" , _default);
    _default.pop_back();
        printvecs("default  after pop_back() :" , _default);
    std::cout << "is _default is empty ? " << _default.empty() << std::endl;
    
   
    std::cout << "_default == _default2 : " << (_default == _default2) << std::endl; 
    std::cout << "_default != _default2 : " << (_default != _default2) << std::endl; 
    std::cout << "_default >= _default2 : " << (_default >= _default2) << std::endl; 
    std::cout << "_default <= _default2 : " << (_default <= _default2) << std::endl; 
    std::cout << "_default > _default2 : " << (_default > _default2) << std::endl ;
    std::cout << "_default < _default2 : " << (_default < _default2) << std::endl ;
    
    
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator iter = _default.begin();

    TESTED_NAMESPACE::vector<TESTED_TYPE> test(12, 12);
    iter ++; 
    iter ++; 
    iter ++; 
    _default.insert(iter, 100, 100);
    iter = _default.begin();
    return(0);
}

int main()
{
	std::cout << "---------------------- TEST ONE -------------------" << std::endl;
	test_one();
	std::cout << "---------------------- TEST TWO -------------------" << std::endl;
	test_two();
	std::cout << "---------------------- TEST THREE -------------------" << std::endl;
	test_three();
	std::cout << "---------------------- TEST FOUR -------------------" << std::endl;
	test_four();
	return(0);

}
