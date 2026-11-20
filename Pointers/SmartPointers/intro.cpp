#include <iostream>
#include <memory>

using namespace std;

struct Data{
    Data() { cout << "Data created." << endl; } // Constructor
    ~Data() { cout << "Data destroyed." << endl; }// Destructor
};


int main(){
    //Data* d = new Data;
    // do something
    //throw runtime_error("error");
    //do more
    //delete d;
    
    //unique_ptr<Data> p = make_unique<Data>(); // Cannot be copied
    //unique_ptr<Data> p2 = move(p);

    shared_ptr<int> p = make_shared<int>(64); // Tracks a reference count
    shared_ptr<int> p2 = p, p3 = p;
    shared_ptr<int> p4 = make_shared<int>(16);
    cout << *p2 << endl;

    p.reset(); // destroy pointer & data

    return 0;
}