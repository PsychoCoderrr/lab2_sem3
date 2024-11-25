#include <iostream>
#include "tests.h"
#include "ArrayIterator.h"
#include "ComplexComparator.h"
#include "HeadSorter.h"
#include "BubbleSort.h"
#include "DefaultComporator.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "Book.h"
int main()
{
    ArraySequence<int> seq;
    seq.Append(10);
    seq.Append(25);
    seq.Append(3);
    seq.Append(23);

    std::cout << "Before sorting:\n";
    for (auto it:seq) {
        std::cout << it << "\n";
    }
    
    HeapSort<int, ArraySequenceIterator<int, false>> HeapSorter;
    HeapSorter.sort(seq.begin(), seq.end(), DefaultComparator);
    std::cout << std::endl;
    std::cout << "After sorting:\n";
    for (auto it = seq.begin(); it != seq.end(); ++it) {
        std::cout << *it << "\n";
    }
    
    return 0;
}
