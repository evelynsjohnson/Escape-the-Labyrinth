There are two portions to this project:
1. Generating and creating the grid (grid.h)
   - Defines a template class called Grid. The purpose of this class is to represent a 2D grid or matrix with elements of type T. The class provides functionality for creating, manipulating, and managing a grid of arbitrary size.
   - Implements smaller helper functions to return the number of columns, total elements, etc.


2. Handles the move commands and win conditions (EscapeTheLabyrinth.h)
   - Determines if a given sequence of moves leads from a starting MazeCell to freedom in a maze.
   - Handles user movement, takes the MazeCell (start) and a string (moves) representing a sequence of moves (N, S, E, W for North, South, East, and West) to navigate through the maze.
   - Iterates through each move, updating the current cell based on the movement direction. Checks if the current cell contains any items (Spellbook, Wand, Potion) and sets flags accordingly.

  
Non-technical portion - Mapping it out
   
   Navigating the maze is diffult for the user, because the maze is not actually displayed on screen. All the user sees are the memory addresses of the pointers (north->south, address = XXXXXX87a0, or east->west, address = XXXXXX88e0). As such, the user has to carefully map out where they think the paths are.
   - For the regular labyrinth, this is simple. If you exit a room through the north, you enter the next room through the south.
   - For the twisty labyrinth, the direction you exit is not necessarily the correlated one you enter through.

Hence, a large portion of completing the "game" created is learning how to carefully map out the maze with exact pathways from specific entrances to specific exits, and plan out your route to get to the items and back as soon as possible.
