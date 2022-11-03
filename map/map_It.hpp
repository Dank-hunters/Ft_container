namespace ft
{
    template <class T, class U, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t,
        class Pointer = U*, class Reference = U&>
	class MapIterator
	{
	public:
    	typedef T         		value_type;
    	typedef Distance  		difference_type;
    	typedef Pointer   		pointer;
    	typedef Reference 		reference;
    	typedef Category  		iterator_category;
	
	protected:
		T 						*_ptr;
	public:


	};
}