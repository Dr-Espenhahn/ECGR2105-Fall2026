#include <iostream>
#include <vector>

using namespace std;

class custom_exception : public runtime_error{
    private:
    int n;
    public:
    custom_exception(const std::string& what_arg, int i) : runtime_error(what_arg){
        n = i;
    };

    const char* what() const noexcept override{
        if(n = 0)
            return "Divide by zero";
        else
            return "Custom";
    }
};

double divide(double num, double denom){
    if(denom == 0){
        throw custom_exception("Divide by zero", 0);
    }
    return num / denom;
}

int main(){
    int userInput;
    //string word = "ten";
    //word.at(5);
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);

    cout << "Index: ";
    cin >> userInput;
    try{
       vec.at(userInput);
       double x = divide(20, 0);

        cout << "Continuing try" << endl;
    }
    catch(logic_error& e){
        cout << "Caught 3: " << e.what() << endl;
    }
    catch(out_of_range& e){
        cout << "Caught 1: " << e.what() << endl;
    }
    catch(custom_exception& e){
        cout << "Custom: " << e.what() << endl;
    }
    catch(runtime_error& e){
        cout << "Caught 2: " << e.what() << endl;
    }
    catch(...){
        cout << "Caught throw" << endl;
    }
    

    cout << "Code continues beyond try/catch" << endl;


    return 0;
}