# SO_LONG

                
SUMMARY:

This project is a very small 2D Game. It is built to make you work with textures, sprites. And some very basic gameplay elements.

STATUS:

Result : 
S0_LONG - 100%✅

#MAP :

A valid map is structured as followed:

- 1 player (P)
- 1 exit (E)
- at least 1 collectible (C)`
- is recatangular
- has a solid outside border out of walls (1)
- all the empty spaces are filled with 0
- map has to be .ber
- no other characters than:
    - P
    - E
    - C
    - 1
    - 0
- i.e. map1.ber:
- one new line after the map is valid, if there is anything else, it is not valid

1111111111111
10010000000C1
1000011111001
1P0011E000011
1111111111111


**During the game**

he player can only be moved by WASD.
The player can not move into walls.
The player can only exit if all collectibles are collected.
The amount of movements is counted and displayed in the terminal.
Every try to move even if it is invalid will be counted as one move.

All the visualization is done with the help of the  [MiniLibx library](https://github.com/benanredzhebov/so_long/tree/master/mlx).

**How to run the game** 

All of the commands should be run in the root of the directory.

- compile with ´make all´
- run the game with ´./so_long maps/<mapname>´
