#pragma once

namespace ft
{
    template<
    class value_type
    > struct avl_node
    {
    public:

        typedef avl_node< value_type >              node_type;
        typedef node_type*                          pointer;
        typedef const node_type*                    const_pointer;

        value_type  value;
        pointer     right;
        pointer     left;
        pointer     parent;
    };
}