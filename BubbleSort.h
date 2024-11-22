#pragma once
#include "HeadSorter.h"

template<typename T, typename iterator>
struct BubbleSort : public HeadSorter<T, iterator>
{
    void sort(iterator begin, iterator end, bool (*comparator)(const T&, const T&)) override
    {
//        if (begin == end)
//        {
//            return;
//        }
//        bool swapped = true;
//            while (swapped)
//            {
//                swapped = false;
//                for (auto it = begin; it != (end - 1); ++it)
//                {
//                    auto next = it + 1;
//                    if (comparator(*next, *it)) {
//                        std::swap(*it, *next);
//                        swapped = true;
//                    }
//                }
//            }
        for (auto i = begin; i != end; ++i) {
                for (auto j = begin; j != end - (i - begin) - 1; ++j) {
                    if (!comparator(*j, *(j + 1))) {
                        std::swap(*j, *(j + 1)); // Обмен элементов
                    }
                }
            }
    }
    
};

