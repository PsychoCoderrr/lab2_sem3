#include <iostream>
#include "tests.h"
#include "ArrayIterator.h"
#include "ComplexComparator.h"
#include "HeadSorter.h"
#include "BubbleSort.h"

int main()
{
    ArraySequence<complex> seq;
    seq.Append(complex(3, 4));
    seq.Append(complex(1, 1));
    seq.Append(complex(0, 2));
    seq.Append(complex(5, 0));

    std::cout << "Before sorting:\n";
    for (auto it = seq.begin(); it != seq.end(); ++it) {
        std::cout << *it << "\n";
    }
    
    BubbleSort<complex, ArraySequenceIterator<complex, false>> BubbleSorter;
    BubbleSorter.sort(seq.begin(), seq.end(), ComplexComp);
    std::cout << std::endl;
    std::cout << "After sorting:\n";
    for (auto it = seq.begin(); it != seq.end(); ++it) {
        std::cout << *it << "\n";
    }
    complex test = complex(3, 4);
    complex test2 = complex(5, 0);
    return 0;
}
