#include <iostream>
#include <vector>
#include "car.h"

using namespace std;

/*
class car{ //object, default private attributes & methods
    private: //Access modifier
    // variables within class = attributes (members)
    const int MIN_YEAR = 2006;
    const int MAX_YEAR = 2026;
    string make; 
    string model;
    int year;
    string color;
    string makes[3] = {"Subaru", "Toyta", "Ford"};

    public:
    // Constructor (shares name of class)
    car(){
        make = "Unk";
        model = "Unk";
        year = 0; 
    }
    car(int y){
       make = "Unk";
       model = "Unk";
       year = y; 
    }
    car(string setMake, string setModel, int setYear, string setColor){
        init(setMake, setModel, setYear, setColor);
    }

    // functions within class = method
    void init(string setMake, string setModel, int setYear, string setColor);
    void init(string setMake, string setModel, string setColor);
    void init(string setString);

    void setMake(string setMake);
    void setModel(string setModel);
    void setYear(int setYear);
    void setColor(string setColor);

    int getYear() const;
    string getModel() const{ return model; }
    string getMake() const{ return make; }
    string getColor() const{ return color; }
};

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
   /*
    return year;
}
*/


int main(){

    vector<car> cars;

    cars.push_back(car("Subaru", "Crosstrek", 2019, "White"));
    cars.push_back(car("Toyota", "Highlander", 2001, "Gray"));
    cars.push_back(car("Ford", "F-150", 2035, "Red"));
    cars.push_back(car(2010));


    /*
    car car1("Subaru", "Crosstrek", 2019, "White"), car2(2001), car3, car4; // objects of type car
    car2.init("Toyota", "Highlander", 2001, "Gray");
    car3.init("Ford", "F-150", 2035, "Red");
    car4.init("F-150");
    */

    /*
    // For Public attributes:
    car1.make = "Subaru";
    car1.model = "Crosstrek";
    car1.year = 2019;
    car1.color = "White";

    car2.make = "Toyta";
    car2.model = "Highlander";
    car2.color = "Gray";

    car3.make = "Ford";
    car3.model = "F-150";
    car3.year = 2025;
    car3.color = "Red";
    */

    /*
    cars.push_back(car1);
    cars.push_back(car2);
    cars.push_back(car3);
    cars.push_back(car4);
    */

    cout << cars.at(0).getYear() << endl;  
    cout << cars.at(3).getYear() << endl;    

    // For public attribute:
    //cout << cars.at(0).year << endl;

    //cars.push_back();

    /*
    vector<string> make;
    vector<string> model;
    vector<int> year;
    vector<string> color;

    //add a car
    make.push_back("Subaru");
    model.push_back("Crosstrek");
    year.push_back(2019);
    color.push_back("White");

    //add 2nd car
    make.push_back("Toyota");
    model.push_back("Highlander");
    color.push_back("Gray");

    //add 3rd car
    make.push_back("Ford");
    model.push_back("F-150");
    year.push_back(2025);
    color.push_back("Red");

    cout << year.at(2) << endl;
    */



    return 0;
}