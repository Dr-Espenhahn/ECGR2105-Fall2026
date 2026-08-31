#include <iostream>
#include <string>
#include <cstdlib> // gives us rand() & srand()
#include <ctime> // gives us time()

#include <vector>
#include <iomanip> // gives setprecision()

using namespace std;

const int RPS_THROW_OPTION_COUNT = 3;

string toLowerString(string upperCaseString){
    //Make string (char array) lowercase
    for(int j = 0; j < upperCaseString.length(); j++){
        upperCaseString.at(j) = tolower(upperCaseString.at(j));
    }

    return upperCaseString;
}

int encodeRPS(string userInput, string decodeRPS[RPS_THROW_OPTION_COUNT]){
    userInput = toLowerString(userInput);

    for(int i=0; i<RPS_THROW_OPTION_COUNT; i++){
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
    string decodeRPS[RPS_THROW_OPTION_COUNT] = {"Rock", "Paper", "Scissors"}; // MUST be lowercase

    int gameWinCount = 0;
    double winRate = 0.0;

    srand(time(0)); // Seed our random number generator


    // Vectors - dynamic size
    cout << "How many games would you like to play: ";
    cin >> gameCount;

    for(int i = 0; i < gameCount; i++){
        compInputs.push_back(rand() % 3);
    }

   
    for(int i=0; i < gameCount ; i++){
        bool userWin = false;

        cout << "Rock, paper, scissors, Shoot! ";
        cin >> userInput;

        //Make string (char array) lowercase
        //userInput = toLowerString(userInput);

        int encodedUserInput = encodeRPS(userInput, decodeRPS);

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


        


    winRate = (double)gameWinCount/(double)gameCount;


    cout << fixed << setprecision(1) << "\nWin rate: "  << winRate*100 << "%" << endl;


    
    

    return 0;
}