#include <iostream>
#include <string>

using namespace std;

/*
    Main code that is run
*/
int main(){

    const int DOES_NOT_CHANGE = 5;

    int noDecimal = 1;
    unsigned int longNumber = 1000000000;
    float hasDecimal = 1.01;
    double largerHasDecimal = 1.01;
    char singleCharacter = 'a'; 
    bool trueFalse = true; // 0 = true; 1 = false

    int unIninitialized;
    //void

    string listOfCharacters = "Hello String";
    
    //cout << listOfCharacters.length() << endl;

    unIninitialized = 5;

    //Operators
    /*
    +, -, *, /, %

    % "Modulus" remainder

    ++ increment
    -- decrement
    
    */

    int modExample = 10 % 3;

    cout << ++modExample << endl;
    cout << modExample << endl;

    int age;
    cout << "Enter age: ";
    cin >> age;

    if (age > 21) {
        cout << "Welcome in!" << endl;
    }else if (!(age != 21)){ // age == 21
        cout << "First year? Welcome!" << endl;
    }else {
        cout << "Go away." << endl;
    }

    cout << age << endl;

    return 0;

}