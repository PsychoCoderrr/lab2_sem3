#pragma once
#include "ArraySequence.h"

template<typename T, bool is_const>
class ArraySequenceIterator
{
private:
    typedef std::conditional_t<is_const, const ArraySequence<T>, ArraySequence<T>> *elem_ptr_t;
    
    elem_ptr_t elem_;
    
    ArraySequenceIterator(elem_ptr_t elem): elem_(elem) {};
    
    friend ArraySequence<T>;
    friend ArraySequenceIterator<T, !is_const>;
    
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef std::conditional_t<is_const, const T, T>* pointer;
    typedef std::conditional_t<is_const, const T, T>& reference;
    typedef std::random_access_iterator_tag iterator_category;
    
    template<bool other_const>
    ArraySequenceIterator(ArraySequenceIterator<T, other_const>& o) noexcept requires (is_const >= other_const): elem_(o.elem_) {};
    
    template<bool other_const>
    ArraySequenceIterator& operator =(const ArraySequenceIterator<T, other_const>& o) noexcept requires (is_const >= other_const) // requires не позволяет скопировать из const
    {
        elem_ = o.elem_;
        return *this;
    }
    
    ArraySequenceIterator& operator ++ () noexcept
    {
        ++elem_;
        return *this;
    }
};
