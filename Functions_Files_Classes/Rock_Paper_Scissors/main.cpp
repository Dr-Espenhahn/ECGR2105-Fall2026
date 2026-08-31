#include <iostream>
#include <string>
#include <cstdlib> // gives us rand() & srand()
#include <ctime> // gives us time()
#include <vector>
#include <iomanip> // gives setprecision()

using namespace std;

const int RPS_THROW_OPTION_COUNT = 3; // global variable

// Prototypes of functions before main(). Fully defined afterwards
string toLowerString(string upperCaseString);
int encodeRPS(string userInput, string decodeRPS[RPS_THROW_OPTION_COUNT]);
void setToLower(string& upperCaseString);


int main(){
    string userInput;
    unsigned int computerInput; 
    vector<unsigned int> compInputs; // Dyamic size arrays
    unsigned int gameCount;
    string decodeRPS[RPS_THROW_OPTION_COUNT] = {"Rock", "Paper", "Scissors"}; // MUST be lowercase
    int userRPSCount[RPS_THROW_OPTION_COUNT] = {0, 0, 0}; //TODO: Implement counter for how many times user throws
    int gameWinCount = 0;
    double winRate = 0.0;

    srand(time(0)); // Seed our random number generator


    // Vectors - dynamic size
    cout << "How many games would you like to play: ";
    cin >> gameCount;

    // Pre-load computer RPS
    for(int i = 0; i < gameCount; i++){
        compInputs.push_back(rand() % 3);
    }

   // Get user RPS & determine winner
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
                case 0: //Rock
                    switch(compInputs.at(i)){
                        case 1: //Paper
                            resultOutput = "Computer played " + decodeRPS[compInputs.at(i)] +  ", you lost.";
                            break;
                        case 2: //Scissors
                            resultOutput = "Computer played " + decodeRPS[compInputs.at(i)] +  ", you won!";
                            userWin = true;
                            break;
                        default:
                            cout << "Error 2" << endl;
                            return 0;
                    }
                break;
                case 1: //Paper
                    switch(compInputs.at(i)){
                        case 0: //Rock
                            resultOutput = "Computer played " + decodeRPS[compInputs.at(i)] +  ", you won!";
                            userWin = true;
                            break;
                        case 2: //Scissors
                            resultOutput = "Computer played " + decodeRPS[compInputs.at(i)] +  ", you lost.";
                            break;
                        default:
                            cout << "Error 2" << endl;
                            return 0;
                    }
                break;
                case 2: //Scissors
                    switch(compInputs.at(i)){
                        case 1: //Paper
                            resultOutput = "Computer played " + decodeRPS[compInputs.at(i)] +  ", you won!";
                            userWin = true;
                            break;
                        case 0: //Rock
                            resultOutput = "Computer played " + decodeRPS[compInputs.at(i)] +  ", you lost.";
                            break;
                        default:
                            cout << "Error 2" << endl;
                            return 0;
                    }
                break;
                default:
                    cout << "Error 1" << endl;
                break;
            }
        }

        if(userWin)
            gameWinCount++;

        cout << resultOutput << endl;

    }


    winRate = (double)gameWinCount/(double)gameCount;
    cout << fixed << setprecision(1) << "\nWin rate: "  << winRate*100 << "%" << endl;



    return 0;
}



string toLowerString(string upperCaseString){
    //Make string (char array) lowercase
    for(int j = 0; j < upperCaseString.length(); j++){
        upperCaseString.at(j) = tolower(upperCaseString.at(j));
    }

    return upperCaseString;
}

// Using reference variable (&)
void setToLower(string& upperCaseString){
    //Make string (char array) lowercase
    for(int j = 0; j < upperCaseString.length(); j++){
        upperCaseString.at(j) = tolower(upperCaseString.at(j));
    }
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
