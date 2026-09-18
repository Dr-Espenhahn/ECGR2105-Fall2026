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
    //vector<int> copy_count;

public:
    void addBook(Book* book){
        if(findBook(book->getTitle()) == nullptr){
            books.push_back(book);
            //copy_count.push_back(1);
        }else{
            cout << "Book is already in the library." << endl;
            /*
            for(int i=0; i<books.size(); i++){ //standard "for" loop
                if(books.at(i)->getTitle() == book->getTitle()){
                    copy_count.at(i)++; //increment copy count
                }
            }
            */
        }
    }

    void printLibrary() const {
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

    Book* findBook(string title){
        for (Book* book : books){
            if(book->getTitle() == title) {
                return book;
            }
        }

        return nullptr;
    }

};








int main(){
    //vector<Book> storedBooks;
    Library library;

    Book book1("The Hobbit", "J.R.R. Tolkein");
    Book* book2 = new Book("1984", "George Orwell");
    Book* book3 = new Book("Dune", "Frank Herbert");

    library.addBook(&book1);
    library.addBook(book2);
    library.addBook(book3);

    //library.printLibrary();

    Book* foundBook = library.findBook("1984");

    if(foundBook != nullptr){
        cout << foundBook->getTitle() << " exists.";
    }else{
        cout << "Searched book does not exist";
    }

     Book* foundBook = library.findBook("1984");

    if(foundBook != nullptr){
        cout << foundBook->getTitle() << " exists.";
    }else{
        cout << "Searched book does not exist";
    }
    

    return 0;
}