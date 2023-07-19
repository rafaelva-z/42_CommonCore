# Fdf

Representation of a 3D object/landscape composed of points that are connected through lines.

This program recieves as input a map, that will be displayed in a 3D enviroment where you can move and rotate it.

## The map

The map is a ".fdf" file that looks like this:

-5 0 0 0 -5

0 1 1 1 0

0 1 5 1 0

0 1 1 1 0

-5 0 0 0 -5

Each number represents a 3D point, where the horizontal position corresponds to the X value, the vertical position represents the Y value and the number itself represents the Z value. You can see the program running with tihs map on the image below:

## 

To achieve this i started by downloading "Minilibx" the graphics library that i had to use in this project, and integrating it in my Makefile so i can easly compile the program. Then i started by setting up the window managment, defining the window size, making a way to close the window, creating functions that will draw an image and then place it on the window, and replace the image on the next iteration.

I then proceeded to create the map parser (./src/map/map_reader) that uses the functions inside the ./src/map folder the concept here is to read the file line by line using the [get_next_line function], always checking for invalid map configurations or invalid characters. For every number in the map, i create a struct s_node that contains the coordinates of the point, and some other variables. When the map parser finishes, the linked list looks like this:

image