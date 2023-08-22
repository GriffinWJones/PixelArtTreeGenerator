#ifndef LEAFPIXEL_H
#define LEAFPIXEL_H
#include <SFML/Graphics.hpp>   
#include <iostream>
#include <vector>
#include <cmath>
#include "Pixel.h"
using namespace std;

#pragma once

class LeafPixel : public Pixel {
private:

    vector<vector<int> > pixelColors = {
        {23, 32, 56},
        {37, 86, 46},
        {70, 130, 50},
        {117, 167, 67},
        {168, 202, 88}
    };

public:
    LeafPixel();
    
    LeafPixel(int xpos, int ypos, int ps);

    vector<LeafPixel *> Grow(int r);

};
#endif