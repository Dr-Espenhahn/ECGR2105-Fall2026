#include <iostream>
#include <memory>

using namespace std;

class Child;

class Parent {
    public:
    string print = "Parent exists.";
    shared_ptr<Child> child;

    Parent() { cout << "Parent created." << endl; }
    ~Parent() { cout << "Parent destroyed." << endl;}
};

class Child {
    public:
    weak_ptr<Parent> parent;

    void printParent() {
        if (shared_ptr<Parent> p = parent.lock()){
            cout << p->print << endl;
        }else{
            cout << "Parent no longer exists!" << endl;
        }
        
    }

    Child() { cout << "Child created." << endl; }
    ~Child() { cout << "Child destroyed." << endl; }
};

int main(){
    shared_ptr<Parent> p = make_shared<Parent>();
    p->child = make_shared<Child>();
    p->child->parent = p;

    p.reset();

    p->child->printParent();

    return 0;
}