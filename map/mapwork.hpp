
#pragma once
#include "../includes/enable_if.hpp"
#include "../includes/compare.hpp"
#include "../includes/reverse_iterator.hpp"
#include "../includes/iterator_traits.hpp"
#include "../includes/pair.hpp"
#include <memory>
#include <iterator>
#include <algorithm>
namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	private:
		class Bidirectional_Iterator;
		class Const_Bidirectional_Iterator;
		class BaseNode;
		class Node;

	public:
		typedef Key 													key_type;
		typedef T														mapped_type;
		typedef typename ft::pair<const Key, T> 						value_type;
		typedef std::size_t												size_type;
		typedef std::ptrdiff_t											difference_type;
		typedef Compare													key_compare;
		typedef Allocator												allocator_type;
		typedef value_type&												reference;
		typedef const value_type&										const_reference;
		typedef typename Allocator::pointer								pointer;
		typedef typename Allocator::const_pointer						const_pointer;
		typedef Bidirectional_Iterator												iterator;
		typedef Const_Bidirectional_Iterator											const_iterator;
		typedef typename ft::reverse_iterator<Bidirectional_Iterator>					reverse_iterator;
		typedef typename ft::reverse_iterator<Const_Bidirectional_Iterator>			const_reverse_iterator;
		typedef typename allocator_type::template rebind<Node>::other	node_allocator_type;

	private:
		key_compare			comp;
		node_allocator_type	alloc;
		BaseNode			meta;
		size_type			_size;

	private:
		BaseNode*& root() { return (meta.left); }
		const BaseNode* root() const { return (meta.left); }

		BaseNode* end_node() { return &meta; }
		const BaseNode* end_node() const { return &meta; }

		static int	get_height(BaseNode* node) {
			if (node == NULL)
				return (0);
			return (node->height);
		}

		int	get_balance_factor(BaseNode* node) {
			if (node == NULL)
				return (0);
			return (get_height(node->left) - get_height(node->right));
		}

		BaseNode*	left_rotation(BaseNode* node) {
			if (node == NULL)
				return (node);

			BaseNode*	y = node->right;
			BaseNode*	t2 = y->left;

			node->right = t2;
			y->left = node;

			if (node == root())
				root() = y;

			y->parent = node->parent;
			if (node == node->parent->left)
				node->parent->left = y;
			else
				node->parent->right = y;
			if (t2)
				t2->parent = node;
			node->parent = y;

			node->height = 1 + std::max(get_height(node->left), get_height(node->right));
			y->height = 1 + std::max(get_height(y->left), get_height(y->right));

			return (y);
		}

		BaseNode*	right_rotation(BaseNode* node) {
			if (node == NULL)
				return (node);

			BaseNode*	y = node->left;
			BaseNode*	t3 = y->right;
			if (node == root())
				root() = y;

			y->parent = node->parent;
			if (node == node->parent->left)
				node->parent->left = y;
			else
				node->parent->right = y;
			if (t3)
				t3->parent = node;
			node->left = t3;
			y->right = node;

			node->parent = y;

			node->height = 1 + std::max(get_height(node->left), get_height(node->right));
			y->height = 1 + std::max(get_height(y->left), get_height(y->right));

			return (y);
		}


		BaseNode*	balance_tree(BaseNode*& node) {
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

		BaseNode*	create(const value_type& pair, BaseNode* parent) {
			Node*	new_node;

			new_node = alloc.allocate(1);
			try {
				alloc.construct(new_node, Node(pair, parent));
			} catch(...) {
				alloc.deallocate(new_node, 1);
				throw ;
			}
			_size++;
			return (static_cast<BaseNode*>(new_node));
		}

		void	subtree_shift(BaseNode* node, BaseNode* new_node) {
			if (node == root())
				root() = new_node;
			else if (node == node->parent->left)
				node->parent->left = new_node;
			else if (node == node->parent->right)
				node->parent->right = new_node;
			if (new_node != NULL)
				new_node->parent = node->parent;
		}

		void	delete_BaseNode(BaseNode* node) {
			BaseNode* imbalance_node;
			if (node->left == NULL) {
				imbalance_node = node;
				subtree_shift(node, node->right);
				rebalance(imbalance_node);
			} else if (node->right == NULL) {
				imbalance_node = node;

				subtree_shift(node, node->left);
				rebalance(imbalance_node);
			} else {
				BaseNode* y = node->next();
				imbalance_node = y;
				if (y->parent != node) {
					imbalance_node = y->parent;
					subtree_shift(y, y->right);
					y->right = node->right;
					y->right->parent = y;
				}
				subtree_shift(node, y);
				y->left = node->left;
				y->left->parent = y;
				rebalance(imbalance_node);
			}
			remove_BaseNode(node);
		}

		void	remove_BaseNode(BaseNode* node) {
			this->alloc.destroy(static_cast<Node*>(node));
			this->alloc.deallocate(static_cast<Node*>(node), 1);
			_size--;
		}

		void	rebalance(BaseNode* node) {
			if (node == NULL)
				return ;
			while (node != &meta) {
				node->height = 1 + std::max(get_height(node->left), get_height(node->right));
				balance_tree(node);
				node = node->parent;
			}
		}

		BaseNode*	insert_BaseNode(BaseNode* node, BaseNode* parent, value_type pair) {
			if (node == NULL) {
				node = create(pair, parent);
				return (node);
			}
			if (value_comp()(pair, static_cast<Node*>(node)->pair))
				node->left = insert_BaseNode(node->left, node, pair);
			else if (value_comp()(static_cast<Node*>(node)->pair, pair))
				node->right = insert_BaseNode(node->right, node, pair);
			else
				return (node);

			node->height = 1 + std::max(get_height(node->left), get_height(node->right));

			return (balance_tree(node));
		}

		void	clear_BaseNode(BaseNode*& node) {
			if (node == NULL)
				return ;
			if (node->left != NULL)
				clear_BaseNode(node->left);
			if (node->right != NULL)
				clear_BaseNode(node->right);
			alloc.destroy(static_cast<Node*>(node));
			alloc.deallocate(static_cast<Node*>(node), 1);
			_size--;
			node = NULL;
		}

	private:

		class BaseNode
		{
		public:
			BaseNode*	left;
			BaseNode*	right;
			BaseNode*	parent;
			int			height;

		public:
			BaseNode(void) : left(NULL), right(NULL), parent(NULL), height(1) { }

			BaseNode(BaseNode* parent) : left(NULL), right(NULL), parent(parent), height(1) { }

			~BaseNode(void) { }

			BaseNode*	leftmost() {
				BaseNode* node = this;

				while (node->left)
					node = node->left;
				return (node);
			}

			const BaseNode*	leftmost() const {
				const BaseNode* node = this;

				while (node->left)
					node = node->left;
				return (node);
			}

			BaseNode*	rightmost() {
				BaseNode* node = this;

				while (node->right)
					node = node->right;
				return (node);
			}

			const BaseNode*	rightmost() const {
				const BaseNode* node = this;

				while (node->right)
					node = node->right;
				return (node);
			}

			BaseNode*	first() { return (this->leftmost()); }
			const BaseNode*	first() const { return (this->leftmost()); }

			BaseNode*	previous() {
				BaseNode* node = this;

				if (node->left)
					return (node->left->rightmost());

				BaseNode* parent_node = node->parent;
				while (node != parent_node->right) {
					node = parent_node;
					parent_node = node->parent;
				}
				return (node->parent);
			}

			const BaseNode*	previous() const {
				const BaseNode* node = this;

				if (node->left)
					return (node->left->rightmost());

				const BaseNode* parent_node = node->parent;
				while (node != parent_node->right) {
					node = parent_node;
					parent_node = node->parent;
				}
				return (node->parent);
			}

			BaseNode*	next() {
				BaseNode* node = this;

				if (node->right)
					return (node->right->leftmost());

				BaseNode* parent_node = node->parent;
				while (node != parent_node->left) {
					node = parent_node;
					parent_node = node->parent;
				}
				return (node->parent);
			}

			const BaseNode*	next() const {
				const BaseNode* node = this;

				if (node->right)
					return (node->right->leftmost());

				const BaseNode* parent_node = node->parent;
				while (node != parent_node->left) {
					node = parent_node;
					parent_node = node->parent;
				}
				return (node->parent);
			}

			Bidirectional_Iterator	iter() { return (iterator(this)); }
			Const_Bidirectional_Iterator	iter() const { return (Const_Bidirectional_Iterator(this)); }

		};

		class Node : public BaseNode
		{
		public:
			value_type  pair;

		public:
			Node(value_type pair, BaseNode* parent) : BaseNode(parent), pair(pair) { }

		};

		class Bidirectional_Iterator
		{
		protected:
			Node*	ptr;
			friend class Const_Bidirectional_Iterator;

		public:
			typedef ft::pair<const Key, T>			value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef value_type& 					reference;
			typedef	value_type*						pointer;
			typedef std::bidirectional_iterator_tag iterator_category;

			Bidirectional_Iterator() : ptr(NULL) { }

			Bidirectional_Iterator(BaseNode* base_node) : ptr(static_cast<Node*>(base_node)) { }

			Bidirectional_Iterator(Node* node) : ptr(node) { }

			Bidirectional_Iterator(const Bidirectional_Iterator& other) : ptr(other.ptr) { }

			~Bidirectional_Iterator() { }

			Bidirectional_Iterator&	operator=(const Bidirectional_Iterator& rhs) {
				ptr = rhs.ptr;
				return (*this);
			}

			friend bool	operator==(const Bidirectional_Iterator lhs, const Bidirectional_Iterator rhs) { return (lhs.ptr == rhs.ptr); }
			friend bool	operator!=(const Bidirectional_Iterator lhs, const Bidirectional_Iterator& rhs) { return (!(lhs.ptr == rhs.ptr)); }

			Bidirectional_Iterator&	operator++(void) {
				ptr = static_cast<Node*>(ptr->next());
				return (*this);
			}


			Bidirectional_Iterator	operator++(int) {
				Bidirectional_Iterator	it_temp = *this;
				ptr = static_cast<Node*>(ptr->next());
				return (it_temp);
			}

			Bidirectional_Iterator&	operator--(void) {
				ptr = static_cast<Node*>(ptr->previous());
				return (*this);
			}


			Bidirectional_Iterator	operator--(int) {
				Bidirectional_Iterator	it_temp = *this;
				ptr = static_cast<Node*>(ptr->previous());
				return (it_temp);
			}

			value_type&	operator*(void) const { return (ptr->pair); }
			value_type*	operator->(void) const { return (&(ptr->pair)); }
			BaseNode*	get_BaseNode(void) { return (static_cast<BaseNode*>(ptr)); }

		};

		class Const_Bidirectional_Iterator
		{
		protected:
			const Node*	ptr;

		public:
			typedef ft::pair<const Key, T>			value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef const value_type&				reference;
			typedef	const value_type*				pointer;
			typedef std::bidirectional_iterator_tag iterator_category;

			Const_Bidirectional_Iterator() : ptr(NULL) { }

			Const_Bidirectional_Iterator(const BaseNode* base_node) : ptr(static_cast<const Node*>(base_node)) { }

			Const_Bidirectional_Iterator(const Node* node) : ptr(node) { }

			Const_Bidirectional_Iterator(const Const_Bidirectional_Iterator& other) : ptr(other.ptr) { }

			Const_Bidirectional_Iterator(Bidirectional_Iterator other) : ptr(other.ptr) { }

			~Const_Bidirectional_Iterator() { }

			Const_Bidirectional_Iterator&	operator=(const Const_Bidirectional_Iterator& rhs) {
				ptr = rhs.ptr;
				return (*this);
			}

			friend bool	operator==(const Const_Bidirectional_Iterator lhs, const Const_Bidirectional_Iterator& rhs) { return (lhs.ptr == rhs.ptr); }
			friend bool	operator!=(const Const_Bidirectional_Iterator lhs, const Const_Bidirectional_Iterator& rhs) { return (!(lhs.ptr == rhs.ptr)); }

			Const_Bidirectional_Iterator&	operator++(void) {
				ptr = static_cast<const Node*>(ptr->next());
				return (*this);
			}


			Const_Bidirectional_Iterator	operator++(int) {
				Const_Bidirectional_Iterator	it_temp = *this;
				ptr = static_cast<const Node*>(ptr->next());
				return (it_temp);
			}

			Const_Bidirectional_Iterator&	operator--(void) {
				ptr = static_cast<const Node*>(ptr->previous());
				return (*this);
			}


			Const_Bidirectional_Iterator	operator--(int) {
				Const_Bidirectional_Iterator	it_temp = *this;
				ptr = static_cast<const Node*>(ptr->previous());
				return (it_temp);
			}

			const value_type&	operator*(void) const { return (ptr->pair); }
			const value_type*	operator->(void) const { return (&(ptr->pair)); }
		};

	public:
		class value_compare
		{

			friend class map;

		protected:
			Compare	comp;
			value_compare(Compare c) : comp(c)
			{}

		public:
			typedef bool		result_type;
			typedef	value_type	first_argument_type;
			typedef value_type	second_argument_type;

			bool	operator() (const value_type& lhs, const value_type& rhs) const { return (comp(lhs.first, rhs.first)); }
		};

		map(void) : comp(Compare()), alloc(std::allocator<ft::pair<const Key, T> >()), _size(0) { }

		explicit map(const Compare& comp, const Allocator& alloc = Allocator()) : comp(comp), alloc(alloc), _size(0) { }

		template< class InputIt >
		map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : comp(comp), alloc(alloc), _size(0) { insert(first, last); }

		map(const map& other) : alloc(other.alloc), _size(0) { *this = other; }

		~map(void) { clear(); }

		map&	operator=(const map& other) {
			clear();

			Const_Bidirectional_Iterator iter = other.begin();
			Bidirectional_Iterator	hint;

			if (iter != other.end()) {
				hint = insert(*iter).first;
				iter++;
			}
			for (; iter != other.end(); ++iter)
				hint = insert(hint, *iter);
			return (*this);
		}

		allocator_type	get_allocator(void) const { return (alloc); }

		/* ----- element access ----- */

		T& at(const Key& key) {
			Bidirectional_Iterator	it = find(key);
			if (it == end())
				throw (std::out_of_range("map::at:  key not found"));
			return (it->second);
		}

		T& operator[](const Key& key) {
			Bidirectional_Iterator	it = find(key);
			if (it != end())
				return ((*it).second);
			else
				return (insert(ft::make_pair(key, T())).first->second);
		}

		Bidirectional_Iterator begin(void) {
			Bidirectional_Iterator	it;

			if (root() == NULL)
				it = Bidirectional_Iterator(&meta);
			else
				it = Bidirectional_Iterator(root()->first());
			return (it);
		}

		Const_Bidirectional_Iterator begin(void) const {
			Const_Bidirectional_Iterator	it;

			if (root() == NULL)
				it = Const_Bidirectional_Iterator(&meta);
			else
				it = Const_Bidirectional_Iterator(const_cast<const BaseNode*>(root()->first()));

			return (it);
		}

		Bidirectional_Iterator end(void)
		{
			Bidirectional_Iterator	it(this->end_node());
			return (it);
		}

		Const_Bidirectional_Iterator end(void) const {
			Const_Bidirectional_Iterator	it(const_cast<const BaseNode*>(this->end_node()));
			return (it);
		}

		reverse_iterator	rbegin(void) {
			reverse_iterator	it(this->end());
			return (it);
		}

		const_reverse_iterator	rbegin(void) const {
			const_reverse_iterator	it(this->end());
			return (it);
		}

		reverse_iterator	rend(void) {
			reverse_iterator	it(this->begin());
			return (it);
		}

		const_reverse_iterator	rend(void) const {
			const_reverse_iterator	it(this->begin());
			return (it);
		}

		bool	empty(void) const { return (_size == 0); }
		size_type	size(void) const { return (_size); }
		size_type	max_size(void) const { return (alloc.max_size()); }

		void	clear(void) {
			clear_BaseNode(root());
			meta.left = NULL;
		}

		ft::pair<iterator, bool> insert(const value_type& value) {
			size_type	old_size = size();
			Bidirectional_Iterator	inserted_node;

			if (root() == NULL) {
				root() = create(value, &meta);
				return (ft::make_pair(Bidirectional_Iterator(root()), true));
			}
			insert_BaseNode(root(), &meta, value);
			inserted_node = find(value.first);
			if (old_size == size())
				return (ft::make_pair(inserted_node, false));
			else
				return (ft::make_pair(inserted_node, true));
		}

		iterator insert(iterator hint, const value_type& value) {
			if (hint == this->end())
				return (insert(value).first);
			if (!value_comp()(*hint, value))
				return (insert(value).first);
			++hint;
			if (hint != this->end()) {
				if (!value_comp()(value, *hint))
					return (insert(value).first);
			}
			--hint;
			BaseNode* new_parent = hint.get_BaseNode();
			new_parent->right = insert_BaseNode(new_parent->right, new_parent, value);
			++hint;
			rebalance(new_parent);
			return (hint);
		}

		template <class InputIt>
		void insert(InputIt first, InputIt last) {
			for (; first != last; ++first)
				insert(*first);
		}

		void	erase(iterator pos) { delete_BaseNode(pos.get_BaseNode()); }

		void erase( iterator first, iterator last ) {
			iterator temp = first;
			for (; first != last;) {
				++temp;
				delete_BaseNode(first.get_BaseNode());
				first = temp;
			}

		}

		size_type erase( const Key& key ) {
			Bidirectional_Iterator	item = find(key);
			if (item == this->end())
				return (0);
			delete_BaseNode(item.get_BaseNode());
			return (1);
		}

		void	swap(map& other) {
			std::swap(this->meta.left, other.meta.left);
			std::swap(this->_size, other._size);

			if (this->root())
				this->root()->parent = &this->meta;
			if (other.root())
				other.root()->parent = &other.meta;
		}

		size_type count(const Key& key) const { return (find(key) != this->end()); }

		Bidirectional_Iterator	find(const Key& key) {
			BaseNode* cursor = root();
			while (cursor != NULL) {
				if (key_comp()(key, static_cast<Node*>(cursor)->pair.first))
					cursor = cursor->left;
				else if (key_comp()(static_cast<Node*>(cursor)->pair.first, key))
					cursor = cursor->right;
				else
					return (cursor->iter());
			}
			return (end());
		}

		Const_Bidirectional_Iterator	find(const Key& key) const {
			const BaseNode* cursor = root();
			while (cursor != NULL) {
				if (key_comp()(key, static_cast<const Node*>(cursor)->pair.first))
					cursor = cursor->left;
				else if (key_comp()(static_cast<const Node*>(cursor)->pair.first, key))
					cursor = cursor->right;
				else
					return (cursor->iter());
			}
			return (end());
		}

		ft::pair<iterator, iterator> equal_range(const Key& key) {
			Bidirectional_Iterator	first_iter = this->end();
			Bidirectional_Iterator	second_iter = this->end();

			Bidirectional_Iterator cursor = this->begin();

			while (cursor != this->end()) {
				if (!comp(cursor->first, key)) {
					first_iter = cursor;
					break ;
				}
				++cursor;
			}
			cursor = this->begin();
			while (cursor != this->end()) {
				if (comp(key, cursor->first)) {
					second_iter = cursor;
					break ;
				}
				++cursor;
			}
			return (ft::make_pair(first_iter, second_iter));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const {
			Const_Bidirectional_Iterator	first_iter = this->end();
			Const_Bidirectional_Iterator	second_iter = this->end();

			Const_Bidirectional_Iterator cursor = this->begin();

			while (cursor != this->end()) {
				if (!comp(cursor->first, key)) {
					first_iter = cursor;
					break ;
				}
				++cursor;
			}
			cursor = this->begin();
			while (cursor != this->end()) {
				if (comp(key, cursor->first)) {
					second_iter = cursor;
					break ;
				}
				++cursor;
			}
			return (ft::make_pair(first_iter, second_iter));
		}

		Bidirectional_Iterator	lower_bound(const Key& key) {
			Bidirectional_Iterator cursor = this->begin();

			while (cursor != this->end()) {
				if (!comp(cursor->first, key))
					return (cursor);
				++cursor;
			}
			return (cursor);
		}

		Const_Bidirectional_Iterator	lower_bound(const Key& key) const {
			Const_Bidirectional_Iterator cursor = this->begin();

			while (cursor != this->end()) {
				if (!comp(cursor->first, key))
					return (cursor);
				++cursor;
			}
			return (cursor);
		}

		Bidirectional_Iterator	upper_bound(const Key& key) {
			Bidirectional_Iterator cursor = this->begin();

			while (cursor != this->end()) {
				if (comp(key, cursor->first))
					return (cursor);
				++cursor;
			}
			return (cursor);
		}

		Const_Bidirectional_Iterator	upper_bound(const Key& key) const {
			Const_Bidirectional_Iterator cursor = this->begin();

			while (cursor != this->end()) {
				if (comp(key, cursor->first))
					return (cursor);
				++cursor;
			}
			return (cursor);
		}

		key_compare	key_comp() const { return (key_compare()); }
		value_compare value_comp() const { return (value_compare(key_comp())); }


	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return (!(lhs == rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return (!(rhs < lhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return (rhs < lhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) { x.swap(y); }
}

