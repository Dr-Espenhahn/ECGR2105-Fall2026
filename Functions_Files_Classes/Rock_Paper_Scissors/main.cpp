#include <iostream>
#include <string>
#include <cstdlib> // gives us rand() & srand()
#include <ctime> // gives us time()

#include <vector>
#include <iomanip> // gives setprecision()

using namespace std;

const int RPS_THROW_COUNT = 3;

string toLowerString(string upperCaseString){
    //Make string (char array) lowercase
    for(int j = 0; j < upperCaseString.length(); j++){
        upperCaseString.at(j) = tolower(upperCaseString.at(j));
    }

    return upperCaseString;
}

int encodeRPS(string userInput, string decodeRPS[RPS_THROW_COUNT]){
    userInput = toLowerString(userInput);

    for(int i=0; i<RPS_THROW_COUNT; i++){
        string keyValue = toLowerString(decodeRPS[i]);
        if(userInput == keyValue)
            return i;
    }
    return -1; // Error
}

int main(){
    string userInput;
    unsigned int computerInput; 
    vector<unsigned int> compInputs; // Dyamic size arrays
    unsigned int gameCount;
    string decodeRPS[RPS_THROW_COUNT] = {"Rock", "Paper", "Scissors"}; // MUST be lowercase

    int gameWinCount = 0;
    double winRate = 0.0;

    srand(time(0)); // Seed our random number generator


    /*
    // Arrays - defined size
    //unsigned int compInputs[gameCount]; //DOES NOT WORK, need to define array size at compilation not run
    const unsigned int GAME_COUNT = 5; //unsigned = never negative
    unsigned int compArrayInputs[GAME_COUNT]; //Array size must be defined
    for(int i=0; i < GAME_COUNT; i++){
        compArrayInputs[0] = rand() % 3;
    }
    */

    /*
    // Vector commands
    compInputs.push_back(1); // .push_back(val) -- Add 'val' to the end of the vector
    cout << compInputs.back() << endl; // .back() -- Get us last variable in the vector
    compInputs.pop_back(); // .pop_back -- Removes the last variable in the vector
    */

    //cout << i <<endl; //Does not work; i only defined within "for" loop


    // Vectors - dynamic size
    cout << "How many games would you like to play: ";
    cin >> gameCount;

    for(int i = 0; i < gameCount; i++){
        compInputs.push_back(rand() % 3);
    }

    

    //while(gameCountdown-- > 0){
    for(int i=0; i < gameCount ; i++){
        bool userWin = false;

        cout << "Rock, paper, scissors, Shoot! ";
        cin >> userInput;

        int encodedUserInput = encodeRPS(userInput);

        string resultOutput = "";

        if(encodedUserInput == compInputs.at(i)){
            resultOutput = "It's a tie! You both threw " + decodeRPS[encodedUserInput];
        }else{
            switch(encodedUserInput){
                case 0:
                    switch(compInputs.at(i)){
                        case 1: //Paper
                            cout << "Computer played " << decodeRPS[compInputs.at(i)] <<  ", you lost." << endl;
                            break;
                        case 2: //Scissors
                            cout << "Computer played scissors, you won!" << endl;
                            userWin = true;
                            break;
                        default:
                            cout << "Error." << endl;
                            return 0;
                    }
                break;
                case 1:

                break;
                case 2:

                break;
                default:
                    cout << "Error 1" << endl;
                break;
            }
        }


        /*
        //Moved into function toLowerString()

        //Make string (char array) lowercase
        for(int j = 0; j < userInput.length(); j++){
            userInput.at(j) = tolower(userInput.at(j));
        }
        */

        //Make string (char array) lowercase
        //userInput = toLowerString(userInput);

        //computerInput = rand() % 3; // 0 = Rock, 1 = Paper, 2 = Scissors

        
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

        
            
        /*
        if(userInput == "rock" ){ //'OR': userInput == "Rock" || userInput == "rock" //Note: 'AND' is &&
            cout << "User input rock." << endl;
            /*
            if(computerInput == 0){

            }else if (computerInput == 1){

            }else if (computerInput == 2){
            
            }else{

            }*//* 
        
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
                    cout << "Computer played rock, you won!" << endl;
                    userWin = true;
                    break;
                case 1: //Paper
                    cout << "Computer played paper, you tied." << endl;
                    break;
                case 2: //Scissors
                    cout << "Computer played scissors, you lost." << endl; 
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
                    cout << "Computer played rock, you lost." << endl;
                    break;
                case 1: //Paper
                    cout << "Computer played paper, you won!" << endl;
                    userWin = true;
                    break;
                case 2: //Scissors
                    cout << "Computer played scissors, you tied." << endl;
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
        */
    }

    // gameWinCount -- integer (int)
    // winRate -- double
    // gameCount -- integer (int)

    winRate = (double)gameWinCount/(double)gameCount;


    cout << fixed << setprecision(1) << "\nWin rate: "  << winRate*100 << "%" << endl;


    
    

    return 0;
}