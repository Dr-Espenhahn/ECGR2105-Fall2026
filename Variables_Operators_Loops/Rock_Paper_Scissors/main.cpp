#include <iostream>
#include <string>
#include <cstdlib> //gives us rand() & srand()
#include <ctime> //gives us time()

#include <vector>
#include <iomanip> //gives setprecision()

using namespace std;

int main(){
    string userInput;
    unsigned int computerInput; 
    const unsigned int GAME_COUNT = 5; //unsigned = never negative
    unsigned int compArrayInputs[GAME_COUNT]; //Array size must be defined
    vector<unsigned int> compInputs; //Dyamic size arrays
    unsigned int gameCount;

    int gameWinCount = 0;
    double winRate = 0.0;

    srand(time(0)); //Seed our random number generator

    /*
    //Vector commands
    compInputs.push_back(1); // .push_back(val) -- Add 'val' to the end of the vector
    cout << compInputs.back() << endl; // .back() -- Get us last variable in the vector
    compInputs.pop_back(); // .pop_back -- Removes the last variable in the vector
    */

    cout << "How many games would you like to play: ";
    cin >> gameCount;

    for(int i=0; i < GAME_COUNT; i++){
        compArrayInputs[0] = rand() % 3;
    }

    //cout << i <<endl; //Does not work; i only defined within "for" loop

    for(int i = 0; i < gameCount; i++){
        compInputs.push_back(rand() % 3);
    }

    //unsigned int compInputs[gameCount]; //DOES NOT WORK, need to define array size at compilation not run


    //while(gameCountdown-- > 0){
    for(int i=0; i < gameCount ; i++){
        bool userWin = false;

        cout << "Rock, paper, scissors, Shoot! ";
        cin >> userInput;

        //Make string (char array) lowercase
        for(int j = 0; j < userInput.length(); j++){
            userInput.at(j) = tolower(userInput.at(j));
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
        
            switch(compInputs.at(i)){
                case 0: //Rock
                    cout << "It's a tie! You both played rock." << endl;
                    break;
                case 1: //Paper
                    cout << "Computer played paper, you lost." << endl;
                    break;
                case 2: //Scissors
                    cout << "Computer played scissors, you won!" << endl;
                    userWin = true;
                    break;
                default:
                    cout << "Error." << endl;
                    return 0;
            }

        }else if(userInput == "paper" ){ 
            cout << "User input paper." << endl;
            //TODO: Implement
            switch(compInputs.at(i)){
                case 0: //Rock
                    userWin = true;
                    break;
                case 1: //Paper
                userWin = true;
                    break;
                case 2: //Scissors

                    break;
                default:
                    cout << "Error." << endl;
                    return 0;
            }
        }else if(userInput == "scissors" ){ 
            cout << "User input scissors." << endl;
            //TODO: Implement
            switch(compInputs.at(i)){
                case 0: //Rock
                    
                    break;
                case 1: //Paper
                    userWin = true;
                    break;
                case 2: //Scissors
                    
                    break;
                default:
                    cout << "Error." << endl;
                    return 0;
            }
        }else{
            cout << "Did not understand." << endl;
            return 0;
        }

        if(userWin){
            gameWinCount++;
            cout << "Win count: " << gameWinCount << endl;
        }
    }

    // gameWinCount -- integer (int)
    // winRate -- double
    // gameCount -- integer (int)

    winRate = (double)gameWinCount/(double)gameCount;


    cout << fixed << setprecision(1) << "\nWin rate: "  << winRate*100 << "%" << endl;


    
    

    return 0;
}