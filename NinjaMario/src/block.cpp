#include <graphics.h>
#include "../include/block.hpp"

Block::Block(int _x, int _y, int _width, int _height, int _color) : Object(_x, _y, _color), width(_width), height(_height), previousoverlapX(0), previousoverlapY(0) {}

int Block::getWidth() const { return width; }
int Block::getHeight() const { return height; }
int Block::getBottom() const { return y + height; }
int Block::getRight() const { return x + width; }
int Block::getCenterX() const { return x + (width) / 2; }
int Block::getCenterY() const { return y + (height) / 2; }
int Block::getpreviousOverlapX() const { return previousoverlapX; }
int Block::getpreviousOverlapY() const { return previousoverlapY; }

void Block::setWidth(int value) { width = value; }
void Block::setHeight(int value) { height = value; }
void Block::setpreviousOverlapX(int value) { previousoverlapX = value; }
void Block::setpreviousOverlapY(int value) { previousoverlapY = value; }

void Block::setColor(int value) { color = value; }

void Block::draw() const
{
    setfillstyle(SOLID_FILL, color);
    bar(x, y, x + width, y + height);
}
