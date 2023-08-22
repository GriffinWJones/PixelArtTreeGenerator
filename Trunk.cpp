#include <SFML/Graphics.hpp>   
#include <iostream>
#include <vector>
#include "TrunkPixel.h"
#include "Trunk.h"
#include "LeafPixel.h"
using namespace std;

void Trunk::Grow(int x0, int y0, int x1, int y1, int colorIndex){
    x0 /= pixelSize;
    y0 /= pixelSize;
    x1 /= pixelSize;
    y1 /= pixelSize;

    int dx = x1 - x0;
    int dy = y1 - y0;

    int x = x0;
    int y = y0;

    TrunkPixel * tp1 = new TrunkPixel(x * pixelSize, y * pixelSize, pixelSize, colorIndex);
    pixels.push_back(tp1);

    float m = float(dy) / float(dx);

    int P;

    int octant = 0;
    if(0 <= m && m <= 1 && dx > 0) octant = 1;
    else if(m > 1 && dy > 0) octant = 2;
    else if(m < -1 && dy > 0) octant = 3;
    else if(-1 <= m && m <= 0 && dx < 0) octant = 4;
    else if(0 <= m && m <= 1 && dx < 0) octant = 5;
    else if(m > 1 && dy < 0) octant = 6;
    else if(m < -1 && dy < 0) octant = 7;
    else octant = 8;

    switch (octant)
    {
        case 1:  
            P = 2 * dy - dx;
            while(x < x1){
                if(P > 0)
                {
                    y += 1;
                    P = P + 2 * (dy - dx);
                }
                else
                {
                    P = P + 2 * dy;
                }
                x += 1;
                TrunkPixel * tp2 = new TrunkPixel(x * pixelSize, y * pixelSize, pixelSize, colorIndex);
                pixels.push_back(tp2);
            }
            break;
        
        case 2:
            P = 2 * dx - dy;
            while(y < y1){
                if(P > 0)
                {
                    x += 1;
                    P = P + 2 * (dx - dy);
                }
                else
                {
                    P = P + 2 * dx;
                }
                y += 1;
                TrunkPixel * tp2 = new TrunkPixel(x * pixelSize, y * pixelSize, pixelSize, colorIndex);
                pixels.push_back(tp2);
            }
            break;
        
        case 3:
            P = 2 * dx + dy;
            while(y < y1){
                if(P > 0)
                {
                    x -= 1;
                    P = P + 2 * (-dx - dy);
                }
                else
                {
                    P = P + 2 * (-dx);
                }
                y += 1;
                TrunkPixel * tp2 = new TrunkPixel(x * pixelSize, y * pixelSize, pixelSize, colorIndex);
                pixels.push_back(tp2);
            }
            break;
        
        case 4: 
            P = 2 * dy + dx;
            while(x > x1){
                if(P > 0)
                {
                    y += 1;
                    P = P + 2 * (dy + dx);
                }
                else
                {
                    P = P + 2 * dy;
                }
                x -= 1;
                TrunkPixel * tp2 = new TrunkPixel(x * pixelSize, y * pixelSize, pixelSize, colorIndex);
                pixels.push_back(tp2);
            }
            break;
        
        case 5:  
            P = 2 * (-dy) + dx;
            while(x > x1){
                if(P > 0)
                {
                    y -= 1;
                    P = P + 2 * (-dy + dx);
                }
                else
                {
                    P = P + 2 * (-dy);
                }
                x -= 1;
                TrunkPixel * tp2 = new TrunkPixel(x * pixelSize, y * pixelSize, pixelSize, colorIndex);
                pixels.push_back(tp2);
            }
            break;
        
        case 6:
            P = 2 * dx - dy;
            while(y > y1){
                if(P > 0)
                {
                    x -= 1;
                    P = P + 2 * (-dx + dy);
                }
                else
                {
                    P = P + 2 * (-dx);
                }
                y -= 1;
                TrunkPixel * tp2 = new TrunkPixel(x * pixelSize, y * pixelSize, pixelSize, colorIndex);
                pixels.push_back(tp2);
            }
            break;
        
        case 7:
            P = 2 * dx + dy;
            while(y > y1){
                if(P > 0)
                {
                    x += 1;
                    P = P + 2 * (dx + dy);
                }
                else
                {
                    P = P + 2 * dx;
                }
                y -= 1;
                TrunkPixel * tp2 = new TrunkPixel(x * pixelSize, y * pixelSize, pixelSize, colorIndex);
                pixels.push_back(tp2);
            }
            break;
        
        case 8: 
            P = 2 * dy + dx;
            while(x < x1){
                if(P > 0)
                {
                    y -= 1;
                    P = P + 2 * (-dy - dx);
                }
                else
                {
                    P = P + 2 * (-dy);
                }
                x += 1;
                TrunkPixel * tp2 = new TrunkPixel(x * pixelSize, y * pixelSize, pixelSize, colorIndex);
                pixels.push_back(tp2);
            }
            break;
    
    }

}

