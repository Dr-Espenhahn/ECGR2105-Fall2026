#include <iostream>
#include <string>
#include <cstdlib> //gives us rand() & crand()
#include <ctime>

#include <vector>

using namespace std;

int main(){
    string userInput;
    unsigned int computerInput;
    const unsigned int GAME_COUNT = 5;
    unsigned int compArrayInputs[GAME_COUNT];
    vector<unsigned int> compInputs;
    unsigned int gameCountdown;

    srand(time(0)); //Seed our random number generator


    cout << "How many games would you like to play: ";
    cin >> gameCountdown;

    for(int i=0; i < GAME_COUNT; i++){
        compArrayInputs[0] = rand() % 3;
    }

    for(int i = 0; i < gameCountdown; i++){
        compInputs.push_back(rand() % 3);
    }

    //unsigned int compInputs[gameCountdown]; //DOES NOT WORK, need to define array size at compilation not run



    while(gameCountdown-- > 0){
        cout << "Rock, paper, scissors, Shoot! ";
        cin >> userInput;

        //Make string (char array) lowercase
        for(int i = 0; i < userInput.length(); i++){
            userInput.at(i) = tolower(userInput.at(i));
        }

        computerInput = rand() % 3; // 0 = Rock, 1 = Paper, 2 = Scissors

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

        
            
        
        if(userInput == "rock" ){ //'OR': userInput == "Rock" || userInput == "rock" //Note: 'AND' is &&
            cout << "User input rock." << endl;
            /*
            if(computerInput == 0){

            }else if (computerInput == 1){

            }else if (computerInput == 2){
            
            }else{

            }*/ 
        
            switch(compInputs.at(gameCountdown)){
                case 0: //Rock
                    cout << "It's a tie! You both played rock." << endl;
                    break;
                case 1: //Paper
                    cout << "Computer played paper, you lost." << endl;
                    break;
                case 2: //Scissors
                    cout << "Computer played scissors, you won!" << endl;
                    break;
                default:
                    cout << "Error." << endl;
                    return 0;
            }

        }else if(userInput == "paper" ){ 
            cout << "User input paper." << endl;
            //TODO: Implement
        }else if(userInput == "scissors" ){ 
            cout << "User input scissors." << endl;
            //TODO: Implement
        }else{
            cout << "Did not understand." << endl;
            return 0;
        }
    }


    
    

    return 0;
}