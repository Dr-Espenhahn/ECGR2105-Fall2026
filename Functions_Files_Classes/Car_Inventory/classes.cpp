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