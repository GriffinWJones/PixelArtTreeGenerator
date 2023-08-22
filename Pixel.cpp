#include <SFML/Graphics.hpp>   
#include <iostream>
#include "Pixel.h"
using namespace std;

Pixel::Pixel(){
    pixelSize = 0;
    pixel_rect = sf::RectangleShape(sf::Vector2f(pixelSize, pixelSize));
    pixel_rect.setPosition(0, 0);
    xpos = 0;
    ypos = 0;
    r = 255;
    g = 255;
    b = 255;
    pixel_rect.setFillColor(sf::Color(r,g,b));
}

Pixel::Pixel(int x, int y, int ps){
    pixelSize = ps;
    pixel_rect = sf::RectangleShape(sf::Vector2f(pixelSize, pixelSize));
    pixel_rect.setPosition(x, y);
    xpos = x;
    ypos = y;
    r = 255;
    g = 255;
    b = 255;
    pixel_rect.setFillColor(sf::Color(r,g,b));
}

void Pixel::SetPos(int x, int y){
    xpos = x;
    ypos = y;
    pixel_rect.setPosition(x, y);
}

void Pixel::SetColor(int red, int green, int blue){
    r = red;
    g = green;
    b = blue;
    sf::Color color = sf::Color(r, g, b);
    pixel_rect.setFillColor(color);
}

void Pixel::SetColor(int colorIndex, vector<vector<int> > colors){
    
    r = colors[colorIndex][0];
    g = colors[colorIndex][1];
    b = colors[colorIndex][2];
    sf::Color color = sf::Color(r, g, b);
    pixel_rect.setFillColor(color);
}

int Pixel::X() { return xpos; }
int Pixel::Y() { return ypos; }
int Pixel::R() { return r; }
int Pixel::G() { return g; }
int Pixel::B() { return b; }

sf::RectangleShape Pixel::Rect(){return pixel_rect;}
