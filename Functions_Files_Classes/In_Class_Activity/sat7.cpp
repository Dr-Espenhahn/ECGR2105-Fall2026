/*
In this project you will be working on a practical exercise from the world of engineering:

ANOMALY — SAT-7 BATTERY THERMAL EVENT

A reconnaissance satellite passes over your ground station once every 94 minutes. You get 
roughly 10 seconds of usable contact per pass. During the last pass, the spacecraft 
reported abnormal battery temperatures before signal was lost. You are the ground station 
software engineer. Before the next pass, you need to complete the following code:

The Code

SAT-7 carries exactly six battery temperature sensors. That number is fixed by the 
hardware and will never change. Create a function that will print every reading and flag 
anything above 45°C.

Example output:
BATTERY THERMAL REPORT
20.6
50.7 *** OVER LIMIT ***
26.6
38.9
44.2
37.5

Below is what you know. The satellite doesn't wait. Let's go:

*/


#include <iostream>

using namespace std;

int main(){
    double batteryTemps[6] = { 21.4, 23.8, 47.2, 22.0, 51.6, 20.9 };

    cout << "BATTERY THERMAL REPORT" << endl;

    // Add function call here

    return 0;
}