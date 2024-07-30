#ifndef SCREEN_H
#define SCREEN_H
#include "object.hpp"

class Screen : public Object
{
private:
	int width, height;

public:
	Screen(int _x = 0, int _y = 0, int _color = 0, int _width = 0, int _height = 0);

	int getWidth() const;
	int getHeight() const;
	int getRight() const; // The right most x value of the Screen
	int getBottom() const;

	void setWidth(int value);
	void setHeight(int value);
	void setSize(int _width, int _height);
	void set(int _x, int _y, int _color, int _width, int _height);

	void draw() const;
};

#endif
