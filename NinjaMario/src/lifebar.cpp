#include <graphics.h>
#include "../include/lifebar.hpp"

Lifebar::Lifebar(int _x, int _y, int _color, int _width, int _height) : Object(_x, _y, _color), width(_width), height(_height), health(_width) {}

int Lifebar::getWidth() const { return width; }
int Lifebar::getHeight() const { return height; }

void Lifebar::setWidth(int value) { width = value; }
void Lifebar::setHeight(int value) { height = value; }

void Lifebar::draw() const
{
    if (health > width || health < 0)
        return;

    setfillstyle(SOLID_FILL, color);
    bar(x, y, x + width, y + height);

    setfillstyle(SOLID_FILL, RED);
    bar(x + width / 20, y + height / 20, x + width / 20 + health - (2 * health / 20), y + (19 * height / 20));

    setcolor(BLACK);
    setlinestyle(SOLID_LINE, 0, 1);
    rectangle(x + width / 20, y + height / 20, x + (19 * width / 20), y + (19 * height / 20));
}

void Lifebar::undraw() const
{
    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width, y + height);
}

void Lifebar::damage(int value) { health = health - value; }
