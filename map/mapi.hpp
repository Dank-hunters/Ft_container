#pragma once
#include <iostream>

namespace ft
{
	template <class key, class T>
	class Node
	{
	private:

	public:
	Node *left;
	Node *right;
	Node *daddy;
	int size;

		Node() : left(NULL), right(NULL), daddy(NULL), size(0){}
		Node(Node *newone) : left(NULL), right(NULL), daddy(newone), size(1){}
		~Node();
	
	
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
			return (node->size);
		}
	
	
	};
	template <class key, class T>
		class Nodi : public Node
		{
		public:
			typedef typename ft::pair<const Key, T> 						value_type;
			value_type  pair;

		public:
			Nodi(value_type pair, Node* parent) : Node(parent), pair(pair) { }

		};


	
	








	/*
	class map
	{
	private:
	public:
		map();
		~map();
	};
	
	
	*/


}