#include <graphics.h>
#include "../include/endpoint.hpp"

Endpoint::Endpoint(int _x, int _y, int _color, int _width, int _height) : Object(_x, _y, _color), width(_width), height(_height) {}

int Endpoint::getRight() const { return x + width; }
int Endpoint::getBottom() const { return y + height; }
int Endpoint::getWidth() const { return width; }
int Endpoint::getHeight() const { return height; }
int Endpoint::getCenterX() const { return x + (width) / 2; }
int Endpoint::getCenterY() const { return y + (height) / 2; }

void Endpoint::setWidth(int value) { width = value; }
void Endpoint::setHeight(int value) { height = value; }

void Endpoint::draw() const
{
    setfillstyle(1, GREEN);
    bar(x, y, x + width, y + height / 3);

    setfillstyle(1, BROWN);
    bar(x, y, x + width / 20, y + height);

    setfillstyle(1, BROWN);
    bar(x - width / 10, y + 18 * height / 20, x + width / 10, y + 19 * height / 20);
    bar(x - width / 6, y + 19 * height / 20, x + width / 6, y + height);
}