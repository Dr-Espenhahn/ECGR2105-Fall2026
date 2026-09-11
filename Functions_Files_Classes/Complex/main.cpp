#include <iostream>
#include <cmath>

using namespace std;

struct Complex{ // struct -> class that is by default public
    double real;
    double imag;

    // Constructors
    Complex(){
        real = 0.0;
        imag = 0.0;
    }
    Complex(double real){
        Complex::real = real;
        Complex::imag = 0.0;
    }
    Complex(double real, double imag){
        Complex::real = real;
        Complex::imag = imag;
    }

    // Operator overrides
    Complex operator+(Complex rhs) const {
        Complex sum;
        sum.real = real + rhs.real;
        sum.imag = imag + rhs.imag;
        return sum;
    }

    Complex operator+(double rhs) const {
        Complex sum;
        sum.real = real + rhs;
        sum.imag = imag;
        return sum;
    }

    bool operator>(Complex rhs) const {
        return magnitude() > rhs.magnitude();
    }

    bool operator<(Complex rhs) const {
        return magnitude() < rhs.magnitude();
    }


    // Functions
    double magnitude() const{
        return sqrt(real*real + imag*imag);
    }

    Complex add(Complex rhs){
        Complex sum;
        sum.real = real + rhs.real;
        sum.imag = imag + rhs.imag;
        return sum;
    }

    Complex add(double real, double imag){
        Complex cTemp;
        cTemp.real = Complex::real + real;
        cTemp.imag = Complex::imag + imag;
        return cTemp;
    }

    void print() const{
        cout << real << " " << imag << "i" << endl;
    }

};

int main(){

    Complex c1(1.0, 7.0), c2(2.0, 3.0);

    //c1.real = 1.0;
    //c1.imag = 7.0;
    //c2.real = 2.0;
    //c2.imag = 3.0;

    // Below 2 lines are identical in operation
    Complex c3;
    c3.print();
    Complex c4 = c1.add(c2);

    if(c1 > c2){
        cout << "greater than" << endl;
    }else {
        cout << "less than" << endl;
    }


    return 0;
}