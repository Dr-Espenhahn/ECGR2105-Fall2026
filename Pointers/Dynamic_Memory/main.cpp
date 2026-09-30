#include <iostream>

using namespace std;


class MyClass {
    private:
    int* data; // Pointer to dynamically allocated memory on the heap


    public:
    MyClass(int value){
        data = new int; // Reserving space in the heap
        *data = value; // Setting value in the heap
    }

    // User-define destructor: Free the dynamically allocated memory
    ~MyClass(){
        delete data; // Deallocating space from the heap
    }

};



int main() {
    MyClass obj1(10);

    return 0;
}