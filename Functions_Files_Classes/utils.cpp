#include <iostream>

#include "utils.h"

using namespace std;

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