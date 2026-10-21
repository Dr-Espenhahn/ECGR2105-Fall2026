#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "library.h"

using namespace std;

void Book::printInfo() const {
    cout << title << " by " << author;

    if(checkedOut){
        cout << " [CHECKED OUT]";
    }

    cout << endl;
}



void Book::checkOut() {
    if (!checkedOut) {
        checkedOut = true;
        cout << title << " has been checked out." << endl;
    }else{
        cout << title << " is already checked out." << endl;
    } 
}

void Book::returnBook(){
    if (checkedOut){
        checkedOut = false;
        cout << title << " has been returned." << endl;
    }else{
        cout << title << " was not checked out." << endl;
    }
};

int Library::libraryCount = 0;

Library::Library(){
    libraryCount++;
    thisLibraryCount = libraryCount;

    loadLibrary();
}

string Book::getSaveData(){
    stringstream ss;

    ss << "B," << getTitle() << ","
            << getAuthor() << ","
            << strCheckedOut();

    return ss.str();
}

string EBook::getSaveData(){
    stringstream ss;

    ss << "E," << getTitle() << ","
            << getAuthor() << ","
            << strCheckedOut() << ","
            << getFormatType();

    return ss.str();
}

string AudioBook::getSaveData(){
    stringstream ss;

    ss << "A," << getTitle() << ","
            << getAuthor() << ","
            << strCheckedOut() << ","
            << getFormatType();

    return ss.str();
}

bool Library::saveLibrary(){
    ofstream saveFile;
    string libraryName = "library" + to_string(thisLibraryCount) + ".csv";
    saveFile.open(libraryName);

    if(!saveFile.is_open()){
        cout << "Unable to load library file." << endl;
        return false;
    }

    for(Book* book : books){
        saveFile << book->getSaveData() << "\n";
    }

    saveFile.close();
    return true;
}

bool Library::loadLibrary(){
    ifstream loadFile;
    string libraryName = "library" + to_string(thisLibraryCount) + ".csv";
    loadFile.open(libraryName);

    if(!loadFile.is_open()){
        cout << "Unable to load library file." << endl;
        return false;
    }

    string readBook;
    while(getline(loadFile, readBook)){
        stringstream ss(readBook);
        string title, author, checkedOutStr;
        Book* book;

        string formatType;
        char itemType;
        getline(ss, formatType, ',');
        itemType = formatType[0];

        switch(itemType){
            case 'B': //Book
                if (!getline(ss, title, ',') || !getline(ss, author, ',') || !getline(ss, checkedOutStr, ',')){
                    continue; //skips rest of this iteration in while loop, and rechecks statement (skips invalid lines)
                }
                book = new Book(title, author, checkedOutStr);
                
                break;

            case 'E': //EBook
                if (!getline(ss, title, ',') || !getline(ss, author, ',') || !getline(ss, checkedOutStr, ',') || !getline(ss, formatType, ',')){
                    continue; //skips rest of this iteration in while loop, and rechecks statement (skips invalid lines)
                }
                book = new EBook(title, author, checkedOutStr, formatType);

                break;

            case 'A': //AudioBook
                string formatType;
                if (!getline(ss, title, ',') || !getline(ss, author, ',') || !getline(ss, checkedOutStr, ',')|| !getline(ss, formatType, ',')){
                    continue; //skips rest of this iteration in while loop, and rechecks statement (skips invalid lines)
                }

                book = new AudioBook(title, author, checkedOutStr, formatType);
                
                break;
        }
        

        books.push_back(book);

    }

    return true;
}

void Library::addBook(Book* book){
    if(findBook(book->getTitle()) == nullptr){
        books.push_back(book);
        //copy_count.push_back(1);
    }else{
        cout << book->getTitle() << " is already in the library." << endl;
        /*
        for(int i=0; i<books.size(); i++){ //standard "for" loop
            if(books.at(i)->getTitle() == book->getTitle()){
                copy_count.at(i)++; //increment copy count
            }
        }
        */
    }
}

void Library::printLibrary() const {
    /*
    for(int i=0; i<books.size(); i++){ //standard "for" loop
        books.at(i); //do something
    }*/
    cout << "\nLibary Books: " << endl;

    for(Book* book : books){ // "for-each" loop
        // book; //--> same thing as books.at(i); in previous look
        book->printInfo();
    }

    cout << endl;
}

Book* Library::findBook(string title){
    for (Book* book : books){
        if(book->getTitle() == title) {
            return book;
        }
    }

    return nullptr;
}  

Library::~Library(){
    saveLibrary();
    cout << "deleting Library from memory" << endl;
    for(Book* book : books){
        delete book;
    }
}