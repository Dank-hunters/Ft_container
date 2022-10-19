#pragma once
#include "iterator_traits.hpp"

namespace ft
{
template<typename _Iterator>
    class reverse_iterator
    {
        public:
   
    typedef _Iterator                                      iterator_type;
    typedef ft::iterator_traits<_Iterator>                     __traits_type;
    typedef typename __traits_type::difference_type        difference_type;
    typedef typename __traits_type::pointer                pointer;
    typedef typename __traits_type::reference              reference;
    typedef typename  __traits_type::iterator_category     iterator_category;
    private:
    iterator_type                                              current;
    public:
    reverse_iterator() : current() { }
    
    reverse_iterator(iterator_type _x) : current(_x) { }

        template<typename _Iter>
    reverse_iterator(const reverse_iterator<_Iter>& _x): current(_x.base()) { }
     
   
 iterator_type  base() const
        {
            return current; 
        }
    
    reference operator*() const 
        { 
            _Iterator _tmp = current;
            return *--_tmp;
        }
    
    pointer operator->() const
        {
            return &(operator*());
        }

    reverse_iterator& operator++()
        {
            --current;
            return *this;
        }
    reverse_iterator operator++(int)
        {
            reverse_iterator _tmp = *this;
            --current;
            return _tmp;
        }
    reverse_iterator& operator--()
        {
            ++current;
            return *this;
        }
    
    reverse_iterator operator--(int)
        {
            reverse_iterator _tmp = *this;
            ++current;
            return _tmp;
        }
    
    reverse_iterator operator+(difference_type _n) const 
        {
            return reverse_iterator(current - _n);
        }
    
    
    reverse_iterator& operator+=(difference_type _n)
        {
            current -= _n;
            return *this;
        }
    
    reverse_iterator operator-(difference_type _n) const 
        {
            return reverse_iterator(current + _n);
        }
    
    
    reverse_iterator& operator-=(difference_type _n)
        {
            current += _n;
            return *this;
        }
    
    reference operator[](difference_type _n) const 
        {
            return *(*this + _n);
        }
    
};
template<typename _Iterator>
    bool operator==(const reverse_iterator<_Iterator>& _x,
               const reverse_iterator<_Iterator>& _y)
    { return _x.base() == _y.base(); }

  template<typename _Iterator>
    bool operator<(const reverse_iterator<_Iterator>& _x,
              const reverse_iterator<_Iterator>& _y)
    { return _y.base() < _x.base(); }

  template<typename _Iterator>
    bool operator!=(const reverse_iterator<_Iterator>& _x,
               const reverse_iterator<_Iterator>& _y)
    { return !(_x == _y); }

  template<typename _Iterator>
    bool operator>(const reverse_iterator<_Iterator>& _x,
              const reverse_iterator<_Iterator>& _y)
    { return _y < _x; }

  template<typename _Iterator>
    bool operator<=(const reverse_iterator<_Iterator>& _x,
               const reverse_iterator<_Iterator>& _y)
    { return !(_y < _x); }

  template<typename _Iterator>
    bool operator>=(const reverse_iterator<_Iterator>& _x,
               const reverse_iterator<_Iterator>& _y)
    { return !(_x < _y); }
};
