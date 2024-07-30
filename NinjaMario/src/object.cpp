#include <graphics.h>
#include "../include/object.hpp"

Object::Object(int _x, int _y, int _color) : x(_x), y(_y), color(_color) {}

int Object::getX() const { return x; }
int Object::getY() const { return y; }

void Object::setX(int _x) { x = _x; }
void Object::setY(int _y) { y = _y; }
