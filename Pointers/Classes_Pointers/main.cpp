#include <iostream>
#include <vector>
#include "library.h"

using namespace std;




int main(){
    //vector<Book> storedBooks;
    Library library;

    Book* book1 = new Book("The Hobbit", "J.R.R. Tolkein");
    Book* book2 = new Book("1984", "George Orwell");
    Book* book3 = new Book("Dune", "Frank Herbert");

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    string crInput = "";
    string findTitle;
    Book* foundBook;

    //library.printLibrary();

    //Book* foundBook = library.findBook("1984");

    library.printLibrary();

    while(crInput != "e"){
        cout << "Do you want to checkout (c) or return (r): ";
        getline(cin, crInput);
        
        if(crInput == "c"){
            // Getting user input of book to checkout
            cout << "Title of book to checkout: ";
            getline(cin, findTitle);
            foundBook  = library.findBook(findTitle);

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
        } else if (crInput == "e"){
            cout << "Exiting.." << endl;
        }else {
            cout << "I don't understand." << endl;
        }    

        library.printLibrary();
        cout << endl;
    }
    


    //library.~Library(); // Generally, bad form
    

    return 0;
}