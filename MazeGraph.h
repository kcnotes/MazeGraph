// MazeGraph.h, an interface for a Rescue Maze Graph

// include guard - prevents #including more than once
#ifndef MAZEGRAPH_H
#define MAZEGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

/**
 * Graph contains
 *  - tiles, a 2D array of pointers to Nodes (2D array of Tiles)
 *  - currentTile, a way to keep track of the current position
 *  - currentTileX, the current x-axis grid number
 *  - currentTileY, the current y-axis grid number
 */
typedef struct Graph {
    Tile** tiles;
    Tile currentTile;
    int currentTileX;
    int currentTileY;
} Graph;
typedef Graph *Maze; // 'Maze' is a pointer to a Graph

/**
 * Node contains
 *  - up, 1 if up from the tile is not a wall, 0 otherwise
 *  - left, 1 if left from the tile is not a wall, 0 otherwise
 *  - down, 1 if down is not a wall, 0 otherwise
 *  - right, 1 if right is not a wall, 0 otherwise
 *  - flags, an array to keep track of characteristics of the tile.
 *    Alternatively, create more variables in the struct to store information about
 *    victims, checkpoints, holes. 
 */
typedef struct Node {
	short up; // true or false - i.e. a wall or not a wall
	short left;
	short down;
	short right;
	int flags[4];
} Node;
typedef Node *Tile;

// Create a maze with starting position x, y
Maze createMaze(int size, int x, int y); 
// Print current maze
void printMaze(Maze maze);

// Get current tile
Tile getCurrentTile(Maze maze);
// Add a possible direction from the current position
Tile add(Maze maze, int direction);
// Move current position to an adjacent tile
Tile move(Maze maze, int direction);
// Update status of current tile (flag ID from 0 to 3)
// Tile updateCurrentTile(Maze maze, int flagid, int status);

/* Helper functions */
Tile createTile();

/**
 * Creates a maze and allocates memory for it
 * @param  size the maximum square size of the maze
 * @param  x    x-axis start location of maze
 * @param  y    y-axis start location of maze
 * @return      the maze
 */
Maze createMaze(int size, int x, int y) {
	// Create space for a Graph
	Maze maze = malloc(sizeof(Graph));
	assert(maze != NULL);
	// Create space for the Tiles (pointers) in the Graph
	// No need to actually make space for Nodes - will do when
	// we find them, as there is limited memory.
	maze->tiles = calloc(size * size, sizeof(Tile*));
	assert(maze->tiles != NULL);
	// Create starting tile
	maze->tiles[x][y] = createTile();
	maze->currentTile = maze->tiles[x][y];
	maze->currentTileX = x;
	maze->currentTileY = y;
	return maze;
}

/**
 * Prints the current state of the maze.
 */
void printMaze(Maze maze) {
	// Fill in this function
	// To do so, you will need to loop through the 2D array,
	// check if a Tile exists (doesn't point to NULL), and 
	// print out X or space.
	// If it is a current tile, print O.
}

/**
 * Gets the current tile of the maze.
 * @param  maze the maze
 * @return      a pointer to the current tile
 */
Tile getCurrentTile(Maze maze) {
	return maze->currentTile;
}

/**
 * Updates the status of a flag on the current tile
 * @param  maze   the maze
 * @param  flagid the flag ID of the status you want to change
 * @param  status the value you want to change it to
 * @return        a pointer to the current tile
 */
Tile updateCurrentTile(Maze maze, int flagid, int status) {
	Tile t = maze->currentTile;
	if (t != NULL) {
		t->flags[flagid] = status;
	}
	return t;
}

/**
 * Adds a potential direction to explore from the current tile
 * @param  maze      the maze
 * @param  direction the possible direction from the current tile
 * @return           the current tile
 */
Tile add(Maze maze, int direction) {
	// Fill in this function
	// To fill in this function, you need to update the 
	// currentTile's up, down, left or right depending on what
	// direction was supplied.
	return NULL; // remove this line if not needed
}

/**
 * Move the current tile to a new destination in the direction provided.
 * @param  maze      the maze
 * @param  direction the direction you want to move the tile towards
 * @return           the current tile, NULL if cannot be moved
 */
Tile move(Maze maze, int direction) {
	// Fill in this function
	// To fill in this function, you will need to update
	// the currentTile. 
	// 1. Check if the direction is possible (not a wall)
	//    - if not possible, return NULL
	// 2. Change the currentTile pointer to point to the Tile 
	// above, left, right or down from the current tile.
	// This will require you to look at currentTileX and Y, and you 
	// need to add or subtract those numbers.
	// You will then look at the 2D array to get the new tile,
	// and create one if necessary.
	return NULL; // remove this line if not needed
}

/**
 * Creates a tile
 * @return a pointer to the new tile
 */
Tile createTile() {
	Tile t = malloc(sizeof(Node));
	assert(t != NULL);
	t->up = 0;
	t->left = 0;
	t->down = 0;
	t->right = 0;
	int i;
	for (i = 0; i < 4; i++) {
		t->flags[i] = 0;
	}
	return t;
}

#endif
