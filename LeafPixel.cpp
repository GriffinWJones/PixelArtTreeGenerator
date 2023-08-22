#include <SFML/Graphics.hpp>   
#include <iostream>
#include <vector>
#include <cmath>
#include "Pixel.h"
#include "LeafPixel.h"
using namespace std;

LeafPixel::LeafPixel(){
    r = pixelColors[0][0];
    g = pixelColors[0][1];
    b = pixelColors[0][2];
    pixel_rect.setFillColor(sf::Color(r, g, b));
}

LeafPixel::LeafPixel(int xpos, int ypos, int ps) : Pixel(xpos, ypos, ps){
    r = pixelColors[0][0];
    g = pixelColors[0][1];
    b = pixelColors[0][2];
    pixel_rect.setFillColor(sf::Color(r, g, b));
}

vector<LeafPixel *> LeafPixel::Grow(int r){
    vector<LeafPixel *> leaves;
    int baseXPos = xpos / pixelSize;
    int baseYPos = ypos / pixelSize;

    for(int y = baseYPos - r; y <= baseYPos + r; y++){
        for(int x = baseXPos - r; x <= baseXPos + r; x++){
            if(pow(x-baseXPos, 2) + pow(y - baseYPos, 2) <= pow(r, 2)){
                LeafPixel * l = new LeafPixel(x * pixelSize, y * pixelSize, pixelSize);
                float mid = float(r) * 3.0f / 5.0f;
                int pixelColorIndex = 0;
                if(pow(x - mid/2/2 - baseXPos, 2) + pow(y + mid/2/2 - baseYPos, 2) <= pow(mid/2, 2)) pixelColorIndex = 4;
                else if (pow(x - mid/2 - baseXPos, 2) + pow(y + mid/2 - baseYPos, 2) <= pow(mid, 2)) pixelColorIndex = 3;
                else if (pow(x - mid/0.5/2 - baseXPos, 2) + pow(y + mid/0.5/2 - baseYPos, 2) <= pow(mid/0.5, 2)) pixelColorIndex = 2;
                else if (pow(x - mid/0.25/2 - baseXPos, 2) + pow(y + mid/0.25/2 - baseYPos, 2) <= pow(mid/0.25, 2)) pixelColorIndex = 1;
                else pixelColorIndex = 0;
                l->SetColor(pixelColors[pixelColorIndex][0], pixelColors[pixelColorIndex][1], pixelColors[pixelColorIndex][2]);
                leaves.push_back(l);
            }
        }
    }
    
    return leaves;
}
