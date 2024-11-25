#pragma once
#include <string>


class BookCard
{
private:
    std::string ISBN;  //уникальный код книги
    std::string title;  //название книги
    std::string authorSecondName;  //автор книги(фамилия)
    std::string authorFirstName;  //автор книги(имя)
    int pages; //кол-во страниц в книге
    int YearPublish;  //год публикации
public:
    BookCard()
    {
        ISBN = "";
        title = "";
        authorSecondName = "";
        authorFirstName = "";
        pages = 0;
        YearPublish = 0;
    }
    
    BookCard(std::string ISBN, std::string title, std::string authorSecondName, std::string authorFirstName, int pages, int YearPublish)
    {
        this->ISBN = ISBN;
        this->title = title;
        this->authorSecondName = authorSecondName;
        this->authorFirstName = authorFirstName;
        this->pages = pages;
        this->YearPublish = YearPublish;
    }
    
    BookCard(BookCard& example)
    {
        this->ISBN = example.ISBN;
        this->title = example.title;
        this->authorSecondName = example.authorSecondName;
        this->authorFirstName = example.authorFirstName;
        this->pages = example.pages;
        this->YearPublish = example.YearPublish;
    }
    
    std::string GetISBN()
    {
        return this->ISBN;
    }
    
    std::string GetTitle()
    {
        return this->title;
    }
    
    std::string GetAuthorSecondName()
    {
        return this->authorSecondName;
    }
    
    std::string GetAuthorFirstName()
    {
        return this->authorFirstName;
    }
    
    int GetPages()
    {
        return this->pages;
    }
    
    int GetYearPublish()
    {
        return this->YearPublish;
    }
    
    void SetISBN(std::string& ISBN)
    {
        this->ISBN = ISBN;
    }
    
    void SetTitle(std::string& title)
    {
        this->title = title;
    }
    
    void SetAuthorSecondName(std::string& authorSecondName)
    {
        this->authorSecondName = authorSecondName;
    }
    
    void SetAuthorFirstName(std::string& authorFirstName)
    {
        this->authorFirstName = authorFirstName;
    }
    
    void SetPages(int& pages)
    {
        this->pages = pages;
    }
    
    void SetYearPublish(int& YearPublish)
    {
        this->YearPublish = YearPublish;
    }
};