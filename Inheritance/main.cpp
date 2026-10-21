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

};

class Canine : public Mammal{
    public:
    Canine(string n) : Mammal(n){
        desc << ", howl";
    }

    void howl() {
        cout << name << " makes a howling sound." << endl;
    }

};



int main(){

    Animal genAni("AnimalName");
    Mammal genMam("MammalName");
    Canine genCan("CanineName");

    
    genAni.about();
    genMam.about();
    genCan.about();

    cout << "\n ----- Canine -----" << endl;
    genCan.eat(); // Inherited from Animal
    genCan.feedMilk(); // Inherited from Mammal
    genCan.howl(); // Unique to Canine


    return 0;
}