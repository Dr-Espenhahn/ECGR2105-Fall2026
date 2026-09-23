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

    /*
    ~Book(){
        cout << "deleting Book" << endl;
    }
    */
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

    ~Library(){
        cout << "deleting Library" << endl;
        for(Book* book : books){
            delete book;
        }
    }

};




int main(){
    //vector<Book> storedBooks;
    Library library;

    Book* book1 = new Book("The Hobbit", "J.R.R. Tolkein");
    Book* book2 = new Book("1984", "George Orwell");
    Book* book3 = new Book("Dune", "Frank Herbert");

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    string crInput;
    string findTitle;
    Book* foundBook = library.findBook(findTitle);

    //library.printLibrary();

    //Book* foundBook = library.findBook("1984");

    library.printLibrary();

    
    cout << "Do you want to checkout (c) or return (r): ";
    getline(cin, crInput);

    if(crInput == "c"){
        // Getting user input of book to checkout
        cout << "Title of book to checkout: ";
        getline(cin, findTitle);

        if(foundBook != nullptr){
            // cout << foundBook->getTitle() << " exists." << endl;
            foundBook->checkOut();
        }else{
            cout << findTitle << " is not in the library." << endl;
        }
    } else if (crInput == "r"){
        library.printLibrary();

        cout << "Title of book to return: ";
        getline(cin, findTitle);
        foundBook = library.findBook(findTitle);

        if(foundBook != nullptr){
            // cout << foundBook->getTitle() << " exists." << endl;
            foundBook->returnBook();
        }else{
            cout << "Searched book does not exist" << endl;
        }
    } else {
        cout << "I don't understand." << endl;
    }




    

    library.printLibrary();


    //library.~Library(); // Generally, bad form
    

    return 0;
}