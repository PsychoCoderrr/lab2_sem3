#pragma once
#include "HeadSorter.h"

template<typename T, typename iterator>
struct BubbleSort : public HeadSorter<T, iterator>
{
    void sort(iterator begin, iterator end, bool (*comparator)(const T&, const T&)) override
    {
        for (auto i = begin; i != end; ++i) {
                for (auto j = begin; j != end - (i - begin) - 1; ++j) {
                    if (!comparator(*j, *(j + 1))) {
                        std::swap(*j, *(j + 1)); // Обмен элементов
                    }
                }
            }
    }
    
};

