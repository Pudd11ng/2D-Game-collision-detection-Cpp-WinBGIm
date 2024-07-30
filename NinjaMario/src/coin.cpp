#include <graphics.h>
#include "../include/coin.hpp"
Coin::Coin(int _x, int _y, int _r, int _color) : Object(_x, _y, _color), r(_r) {}

int Coin::getRadius() const { return r; }
int Coin::getColor() const { return color; }

void Coin::setRadius(int value) { r = value; }
void Coin::setColor(int value) { color = value; }

void Coin::set(int _x, int _y, int _color, int _r)
{
    x = _x;
    y = _y;
    color = _color;
    r = _r;
}

void Coin::draw() const
{
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    setlinestyle(SOLID_LINE, 0, 1);
    circle(x, y, r);
    floodfill(x + 1, y + 1, color);
}

void Coin::undraw() const
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    setlinestyle(SOLID_LINE, 0, 1);
    circle(x, y, r);
    floodfill(x + 1, y + 1, BLACK);
}
