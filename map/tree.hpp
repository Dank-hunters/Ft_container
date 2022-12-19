#pragma once
#include <memory>
#include <iterator>
#include <algorithm>
#include "../includes/iterator_vector.hpp"
#include "../includes/enable_if.hpp"
#include "../includes/compare.hpp"
#include "../includes/reverse_iterator.hpp"
//#include "../includes/bidirectional_iterator.hpp"

#include "../includes/pair.hpp"
namespace ft
{

	template <class _K, class _P>
	class Node
	{
		public :
		typedef ft::pair<_K, _P>     value_type;
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


	template <class _K, class _P, class Compare=std::less<_K>, class Alloc=std::allocator<Node<_K, _P> > >
	class tree
	{

	public:
			typedef ft::pair<_K, _P>														value_type;
			typedef _K														key_type;
			typedef _P														val_type;
			typedef Compare													compare_type;
			typedef Alloc													allocator_type;
			//typedef Node<_k, _P>										node_value;
			typedef Node<_K, _P>										*node_ptr;
			typedef size_t 													size_type;
	/* typedef ft::bidirectional_iterator<T>                       iterator;    
				typedef ft::const_bidirectional_iterator<T>                       const_iterator;
                typedef  ft::reverse_iterator<iterator>                     reverse_iterator;    
				typedef  ft::reverse_iterator<const_iterator>               const_reverse_iterator;*/
	private:
			int _truc;
			allocator_type													_alloc;	
			compare_type													_compare;
			node_ptr														_root;
			size_type														_size;
	public :
		
		
		tree(const compare_type &comp = compare_type(), const allocator_type &alloc = allocator_type()) : _truc(0), _alloc(alloc), _compare(comp), _root(NULL), _size(0)
		{}        
	/*	tree(const tree &x): _alloc(NULL), _compare(NULL), _root(NULL), _size(0)
		{
			//deepthroat
		}        */

		~tree()
		{
			if (_root)
				clear_all(_root);
			_destroy_node(_root);
		}

		private :
		node_ptr	new_node(value_type const &val)
		{
			node_ptr node = _alloc.allocate(sizeof(node_ptr));
			_alloc.construct(node, val);
			return(node);
		}
		public :

		void	clear()
		{
			clear_all(_root);
		}
		void clear_all(node_ptr	&tmp)
		{
			node_ptr	save = 0;
				//std::cout << "deja ? " << tmp->val.second << std::endl;
			if (tmp->left)
				{
					clear_all(tmp->left);
				}
			else if (tmp->right)
				clear_all(tmp->right);
			else
			{
				save = tmp->daddy;
				_alloc.destroy(tmp);
				_alloc.deallocate(tmp, sizeof(node_ptr));
				tmp = NULL;

			}
			if (save != _root)
				{
				clear_all(_root);
				}
			else 
				return;
		}

