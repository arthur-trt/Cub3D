# Cub3D

Cub3D is a project of the school 42 where you have to code a small game engine using the raycasting technique like Wolfenstein 3D did.

## Usage

To compile the game just do :
```bash
make
```

You can then launch it by doing :
```bash
./bin/cub3d [--save] map.cub
```

Keyboard key :
- **W** : Move up
- **S** : Move down
- **A** : Rotate left
- **D** : Rotate right
- **Shift** : Run

## Create Map

The `.cub` files consist of several pieces of information, here is an example of a very simple map :

```
R	640	480
NO ./textures/mossy.xpm
SO ./textures/redbrick.xpm
EA ./textures/stone.xpm
WE ./textures/wood.xpm
S ./textures/barrel.xpm

F 255,0,255
C 0,128,128


1111111111111111111111111111111111111111111
1000000000000000000000000000000002000002001
10000000000000000000000000000000000020000W1
1000111111111111111111111111111111111111111
1000100000000001000000000111111111110000111
1000100000000001000000000111111111110000111
1000100000000001000000000000001111110000111
1000100000000001000000000000000001110000111
1000100000000001000000000000000000000000111
1000100000000000000000000000000000000000111
1000111111111111111111111111111111110000111
1000111111111111111111111111111111110000111
1000000000000000000000000000000000000000111
1000000000000000000000000000000000000000111
1111111111111111111111111111111111111111111
```

Here are the details of the different instructions used:

| ID |          Accepted values                                 |    Description      |
|:--:|:--------------------------------------------------------:|:-------------------:|
| R  | Two numbers separated by a space                         |  Window resolution  |
| NO | Path to textures for north wall                          |                     |
| SO | Path to textures for south wall                          |                     |
| EA | Path to textures for east wall                           |                     |
| WE | Path to textures for west wall                           |                     |
| S  | Path to textures for sprite                              |                     |
| F  | Three numbers between 0 and 255 separated by a comma     | Color in RGB format |
| C  | Three numbers between 0 and 255 separated by a comma     | Color in RGB format |

And to build a map :

|     ID      | Description                                              |
|:-----------:|:--------------------------------------------------------:|
|    **0**    | Represent the ground                                     |
|    **1**    | Represent a wall                                         |
|    **2**    | Represent a sprite                                       |
| **N,S,E,W** | Represents the player's starting position and direction. |


There are a few rules for creating a map:
- It must be surrounded by a wall
- It can contain spaces, they will be treated as walls.
- It should contain only one starting position for the player.
