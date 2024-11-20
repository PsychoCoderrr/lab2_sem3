#pragma once
#include <iostream>
#include "Complex.h"
#include "DynamicArray.h"
#include "Person.h"
#include "assert.h"
#include "ArraySequence.h"
#include <compare>

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

void TestDynamicArrayConstructors()
{
    int a[] = {1, 2, 3, 4, 5, 6};

    DynamicArray<int> test1(6);
    assert(test1.GetSize() == 6);

    DynamicArray<int> test2(a, 6);
    assert(test2.GetSize() == 6);
    for (int i = 0; i < test2.GetSize(); i++)
    {
        assert(test2.Get(i) == a[i]);
    }

    DynamicArray<int> test3(test2);
    assert(test3.GetSize() == test2.GetSize());
    for (int i = 0; i < test3.GetSize(); i++)
    {
        assert(test2.Get(i) == test3.Get(i));
    }
}

void TestDynamicArraySet()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    DynamicArray<int> test(a, 8);
    assert(test.GetSize() == 8);
    for (int i = 0; i < test.GetSize(); i++)
    {
        assert(test.Get(i) == a[i]);
    }
    test.Set(9, 3);
    assert(test.Get(3) == 9);
    test[3] = 10;
    assert(test[3] == 10);
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
}
