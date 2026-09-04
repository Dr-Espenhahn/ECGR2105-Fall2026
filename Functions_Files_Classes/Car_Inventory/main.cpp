#include <iostream>
#include <vector>

using namespace std;


class car{
    private: //Access modifier
    // variables within class = attributes (members)
    string make; 
    string model;
    int year;
    string color;
    string makes[3] = {"Subaru", "Toyta", "Ford"};

    public:
    // functions within class = method
    void init(string setMake, string setModel, int setYear, string setColor){
        if(setYear > 2005 && setYear < 2028){
            make = setMake;
            model = setModel;
            year = setYear;
            color = setColor;
        }else if (setYear > 2028){
           cout << setYear << " cars do not exist." << endl; 
        }else{
            cout << "Do not accept this " << setYear << " " << setMake << " " << setModel << endl;
        }
        
    }
    void init(string setMake, string setModel, string setColor){
        make = setMake;
        model = setModel;
        color = setColor;
        year = 0;
    }
    void init(string setString){
        for(string findMake : makes){
            if (setString == findMake){
                make = setString;
                model = "Unknown";
                year = 0;
                return;
            }
        }
        model = setString;
        year = 0;

        
    }

    void setMake(string setMake){
        make = setMake;
    }
    void setModel(string setModel){
        model = setModel;
    }
    void setYear(int setYear){
        if(setYear > 2005){
            year = setYear;
        }else{
            cout << "Do not accept this car." << endl;
        }
        
    }
    void setColor(string setColor){
        color = setColor;
    }
    int getYear(){
        return year;
    }
    string getModel(){
        return model;
    }
    string getMake(){
        return make;
    }
    string getColor(){
        return color;
    }
};

int main(){

    vector<car> cars;
    car car1, car2, car3, car4;

    car1.setMake("Subaru");
    car1.setModel("Crosstrek");
    car1.setYear(2019);
    car1.setColor("White");

    car2.init("Toyota", "Crosstrek", 2001, "Gray");

    car3.init("Ford", "F-150", 2035, "Red");

    car4.init("F-150");

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

    cars.push_back(car1);
    cars.push_back(car2);
    cars.push_back(car3);
    cars.push_back(car4);

    cout << cars.at(3).getModel() << endl;    

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