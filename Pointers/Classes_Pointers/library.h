#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>

using namespace std;

class Book{
private:
    string title;
    string author;
    bool checkedOut;

public:
    Book(string title, string author){
        Book::title = title;
        Book::author = author;
        checkedOut = false;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const{
        return author;
    }

    void printInfo() const;

    void checkOut();

    void returnBook();
};




class Library{
private:
    vector<Book*> books;
    //vector<int> copy_count;

public:
    void addBook(Book* book);

    void printLibrary() const;

    Book* findBook(string title);

    ~Library();

};



#endif