#pragma once
#include "Book.h"

bool ComporatorBookPages(BookCard& lhs, BookCard& rhs)
{
    return (rhs.GetPages() >= lhs.GetPages());
}

bool DescComporatorBookPages(BookCard& lhs, BookCard& rhs)
{
    return !(rhs.GetPages() >= lhs.GetPages());
}

bool ComporatorBookYear(BookCard& lhs, BookCard& rhs)
{
    return rhs.GetYearPublish() >= lhs.GetYearPublish();
}

bool DescComporatorBookYear(BookCard& lhs, BookCard& rhs)
{
    return !(rhs.GetYearPublish() >= lhs.GetYearPublish());
}

bool ComporatorBookFirstName(BookCard& lhs, BookCard& rhs)
{
    return rhs.GetAuthorFirstName() >= lhs.GetAuthorFirstName();
}

bool DescComporatorBookFirstName(BookCard& lhs, BookCard& rhs)
{
    return !(rhs.GetAuthorFirstName() >= lhs.GetAuthorFirstName());
}

bool ComparatorBookTitle(BookCard& lhs, BookCard& rhs)
{
    return rhs.GetTitle() >= lhs.GetTitle();
}

bool DescComparatorBookTitle(BookCard& lhs, BookCard& rhs)
{
    return !(rhs.GetTitle() >= lhs.GetTitle());
}

bool ComporatorBookSecondName(BookCard& lhs, BookCard& rhs)
{
    return rhs.GetAuthorSecondName() >= lhs.GetAuthorSecondName();
}

bool DescComporatorBookSecondName(BookCard& lhs, BookCard& rhs)
{
    return !(rhs.GetAuthorSecondName() >= lhs.GetAuthorSecondName());
}
