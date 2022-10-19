#pragma once 
#include <vector>
#include <iostream>
#include <iterator>
#include <limits>
#include "../includes/random_acces_iterator.hpp"
#include "../includes/iterator_vector.hpp"
#include "../includes/enable_if.hpp"
#include "../includes/reverse_iterator.hpp"
namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
		class vector
		{
			public:

				typedef T                                                   value_type;
				typedef Alloc                                               allocator_type;

				typedef typename allocator_type::reference                  reference;
				typedef typename allocator_type::const_reference            const_reference;
				typedef typename allocator_type::pointer                    pointer;
				typedef typename allocator_type::const_pointer              const_pointer;

				typedef  ft::random_access_iterator<value_type>				iterator;
				typedef  ft::random_access_iterator<const value_type> 		const_iterator;
				typedef  ft::reverse_iterator<iterator>                     reverse_iterator;    
				typedef  ft::reverse_iterator<const_iterator>               const_reverse_iterator;

				typedef size_t                                              size_type;
				typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			private:
				allocator_type  _alloc;
				size_t          _capacity;
				pointer         _end;
				pointer         _start;
				pointer         _end_of_storage;

				void    del_storage(size_type n)
				{
					size_type i = 0;

					while (i < n && _end >= _start)
					{
						if (_end == _start)
							_alloc.destroy(_start);
						else
							_alloc.destroy(--_end);	
						++i;
					}
				}

				void    set_new_block(size_type n, const value_type& val)
				{
					size_t i = 0;
					if (_end == _start)
					{
						_alloc.construct(_end++, val);
						++i;
					}
					while ( i < n && (_end) < _end_of_storage)
					{
						_alloc.construct(_end++, val);
						i++;
					}
				}

				template <class Itt>
					void    set_new_range(Itt first, Itt last)
					{
						while (first != last)
						{
							_alloc.construct(_end++, (*first++));
						}
					}


				void    delete_block(pointer _del, size_t n)
				{
					if (_start)
					{
						for (size_t i = 0; i < n; i++)
						{
							_alloc.destroy(&_del[i]);
						}
						_alloc.deallocate(_del, n);
					}

				}

				void    add_memory(size_type n)
				{
					pointer tmp = _alloc.allocate(n);
					iterator start = begin();
					size_type      i = 0;
					size_type sized = size();

					_end = tmp;
					while(i != sized)
					{
						_alloc.construct(_end++, start[i]);
						i++;
					}
					_end_of_storage = _end;
					while ( i < n)
					{
						++_end_of_storage;
						i++;
					}
					delete_block(_start, sized);
					_start = tmp;
				}

				iterator remove_block(iterator first, iterator last)
				{
					iterator tmp = first;

					if (first == last)
						return (first);
					while (tmp != last)
					{
						_alloc.destroy(&(tmp));
						tmp++;
						_end--;
					}
					tmp = first;
					while(tmp != _end)
					{
						_alloc.construct(&(*tmp), *(tmp + 1));
						_alloc.destroy(&(*(tmp + 1)));
						tmp++;
					}
					//_end--;
					return(first);
				}
			public :

				//                      constructeur/destructeur

				explicit vector (const allocator_type& alloc = allocator_type()) : _end(NULL), _start(NULL), _end_of_storage(NULL), _alloc(alloc) 
			    {}

				explicit vector (size_type n, 
						const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) :_end(NULL), _start(NULL), _end_of_storage(NULL),  _alloc(alloc)
			    {   
				    assign(n, val);
			    }

				template <class Itt>         
					vector (Itt first, Itt last, 
							const allocator_type& alloc = allocator_type()) : _end(NULL), _start(NULL), _end_of_storage(NULL),  _alloc(alloc)
			    {
				    assign(first, last);
			    }

				vector (const vector& x) : _end(NULL), _start(NULL), _end_of_storage(NULL),  _alloc(x._alloc)
			    {
				    *this = x;
			    }

				~vector()
				{
					if (_start)
					{
						delete_block(_start, size());
					}
				}

				vector& operator= (const vector& x)
				{
					clear();

				//	if (capacity() < x.capacity())

					//else
						assign(x.begin(), x.end());
					return (*this);
					
				}

				//                      Iterator                
				iterator begin()
				{
					return iterator(_start);
				}
				const_iterator begin() const
				{
					return const_iterator(_start);
				}
				reverse_iterator rbegin()
				{
					iterator i = end();
					return reverse_iterator(i);
				}
				const_reverse_iterator rbegin() const
				{
					const_iterator i = end();
					return const_reverse_iterator(i);
				}

				iterator end()
				{
					return iterator(_end);
				}
				const_iterator end() const
				{
					return const_iterator(_end);
				}
				reverse_iterator rend()
				{
					iterator i = begin();
					return reverse_iterator(i);
				}
				const_reverse_iterator rend() const
				{
					const_iterator i = begin();
					return const_reverse_iterator(i);
				}
				//      Capacity
				
                size_type capacity(void) const 
                {
                     return static_cast<size_type>(_end_of_storage - _start);
                }
				size_type size(void) const 
                {
                     return static_cast<size_type>(_end - _start); 
                }
				size_type max_size() const
				{
					//return std::numeric_limits<size_type>::max() / sizeof(T); 	
					return std::numeric_limits<difference_type>::max() / sizeof(T); 	
				}
				bool empty() const
				{
					return (_start == _end);
				}
				void reserve (size_type n)
				{
					if (n > capacity())
					add_memory(n);
				}
				void resize (size_type n, value_type val = value_type())
				{
					if (n == size())
						return;
					if (n < size())
						del_storage(size() - n);
					else if (n > size())
					{
						if (n > capacity())
						{
							add_memory(n - capacity());
							set_new_block(n - size(), val);
						}
						else
							set_new_block(n - size(), val);
					}
				}
				//      Modifier

				template <class InputIterator>
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
					assign (InputIterator first, InputIterator last)
					{
						size_type n = 0;
						for (InputIterator itf = first; itf != last; itf++)
						{
							n++;
							// dprintf(1, "%zu\n", n);
						}
						if (n > capacity())
						{
							delete_block(_start, size());
							_start = _alloc.allocate(n);
							_end = _start;
							_end_of_storage = _end;
							size_type m = n;
							while (m != 0)
							{
								++_end_of_storage;
								--m;
							}
						}
						else
							del_storage(size());
						set_new_range(first, last);
					}

				void assign (size_type n, const value_type& val)
				{
					if (n == 0)
						return;
					if (n > capacity())
					{
						delete_block(_start, size());
						_start = _alloc.allocate(n);
						_end = _start;
						_end_of_storage = _end;
						size_type m = n;
						while (m != 0)
						{
							++_end_of_storage;
							--m;
						}
					}
					else
						del_storage(size());
					set_new_block(n, val);
				}

				void push_back (const value_type& val)
				{
					if (size() + 1 > capacity())
					{
						if (!(capacity()))
							add_memory(1);
						else
							add_memory(capacity() * 2);
					}
					set_new_block(1, val);
				}

				void pop_back()
				{
					del_storage(1);
				}

				void clear()
				{
					delete_block(_start, capacity());
				}

				iterator erase (iterator position)
				{
					
					return (remove_block(position, position + 1));
				}
				iterator erase (iterator first, iterator last)
				{	
					return (remove_block(first, last));
				}
				
				iterator insert (iterator position, const value_type& val)
    			{
					if (capacity() < size() + 1)
					{
						if (capacity() == 0)
								add_memory(1);
						else 
							add_memory(capacity() * 2);
					}
					_end++;
					iterator tmp = _end;
					while(tmp != position)
					{
						_alloc.construct(&(*tmp), *(tmp - 1));
						_alloc.destroy(&(*(tmp - 1)));
						tmp--;
					}
					_alloc.construct(&(*position), val);
					return(position);
				}
				
				void insert (iterator position, size_type n, const value_type& val)
				{
					if (capacity() < size() + n)
					{
						if (capacity() == 0)
							add_memory(n);
						else 
						{
							if ((capacity() * 2) < capacity() + n)
								{
									add_memory((capacity() *2) + n);
								}
							else 	
								add_memory(capacity()*2);
						}
					}
					_end += n;
					iterator tmp = _end ;
					while(tmp != position + n - 1)
					{
						_alloc.construct(&(*tmp), *(tmp - n));
						_alloc.destroy(&(*(tmp - n)));
						tmp--;
					}
					for (size_t i = 0; i < n; i++)
					{
						_alloc.construct(&(*position), val);
						position++;
					}
				}

				template <class InputIterator>
				typename enable_if<!ft::is_integral<InputIterator>::value, void>::type
							 insert (iterator position, InputIterator first, InputIterator last)
							 {

								int i = 0;

							 }
				
		};
}
