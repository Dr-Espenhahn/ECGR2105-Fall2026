#include <iostream>
#include <vector>

using namespace std;

bool getUserDrinkingAge(){
    int age;
    cin >> age;

    if(age < 21){
        return false;
    }else{
        return true;
    }
}

// Custom exception
class LessThan10 : public exception {
    private:
        int value;

    public:
    //Constructor
    LessThan10(int val) : value(val) {}

    //Need to override to tell what error is
    const char* what() const noexcept override{
        return "Value less than 10 error.";
    }

    int getValue() const{
        return value;
    }

};

void throwEx(int n){
    if (n > 10){
        cout << "Does something";
    } else{
        throw LessThan10(n);
    }
}

int main(){

    try{
        throwEx(5);
    }
    catch(int e){
        cout << "An error occured. Error code: " << e << endl;
    }
    catch(double e){
        cout << "A double error occured." << endl;
    }
    catch(LessThan10 &e){
        cout << e.what() << endl;
        cout << "Value was: " << e.getValue() << endl;
    }
    
    

    cout << "Age: ";
    if (getUserDrinkingAge()){
        cout << "Over 21, come in!" << endl;
    } else{
        cout << "Under 21, go away." << endl;
    }
    return 0;
}