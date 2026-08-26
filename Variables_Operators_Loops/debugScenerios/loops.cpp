// station_status_fixed.cpp
// Ground Station Startup Banner
//
// REQUIREMENT GS-002:
//   On startup, the ground station shall print a status banner,
//   then list every downlink channel as "ready".
//   The station has 4 downlink channels, numbered 1 through 4.


#include <iostream>


int main() {
    int channelCount = 4;


    std::cout << "TS-114 Ground Station: ONLINE" << std::endl


    for (int i = 1; i < channelCount; i++) {   
        std::cout << "  Channel " << i << ": ready" << std::endl;
    }


    return 0;
}
