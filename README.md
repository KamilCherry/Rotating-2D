## 2D matrix vector rotation

### Description

This application was made as a learning experience.
It is entirely written in C++. For creating a window and managing events SDL2 was used.
It normalizes avaliable display space s.t. top edge of the window has value of -1 in y axis, bottom edge has value of 1 in y axis, left edge has value of -1 in x axis and right edge has value of 1 in x axis.
Than It multiplies every vector / point by a rotation matrix, which results in rotating given polygon.
By the default, the displayed object is a square, but it can be easily change, by modifying polygons's mesh (which consists of triangles) and it rotates by pi/128 each frame.

Feel free to use it!
