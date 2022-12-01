#include "../map/map.hpp"
#include "enable_if.hpp"
#include "compare.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "pair.hpp"
#include <memory>
#include <iterator>
#include <algorithm>


template<class key, class T>
class Bidirectional_Iterator
		{
		protected:
			Node<key, T>*	ptr;
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
			Node*	get_Node(void) { return (static_cast<Node*>(ptr)); }

		};

		template <class key, class T>
		class Const_Bidirectional_Iterator
		{
		protected:
			const Node<key, T>*	ptr;

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
