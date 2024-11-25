#pragma once
#include "HeadSorter.h"

template<typename T, typename iterator>
struct HeapSort: public HeadSorter<T, iterator>
{
    void sort(iterator begin, iterator end, bool (*comparator)(const T&, const T&)) override {
            auto size = end - begin;
            if (size <= 1) return;
        
            for (auto i = size / 2 - 1; i >= 0; --i) {
                heapify(begin, size, i, comparator);
            }

            for (auto i = size - 1; i > 0; --i) {
                std::swap(*(begin), *(begin + i));
                heapify(begin, i, 0, comparator);
            }
        }

    private:
        void heapify(iterator begin, size_t size, size_t root_index, bool (*comparator)(const T&, const T&)) {
            auto largest = root_index;              // Initialize largest as root
            auto left = 2 * root_index + 1;         // Left child index
            auto right = 2 * root_index + 2;        // Right child index

            if (left < size && comparator(*(begin + largest), *(begin + left))) {
                largest = left;
            }

            if (right < size && comparator(*(begin + largest), *(begin + right))) {
                largest = right;
            }

            if (largest != root_index) {
                std::swap(*(begin + root_index), *(begin + largest));
                heapify(begin, size, largest, comparator); // Recursively heapify the affected subtree
            }
        }
};
