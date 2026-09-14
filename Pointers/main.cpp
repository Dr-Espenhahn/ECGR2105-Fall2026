#include <iostream>

using namespace std;

void func(){
    int z=15;
    //cout << z << endl;
    return;
}

void swap(int* x, int* y){
    int temp = *x; // storing the data at location x
    *x = *y; // copy data stored at y to be at location x
    *y = temp; 
}

void swap2(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int* ptrB = new int; // new = create memory space

    *ptrB = 20;

    cout << "ptrB: " << ptrB << endl;
    cout << "*ptrB: " << *ptrB << endl;

    delete ptrB; // delete = clean memory space reserved using "new"

    int x = 5;
    int y = 15;
    int* ptr = &x; // * = pointer, & = address of variable

    cout << "ptrB: " << ptrB << endl;
    cout << "*ptrB: " << *ptrB << endl;

    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;
    cout << "ptr: " << ptr << endl;
    cout << "*ptr: " << *ptr << endl;

    cout << "x: " << x << endl;
    swap(ptr, &y);
    cout << "x: " << x << endl;
    swap2(x, y);
    cout << "x: " << x << endl;

    func();

    int a = 5;


    return 0;
}