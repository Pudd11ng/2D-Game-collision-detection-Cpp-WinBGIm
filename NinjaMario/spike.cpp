#include <graphics.h>
#include "spike.hpp"

Spike::Spike(int _x, int _y, int _color, int _width, int _height) : Object(_x, _y, _color), width(_width), height(_height){}


int Spike::getLeft() const { return x - width/2; }  
int Spike::getTop() const { return y; }
int Spike::getRight() const { return x + width/2; }  
int Spike::getBottom() const { return y + height; }     
int Spike::getWidth() const { return width; }
int Spike::getHeight() const { return height; }
int Spike::getCenterX() const { return x; }
int Spike::getCenterY() const { return y + (height)/2; }

void Spike::setWidth(int value) { width = value; }
void Spike::setHeight(int value) { height = value; }


void Spike::draw() const
{    
    setfillstyle(SOLID_FILL,color);
    setlinestyle(SOLID_LINE,0,5);
    setcolor(color);
    line(x, y, x - width/2, y + height);
    line(x, y, x + width/2, y + height);
    line(x - width/2, y + height, x + width/2, y + height);
    floodfill(x + 1, y + 10, color);
}


