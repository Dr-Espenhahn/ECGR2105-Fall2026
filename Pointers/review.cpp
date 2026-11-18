#include <iostream>
#include <vector>

using namespace std;


class Room{
    string name;
    vector<string> items;
    //...
    
};

class House{
    string desc;
    vector<Room> rooms;
    vector<string> items;
    int sqft;
    //...

    // Constructor
    public:
    House(){
        desc = "This is a house.";
    }
    House(string d) : desc(d) { }

    friend ostream &operator<<(ostream &out, const House &h);
};

ostream &operator<<(ostream &out, const House &h){
    out << h.desc;
    return out;
}

// Pass by reference is just a pointer
void funcExample(House &house){

}

struct example{
    int integer;
    example(int i) : integer(i) {}
    example() { integer = 0; }
};

example* makeData(){
    //example n(5);
    example* nptr = new example(5);
    return nptr;
}

int main(){
    vector<House> v1;
    vector<House>* v2 = &v1;

    example n(5);
    example* nptr = &n;

    example* makeEx = makeData();

    example* exPtr = new example();
    delete exPtr;

    cout << "makeData: " << makeEx->integer << endl;
    delete makeEx;


    nptr->integer = 10;

    n.integer = 7;

    cout << "n: " << n.integer << "\nnptr: " << nptr->integer << endl;

    cout << exPtr->integer << endl; // Dangling pointer

    House myHouse("My house");
    House* myAddress = &myHouse;

    cout << "House: " << myHouse << endl;
    cout << "Address: " << myAddress << endl;
    cout << "&House: " << &myHouse << endl;
    cout << "*Address: " << *myAddress << endl;
    cout << "&Address: " << &myAddress << endl;

    delete exPtr; // Double delete

    return 0;
}