vector<int> Trunk::MakeBranch(int x0, int y0, int x1, int y1, int w){
    vector<int> branch(5);
    float dx = x1 - x0;
    float dy = y1 - y0;
    float m = dy / dx;
    
    int branchStartHeight = (2 * (y0 - y1)) / 3;
    int y = rand() % branchStartHeight + y1;
    int x = ((y - y1) / m) + x1;

    float yLevel = 3 * float(y) / float(y0);
    
    int xDist = float(rand() % (width / 10) + (width/20)); 
    xDist *= ((rand() % 2) * 2 - 1); 
    xDist *= yLevel; 
    xDist += x;
    int yDist = float(rand() % 10 + 3) * yLevel;
    yDist = y - yDist;
    
    branch[0] = x * pixelSize;
    branch[1] = y * pixelSize;
    branch[2] = xDist * pixelSize;
    branch[3] = yDist * pixelSize;
    branch[4] = float(w / 4) * yLevel + 1;

    return branch;
}

void Trunk::GrowTree(){
    vector<vector<int> > treePoints;
    vector<int> trunk(5);
    int seedX = width/2 - 1;
    int seedY = height - 1;
    int endX = seedX + ((width / (rand() % 10 + 3)) * (((rand() % 2) * 2) - 1));
    int endY = (seedY - (4 * height) / 5) + ((rand() % height/7) * (((rand() % 2) * 2) - 1));
    int branchWidth = width / 14;

    trunk[0] = seedX * pixelSize;
    trunk[1] = seedY * pixelSize;
    trunk[2] = endX * pixelSize;
    trunk[3] = endY * pixelSize;
    trunk[4] = branchWidth;

    treePoints.push_back(trunk);

    int numBranches = rand() % 15 + 7;

    for(int i = 0; i < numBranches; i++){
        vector<int> branch = MakeBranch(seedX, seedY, endX, endY, branchWidth);
        treePoints.push_back(branch);
    }

    for(int i = 0; i < treePoints.size(); i++){
        if(treePoints[i].size() == 5){
            int dx = abs(treePoints[i][2] - treePoints[i][0]);
            int dy = abs(treePoints[i][3] - treePoints[i][1]);

            int colorIndex;

            if(dy > dx){
                for(int n = - treePoints[i][4] / 2; n < treePoints[i][4]/2; n++){
                    colorIndex = (n + treePoints[i][4]/2) / ((treePoints[i][4]) / 4);
                    if(treePoints[i][4] <= 1)
                        colorIndex = 2;
                    Grow(treePoints[i][0] + (n * pixelSize), treePoints[i][1], treePoints[i][2], treePoints[i][3], colorIndex);
                }
            }
            else{
                for(int n = - treePoints[i][4] / 2; n < treePoints[i][4]/2; n++){
                    colorIndex = (n + treePoints[i][4]/2) / ((treePoints[i][4]) / 4);
                    if(treePoints[i][4] <= 1)
                        colorIndex = 2;
                    Grow(treePoints[i][0], treePoints[i][1] + (n * pixelSize), treePoints[i][2], treePoints[i][3], colorIndex);
                }
            }
            
            int leafSize = (rand() % (width / 10))  + width/10;
            
            while(leafSize > 0 && (treePoints[i][2]/pixelSize + leafSize >= width || treePoints[i][2]/pixelSize - leafSize < 0 || treePoints[i][3]/pixelSize + leafSize >= height || treePoints[i][3]/pixelSize - leafSize < 0)){
                leafSize--;
            }
           GrowLeafs(treePoints[i][2], treePoints[i][3], leafSize);
        }
    }
} 

void Trunk::GrowLeafs(int x, int y, int w){
    LeafPixel * lp = new LeafPixel(x, y, pixelSize);
    pixels.push_back(lp);
    vector<LeafPixel *> lps = lp->Grow(w);
    pixels.insert(pixels.end(), lps.begin(), lps.end());
}

Trunk::Trunk(){
    width = 0;
    height = 0;
    pixelSize = 0;
}

Trunk::Trunk(int width_, int height_, int pixleSize_){
    width = width_;
    height = height_;
    pixelSize = pixleSize_;
    GrowTree();
}

vector<Pixel*> Trunk::Pixels(){ return pixels; }
