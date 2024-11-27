#include <iostream>
#include <time.h>

#include "tests.h"
#include "ArrayIterator.h"
#include "ComplexComparator.h"
#include "HeadSorter.h"
#include "BubbleSort.h"
#include "DefaultComporator.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "Book.h"
#include "Generator.h"
#include "BookCardComporator.h"
int main()
{
    
    ArraySequence<int> seq;
    
    int size = 10000000;
    int start_sequence = -10000;
    int end_sequence = 10000;
    int a;
    for (int i = 0; i < size; i++)
    {
        a = rand() % (end_sequence - start_sequence + 1) + start_sequence;
        seq.Append(a);
    }
    
    QuickSort<int, ArraySequenceIterator<int, false>> HeapSorter;
    clock_t start = clock();
    HeapSorter.sort(seq.begin(), seq.end(), DefaultComparator);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << std::endl;
    
//    std::cout << "After sorting:\n";
//    for (auto it:seq) {
//        std::cout << it << std::endl;
//    }
//    
    std::cout << seconds << "\n";
    return 0;
}
