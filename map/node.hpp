#pragma once 
#include "../includes/pair.hpp"

namespace ft
{
	template <class Pair>
	class Node
	{
		public :
		typedef Pair    value_type;
		Node            *left;    
		Node            *right;    
		Node            *daddy;    
		Node 			*end;
		bool			print;
		value_type      val;
		

		Node():  left(NULL), right(NULL), daddy(NULL), end(NULL), print(1), val(){}
		Node(const value_type &val): left(NULL), right(NULL), daddy(NULL), end(NULL), print(1), val(val)
		{} 
		value_type *get_pair()
		{
			if (print == 0)
				return(NULL);
			return (val);

		}
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
			if (p->left)
				std::cout << "NULLLLL" << std::endl;
			while (p && tmp == p->left)
			{
				tmp = p;
				p = p->daddy;
			}
			return p;
		}

	};
		
/*	Node	*next()
	{
		Node		*current;

		current = this;
		if (current->right == NULL)
		{
			current = current->daddy;
			if (current->right == this)
			{
				current = current->daddy;
				while (current && current->right == NULL)
					current = current->daddy;
				if (current && current->daddy == NULL)
					return (NULL);
			}
			return (current);
		}
		else
		{
			current = current->right;
			while (current->left != NULL)
				current = current->left;
			return (current);
		}
	}

	
	Node	*prev()
	{
		Node		*current;
		Node		*previous;

		current = this;
		if (current->left == NULL)
		{
			current = current->daddy;
			if (current->left == this)
			{
				previous = current;
				current = current->daddy;
				while (current->left == NULL ||
						(current->left != NULL && current->left == previous))
				{
					if (current->daddy == NULL)
						return (NULL);
					previous = current;
					current = current->daddy;
				}
			}
			return (current);
		}
		else
		{
			current = current->left;
			while (current->right != NULL)
				current = current->right;
			return (current);
		}
	};
	}*/

}