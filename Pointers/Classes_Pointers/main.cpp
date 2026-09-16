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

    void printInfo() const {
        cout << title << " by " << author;

        if(checkedOut){
            cout << " [CHECKED OUT]";
        }

        cout << endl;
    }

    void checkOut() {
        if (!checkedOut) {
            checkedOut = true;
            cout << title << " has been checked out." << endl;
        }else{
            cout << title << " is already checked out." << endl;
        } 
    }

    void returnBook(){
        if (checkedOut){
            checkedOut = false;
            cout << title << " has been returned." << endl;
        }else{
            cout << title << " was not checked out." << endl;
        }
    }
};

class Library{
private:
    vector<Book*> books;

public:
    void addBook(Book* book){
        books.push_back(book);
    }
};

int main(){
    vector<Book> storedBooks;

    return 0;
}