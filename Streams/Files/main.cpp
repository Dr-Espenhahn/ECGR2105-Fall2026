#include <iostream>
#include <fstream> // file streams

using namespace std;

int main(){
    ofstream outFile; // output file stream
    ifstream inFile; // input file stream

    /*
    outFile.open("Example.txt");

    if(!outFile.is_open()){
        cout << "Unable to open file" << endl;
        return 0;
    }

    outFile << "Hello World!" << endl;

    outFile.close();
    */


    inFile.open("Example.txt");

    if(!inFile.is_open()){
        cout << "Unable to open file" << endl;
        return 0;
    }

    string text;

    while(!inFile.eof()){
        getline(inFile, text);
        cout << text << endl;
    }
    
    

    inFile.close();


    return 0;
}