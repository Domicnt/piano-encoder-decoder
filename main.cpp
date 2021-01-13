//13 analog input
//52 digital input
//25 keys
//
//10 keys max pressed at once
//
//10 analog inputs active = all 10 keys pressed
//10 digital inputs of the first 25 should be active at this point
//based on which of the digital inputs pressed is which keys are pressed
//
//analog inputs are in ascending order ex: if 3 keys are pressed: 3,7, and 13, 
//then the 3rd, 7th, and 13th digital inputs will be active, and the first 3 
//analog inputs will be active, first for key 3, then key 7, then key 13

#include "stdio.h"
#include "tuple"

void main() {

    return;
}

std::tuple<bool[52], float[13]> encode(std::tuple<float[25]> keys) {
    std::tuple<bool[52], float[13]> pins;
    
    //force of keys
    float activeKeys[10];
    //keys which are pressed
    int usedKeys[10];
    //current key
    int pin = 0;

    for (auto i = 0; i < 25; i++) {
        float key = std::get<0>(keys)[i];
        if (key > 0 && pin < 10) {
            activeKeys[pin] = key;
            usedKeys[pin] = i;
            pin++;
        }
    }

    for (auto i = 0; i <= pin; i++) {
        std::get<0>(pins)[usedKeys[i]] = true;
        std::get<1>(pins)[i] = activeKeys[i];
    }
    
    return pins;
}

std::tuple<float[25]> decode(std::tuple<bool[52], float[13]> pins) {
    std::tuple<float[25]> keys;

    //force of keys
    float activeKeys[10];
    //keys which are pressed
    int usedKeys[10];
    //current key
    int pin = 0;

    for (auto i = 0; i < 52; i++) {
        if (std::get<0>(pins)[i] == true) {
            usedKeys[pin] = i;
            activeKeys[pin] = std::get<1>(pins)[pin];
            pin++;
        }
    }

    for (auto i = 0; i <= pin; i++)
        std::get<0>(keys)[usedKeys[i]] = activeKeys[i];
        
    return keys;
}