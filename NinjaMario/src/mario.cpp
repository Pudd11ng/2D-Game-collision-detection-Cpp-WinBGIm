#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include "../include/mario.hpp"

using namespace std;
#define g 20

int screenWidth = getmaxwidth();
int screenHeight = getmaxheight();

Mario::Mario(int _x, int _y, int _color, int _size, int _vx, int _vy)
    : Object(_x, _y, _color), size(_size), vx(_vx), vy(_vy), image(new char[imagesize(x, y, x + size, y + size)]), blockcount(0), spikecount(0), coincount(0), enemycount(0) {}

int Mario::getVx() const { return vx; }
int Mario::getVy() const { return vy; }
int Mario::getRight() const { return x + size; }
int Mario::getBottom() const { return y + size; }
int Mario::getCenterX() const { return x + size / 2; }
int Mario::getCenterY() const { return y + size / 2; }
int Mario::getSpeed() const { return speed; }

void Mario::setImage()
{
    readimagefile("./images/mr.jpg", x, y, x + size, y + size);
    getimage(x, y, x + size, y + size, image);
    undraw();
}
void Mario::setSpike(Spike *_spike)
{
    spikes[spikecount] = _spike;
    spikecount++;
}
void Mario::setLifebar(Lifebar *_lifebar) { lifebar = _lifebar; }
void Mario::setBlock(Block *_block)
{
    blocks[blockcount] = _block;
    blockcount++;
}
void Mario::setEndpoint(Endpoint *_endpoint) { endpoint = _endpoint; }
void Mario::setCoin(Coin *_coin)
{
    coins[coincount] = _coin;
    coincount++;
}
void Mario::setEnemy(Enemy *_enemy)
{
    enemys[enemycount] = _enemy;
    enemycount++;
}
void Mario::setSpeed(int _speed) { speed = _speed; }
void Mario::set(int _x, int _y, int _size, int _color, int _speed)
{
    setSpeed(_speed);
}

void Mario::draw() const
{
    putimage(x, y, image, COPY_PUT);
}

void Mario::undraw()
{
    setfillstyle(SOLID_FILL, BLACK);
    setcolor(BLACK);
    bar(x, y, x + size + 1, y + size + 1);
}

int Mario::handleMario()
{
    char key = 0;
    key = getch();
    switch (key)
    {
    case KEY_UP:
        y = y - 10 * vy;
        break;

    case KEY_LEFT:
        if ((y + size) != screenHeight)
            x = x - 6 * vx;
        else
            x = x - vx;
        break;

    case KEY_RIGHT:
        if ((y + size) != screenHeight)
            x = x + 6 * vx;
        else
            x = x + vx;
        break;
    }

    return key;
}
void Mario::update()
{
    y += g;

    if (x < 0)
    {
        x = 0;
    }
    else if (x + size > screenWidth)
    {
        x = screenWidth - size;
    }

    if (y < 0)
    {
        y = 0;
    }
    else if (y + size > screenHeight)
    {
        y = screenHeight - size;
    }
}

void Mario::spikeCollision()
{
    int key = 0;
    for (int i = 0; i < SPIKEMAX; i++)
    {
        int dx = abs(getCenterX() - spikes[i]->getCenterX());
        int dy = abs(getCenterY() - spikes[i]->getCenterY());
        int overlapX = (size / 2) + ((spikes[i]->getWidth()) / 2) - dx;
        int overlapY = (size / 2) + ((spikes[i]->getHeight()) / 2) - dy;

        if (overlapX > 0 && overlapY > 0)
        {
            size = 0;
            x = screenWidth + 1;
            y = screenHeight + 1;
            lifebar->damage(400);
            lifebar->undraw();
            lifebar->draw();
            readimagefile("./images/gameover.jpg", 0.2 * screenWidth, 0.2 * screenHeight, 0.8 * screenWidth, 0.8 * screenHeight);
        }
    }
}

