#pragma once
#include <memory>
#include <iterator>
#include "../includes/iterator_vector.hpp"
#include "../includes/enable_if.hpp"
#include "../includes/compare.hpp"
#include "../includes/reverse_iterator.hpp"
#include "../includes/pair.hpp"
namespace ft
{

	template <class _P>
	class Node
	{
		public :
		typedef _P     value_type;
		Node            *left;    
		Node            *right;    
		Node            *daddy;    
		value_type      val;
		


		Node(const value_type &val): left(NULL), right(NULL), daddy(NULL), val(val){} 
		~Node();
	};


	template <class _P, class Compare=std::less<_P>, class Alloc=std::allocator<Node<_P> > >
	class tree
	{

	public:
			typedef _P														value_type;
			typedef Compare													compare_type;
			typedef Alloc													allocator_type;
			typedef Node<value_type>										node_value;
			typedef Node<value_type>										*node_ptr;
			typedef size_t 													size_type;
			typedef std::__is_bidirectional_iterator<node_value>			iterator;
			typedef std::__is_bidirectional_iterator<const node_value>		const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
	private:
			allocator_type													_alloc;	
			compare_type													_compare;
			node_ptr														_root;
			size_type														_size;
	public :
		
		
		tree(const compare_type &comp = compare_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _compare(comp), _root(NULL), _size(0)
		{}        
	/*	tree(const tree &x): _alloc(NULL), _compare(NULL), _root(NULL), _size(0)
		{
			//deepthroat
		}        */

		~tree()
		{
		//clear();
		}

		private :
		node_ptr	new_node(value_type const &val)
		{
			node_ptr node = _alloc.allocate(1);
			_alloc.construct(node, val);
			return(node);
		}
		public :
		/*ft::pair<iterator,bool>*/ void insert (const value_type &val)
		{
			node_ptr	cursor = _root;
			node_ptr	prev = NULL;
			int		var = 0;
			while (cursor)
			{
				prev = cursor;
				if (_compare(val, cursor->val) && (var = 1))
					cursor = cursor->left;
				else if (_compare(cursor->val, val) && (var = 2))
					cursor = cursor->right;
				else
					return;// (ft::make_pair(iterator(cursor, _root), false));
			}
			node_ptr node = new_node(val);
			_size++;
			node->daddy = prev;
			if (var == 1)
				prev->left = node;
			else if (var == 2)
				prev->right = node;
			else 
				_root = node;
			//return(ft::make_pair(iterator((node), _root), true));
			}
			void	_destroy_node(node_ptr &node)
			{
						//_alloc.destroy(node);
						//_alloc.deallocate(node, 1);
						_size--;
			}
		size_type erase (const value_type& val)
		{
				node_ptr	cursor = _root;
				node_ptr	prev = NULL;
			while (cursor)
			{
				prev = cursor;
				if (_compare(val, cursor->val))
					cursor = cursor->left;
				else if (_compare(cursor->val, val))
					cursor = cursor->right;
				else
				{
					if (cursor->left && cursor->right)
					{
						

					}
					else if (cursor->left)
					{

					}
					else if (cursor->right)
					{

					}
					else
					{
						if (cursor->daddy->left == cursor)
							cursor->daddy->left = NULL;
						else
							cursor->daddy->right = NULL;
						_destroy_node(cursor);
					}
					return(1);
				}
			}
			return (0);


		}






		node_ptr 	get_root()
		{return(_root);}

//		iterator insert (iterator position, const value_type& val);


	};
	

	

}