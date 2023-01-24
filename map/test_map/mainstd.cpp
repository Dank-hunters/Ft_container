#include <map>
#include <list>
#include "../map.hpp"

#define TESTED_NAMESPACE std

#define _pair TESTED_NAMESPACE::pair


template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo

template <typename T>
T	inc(T it, int n)
{
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}
////////////////////////////////////////// common


template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T1, typename T2>
void	printReverse(TESTED_NAMESPACE::map<T1, T2> &mp)
{
	typename TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << printPair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}


//////////////////////////////////////////////////////////////tester


#define TL1 char
#define DEF foo<float>
typedef TESTED_NAMESPACE::map<TL1, DEF> _map;
typedef _map::const_iterator const_it;

static unsigned int i = 0;

void	ft_comp(const _map &mp, const const_it &it1, const const_it &iDEF)
{
	bool res[2];

	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = mp.key_comp()(it1->first, iDEF->first);
	res[1] = mp.value_comp()(*it1, *iDEF);
	std::cout << "with [" << it1->first << " and " << iDEF->first << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}

int		test_zero(void)
{
	_map	mp;

	mp['a'] = 2.3;
	mp['b'] = 1.4;
	mp['c'] = 0.3;
	mp['d'] = 4.2;
	printSize(mp);

	for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
		for (const_it iDEF = mp.begin(); iDEF != mp.end(); ++iDEF)
			ft_comp(mp, it1, iDEF);

	printSize(mp);
	return (0);
}

#define T1 int
#define TU2 std::string
typedef TESTED_NAMESPACE::map<T1, TU2>::value_type TU3;

int		test_one(void)
{
	std::list<TU3> lst;
	std::list<TU3>::iterator itlst;

	lst.push_back(TU3(42, "lol"));
	lst.push_back(TU3(50, "mdr"));
	lst.push_back(TU3(35, "funny"));
	lst.push_back(TU3(45, "bunny"));
	lst.push_back(TU3(21, "fizz"));
	lst.push_back(TU3(35, "this key is already inside"));
	lst.push_back(TU3(55, "fuzzy"));
	lst.push_back(TU3(38, "buzz"));
	lst.push_back(TU3(55, "inside too"));

	std::cout << "List contains: " << lst.size() << " elements." << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		printPair(itlst);
	std::cout << "---------------------------------------------" << std::endl;

	TESTED_NAMESPACE::map<T1, TU2> mp(lst.begin(), lst.end());
	lst.clear();

	printSize(mp);

	return (0);
}

#define VE char
#define VA int
typedef _pair<const VE, VA> TD3;

template <class T>
void	is_empty(T const &mp)
{
	std::cout << "is_empty: " << mp.empty() << std::endl;
}

int		test_two(void)
{
	std::list<TD3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(TD3('a' + i, lst_size - i));

	TESTED_NAMESPACE::map<VE, VA> mp(lst.begin(), lst.end()), mp2;
	TESTED_NAMESPACE::map<VE, VA>::iterator it;

	lst.clear();
	is_empty(mp);
	printSize(mp);

	is_empty(mp2);
	mp2 = mp;
	is_empty(mp2);

	it = mp.begin();
	for (unsigned long int i = 3; i < mp.size(); ++i)
		it++->second = i * 7;

	printSize(mp);
	printSize(mp2);

	mp2.clear();
	is_empty(mp2);
	printSize(mp2);
	return (0);
}




#define TI1 int
#define TI2 std::string
typedef _pair<const TI1, TI2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

int		test_three(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	TESTED_NAMESPACE::map<TI1, TI2> mp(lst.begin(), lst.end());
	printSize(mp);

	ft_erase(mp, ++mp.begin());

	ft_erase(mp, mp.begin());
	ft_erase(mp, --mp.end());

	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	ft_erase(mp, --(--(--mp.end())), --mp.end());


	mp[10] = "Hello";
	mp[11] = "Hi there";
	std::cout << "la il ajhoute ta mere " << std::endl;
	
	printSize(mp);
	
	ft_erase(mp, --(--(--mp.end())), mp.end());
	std::cout << "ici ?" << std::endl;

	mp[12] = "ONE";
	mp[13] = "TWO";
	mp[14] = "THREE";
	mp[15] = "FOUR";
	printSize(mp);
	ft_erase(mp, mp.begin(), mp.end());

	mp[10] = "TEST DU CRASH";

	TESTED_NAMESPACE::map<TI1, TI2>::iterator i;
	i = mp.begin();
	std::cout << mp.begin()->first << std::endl;
	return (0);
}



