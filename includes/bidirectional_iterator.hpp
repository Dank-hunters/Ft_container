#pragma once
#include <iterator>
#include "iterator_traits.hpp"
#include <map>

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

    };

}