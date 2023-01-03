#pragma once 

#include "tree.hpp"
#include "bidirectional_iterator.hpp"

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > > 
class map
{
public:
	typedef Key																		key_type;
	typedef T 																		mapped_type;
	typedef	ft::pair<const key_type, mapped_type>									value_type; //sa mere la pute ca pue sa mere les const
	typedef	ft::pair<key_type, mapped_type>											used_value_type; //sa mere la pute ca pue sa mere les const
	typedef Compare 																key_compare;

			/*						
	class value_compare
	{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
		  friend class map;
		protected:
  			key_compare comp;
  			value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			typedef bool 								result_type;
 
  			bool operator() (const value_type& x, const value_type& y) const
 			 {
 			   return comp(x.first, y.first);
 			 }
	};*/
//	typedef value_compare															value_comp;
	typedef Alloc																	allocator_type;

	typedef typename allocator_type::reference										reference;
	typedef typename allocator_type::const_reference            					const_reference;
	typedef typename allocator_type::pointer                    					pointer;
	typedef typename allocator_type::const_pointer              					const_pointer;
	
	typedef bidirectional_iterator<used_value_type >									iterator;
	typedef bidirectional_iterator<used_value_type >									const_iterator;
	typedef reverse_iterator<iterator>											reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;

	typedef typename ft::iterator_traits<iterator>::difference_type 				difference_type;
	typedef size_t                                              					size_type;
	
	typedef	tree<used_value_type, key_compare>								tree_type;
	typedef	Node<used_value_type>								trees_type;
private:

	tree_type																		Avl;

public:

//	value_compare value_comp() const {return(value_compare());}


	map():Avl(){}
	~map(){}


	iterator begin()
	{
		return(Avl.begin());
	}
	iterator end()
	{
		return(Avl.end());
	}
	reverse_iterator rbegin()
	{
		iterator	it(Avl.end());
		return(reverse_iterator(it));
	}
	reverse_iterator rend()
	{

		iterator	it(Avl.begin());
		return(reverse_iterator(it));
	}
	void	erase(const used_value_type &val)
	{
		Avl.erase(val);
	}
	trees_type	*get_root()
	{
		return Avl.get_root();
	}
	bool empty() const
	{
		if (Avl.get_root() == NULL)
			return(true);
		return false;
	}
	size_type size() const
	{
		return Avl.size();
	}




	////////////////// modificateur ///////////////




		pair<iterator,bool> insert (const value_type& val)
		{
			return(Avl.insert(val));
		}
		//iterator insert (iterator position, const value_type& val)
		//{}

		template <class InputIterator>  
		void insert (InputIterator first, InputIterator last)
		{
			InputIterator tmp = first;

			//Avl.insert(ft::make_pair<key_type, mapped_type>(tmp->first, tmp->second));

			while(tmp != last)
			{
				Avl.insert(ft::make_pair<key_type, mapped_type>(tmp->first, tmp->second));
				tmp++;

			}

		}

};

}

//value_compare	Nested function class to compare elements	see value_comp