#define YU int
#define YA int
typedef _pair<const YU, YA> TO;

int		test_seven(void)
{
				std::cout << "bite" << std::endl;

	std::list<TO> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(TO(lst_size - i, i));
				std::cout << "bite" << std::endl;

	TESTED_NAMESPACE::map<YU, YA> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<YU, YA>::iterator it = mp.begin(), ite = mp.end();
				std::cout << "bite" << std::endl;

	TESTED_NAMESPACE::map<YU, YA> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	TESTED_NAMESPACE::map<YU, YA> mp_copy(mp);
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
#define TS3 foo<int>
typedef TESTED_NAMESPACE::map<T1, TS3>::value_type TS4;
typedef TESTED_NAMESPACE::map<T1, TS3>::iterator ft_iterator;
typedef TESTED_NAMESPACE::map<T1, TS3>::const_iterator ft_const_iterator;

static int issou = 0;

template <typename MAP>
void	ft_bound(MAP &mp, const T1 &param)
{
	ft_iterator ite = mp.end(), it[2];
	_pair<ft_iterator, ft_iterator> ft_range;

	std::cout << "\t-- [" << issou++ << "] --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;

	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
//	std::cout << "first" << ft_range.first->first << "    " << it[0] << std::endl;
//	std::cout << "first" << ft_range.second->first << "    " << it[1] << std::endl;
}

template <typename MAP>
void	ft_const_bound(const MAP &mp, const T1 &param)
{
	ft_const_iterator ite = mp.end(), it[2];
	_pair<ft_const_iterator, ft_const_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

int		test_six(void)
{
	std::list<TS4> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(TS4(i + 1, (i + 1) * 3));
	TESTED_NAMESPACE::map<T1, TS3> mp(lst.begin(), lst.end());
	printSize(mp);
	ft_const_bound(mp, -10);
	ft_const_bound(mp, 1);
	ft_const_bound(mp, 5);
	ft_const_bound(mp, 10);
	ft_const_bound(mp, 50);

	printSize(mp);

	mp.lower_bound(3)->second = 404;
	mp.upper_bound(7)->second = 842;
	ft_bound(mp, 5);
	ft_bound(mp, 7);

	printSize(mp);
	return (0);
}

#define DI std::string
#define DU std::string

template <typename It>
void print_map(It first, It last)
{
    for (; first != last; ++first) {
        std::cout << "K: " << first->first << " V: " << first->second << " ";
    }
    std::cout << std::endl;
}

int test_five()
{
	TESTED_NAMESPACE::map<DI, DU>	m;
	TESTED_NAMESPACE::map<DI, DU>::const_iterator it;
	TESTED_NAMESPACE::map<DI, DU>::const_iterator ite;
	
	std::cout <<  "size before add" <<  m.size() << std::endl;
	
	m.erase("");

		m.insert(TESTED_NAMESPACE::make_pair("", "")); //del
        m.insert(TESTED_NAMESPACE::make_pair("123", "kjhgfdsdffghsfghdfgh"));//
        m.insert(TESTED_NAMESPACE::make_pair("1234", "gfdsadgg"));//
        m.insert(TESTED_NAMESPACE::make_pair("123456789123456789123456789", "49857459898674568464"));//
        m.insert(TESTED_NAMESPACE::make_pair("0", "2345456456456456"));//
        m.insert(TESTED_NAMESPACE::make_pair("", ""));//
        m.insert(TESTED_NAMESPACE::make_pair("", "9459845984598498"));//
        m.insert(TESTED_NAMESPACE::make_pair("000000000000000000000000", "1111111111111111111111111111"));

	m.erase("1");
	print_map(m.begin(), m.end());

	m.erase("123");
	print_map(m.begin(), m.end());

	m.erase("123");
	print_map(m.begin(), m.end());

	m.erase("");
	print_map(m.begin(), m.end());


	m.erase("1234");
	print_map(m.begin(), m.end());

	m.erase("123456789123456789123456789");
	print_map(m.begin(), m.end());
	 std::cout << "\nMap content:\n" << std::endl; 

	m.erase("000000000000000000000000");
	print_map(m.begin(), m.end());


	m.erase("0");
	print_map(m.begin(), m.end());
	m.erase("000000000000000000000000");
 
	return(0);
}


int main()
{
	test_zero();
	test_one();
	test_two();
	test_three();
	test_five();
	test_six();
	test_seven();
	return(0);
}