		/*ft::pair<iterator,bool>*/ void insert (const value_type &val)
		{
			node_ptr	cursor = _root;
			node_ptr	prev = NULL;
			int		var = 0;

			while (cursor)
			{
				prev = cursor;
				if (_compare(val.first, cursor->val.first) && (var = 1))
					cursor = cursor->left;
				else if (_compare(cursor->val.first, val.first) && (var = 2))
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
			balancing(node->daddy);
			//return(ft::make_pair(iterator((node), _root), true));
			}


			void	_destroy_node(node_ptr &node)
			{
						_size--;
						if (_size == 0)
						{
						//	_root->daddy = NULL;
						//	_root->left = NULL;
						//	_root->right = NULL;
							_root = NULL;
						}

						_alloc.destroy(node);
						_alloc.deallocate(node, sizeof(node_ptr));
			}

		size_type erase (const key_type& val)
		{
		node_ptr    current;
		node_ptr    current_daddy;

        int            direction;
		current_daddy = NULL; 

        current = _root;
        direction = 0;
        while (current != NULL)
        {
            if (_compare(val, current->val.first) && (direction = 1))
                current = current->left;
            else if (_compare(current->val.first, val) && (direction = 2))
                current = current->right;
            else
                {
					current_daddy = current->daddy; 
					current = oblitarate(current, direction);
					balancing(current_daddy);
				}
		}
			//	std::cout << current_daddy->val.second << std::endl;

		return(0);
		}
			

    void    single_oblitarate(node_ptr &current)
    {
        node_ptr    prev;
        node_ptr    tmp;
        node_ptr    substitute;
        int            direction;

        prev = current->daddy;
        tmp = current;
        substitute = current->right;
        if (current->left != NULL)
            substitute = current->left;
        direction = 2;
		if (prev == NULL)
		{
			_root = substitute;
			_root->daddy = NULL;
			_destroy_node(current);
			return;
		}
        if (prev->left->val.first == current->val.first)
            direction = 1;
		else
			direction = 3;
        _destroy_node(tmp);
        if (direction == 1)
            prev->left = substitute;
        else
            prev->right = substitute;
		substitute->daddy = prev;
    }


    void    complex_oblitarate(node_ptr &remove)
    {
        node_ptr		substitute;
        node_ptr		current;
        node_ptr		prev;
        key_type    save_key;
        val_type    save_val;

        current = remove;
        prev = remove->daddy;
        current = current->right;
        while (current != NULL)
        {
            substitute = current;
            current = current->left;
        }
        save_key = substitute->val.first;
        save_val = substitute->val.second;
        erase(save_key);
        remove->val.first = save_key; //potentiel problem avec la validite des iterateurs
        remove->val.second = save_val; //potentiel problem avec la validite des iterateurs
    }
    node_ptr	oblitarate(node_ptr &current, const int &direction)
    {
        node_ptr prev;

        prev = current->daddy;
        if (current->left == NULL && current->right == NULL)
		{
			if (_size != 1)
			{
            	_destroy_node(current);
            	(direction == 1) ? prev->left = NULL : prev->right = NULL;
			}
			else 
				_destroy_node(current);
		}
		else if (current->left != NULL && current->right != NULL)
				complex_oblitarate(current);
        else
            single_oblitarate(current);
		return (NULL);
    }

  


	void	RR_rotate(node_ptr grandpa, node_ptr parent)
	{
		std::cout << "RR" << std::endl;
		node_ptr	tie;
		tie = grandpa->daddy;
		grandpa->left = parent->right;
		if (parent->right != NULL)
			parent->right->daddy = grandpa;
		parent->right = grandpa;
		parent->daddy = tie;
		grandpa->daddy = parent;
		if (tie == NULL)
		{
			_root = parent;
			return ;
		}
		if (tie->left == grandpa)
			tie->left = parent;
		else
			tie->right = parent;

	}

	void	LL_rotate(node_ptr grandpa, node_ptr parent)
	{
		node_ptr	tie;

		std::cout << "LL" << std::endl;
			
		tie = grandpa->daddy;
		grandpa->right = parent->left;
		if (parent->left != NULL)
			parent->left->daddy = grandpa;
		parent->left = grandpa;
		parent->daddy = tie;
		grandpa->daddy = parent;
		if (tie == NULL)
		{
			_root = parent;
			return ;
		}
		if (tie->left == grandpa)
			tie->left = parent;
		else
			tie->right = parent;

	}

	void	LR_rotate(node_ptr grandpa, node_ptr parent, node_ptr child)
	{
		node_ptr	tie;
		node_ptr	ltmp;
		node_ptr	rtmp;

		std::cout << "LR" << std::endl;

		tie = grandpa->daddy;
		ltmp = child->left;
		rtmp = child->right;
		child->left = parent;
		child->right = grandpa;
		parent->daddy = child;
		parent->right = ltmp;
		if (ltmp)
			ltmp->daddy = parent;
		grandpa->daddy = child;
		grandpa->left = rtmp;
		if (rtmp)
			rtmp->daddy = grandpa;
		if (tie == NULL)
		{
			_root = child;
			child->daddy = NULL;
			return ;
		}
		if (tie->left == grandpa)
			tie->left = child;
		else
			tie->right = child;
		child->daddy = tie;
	}

	void	RL_rotate(node_ptr grandpa, node_ptr parent, node_ptr child)
	{
		node_ptr	tie;
		node_ptr	ltmp;
		node_ptr	rtmp;
		std::cout << "RL" << std::endl;

		tie = grandpa->daddy;
		ltmp = child->left;
		rtmp = child->right;
		child->left = grandpa;
		child->right = parent;
		parent->daddy = child;
		parent->left = rtmp;
		if (rtmp != NULL)
			rtmp->daddy = parent;
		grandpa->daddy = child;
		grandpa->right = ltmp;
		if (ltmp != NULL)
			ltmp->daddy = grandpa;
		if (tie == NULL)
		{
			_root = child;
			child->daddy = NULL;
			return ;
		}
		if (tie->left == grandpa)
			tie->left = child;
		else
			tie->right = child;
		child->daddy = tie;
	}

	void	settruc()
	{
		_truc = 1;
	}
	void	balancing(node_ptr current)
	{
		int		left_height = 0;
		int		right_height = 0;
		int		factor;

		while (current != NULL)
		{
			if (current->left != NULL)
				left_height = 1 + get_sub_height(current->left);
			if (current->right != NULL)
				right_height = 1 + get_sub_height(current->right);
			factor = left_height - right_height;
			if (factor > 1 || factor < -1)
				choose_rotate(current, factor);
			current = current->daddy;
		}
	}


	void	choose_rotate(node_ptr current, int factor)
    {
        int        left_height;
        int        right_height;

        left_height = 0;
        right_height = 0;
        if (factor > 1)
        {
            if (current->left->left != NULL)
                left_height = 1 + get_sub_height(current->left->left);
            if (current->left->right != NULL)
                right_height = 1 + get_sub_height(current->left->right);
            factor = left_height - right_height;
            if (factor > 0)
                RR_rotate(current, current->left);
            else
                LR_rotate(current, current->left, current->left->right);

        }
        else
        {
            if (current->right->left != NULL)
                left_height = 1 + get_sub_height(current->right->left);
            if (current->right->right != NULL)
                right_height = 1 + get_sub_height(current->right->right);
            factor = left_height - right_height;
            if (factor > 0)
                RL_rotate(current, current->right, current->right->left);
            else
                LL_rotate(current, current->right);
        }
    }

	int		get_sub_height(node_ptr current)
	{
		int		left_height;
		int		right_height;

		left_height = 0;
		right_height = 0;
		if (current == NULL)
			return (0);
		if (current->right != NULL)
			++right_height += get_sub_height(current->right);
		if (current->left != NULL)
			++left_height += get_sub_height(current->left);
		if (left_height > right_height)
			return (left_height);
		return (right_height);
	}



		node_ptr 	get_root()
		{
			return(_root);
		}

	};
	
}