void Mario::blockCollision()
{
    for (int i = 0; i < BLOCKMAX; i++)
    {
        int dx = abs(getCenterX() - blocks[i]->getCenterX());
        int dy = abs(getCenterY() - blocks[i]->getCenterY());
        int overlapX = (size / 2) + ((blocks[i]->getWidth()) / 2) - dx;
        int overlapY = (size / 2) + ((blocks[i]->getHeight()) / 2) - dy;

        if (overlapX > 0 && overlapY > 0)
        {
            if (blocks[i]->getpreviousOverlapY() > 0 && blocks[i]->getpreviousOverlapX() <= 0 && getX() < blocks[i]->getRight())
            {
                x -= (overlapX);
                blocks[i]->draw();
            }
            // {x = blocks[i]->getX() - 1 - size;}

            if (blocks[i]->getpreviousOverlapY() > 0 && blocks[i]->getpreviousOverlapX() <= 0 && getRight() > blocks[i]->getX())
            // {x -= (overlapX); }
            {
                x = blocks[i]->getRight() + 1;
            }

            if (blocks[i]->getpreviousOverlapX() > 0 && blocks[i]->getpreviousOverlapY() <= 0 && getY() < blocks[i]->getBottom())
            {
                y -= (overlapY);
                blocks[i]->draw();
            }
            // {y = blocks[i]->getY() - 1 - size;}

            if (blocks[i]->getpreviousOverlapX() > 0 && blocks[i]->getpreviousOverlapY() <= 0 && getBottom() > blocks[i]->getY())
            // {x -= (overlapY); }
            {
                y = blocks[i]->getBottom() + 1;
            }
        }

        if (!(overlapX > 0 && overlapY > 0))
        {
            blocks[i]->setpreviousOverlapX(overlapX);
            blocks[i]->setpreviousOverlapY(overlapY);
        }
    }
}

void Mario::endpointCollision()
{

    int dx = abs(getCenterX() - endpoint->getCenterX());
    int dy = abs(getCenterY() - endpoint->getCenterY());
    int overlapX = (size / 2) + ((endpoint->getWidth()) / 2) - dx;
    int overlapY = (size / 2) + ((endpoint->getHeight()) / 2) - dy;

    if (overlapX > 0 && overlapY > 0)
    {
        size = 0;
        x = screenWidth + 1;
        y = screenHeight + 1;
        readimagefile("./images/victory.jpg", 0.2 * screenWidth, 0.2 * screenHeight, 0.8 * screenWidth, 0.8 * screenHeight);
    }
}

void Mario::coinCollision()
{
    for (int i = 0; i < COINMAX; i++)
    {
        int dx = abs(getCenterX() - coins[i]->getX());
        int dy = abs(getCenterY() - coins[i]->getY());
        int overlapX = (size / 2) + ((coins[i]->getRadius())) - dx;
        int overlapY = (size / 2) + ((coins[i]->getRadius())) - dy;

        if (overlapX > 0 && overlapY > 0)
            coins[i]->undraw();
    }
}

void Mario::enemyCollision()
{

    for (int i = 0; i < ENEMYMAX; i++)
    {
        int dx = abs(getCenterX() - enemys[i]->getCenterX());
        int dy = abs(getCenterY() - enemys[i]->getCenterY());
        int overlapX = (size / 2) + ((enemys[i]->getWidth()) / 2) - dx;
        int overlapY = (size / 2) + ((enemys[i]->getHeight()) / 2) - dy;

        if (overlapX > 0 && overlapY > 0)
        {
            size = 0;
            x = screenWidth + 1;
            y = screenHeight + 1;
            lifebar->damage(400);
            lifebar->undraw();
            lifebar->draw();
            readimagefile("./images/gameover.jpg", 0.2 * screenWidth, 0.2 * screenHeight, 0.8 * screenWidth, 0.8 * screenHeight);
        }
    }
}
