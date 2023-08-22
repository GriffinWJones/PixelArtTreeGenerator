#include <SFML/Graphics.hpp>   
#include <iostream>
#include <vector> 
#include "Trunk.h"
#include "lodepng.h"
using namespace std;

void Generate(int width, int height, int pixelSize, vector<Pixel *> &pixels, vector<vector<Pixel*> > &Canvas ){
    pixels.clear();

    for(int r = 0; r < width; r++)
        for(int c = 0; c < height; c++)
            Canvas[r][c] = nullptr;

    Trunk trunk(width, height, pixelSize);
    for(auto t : trunk.Pixels()){
        pixels.push_back(t);
    }
}

int main()
{
    int WIDTH = 64;
    int HEIGHT = 64;
    int pixelSize = 10;

    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(WIDTH*pixelSize, HEIGHT*pixelSize), "TREE MAKER");
    vector<vector<Pixel*> > Canvas(HEIGHT, vector<Pixel*>(WIDTH, nullptr));
    vector<Pixel*> pixels;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::S) {
                    vector<unsigned char> image;
                    for(int r = 0; r < HEIGHT; r++){
                        for(int c = 0; c < WIDTH; c++){
                            if(Canvas[r][c] == nullptr){
                                image.push_back(255);
                                image.push_back(255);
                                image.push_back(255);
                                image.push_back(0);
                            }
                            else{
                                image.push_back(Canvas[r][c]->R());
                                image.push_back(Canvas[r][c]->G());
                                image.push_back(Canvas[r][c]->B());
                                image.push_back(255);
                            }
                        }
                    }
                    unsigned error = lodepng::encode("output.png", image, WIDTH, HEIGHT);
                    if (error) 
                        std::cout << "PNG encoding error: " << lodepng_error_text(error) << std::endl;
                }
                else if (event.key.code == sf::Keyboard::R){
                    Generate(WIDTH, HEIGHT, pixelSize, pixels, Canvas);
                }
            }
            
            if (event.type == sf::Event::Closed)
                window.close();
        } 

        window.clear(sf::Color(200, 200, 200));

        for(auto pixel : pixels){
            if(pixel->Y()/pixelSize < HEIGHT && pixel->X()/pixelSize < WIDTH && pixel->Y()/pixelSize >= 0 && pixel->X()/pixelSize >= 0 ){
                Canvas[pixel->Y()/pixelSize][pixel->X()/pixelSize] = pixel;
            }

            window.draw(pixel->Rect());
        }
        window.display();
    }

    return 0;
}
