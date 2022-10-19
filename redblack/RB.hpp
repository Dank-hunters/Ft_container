#include <iostream>
#inlcude "../pair.hpp"

//0 = black
//1 = red



 template < class Key, class T, class Compare = ft::less<Key>, 
            class Alloc = ft::allocator<ft::pair<const Key, T> >
    > class Rb_Tree
{
private:
    struct node
    {
        bool                color;
        ft::pair<key, T>    data;
        node                *childleft;
        node                *childright;
        node                *dad;
    };
    node       *root;
public:
    Rb_Tree(/* args */);


    ~Rb_Tree();
};

Rb_Tree::Rb_Tree() : root(nullptr)
{
}
node    *getroot() {return(root);}
void    Rb_tree::*insert(ft::pair(key, T) stuff)
{
    if (root = nullptr)
    {
        root = new node;
        this.color = 0;
        this.data = stuff;
        root->dad 


    }

}
Rb_Tree::~Rb_Tree()
{
}
