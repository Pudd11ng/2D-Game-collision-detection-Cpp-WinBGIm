# SimpleMarioGame-Cpp-Collision
//Install WinBGIm and add into your path
//compile
g++ -g -I./include main.cpp src/*.cpp -o NinjaMario -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

The Separating Axis Theorem (SAT) is employed in this code snippet to examine collisions along both the X and Y axes.

Here's a breakdown of the algorithm:

1. Calculate Distances:
Compute the absolute differences in the X and Y coordinates between the centers of the two objects, resulting in dx and dy.

2. Determine Overlaps:
Find the overlap along the X and Y axes by utilizing half of the width and height of each object, leading to overlapX and overlapY.

3. Collision Check:
Verify if there is an overlap along both axes (overlapX > 0 and overlapY > 0). If this condition holds true, a collision is identified.

4. Collision Resolution:
Within the collision block, analyze previous overlap values and the relative positions of the objects to ascertain the collision direction. Adjust the position of the current object (this) accordingly to handle collisions from various directions.

5. Update Overlap Values:
Update the previous overlap values for the other object (blocks[i]) if no collision is detected.

//Code to detect the collision and and act accordingly depending on which way they collide

void Mario::blockCollision()
{   

    for (int i = 0; i < BLOCKMAX; i++)
    {
        int dx = abs(getCenterX() - blocks[i]->getCenterX());
        int dy = abs(getCenterY() - blocks[i]->getCenterY());
        int overlapX = (size/2) + ((blocks[i]->getWidth())/2) - dx;
        int overlapY = (size/2) + ((blocks[i]->getHeight())/2) - dy;

        if (overlapX > 0 && overlapY > 0)
        {
            if (blocks[i]->getpreviousOverlapY() > 0 && blocks[i]->getpreviousOverlapX() <= 0 && getX() < blocks[i]->getRight()) 
            {x -= (overlapX); blocks[i]->draw();}
            // {x = blocks[i]->getX() - 1 - size;}

            if (blocks[i]->getpreviousOverlapY() > 0 && blocks[i]->getpreviousOverlapX() <= 0 && getRight() > blocks[i]->getX()) 
            // {x -= (overlapX); } 
            {x = blocks[i]->getRight() + 1;}

            if (blocks[i]->getpreviousOverlapX() > 0 && blocks[i]->getpreviousOverlapY() <= 0 && getY() < blocks[i]->getBottom())  
            {y -= (overlapY); blocks[i]->draw();}
            // {y = blocks[i]->getY() - 1 - size;}

            if (blocks[i]->getpreviousOverlapX() > 0 && blocks[i]->getpreviousOverlapY() <= 0 && getBottom() > blocks[i]->getY())  
            // {x -= (overlapY); } 
            {y = blocks[i]->getBottom() + 1;}

        }   

        if (!(overlapX > 0 && overlapY > 0))
        {
            blocks[i]->setpreviousOverlapX(overlapX);
            blocks[i]->setpreviousOverlapY(overlapY); 
        }

    }

}
