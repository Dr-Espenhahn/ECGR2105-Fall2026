#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>

using namespace std;

class Book{
protected:
    const string CHECKEDOUT = "1";
    string title;
    string author;
    bool checkedOut;

public:    
    Book(string title, string author){
        Book::title = title;
        Book::author = author;
        checkedOut = false;
    }
    Book(string title, string author, bool checkedOut){
        Book::title = title;
        Book::author = author;
        Book::checkedOut = checkedOut;
    }
    Book(string title, string author, string checkedOut){
        Book::title = title;
        Book::author = author;
        Book::checkedOut = (checkedOut == CHECKEDOUT);
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const{
        return author;
    }

    string strCheckedOut() const{
        if(checkedOut)
            return CHECKEDOUT;
        return "0";
    }

    void printInfo() const;

    void checkOut();

    void returnBook();
};


class EBook : public Book{
    private: 
    string formatType; // pdf, 

    public:
    EBook(string title, string author, string formatType) : Book(title, author){
        this->formatType = formatType;
    }

    string getFormatType(){
        return this->formatType;
    }

    void printInfo() const{};

};

class AudioBook : public EBook{
    private:
    string formatType = "AudioBook";

    public:
    AudioBook(string title, string author, string formatType) : EBook(title, author, formatType){
        this-> formatType = "AudioBook";
    }
};




class Library{
private:
    vector<Book*> books;
    static int libraryCount; // persistant across all objects
    int thisLibraryCount;
    //vector<int> copy_count;

public:
    void addBook(Book* book);

    void printLibrary() const;

    bool saveLibrary();
    bool loadLibrary();

    Book* findBook(string title);

    Library();

    ~Library();

};



#endif