#pragma once
#include <iostream>
#include <time.h>

#include "Complex.h"
#include "Person.h"
#include "assert.h"
#include "ArraySequence.h"
#include <compare>
#include "Generator.h"
#include "ArrayIterator.h"
#include "QuickSort.h"
#include "BookCardComporator.h"


void TestComplexSum()
{
    complex test1(2, 4);
    complex test2(1, 3);
    complex test3 = test1 + test2;
    assert(test3.GetRe() == 3);
    assert(test3.GetIm() == 7);
    assert(test1.GetRe() == 2);
    test3 += test1;
    assert(test3.GetRe() == 5);
    assert(test3.GetIm() == 11);
}

void TestComplexSubtract()
{
    complex test1(2, 4);
    complex test2(1, 3);
    complex test3 = test1 - test2;
    assert(test3.GetRe() == 1);
    assert(test3.GetIm() == 1);
    test3 -= test1;
    assert(test3.GetRe() == -1);
    assert(test3.GetIm() == -3);
}

void TestComplexMulti()
{
    complex test1(2, 4);
    complex test2(1, 3);
    complex test3 = test1 * test2;
    assert(test3.GetRe() == -10);
    assert(test3.GetIm() == 10);
    test3 *= test1;
    assert(test3.GetRe() == -60);
    assert(test3.GetIm() == -20);
}

void TestComplexDiv()
{
    complex test1(1, 1);
    complex test2(1, 1);
    complex test3 = test1 / test2;
    assert(test3.GetRe() == 1);
    assert(test3.GetIm() == 0);
}

void TestArraySequence()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ArraySequence<int> test(a, 8);
    assert(test.GetFirst() == 1);
    assert(test.GetLast() == 8);
    test.Append(9);
    assert(test.GetLength() == 9);
    assert(test.GetLast() == 9);
    test.Prepend(0);
    assert(test.GetLength() == 10);
    assert(test.GetFirst() == 0);
    assert(test[0] == 0);
    assert(test[5] == 5);
    test[5] = 80;
    assert(test[5] == 80);
}


void testQuickSortPages(int cnt)
{
    std::string filename = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/laboratory2/laboratory2/otput.csv";
    std::string filename_2 = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/laboratory2/laboratory2/input.csv";

    Generator(filename, cnt);
    ArraySequence<BookCard> a;
    QuickSort<BookCard, ArraySequenceIterator<BookCard, false>> QuickSorter;
    GettingDataFromFile(filename, a);
    std::cout << a.GetLength() << std::endl;
    std::cout<<a[1] << std::endl;
    clock_t start = clock();
    QuickSorter.sort(a.begin(), a.end(), ComporatorBookPages);
    clock_t end = clock();
    std::cout << a[1] << std::endl;
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << std::endl;
    PuttingDataToFile(filename_2, a);
}
