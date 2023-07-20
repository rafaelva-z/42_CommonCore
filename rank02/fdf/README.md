# Fdf

Representation of a 3D object/landscape composed of points that are connected through lines.\
This program recieves as input a map, that will be displayed in a 3D enviroment where you can move and rotate it.\
## The map
\
The map is a ".fdf" file that looks like this:\
\
image\
\
Each number represents a 3D point, where the horizontal position corresponds to the X value, the vertical position represents the Y value and the number itself represents the Z value. You can see the program running with tihs map on the image below:\

## Process
\
To achieve this i started by downloading [Minilibx](https://harm-smits.github.io/42docs/libs/minilibx) the graphics library that i had to use in this project, and integrating it in my Makefile so i can easly compile the program. Then i started by setting up the window managment, defining the window size, making a way to close the window, creating functions that will draw an image and then place it on the window, and replace the image on the next iteration.\
\
I then proceeded to create the map parser [map_reader.c](./src/map/map_reader.c) that uses the functions inside the ./src/map folder the concept here is to read the file line by line using the [get_next_line](../../rank01/get_next_line/) function, always checking for invalid map configurations or invalid characters. For every number in the map, i create a struct s_node that contains the coordinates of the point, and some other variables. When the map parser finishes, the linked list looks like this:\
\
image\
\
The next step is to draw the image, but first, we need to know how to draw it.\
We have a map filled with 3D points but we are drawing on a 2D image, and we need to be able to change the prespective on the model.\
For that, the program uses a formula that will be applied to all points in the map, rotating the model in the desired axis, and then another formula to convert all the points to 2D coordinates that can be drawn in the image. (./src/draw/draw_calc.c)\
Rotation formula:\
\
&nbsp;&nbsp;&nbsp;&nbsp;(angle)			how much to rotate\
&nbsp;&nbsp;&nbsp;&nbsp;(x)(y)(z)		position before rotation\
&nbsp;&nbsp;&nbsp;&nbsp;rot_(x)(y)(z)	position after rotation\
	\
&nbsp;&nbsp;&nbsp;&nbsp;X axis rotation formula\
&nbsp;&nbsp;&nbsp;&nbsp;rot_y = y * cos(angle) + z * sin(angle)\
&nbsp;&nbsp;&nbsp;&nbsp;rot_z = -y * sin(angle) + z * cos(angle)\
\
&nbsp;&nbsp;&nbsp;&nbsp;Y axis rotation formula\
&nbsp;&nbsp;&nbsp;&nbsp;rot_x = x * cos(angle) + rot_z * sin(angle)\
&nbsp;&nbsp;&nbsp;&nbsp;rot_z = -x * sin(angle) + rot_z * cos(angle)\
\
&nbsp;&nbsp;&nbsp;&nbsp;Z axis rotation formula\
&nbsp;&nbsp;&nbsp;&nbsp;rot_x = rot_x * cos(angle) + rot_y * sin(angle)\
&nbsp;&nbsp;&nbsp;&nbsp;rot_y = -rot_x * sin(angle) + rot_y * cos(angle)\
\
3D to 2D formula:\
&nbsp;&nbsp;&nbsp;&nbsp;x_2D = rot_x - rot_y\
&nbsp;&nbsp;&nbsp;&nbsp;y_2D = rot_z + rot_x + rot_y\
\
I also added scale and translation (offset), to the model on the 3D to 2D formula.\
To allow the model to be moved, rotated and scaled, i use variables throughout these formulas, so that the values can be changed with keypresses that you can find on [hooks.c](./src/hooks.c), [move_map.c](./src/move_map.c) and [move_map2.c](./src/move_map2.c).