#ifndef OBJECT_H
#define OBJECT_H

class Object 
{
protected:
	int x, y;	   
	int color;
public:
	Object(int _x = 0, int _y = 0, int _color = 0);

	int getX() const;
	int getY() const;
	void setX(int _x);
	void setY(int _y);

	virtual void draw() const = 0;

};

#endif