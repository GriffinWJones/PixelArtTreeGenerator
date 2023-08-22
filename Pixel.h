#ifndef PIXEL_H
#define PIXEL_H
#include <SFML/Graphics.hpp>   
#include <iostream>
using namespace std;

#pragma once

class Pixel {

protected: 
    sf::RectangleShape pixel_rect;
    int xpos, ypos;
    int pixelSize;
    int r, g, b;

public:
    Pixel();

    Pixel(int x, int y, int ps);

    void SetPos(int x, int y);

    void SetColor(int red, int green, int blue);

    void SetColor(int colorIndex, vector<vector<int> > colors);

    int X();
    int Y();
    int R();
    int G();
    int B();

    sf::RectangleShape Rect();

};

#endif 