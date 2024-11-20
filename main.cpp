#include <iostream>
#include "tests.h"
#include "ArrayIterator.h"

int main()
{
    static_assert(std::random_access_iterator<
    ArraySequenceIterator<int, false>>);
    return 0;
}
