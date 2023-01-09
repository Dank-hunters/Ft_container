#pragma once 
#include "../includes/pair.hpp"

namespace ft
{
	template <class Pair>
	class Node
	{
		public :
		typedef Pair    value_type;
		typedef size_t	size_type;
		Node            *left;    
		Node            *right;    
		Node            *daddy;    
		Node 			*end;
		Node *max;
		bool			print;
		value_type      val;
		

		Node():  left(NULL), right(NULL), daddy(NULL), end(NULL), max(NULL),  print(1), val(NULL){}
		Node(const value_type &val): left(NULL), right(NULL), daddy(NULL), end(NULL), max(NULL),  print(1), val(val)
		{} 
		//Node (const Node &copy): left()
		value_type *get_pair()
		{
			//std::cout << "address : " << this << "|" <<  std::endl;
			if (print == 0)
				return(NULL);
			return (&val);


		}
		Node	*mini(Node *search) const
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
	
	//		if (max == NULL)
	//		{
	//			//return(NULL);
	//			std::cout << "dfddddddddddddddddddd" << std::endl;
	//		}
			//std::cout << "le tmp " << tmp->val.first << std::endl /*<< " le max " << std::endl << max->val.first */<< std::endl;
			//if (tmp && tmp->daddy != NULL)
			//	std::cout << "le dad " << tmp->daddy->val.first;
				//std::cout << "testi " << std::endl;
			if (/*tmp &&*/ tmp == max)
			{
			//	std::cout << "je suis au max de ma forme wesh " << tmp->val.first << " | " << max->val.first <<std::endl;
				return(end);
			}
			if (tmp->right)
			{
				return mini(tmp->right);
			}
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
		//	if (tmp != NULL)
		//		std::cout << "test " << std::endl;
		//	std::cout << tmp->val.first << std::endl;
			if (tmp->left != NULL)
				return maxi(tmp->left);

			Node* p = tmp->daddy;
			while (p && tmp == p->left)
			{
				tmp = p;
				p = p->daddy;
			}
			return p;
		}
		size_type	size(Node *N) const
		{
			if (N == NULL)
				return(0);
			Node *tmp;
			tmp = mini(N);
			//tmp = tmp->mini(N);
			size_type size = 0;
			while (tmp != NULL && tmp != end)
			{

			//std::cout << "le plus petit :" << tmp->val.first << std::endl;
			//		std::cout << tmp->val.first << std::endl;
					tmp = tmp->next();
					//if (tmp == NULL)
					//	std::cout << "ntmmmmmmmmmmmmmmmm" << std::endl;
					size++;
			}
			return (size);

		}

	};/*
	
	Node	*next()
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
	}
	};
*/
}
