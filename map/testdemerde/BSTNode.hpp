/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:36:53 by frdescam          #+#    #+#             */
/*   Updated: 2022/11/03 14:28:55 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSTNODE_HPP
# define BSTNODE_HPP

namespace ft
{
	template<class Pair>
	struct BSTNode
	{
		BSTNode* 	parent;
		BSTNode* 	left;
		BSTNode* 	right;
		Pair		value;

		explicit BSTNode() : parent(NULL), left(NULL), right(NULL), value()
		{
			/* NOP */
		}

		explicit BSTNode(const Pair &data): parent(NULL), left(NULL), right(NULL), value(data)
		{
			/* NOP */
		}

		~BSTNode(void)
		{
			/* NOP */
		}

		BSTNode(const BSTNode &x) :
				parent(x.parent),
				left(x.left),
				right(x.right),
				value(x.value)
		{
			/* NOP */
		}

		BSTNode &operator=(const BSTNode &x)
		{
			if (this != &x)
			{
				parent = x.parent;
				left = x.left;
				right = x.right;
				value = x.value;
			}
			return *this;
		}

		BSTNode *findMin(BSTNode *node)
		{
			if (!node)
				return NULL;
			while (node->left)
				node = node->left;
			return node;
		}

		BSTNode *findMax(BSTNode *node)
		{
			if (!node)
				return NULL;
			while (node->right)
				node = node->right;
			return node;
		}

		BSTNode *next(void)
		{
			BSTNode* tmp = this;

			if (tmp->right)
				return findMin(tmp->right);

			BSTNode* tmpparent = tmp->parent;

			while (tmpparent && tmp == tmpparent->right)
			{
				tmp = tmpparent;
				tmpparent = tmpparent->parent;
			}
			return tmpparent;
		}

		BSTNode *prev(void)
		{
			BSTNode *tmp = this;

			if (tmp->left)
				return findMax(tmp->left);

			BSTNode* p = tmp->parent;
			while (p && tmp == p->left)
			{
				tmp = p;
				p = p->parent;
			}
			return p;
		}
	};
}

#endif

