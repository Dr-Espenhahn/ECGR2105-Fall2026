#include <iostream>
#include "utils.h"

using namespace std;

/*
//Prototypes of overloaded functions (functions of same name with different passed variables)
int roundHund(int sendVal);
void roundHund(int& sendVal, int& sendVal2);
double roundHund(double sendVal);
*/

main(){

    int var1 = 1;
    int var2 = 2;

    roundHund(var1, var2);

    return 0;
}

/*
int roundHund(int sendVal){
    sendVal /= 100;
    sendVal *= 100;
    cout << "int" << endl;
    return sendVal;
}

void roundHund(int& sendVal, int& sendVal2){
    sendVal /= 100;
    sendVal *= 100;

    sendVal2 /= 100;
    sendVal2 *= 100;
    cout << "multi int" << endl;
}

double roundHund(double sendVal){
    sendVal /= 100;
    sendVal = (int) sendVal;
    sendVal *= 100.0;
    cout << "double" << endl;
    return sendVal;
}
    */