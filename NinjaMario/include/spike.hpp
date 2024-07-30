#ifndef SPIKE_H
#define SPIKE_H
#define SPIKEMAX 10
#include "object.hpp"

class Spike : public Object
{
private:
    int width, height;

public:
    Spike(int _x = 0, int _y = 0, int _color = 0, int _width = 0, int _height = 0);

    int getLeft() const;
    int getTop() const;
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