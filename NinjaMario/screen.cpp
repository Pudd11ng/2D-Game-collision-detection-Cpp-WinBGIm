#include "screen.hpp"
#include <graphics.h>



Screen::Screen(int _x, int _y, int _color, int _width, int _height): Object(_x, _y, _color), width(_width), height(_height) {}


int Screen::getWidth() const { return width; }
int Screen::getHeight() const { return height; }
int Screen::getRight() const { return x + width; }
int Screen::getBottom() const { return y + height; }



void Screen::setWidth(int value) { width = value; }
void Screen::setHeight(int value) { height = value; }
void Screen::setSize(int _width, int _height)
{
	width = _width;
	height = _height;
}

void Screen::set(int _x, int _y, int _color, int _width, int _height)
{
	x = _x;
	y = _y;
	color = _color;
	width = _width;
	height = _height;
	
}

void Screen::draw() const
{
	setfillstyle(SOLID_FILL,color);
	bar( x, y, x+width, y+height );
}
