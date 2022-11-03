#pragma once
#include <iterator>
#include "iterator_traits.hpp"
#include "map/tree.hpp"

namespace ft
{

    template < class _T>
    class bidirectional_iterator
    {
        public:
                typedef _T                                                          value_type;
                typedef _T                                                          *pointer;
                typedef _T                                                          &reference;
                typedef ptrdiff_t                                                   difference_type;
                typedef ft::iterator_traits<_T>                                     iterator_category;
        private:
                pointer _it;
        public:
       // bidirectional_iterator(/* args */);
        //~bidirectional_iterator();
                bidirectional_iterator() : _it(NULL) {}
                bidirectional_iterator(pointer ptr) : _it(ptr) {}
                bidirectional_iterator(const bidirectional_iterator &copy) : _it(copy._it) {}
                ~bidirectional_iterator() {}
            bidirectional_iterator &operator=(const bidirectional_iterator &copy)
                {
                }
                operator _const() const { return _const(_it);}


                pointer operator->() const { return _it->val; }
                reference operator*() const { return *_it->val; }

                bool operator==(const _const &it) const { return _it == it.operator->(); }
                bool operator!=(const _const &it) const { return _it != it.operator->(); }

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

                random_access_iterator &operator--()
                {
                        return *_it->prev();
                }

                random_access_iterator operator--(int)
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

		reference operator * (void) const
		{
			return _it->val;
		}

		pointer operator -> (void) const
		{
			return &_it->val;
		}
    };

}