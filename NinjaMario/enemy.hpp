#ifndef ENEMY_H
#define ENEMY_H
#define ENEMYMAX 2
#include "object.hpp"

class Enemy : public Object
{
    private:
        
        int width, height; 
		

    public:
        Enemy(int _x = 0, int _y = 0, int _color = 0, int _width = 0, int _height = 0);

	   
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