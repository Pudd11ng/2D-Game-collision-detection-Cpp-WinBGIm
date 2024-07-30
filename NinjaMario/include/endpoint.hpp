#ifndef ENDPOINT_H
#define ENDPOINT_H

#include "object.hpp"

class Endpoint : public Object
{
private:
    int width, height;

public:
    Endpoint(int _x = 0, int _y = 0, int _color = 0, int _width = 0, int _height = 0);

    int getRight() const;
    int getBottom() const;
    int getWidth() const;
    int getHeight() const;
    int getCenterX() const;
    int getCenterY() const;

    void setWidth(int value);
    void setHeight(int value);
    void draw() const;
};

#endif
