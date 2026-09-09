#ifndef CAR_H
#define CAR_H

using namespace std;


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




#endif