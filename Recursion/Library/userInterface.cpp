#include "library.h"
#include "userInterface.h"

void checkOutBook(Library* library){
    string findTitle; 
    Book* foundBook;
    // Getting user input of book to checkout
    cout << "Title of book to checkout: ";
    getline(cin, findTitle);
    foundBook  = library->findBook(findTitle);

    if(foundBook != nullptr){
        // cout << foundBook->getTitle() << " exists." << endl;
        foundBook->checkOut();
    }else{
        cout << findTitle << " is not in the library." << endl;
    }
}

void returnBook(Library* library){
    string findTitle; 
    Book* foundBook;
    library->printLibrary();

    cout << "Title of book to return: ";
    getline(cin, findTitle);
    foundBook = library->findBook(findTitle);

    if(foundBook != nullptr){
        // cout << foundBook->getTitle() << " exists." << endl;
        foundBook->returnBook();
    }else{
        cout << "Searched book does not exist" << endl;
    }
}

 void userInterface(Library* library){
    string crInput = "";
    
    Book* foundBook;

    library->printLibrary();

    cout << "Do you want to checkout (c) or return (r): ";
    getline(cin, crInput);

    if(crInput == "c"){
        checkOutBook(library);
    } else if (crInput == "r"){
        returnBook(library);
    } else if (crInput == "e"){
        cout << "Exiting.." << endl;
        return;
    }else {
        cout << "I don't understand." << endl;
    }

    // Tail-end recursion: recursive call at END of function
    userInterface(library);
 }