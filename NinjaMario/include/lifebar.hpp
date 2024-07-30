#ifndef LIFEBAR_H
#define LIFEBAR_H
#include "object.hpp"
class Lifebar : public Object
{
private:
    int width, height;
    int health;

public:
    Lifebar(int _x = 0, int _y = 0, int _color = 0, int _width = 0, int _height = 0);

    int getWidth() const;
    int getHeight() const;

    void setWidth(int value);
    void setHeight(int value);
    void draw() const;
    void undraw() const;
    void damage(int value);
};

#endif