#include <iostream>
#include <string>
#include "car.h"

using namespace std;


void car::init(string setMake, string setModel, int setYear, string setColor){
    if(setYear > MIN_YEAR && setYear < MAX_YEAR){
        make = setMake;
        model = setModel;
        year = setYear;
        color = setColor;
    }else if (setYear > MAX_YEAR){
        cout << setYear << " cars do not exist." << endl; 
    }else{
        cout << "Do not accept this " << setYear << " " << setMake << " " << setModel << endl;
    }
    
}
void car::init(string setMake, string setModel, string setColor){
    make = setMake;
    model = setModel;
    color = setColor;
}
void car::init(string setString){
    for(string findMake : makes){
        if (setString == findMake){
            make = setString;
            return;
        }
    }
    model = setString;

    
}

void car::setMake(string setMake){
    make = setMake;
}
void car::setModel(string setModel){
    model = setModel;
}
void car::setYear(int setYear){
    if(setYear > 2005){
        year = setYear;
    }else{
        cout << "Do not accept this car." << endl;
    }  
}
void car::setColor(string setColor){
    color = setColor;
}
int car::getYear() const{ // const method cannot change class attributes
    /*
    // It's ok to change local variables
    int tempVal;
    cout << tempVal << endl;
    tempVal = 40;
    cout << tempVal << endl;
    */
    return year;
}