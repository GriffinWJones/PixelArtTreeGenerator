#ifndef TRUNK_H
#define TRUNK_H
#include <SFML/Graphics.hpp>   
#include <iostream>
#include <vector>
#include "TrunkPixel.h"
#include "LeafPixel.h"
using namespace std;

#pragma once

class Trunk {
private:
    int pixelSize;
    int width, height;
    vector<Pixel *> pixels;

    void Grow(int x0, int y0, int x1, int y1, int colorIndex);

    vector<int> MakeBranch(int x0, int y0, int x1, int y1, int w);
    
    void GrowTree();

    void GrowLeafs(int x, int y, int w);

public:
    Trunk();

    Trunk(int width_, int height_, int pixleSize_);

    vector<Pixel*> Pixels();

};

#endif