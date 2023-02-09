#pragma once

namespace ft
{

// Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), 
// and false otherwise, using binary function 'p' for compare
template< class InputIt1, class InputIt2, class BinaryPredicate >
bool equal( InputIt1 first1,
            InputIt1 last1,
            InputIt2 first2,
            BinaryPredicate p )
{
    for (; first1 != last1; ++first1, ++first2) {
        if (!p(*first1, *first2)) {
            return false;
        }
    }
    return true;
};

// Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), 
// and false otherwise, using ==
template< class InputIt1, class InputIt2 >
bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
{
    for (; first1 != last1; ++first1, ++first2) {
        if (!(*first1 == *first2)) {
            return false;
        }
    }
    return true;
};


// Elements are compared using operator<
template< class InputIt1, class InputIt2 >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
                              InputIt2 first2, InputIt2 last2 )
{
    for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    {
        if (*first1 < *first2)
            return (true);
        if (*first2 < *first1)
            return (false);
    }
    return (first1 == last1) && (first2 != last2);
}

//Elements are compared using given binary comparison function comp
template< class InputIt1, class InputIt2, class Compare >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
                              InputIt2 first2, InputIt2 last2, Compare comp )
{
    for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    {
        if (comp(*first1, *first2))
            return (true);
        if (comp(*first2, *first1))
            return (false);
    }
    return (first1 == last1) && (first2 != last2);
}

template< class T >
void swap(T& lhs, T& rhs)
{
    T   tmp(lhs);
    lhs = rhs;
    rhs = tmp;
}

} // namespace ft