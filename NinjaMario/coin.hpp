#ifndef COIN_H
#define COIN_H
#define COINMAX 10
#include "object.hpp"

class Coin : public Object 
{
  private:
	int r; 

  public:
	
	Coin(int _x = 0, int _y = 0, int _r = 0, int _color = 0);

    int getRadius() const;
	int getColor() const;
	
	void setRadius(int value);
	void setColor(int value);	
	void set(int _x, int _y, int _color, int _r);
	void draw() const;
	void undraw() const;

};

#endif
