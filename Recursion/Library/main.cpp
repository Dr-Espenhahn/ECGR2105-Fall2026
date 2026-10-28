#include <iostream>
#include <vector>
#include "library.h"
#include "userInterface.h"

using namespace std;



int main(){
    //vector<Book> storedBooks;
    Library* library = new Library();

    userInterface(library);

    cout << "Leaving program." << endl;

    delete library;

    return 0;
}