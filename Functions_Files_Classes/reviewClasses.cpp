#include <iostream>

using namespace std;


class MyClass{
    private:
	int myInt;
	double myDbl;

    public:
	MyClass(){}
	MyClass(int myInt, double myDbl){
		MyClass::myInt = myInt;
		MyClass::myDbl = myDbl;
	}

    void setInt(int myInt){
        MyClass::myInt = myInt;
    }

    void setDbl(double myDbl){
        MyClass::myDbl = myDbl;
    }

    void printInt() const{
        cout << myInt << endl;
    }
};

int main() {
	MyClass myObj;
    
	
	myObj.setInt(5);
	myObj.setDbl(20.6);

    myObj.printInt();
}