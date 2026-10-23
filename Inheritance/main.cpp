#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Base class
class Animal {
    public:
    Animal(string n){
        name = n;
        desc << name << " can eat";
    }

    void about(){
        cout << desc.str() << endl;
    }

    void eat(){
        cout << name << " is eating." << endl;
    }

    virtual void vocalize() = 0; // pure virtual function -- makes class an abstract class

    protected:
    string name;
    stringstream desc;
};

class Mammal : public Animal {
    public:
    Mammal(string n) : Animal(n){
        desc << ", feed its babies with milk";
    }

    void feedMilk(){
        cout << name << " feeds its babies with milk." << endl;
    }

    void vocalize() override{
        cout << name << " makes a generic vocalization." << endl;
    }
    

};

class Canine : public Mammal{
    public:
    Canine(string n) : Mammal(n){
        desc << ", howl";
    }

    void howl() {
        cout << name << " makes a howling sound." << endl;
    }

    void vocalize() override{
        howl();
    }

};



int main(){
    Animal* ptrAni = new Canine("PtrName"); // pointer is fine

    //Animal genAni("AnimalName"); // Animal object cannot be created as it contains a pure virtual function
    Mammal genMam("MammalName");
    Canine genCan("CanineName");

    cout << "\n ----- PTR -----" << endl;
    ptrAni->vocalize();

    /*
    cout << "\n ----- Animal -----" << endl;
    genAni.about();
    genAni.vocalize();
    */

    cout << "\n ----- Mammal -----" << endl;
    genMam.about();
    genMam.vocalize();

    cout << "\n ----- Canine -----" << endl;
    genCan.about();
    genCan.vocalize();
    genCan.eat(); // Inherited from Animal
    genCan.feedMilk(); // Inherited from Mammal
    genCan.howl(); // Unique to Canine


    return 0;
}