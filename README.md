# SimpleMarioGame-Cpp-Collision

The Separating Axis Theorem (SAT) is employed in this code snippet to examine collisions along both the X and Y axes.

Here's a breakdown of the algorithm:

Calculate Distances:
Compute the absolute differences in the X and Y coordinates between the centers of the two objects, resulting in dx and dy.

Determine Overlaps:
Find the overlap along the X and Y axes by utilizing half of the width and height of each object, leading to overlapX and overlapY.

Collision Check:
Verify if there is an overlap along both axes (overlapX > 0 and overlapY > 0). If this condition holds true, a collision is identified.

Collision Resolution:
Within the collision block, analyze previous overlap values and the relative positions of the objects to ascertain the collision direction. Adjust the position of the current object (this) accordingly to handle collisions from various directions.

Update Overlap Values:
Update the previous overlap values for the other object (blocks[i]) if no collision is detected.
