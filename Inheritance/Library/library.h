#ifndef LIBRARY_H 
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <sstream>

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

    virtual string getSaveData();

    void printInfo() const;

    void checkOut();

    void returnBook();
};


class EBook : public Book{
    protected: 
    string formatType; // PDF, EPUB, AZW, IBA

    public:
    EBook(string title, string author, string formatType) : Book(title, author){
        this->formatType = formatType;
    }
    EBook(string title, string author, string checkedOut, string formatType) : Book(title, author, checkedOut){
        this->formatType = formatType;
    }

    string getFormatType(){
        return this->formatType;
    }
    string getSaveData() override;

    void printInfo() const{};

};

class AudioBook : public EBook{
    private:
    //string formatType = "AudioBook";

    public:
    AudioBook(string title, string author, string formatType) : EBook(title, author, formatType){
    }
    AudioBook(string title, string author, string checkedOut, string formatType) : EBook(title, author, checkedOut, formatType){
    }

    string getSaveData() override;

    void showFormats(){
        cout << "\n[AudioBook]\n"
            << "this->formatType: " << this->formatType << '\n'
            << "AudioBook::formatType: " << AudioBook::formatType << '\n'
            << "EBook::formatType: " << EBook::formatType << '\n'
            << "getFormatType(): " << getFormatType() << endl;
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