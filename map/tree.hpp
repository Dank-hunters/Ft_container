#pragma once
#include <memory>
#include <iterator>
#include <algorithm>
#include "../includes/iterator_vector.hpp"
#include "../includes/enable_if.hpp"
#include "../includes/compare.hpp"
#include "../includes/reverse_iterator.hpp"
#include "../includes/bidirectional_iterator.hpp"

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
		int 			height;
		


		Node(const value_type &val): left(NULL), right(NULL), daddy(NULL), val(val), height(1){} 

		Node	*mini(Node *search)
		{
			if (search->left == NULL)
				return (search);
			while (search->left)
				search = search->left;
			return (search);
		}

		Node	*maxi(Node *search)
		{
			if (search->right == NULL)
				return (search);
			while (search->right)
				search = search->right;
			return (search);
		}
		Node *next()
		{
			Node *tmp = this;
			if (tmp->right)
				return mini(tmp->right);

			Node* tmpdaddy = tmp->daddy;

			while (tmpdaddy && tmp == tmpdaddy->right)
			{
				tmp = tmpdaddy;
				tmpdaddy = tmpdaddy->daddy;
			}
			return tmpdaddy;
		}
		Node *prev(void)
		{
			Node *tmp = this;

			if (tmp->left)
				return maxi(tmp->left);

			Node* p = tmp->daddy;
			while (p && tmp == p->left)
			{
				tmp = p;
				p = p->daddy;
			}
			return p;
		}
		static int	get_height(Node* node) {
			if (node == NULL)
				return (0);
			return (node->height);
		}
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
	 typedef ft::bidirectional_iterator<T>                       iterator;    
				typedef ft::const_bidirectional_iterator<T>                       const_iterator;
                typedef  ft::reverse_iterator<iterator>                     reverse_iterator;    
				typedef  ft::reverse_iterator<const_iterator>               const_reverse_iterator;
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
			static int	get_height(node_ptr node) {
			if (node == NULL)
				return (0);
			return (node->height);
		}

	node_ptr	left_rotation(node_ptr node) {
			if (node == NULL)
				return (node);

			node_ptr	y = node->right;
			node_ptr	t2 = y->left;

			node->right = t2;
			y->left = node;

			if (node == _root)
				_root = y;

			y->daddy = node->daddy;
			if (node == node->daddy->left)
				node->daddy->left = y;
			else
				node->daddy->right = y;
			if (t2)
				t2->daddy = node;
			node->daddy = y;

			node->height = 1 + std::max(get_height(node->left), get_height(node->right));
			y->height = 1 + std::max(get_height(y->left), get_height(y->right));

			return (y);
		}

node_ptr	right_rotation(node_ptr node) {
			if (node == NULL)
				return (node);

			node_ptr	y = node->left;
			node_ptr	t3 = y->right;
			if (node == _root)
				_root = y;

			y->daddy = node->daddy;
			if (node == node->daddy->left)
				node->daddy->left = y;
			else
				node->daddy->right = y;
			if (t3)
				t3->daddy = node;
			node->left = t3;
			y->right = node;

			node->daddy = y;

			node->height = 1 + std::max(get_height(node->left), get_height(node->right));
			y->height = 1 + std::max(get_height(y->left), get_height(y->right));

			return (y);
		}



int	get_balance_factor(node_ptr node) {
			if (node == NULL)
				return (0);
			return (get_height(node->left) - get_height(node->right));
		}


node_ptr	balance_tree(node_ptr& node) {
			int	balance = get_balance_factor(node);

			if (node == NULL)
				return (node);
			if (balance > 1 && get_balance_factor(node->left) == 1) {
				node = right_rotation(node);
				return (node);
			}

			if (balance < -1 && get_balance_factor(node->right) == -1) {
				node = left_rotation(node);
				return (node);
			}

			if (balance > 1 && get_balance_factor(node->left) == -1) {
				node->left = left_rotation(node->left);
				node = right_rotation(node);
				return (node);
			}

			if (balance < -1 && get_balance_factor(node->right) == 1) {
				node->right = right_rotation(node->right);
				node = left_rotation(node);
				return (node);
			}

			return (node);

}

void	do_balance(node_ptr node) {
			if (node == NULL)
				return ;
			while (node != _root) 
			{
				node->height = 1 + std::max(get_height(node->left), get_height(node->right));
				balance_tree(node);
				node = node->daddy;
			}
		}


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
			do_balance(node);
			//return(ft::make_pair(iterator((node), _root), true));
			}


			void	_destroy_node(node_ptr &node)
			{
						_alloc.destroy(node);
						_alloc.deallocate(node, 1);
						_size--;
						if (_size == 0)
						{
							_root->daddy = NULL;
							_root->left = NULL;
							_root->right = NULL;
							_root = NULL;
						}
			}


		node_ptr root()
		{
			return(_root);
		}
		size_type erase (const value_type& val)
		{
			node_ptr	cursor = _root;
		/*	if (!_compare(val, _root->val) && !_compare(_root->val, val))
			{
				node_ptr tm;
				if (cursor->left)
					tm = cursor->mini(cursor);
				else 
					tm = cursor->mini(cursor->right);
				tm->daddy->left = NULL;
				_root = tm;
				_root->daddy = NULL;
				if (cursor->left)
				{
				//dprintf(1, "%i\n", tm->val);
					_root->left = cursor->left;
					cursor->left->daddy = _root;
				}
				if (cursor->right)
				{
			//	dprintf(1, "%i\n", cursor->val);
					_root->right = cursor->right;
					cursor->right->daddy = _root;
				}
				_destroy_node(cursor);

				return(1);
			}*/
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
						node_ptr tmp = cursor->next();
						if (tmp == cursor->right)
						{
							if (!cursor->daddy)
								_root = tmp;
							else if (cursor->daddy->right == cursor)
								cursor->daddy->right = tmp;
							else
								cursor->daddy->left = tmp;
							cursor->left->daddy = tmp;
							tmp->daddy = cursor->daddy;
							tmp->left = cursor->left;
						}
						else
						{
							if (tmp->right)
							{
								tmp->daddy->left = tmp->right;
								tmp->right->daddy = tmp->daddy;
							}
							if (!cursor->daddy)
								_root = tmp;
							else if(cursor->daddy->right == cursor)
								cursor->daddy->right = tmp;
							else
								cursor->daddy->left = tmp;
							if(tmp->daddy->right == cursor)
								tmp->daddy->right = tmp;
							else
								tmp->daddy->left = tmp;
							tmp->daddy = cursor->daddy;
							tmp->left = cursor->left;
							tmp->right = cursor->right;
							cursor->left->daddy = tmp;
							cursor->right->daddy = tmp;
						}
					}
					else if (cursor->left && !cursor->right)
					{
						if (cursor->daddy->right == cursor)
							cursor->daddy->right = cursor->left;
						else
							cursor->daddy->left = cursor->right;
						cursor->left->daddy = cursor->daddy;

					}
					else if (cursor->right && !cursor->left)
					{
						if (cursor->daddy->right == cursor)
							cursor->daddy->right = cursor->right;
						else
							cursor->daddy->left = cursor->right;
						cursor->right->daddy = cursor->daddy;
					}
					else
					{
						if (cursor->daddy->left == cursor)
							cursor->daddy->left = NULL;
						else
							cursor->daddy->right = NULL;
					}
						do_balance(cursor->daddy);
						_destroy_node(cursor);

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