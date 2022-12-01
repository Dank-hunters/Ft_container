#pragma once
#include <iostream>
#include "../includes/bidirectional_iterator.hpp"

namespace ft
{
    template<
        class Key,
        class T,
        class Compare = std::less<Key>,
        class Allocator = std::allocator<ft::pair<const Key, T> > > 
        class map
        {
            private:
                typedef Key	                                                        key_type;
                typedef T                                                           mapped_type;
                typedef ft::pair<const Key, T>                                      value_type;
                typedef Compare                                                     key_compare;
                typedef Allocator                                                   allocator_type;	
                typedef size_t                                                      size_type;
                typedef typename allocator_type::reference                          reference;
				typedef typename allocator_type::const_reference                    const_reference;
				typedef typename allocator_type::pointer                            pointer;
				typedef typename allocator_type::const_pointer                      const_pointer;

            //    iterator bidirectional_iterator to value_type
              //  const_iterator bidirectional_iterator to const value_type
                typedef ft::bidirectional_iterator<T>                       iterator;    
				typedef ft::const_bidirectional_iterator<T>                       const_iterator;
                typedef  ft::reverse_iterator<iterator>                     reverse_iterator;    
				typedef  ft::reverse_iterator<const_iterator>               const_reverse_iterator;
                typedef typename ft::iterator_traits<iterator>::difference_type     difference_type;

           // public :
             //class Node;c
            public:
                tree<T, key_compare, allocator_type>    _tree;
              //  map(void) : comp(Compare()), alloc(std::allocator<ft::pair<const Key, T> >()), _size(0) { }
                map(/* args */): _tree(){}
                ~map(){}

               iterator begin(){return(iterator(_tree.get_root())); }
               
               //const_iterator begin() const {return(const_iterator(_tree.get_root())); }
        
    };
    
}