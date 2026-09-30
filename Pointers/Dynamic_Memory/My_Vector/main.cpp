#include <iostream>

using namespace std;

class MyVector{
    public:
    // Constructor
    MyVector(){
        allocatedSize = MEMORY_INCREMENT;
        filledSize = 0;
        a = new int[allocatedSize];
    }

    void push_back(int data){
        if(filledSize == allocatedSize){
            allocatedSize += MEMORY_INCREMENT;
            int* temp = new int[allocatedSize];
            for(int i = 0; i < filledSize; i++){
                temp[i] = a[i];
            }
            delete[] a;
            a = temp;
        }
        a[filledSize] = data;
        filledSize++;
    }

    void pop_back(){
        if(filledSize > 0)
            filledSize--;
    }

    int& at(unsigned int index){
        return a[index];
    }

    unsigned int size() const{
        return filledSize;
    }

// ********* 3 Functions that MUST be created when using pointers in a class

    // Destructor
    ~MyVector(){
        delete[] a;
    }

    // Override assignment operator
    void operator=(const MyVector& other){
        if(this == &other)
            return;

        delete[] a;

        allocatedSize = other.allocatedSize;
        filledSize = other.filledSize;
        a = new int[allocatedSize];
        for(int i = 0; i < filledSize; i++){
            a[i] = other.a[i];
        }
    }

    // Copy Constructor
    MyVector(const MyVector& other){
        allocatedSize = other.allocatedSize;
        filledSize = other.filledSize;
        a = new int[allocatedSize];
        for(int i = 0; i < filledSize; i++){
            a[i] = other.a[i];
        }
    }



    private:
    unsigned int const MEMORY_INCREMENT = 3; // Avoiding "magic" numbers
    unsigned int allocatedSize;
    unsigned int filledSize;
    int* a;
};



int main(){
    MyVector v, v2;

    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    v.push_back(9);

    v2 = v;

    v.pop_back();

    v.at(0) = 3;

    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }



    cout << "\nv2: " << endl;

    for(int i = 0; i < v2.size(); i++){
        cout << v2.at(i) << endl;
    }


    return 0;
}