#pragma once
#include "../vector/vector.hpp"
#include <stack>
#include <iostream>


namespace ft
{
    template< class T, class Container = ft::vector<T> > class stack
    {

    public:
        typedef Container   container_type;
        typedef T           value_type;
        typedef size_t      size_type;
    protected:
        container_type  c;
    public:

        explicit stack(const container_type& ctnr = container_type())
        {
            c = ctnr;
        }

        ~stack()
        {}

        bool                empty() const
        {
            return c.empty();
        }

        size_type           size() const
        {
            return c.size();
        }

        value_type&         top()
        {
            return c.back();
        }
        
        const value_type&   top() const
        {
            return c.back();
        }

        void                push(const value_type& val)
        {
            c.push_back(val);
        }
        void                pop()
        {
            c.pop_back();
        }
    template <class T1, class C1>  
    friend bool operator== (const stack<T1,C1>& lhs, const stack<T1,C1>& rhs);
    template <class T1, class C1>  
    friend bool operator!= (const stack<T1,C1>& lhs, const stack<T1,C1>& rhs);
    template <class T1, class C1>  
    friend bool operator<  (const stack<T1,C1>& lhs, const stack<T1,C1>& rhs);
    template <class T1, class C1>  
    friend bool operator<= (const stack<T1,C1>& lhs, const stack<T1,C1>& rhs);
    template <class T1, class C1>  
    friend bool operator>  (const stack<T1,C1>& lhs, const stack<T1,C1>& rhs);
    template <class T1, class C1>  
    friend bool operator>= (const stack<T1,C1>& lhs, const stack<T1,C1>& rhs);

    };

template <class T1, class C1>  
    bool operator== (const stack<T1,C1>& lhs, const stack<T1,C1>& rhs)
{
    return lhs.c == rhs.c;
}

template <class T1, class C1>    
    bool operator!= (const stack<T1,C1>& lhs, const stack<T1,C1>& rhs)
{
    return lhs.c != rhs.c;
}

template <class T1, class C1>    
    bool operator<  (const stack<T1,C1>& lhs, const stack<T1,C1>& rhs)
{
    return lhs.c < rhs.c;
}

template <class T1, class C1>    
    bool operator<= (const stack<T1,C1>& lhs, const stack<T1,C1>& rhs)
{
    return lhs.c <= rhs.c;
}

template <class T1, class C1>    
    bool operator>  (const stack<T1,C1>& lhs, const stack<T1,C1>& rhs)
{
    return lhs.c > rhs.c;
}

template <class T1, class C1>    
    bool operator>= (const stack<T1,C1>& lhs, const stack<T1,C1>& rhs)
{
    return lhs.c >= rhs.c;
}

//FRIEND IS FOR ACCESS PRIVAITE ELEMENT (LIKE CTNR IN OVERLOAD)

}