#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){

    string userInput;
    unsigned int computerInput = rand() % 3;

    cout << "Rock, paper, scissors, Shoot! ";
    cin >> userInput;

    //Make array lowercase
    for(int i = 0; i < userInput.length(); i++){
        userInput.at(i) = tolower(userInput.at(i));
    }

    /*
    int i = 0;
    while(i < userInput.length()){
        userInput[i] = tolower(userInput[i]);
        i++;
    }
    */

    /*
    do{
        //Run code once, then check variable status if should run again
    }while(true)
    */

    /*
    for(char a : userInput){
        cout << a << endl; //creates new memory location to store 'a', seperately from array
    }
    */

    
        

    if(userInput == "Rock" || userInput == "rock" ){ //OR: userInput == "Rock" || userInput == "rock" //Note: and is &&
        cout << "User input rock." << endl;
        /*
        if(computerInput == 0){

        }else if (computerInput == 1){

        }else{

        }*/
        switch(computerInput){
            case 0:
                //do stuff
                break;
            case 1:
                //do stuff
                break;
            case 2:
                //do stuff
                break;
            default:
                cout << "Error." << endl;
                return 0;
        }
    }else if(userInput == "Paper" || userInput == "paper" ){ 
        cout << "User input paper." << endl;
    }else if(userInput == "Scissors" || userInput == "scissors" ){ 
        cout << "User input scissors." << endl;
    }else{
        cout << "Did not understand." << endl;
        return 0;
    }

    return 0;
}