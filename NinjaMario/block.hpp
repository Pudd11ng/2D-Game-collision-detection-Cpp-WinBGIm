#ifndef BLOCK_H
#define BLOCK_H
#define BLOCKMAX 5
#include "object.hpp"

class Block : public Object 
{
private:
	int width, height; 
	
	int previousoverlapX;
	int previousoverlapY; 

public:
	Block(int _x = 0, int _y = 0, int _width= 0, int _height= 0, int _color = 0);

    int getWidth() const;
    int getHeight() const;
	
	int getBottom() const;
	int getRight() const; 
	int getCenterX() const;
	int getCenterY() const;
	int getpreviousOverlapX() const; 
	int getpreviousOverlapY() const; 


	void setWidth(int value);
	void setHeight(int value);
    void setColor(int value);
	void setpreviousOverlapX(int value);
	void setpreviousOverlapY(int value);

    void draw() const;
	
};

#endif