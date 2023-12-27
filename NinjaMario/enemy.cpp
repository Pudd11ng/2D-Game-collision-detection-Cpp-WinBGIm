#include <graphics.h>
#include "enemy.hpp"

  Enemy::Enemy(int _x, int _y,int _color, int _width, int _height) : Object(_x, _y, _color), width(_width), height(_height){}

       
       int Enemy::getWidth() const { return width; }
       int Enemy::getHeight() const { return height; }
       int Enemy::getBottom() const { return x + height; } 
       int Enemy::getRight() const { return y + width; } 
       int Enemy::getCenterX() const { return x + (width)/2; }
       int Enemy::getCenterY() const { return y + (height)/2; }

       void Enemy::setWidth(int value) { width = value; }
       void Enemy::setHeight(int value) { height = value; }
   

       void Enemy::draw() const
       {
          readimagefile("enemy.jpg", x, y, x + width, y + height);
       }
