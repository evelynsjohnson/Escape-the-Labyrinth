#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;


const string kYourNetID = "ejohn50";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "SESSWENNNESSENN"; // TODO: Replace this string with your path out of the normal maze.
const string kPathOutOfTwistyMaze = "SSSWEWN"; // TODO: Replace this string with your path out of the twisty maze.

bool isPathToFreedom(MazeCell* start, const string& moves) {
    MazeCell* currentCell = start;

    // Flags to track if each item is picked up
    bool pickedSpellbook = false;
    bool pickedWand = false;
    bool pickedPotion = false;

    if (currentCell->whatsHere == "Spellbook") {
        pickedSpellbook = true;
    }
    else if (currentCell->whatsHere == "Wand") {
        pickedWand = true;
    }
    else if (currentCell->whatsHere == "Potion") {
        pickedPotion = true;
    }

    for (char move : moves) {
        // Check for invalid moves
        if (move != 'N' && move != 'S' && move != 'E' && move != 'W') {
            return false;
        }

        // Move to the next cell based on the current move
        if (move == 'N' && currentCell->north != nullptr) {
            currentCell = currentCell->north;
        }
        else if (move == 'S' && currentCell->south != nullptr) {
            currentCell = currentCell->south;
        }
        else if (move == 'E' && currentCell->east != nullptr) {
            currentCell = currentCell->east;
        }
        else if (move == 'W' && currentCell->west != nullptr) {
            currentCell = currentCell->west;
        }
        else {
            // Invalid move
            return false;
        }

        // Check if the move picks up any items
        if (currentCell->whatsHere == "Spellbook") {
            pickedSpellbook = true;
        }
        else if (currentCell->whatsHere == "Wand") {
            pickedWand = true;
        }
        else if (currentCell->whatsHere == "Potion") {
            pickedPotion = true;
        }
    }

    // Check if all items are picked up
    return pickedSpellbook && pickedWand && pickedPotion;
}