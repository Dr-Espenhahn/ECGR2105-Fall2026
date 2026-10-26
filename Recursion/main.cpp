#include <iostream>

using namespace std;

void countdown(int n){
    if (n == 0){
        cout << "Blast off!" << endl;
        return;
    }

    cout << n << endl;

    countdown(n - 1); // Tail-end recursion
}

int factorial(int n){
    if (n <= 1){
        return 1;
    }

    if (n > 100){
        cout << " Too large number for factorial." << endl;
        return 0;
    }

    return n * factorial(n - 1); //NOT tail-end recursion
}

void makeChoice(int choice){
    
    int n;

    switch(choice){
        case 0:
            break;
        case 1: 
            cout << "Please enter an integer: ";
            cin >> n;
            countdown(n);
            break;
        case 2:
            cout << "Please enter an integer: ";
            cin >> n;
            cout << "factorial(" << n << "): "  << factorial(n) << endl;
            break;
        default:
            return;
    }

    cout << "\nChoose an activity:\n";
    cout << "1. Countdown\n";
    cout << "2. Calculate factorial\n";

    cin >> choice;
    makeChoice(choice);
    
}

int main(){

    makeChoice(0);

    cout << "countdown(5): " << endl;
    countdown(5);

    cout << "factorial(5): " << factorial(5) << endl;



    return 0;
}