#ifndef TRUNKPIXEL_H
#define TRUNKPIXEL_H
#include <SFML/Graphics.hpp>   
#include <iostream>
#include <vector>
#include "Pixel.h"
using namespace std;

#pragma once

class TrunkPixel : public Pixel {
private:

    vector<vector<int> > pixelColors = {
        {36, 21, 39},
        {52, 28, 39},
        {77, 43, 50},
        {122, 72, 65},
        {173, 119, 87}
    };

public:
    TrunkPixel();
    
    TrunkPixel(int xpos, int ypos, int ps);

    TrunkPixel(int xpos, int ypos, int ps, int colorIndex);

    vector<TrunkPixel*> Grow(int n);

};

#endif