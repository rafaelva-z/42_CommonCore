# Fdf

Representation of a 3D object/landscape composed of points that are connected through lines. \
This program recieves as input a map, that will be displayed in a 3D enviroment where you can move and rotate it.

<img src="https://github.com/rafaelva-z/42_CommonCore/assets/26445891/27f11421-6cc8-47de-aea4-a156fe29044a" width="90%">

## The map


The map is a ".fdf" text file where each number written represents a 3D point. \
\
*The horizontal position (col) corresponds to the X value, \
*the vertical position (line) represents the Y value, \
*the number itself represents the Z value. \
\
The program ignores all the spaces between numbers, but they are necessary to separate the points. \
\
Here's a small fdf map example ([maps/01_spike.fdf](maps/01_spike.fdf)): \
<img src="https://github.com/rafaelva-z/42_CommonCore/assets/26445891/65ee2bae-2292-4f61-887d-fddf822a014d" width="60%">\
\
The output of this map would be this shape: \
<img src="https://github.com/rafaelva-z/42_CommonCore/assets/26445891/bccbfc57-310b-4628-8744-b2bd2887589c" width="30%">

## Developing Process
\
**1.**
I started this project by integrating [Minilibx](https://harm-smits.github.io/42docs/libs/minilibx) to my Makefile, the graphics library that was requested to be used in this project. I proceeded to read the documentation i found online, learned the functions necessary to program the window management, as well as how to draw pixels and images on the screen. \
\
**2.**
Then I proceeded to create the map parser [map_reader.c](./src/map/map_reader.c) that uses all the functions inside the [./src/map](./src/map) folder. \
The concept here is to read the file line by line using the [get_next_line](../../rank01/get_next_line/) function, always checking for invalid map configurations or invalid characters. For every number in the map, i create a struct s_node that contains the coordinates of the point, and some other variables. When the map parser finishes, the linked list looks like this: \
\
image\
\
\
**3.**
The next step is to draw the image, but first, we need to know how to draw it. \
\
The smallest piece of this step is to draw a pixel on the screen, and for that, the [Minilibx](https://harm-smits.github.io/42docs/libs/minilibx) documentation has a simple tutorial. And we can quickly go to the next part that is drawing a line. The [Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm) is an algorithm to draw lines from a point_a to a point_b on a 2D plane. \
Having this out of the way, now we have a map filled with 3D points, all connected horizontaly and vertically thank to the linked lists, so it should be as easy as conecting the dots right? \
Well, the problem here is that we are drawing on a 2D window on the screen, and that means that a 3D point has one extra dimention that we can't simply remove.\
\
using the coordinates from a 3D point on the following formula will give you a 2D point. (x, y)
3D to 2D formula: \
&nbsp;&nbsp;&nbsp;&nbsp;x_2D = x - y \
&nbsp;&nbsp;&nbsp;&nbsp;y_2D = z + x + y \
\
This is it for drawing our map on the screen, without much control on the rotation of the object.
The bonus part of this project rquires the program to rotate, translate and scale. \
For that, the program uses a formula that will be applied to all points in the map, rotating the model in the desired axis, and then applying the *3D to 2D formula above to create a 2D point that can be draw. [draw_calc.c](./src/draw/draw_calc.c)\
\
Rotation formula:\
\
&nbsp;&nbsp;&nbsp;&nbsp;(angle)			how much to rotate\
&nbsp;&nbsp;&nbsp;&nbsp;(x)(y)(z)		position before rotation\
&nbsp;&nbsp;&nbsp;&nbsp;rot_(x)(y)(z)	position after rotation\
\
&nbsp;&nbsp;&nbsp;&nbsp;X axis rotation formula\
&nbsp;&nbsp;&nbsp;&nbsp;rot_y = y * cos(angle) + z * sin(angle) \
&nbsp;&nbsp;&nbsp;&nbsp;rot_z = -y * sin(angle) + z * cos(angle) \
\
&nbsp;&nbsp;&nbsp;&nbsp;Y axis rotation formula\
&nbsp;&nbsp;&nbsp;&nbsp;rot_x = x * cos(angle) + rot_z * sin(angle) \
&nbsp;&nbsp;&nbsp;&nbsp;rot_z = -x * sin(angle) + rot_z * cos(angle) \
\
&nbsp;&nbsp;&nbsp;&nbsp;Z axis rotation formula\
&nbsp;&nbsp;&nbsp;&nbsp;rot_x = rot_x * cos(angle) + rot_y * sin(angle) \
&nbsp;&nbsp;&nbsp;&nbsp;rot_y = -rot_x * sin(angle) + rot_y * cos(angle) \
\
**All of these formulas need to be applied in this order**, otherwise we will get different results. 
X rotation > Y rotation > Z rotation > 3D to 2D conversion > scale and translation
\
I also added scale and translation (offset), to the model on the 3D to 2D formula by after 3D to 2D conversion, multiplying the reult of X and Y by the scale, and the adding the offset value. \
To allow the model to be moved, rotated and scaled using the keyboard, i use variables throughout these formulas, and change the values as the key is pressed. [hooks.c](./src/hooks.c), [move_map.c](./src/move_map.c) and [move_map2.c](./src/move_map2.c).
