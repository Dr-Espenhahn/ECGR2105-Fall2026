#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
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
}

bool Library::saveLibrary(){
    ofstream saveFile;
    string libraryName = "library" + to_string(thisLibraryCount) + ".csv";
    saveFile.open(libraryName);

    if(!saveFile.is_open()){
        cout << "Unable to load library file." << endl;
        return false;
    }

    for(const Book* book : books){
        saveFile << book->getTitle() << ","
            << book->getAuthor() << ","
            << book->strCheckedOut() << "\n";
    }

    saveFile.close();
    return true;
}

bool Library::loadLibrary(){
    ifstream loadFile;
    string libraryName = "library" + to_string(thisLibraryCount) + ".csv";
    loadFile.open(libraryName);

    //TODO: Load data

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
    cout << "Libary Books: " << endl;

    for(Book* book : books){ // "for-each" loop
        // book; //--> same thing as books.at(i); in previous look
        book->printInfo();
    }
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