#ifndef MARIO_H
#define MARIO_H
#include "block.hpp"
#include "spike.hpp"
#include "coin.hpp"
#include "lifebar.hpp"
#include "endpoint.hpp"
#include "enemy.hpp"
#include "object.hpp"

class Mario : public Object
{
    private:
        int size;
        int color;
        int speed;
        int vx, vy;
        void *image;
        int blockcount;
        int spikecount;
        int coincount;
        int enemycount;
            // these three objects are for Collision purpose 
        Block *blocks[BLOCKMAX];
        Spike *spikes[SPIKEMAX];
        Coin *coins[COINMAX]; 
        Enemy *enemys[ENEMYMAX];
        Lifebar *lifebar;
        Endpoint *endpoint;    
        Object *object;        
    
    public:
        Mario(int _x , int _y , int _color, int _size , int _vx, int _vy);
       
        
        int getVx() const;
        int getVy() const;
        int getRight() const;
        int getBottom() const;
        
        int getCenterX() const;
        int getCenterY() const;
        int getSpeed() const;

        void setImage();
        void setSpike(Spike* _spike);
        void setLifebar(Lifebar* _lifebar);
        void setEndpoint(Endpoint*_endpoint);
        void setBlock(Block* _block);
        void setEnemy(Enemy* _enemy);
        void setCoin(Coin* _coin);
        void setSpeed(int _speed);
        void set(int _x, int _y, int _size, int _color, int _speed);
        
        void draw() const;
        void undraw() ;
        int handleMario();
        void update();
        
        void spikeCollision();
        void blockCollision();
        void endpointCollision();
        void coinCollision();
        void enemyCollision();


};

#endif