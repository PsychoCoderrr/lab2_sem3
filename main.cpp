#include <iostream>
#include "tests.h"
#include "ArrayIterator.h"
#include "ComplexComparator.h"
#include "HeadSorter.h"
#include "BubbleSort.h"
#include "DefaultComporator.h"

int main()
{
    ArraySequence<int> seq;
    seq.Append(1);
    seq.Append(8);
    seq.Append(5);
    seq.Append(3);

    std::cout << "Before sorting:\n";
    for (auto it = seq.begin(); it != seq.end(); ++it) {
        std::cout << *it << "\n";
    }
    
    BubbleSort<int, ArraySequenceIterator<int, false>> BubbleSorter;
    BubbleSorter.sort(seq.begin(), seq.end(), DefaultComparator);
    std::cout << std::endl;
    std::cout << "After sorting:\n";
    for (auto it = seq.begin(); it != seq.end(); ++it) {
        std::cout << *it << "\n";
    }
    complex test = complex(3, 4);
    complex test2 = complex(5, 0);
    return 0;
}
