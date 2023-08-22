#include <SFML/Graphics.hpp>   
#include <iostream>
#include <vector>
#include "Pixel.h"
#include "TrunkPixel.h"
using namespace std;

TrunkPixel::TrunkPixel(){
    r = pixelColors[0][0];
    g = pixelColors[0][1];
    b = pixelColors[0][2];
    pixel_rect.setFillColor(sf::Color(r, g, b));
}

TrunkPixel::TrunkPixel(int xpos, int ypos, int ps) : Pixel(xpos, ypos, ps){
    r = pixelColors[0][0];
    g = pixelColors[0][1];
    b = pixelColors[0][2];
    pixel_rect.setFillColor(sf::Color(r, g, b));
}

TrunkPixel::TrunkPixel(int xpos, int ypos, int ps, int colorIndex) : Pixel(xpos, ypos, ps) {
    SetColor(colorIndex, pixelColors);
    
}

vector<TrunkPixel*> TrunkPixel::Grow(int n){
    vector<TrunkPixel *> newPixels;
    int xMod = -n/2;
    for(int i = 0; i < n; i++){
        TrunkPixel *t = new TrunkPixel(xpos + xMod * pixelSize, ypos, pixelSize);
        newPixels.push_back(t);
        xMod++;
    }
    return newPixels;
}
