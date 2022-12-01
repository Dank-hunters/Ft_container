#pragma once
#include <iterator>
#include "iterator_traits.hpp"
#include "../map/tree.hpp"

namespace ft
{

    template < class _T>
    class Bidirectional_Iterator
    {
        public:
                typedef _T                                                          value_type;
                typedef _T                                                          *pointer;
                typedef _T                                                          &reference;
                typedef ptrdiff_t                                                   difference_type;
                typedef ft::iterator_traits<_T>                                     iterator_category;
        private:
                tree<_T> *_it;
        public:
       // bidirectional_iterator(/* args */);
        //~bidirectional_iterator();
                bidirectional_iterator() : _it(NULL) {}
                bidirectional_iterator(tree<_T> ptr) : _it(ptr) {}
                bidirectional_iterator(const bidirectional_iterator &copy) : _it(copy._it) {}
                ~bidirectional_iterator() {}
            bidirectional_iterator &operator=(const bidirectional_iterator &copy)
                {
                        _it = copy._it;
                        return (*this);
                }
               // operator _const() const { return _const(_it);}


             //   pointer operator->() const { return _it->val; }
              //  reference operator*() const { return *_it->val; }

               // bool operator==(const bidirectional_iterator &it) const { return _it == it.operator->(); }
              //  bool operator!=(const bidirectional_iterator &it) const { return _it != it.operator->(); }

                bidirectional_iterator &operator++()
                {
                        _it = _it->next();
                        return *this;
                }

                bidirectional_iterator operator++(int)
                {
                        bidirectional_iterator tmp = _it;
                        _it = _it->next();
                        return tmp;
                }

                bidirectional_iterator &operator--()
                {
                        return *_it->prev();
                }

                bidirectional_iterator operator--(int)
                {
                        bidirectional_iterator tmp = _it;
                        _it = _it->prev();
                        return tmp;
                }
        bool operator == (const bidirectional_iterator &other) const
		{
			return _it == other._it;
		}

		bool operator != (const bidirectional_iterator &other) const
		{
			return _it != other._it;
		}

		value_type& operator * (void) const
		{
			return _it->val;
		}

		value_type* operator -> (void) const
		{
			return &_it->val;
		}
    };
        template < class _T>
    class const_bidirectional_iterator
    {
        public:
                typedef _T                                                          value_type;
                typedef const value_type                                                          *pointer;
                typedef const value_type                                                          &reference;
                typedef ptrdiff_t                                                   difference_type;
                typedef ft::iterator_traits<_T>                                     iterator_category;
        private:
                const tree<_T> *_it;
        public:
       // bidirectional_iterator(/* args */);
        //~bidirectional_iterator();
                const_bidirectional_iterator() : _it(NULL) {}
                const_bidirectional_iterator(const tree<_T> *ptr) : _it(ptr) {}
                const_bidirectional_iterator(const_bidirectional_iterator &copy) : _it(copy._it) {}
                ~const_bidirectional_iterator() {}
            const_bidirectional_iterator &operator=(const const_bidirectional_iterator &copy)
                {
                        _it = copy._it;
                        return (*this);
                }
               // operator _const() const { return _const(_it);}


             //   pointer operator->() const { return _it->val; }
              //  reference operator*() const { return *_it->val; }

               // bool operator==(const bidirectional_iterator &it) const { return _it == it.operator->(); }
              //  bool operator!=(const bidirectional_iterator &it) const { return _it != it.operator->(); }

                const_bidirectional_iterator &operator++()
                {
                        _it = _it->next();
                        return *this;
                }

                const_bidirectional_iterator operator++(int)
                {
                        const_bidirectional_iterator tmp = _it;
                        _it = _it->next();
                        return tmp;
                }

                const_bidirectional_iterator &operator--()
                {
                        return *_it->prev();
                }

                const_bidirectional_iterator operator--(int)
                {
                        const_bidirectional_iterator tmp = _it;
                        _it = _it->prev();
                        return tmp;
                }
        bool operator == (const const_bidirectional_iterator &other) const
		{
			return _it == other._it;
		}

		bool operator != (const const_bidirectional_iterator &other) const
		{
			return _it != other._it;
		}

		const value_type & operator * (void) const
		{
			return _it->val;
		}

		const value_type* operator -> (void) const
		{
			return &_it->val;
		}
    };

}