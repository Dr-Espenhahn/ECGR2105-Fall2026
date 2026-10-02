#include <iostream>
#include <sstream> // Create our own string buffers (formatting shortcut!)
#include <iomanip> // Provides functions to change the output visuals

using namespace std;

class cOverride{
    int privInt;

    public:
    cOverride operator<<(int test){
        cout << "<< operator override" << endl;;
        privInt = test;
        return *this;
    }

};

int main() {
    string name, first, last;
    cin >> first; // extraction operator, breaks on whitespace
    // Buffer: "First Last\n"
    cout << first << "\n"; // insertion operator
    cin >> last;

    cout << first << " " << last << endl; // endl - both adds \n and 'flushes' buffer

    getline(cin, name); // breaks on new line (\n), NOT spaces

    


    cOverride overrideExample;
    overrideExample << 3;


    stringstream ss; // build our own stream

    string month;
    int day;
    char comma;
    int year;

    cout << "Date: ";

    cin >> month;
    cin >> day;
    cin >> comma;
    cin >> year;

    ss << month << " " << day << ", " << year;
    cout << ss.str() << endl;






    ss << setw(10) << setfill('*'); // iomanip functions
    ss << "test1 ";

    cout << ss.str() << endl;

    double x = 1122.5;

    ss << setprecision(2) << x;

    cout << ss.str() << endl;

    return 0;
}