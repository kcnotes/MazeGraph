// MazeGraph.h, an interface for a Rescue Maze Graph

// include guard - prevents #including more than once
#ifndef MAZEGRAPH_H
#define MAZEGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define UP 1
#define LEFT 2
#define DOWN -1
#define RIGHT -2

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
    int size;
} Graph;
typedef Graph *Maze; // 'Maze' is a pointer to a Graph

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
Tile updateCurrentTile(Maze maze, int flagid, int status);

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
	Maze maze = (Maze)malloc(sizeof(Graph));
	assert(maze != NULL);
	// Create space for the Tiles (pointers) in the Graph
	// No need to actually make space for Nodes - will do when
	// we find them, as there is limited memory.
	maze->tiles = (Tile**)calloc(size, sizeof(Tile*));
	int i;
	for (i = 0; i < size; i++) {
		maze->tiles[i] = (Tile*)calloc(size, sizeof(Tile));
	}
	assert(maze->tiles != NULL);
	// Create starting tile
	maze->tiles[x][y] = createTile();
	maze->currentTile = maze->tiles[x][y];
	maze->currentTileX = x;
	maze->currentTileY = y;
	maze->size = size;
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
	int x, y;
	for (x = 0; x < maze->size; x++) {
		for (y = 0; y < maze->size; y++) {
			Tile tile = maze->tiles[x][y];
			if (tile == NULL) {
				printf(" ");
			} else if (x == maze->currentTileX && y == maze->currentTileY) {
				printf("O");
			} else {
				printf("X");
			}
		}
		printf("\n");
	}
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
	Tile current = maze->currentTile;
	switch(direction){
		case UP:
			current->up = 1;
			break;
		case LEFT:
			current->left = 1;
			break;
		case DOWN:
			current->down = 1;
			break;
		case RIGHT:
			current->right = 1;
			break;
	}
	return current; // remove this line if not needed
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
	Tile current = maze->currentTile;
	switch(direction){
		case UP:
			if (!current->up || maze->currentTileX == 0) return NULL;
			maze->currentTileX--;
			break;
		case LEFT:
			if (!current->left || maze->currentTileY == 0) return NULL;
			maze->currentTileY--;
			break;
		case DOWN:
			if (!current->down || maze->currentTileX == maze->size - 1) return NULL;
			maze->currentTileX++;
			break;
		case RIGHT:
			if (!current->right || maze->currentTileY == maze->size - 1) return NULL;
			maze->currentTileY++;
			break;
	}
	// Create tile if it doesn't exist
	if (maze->tiles[maze->currentTileX][maze->currentTileY] == NULL) {
		maze->tiles[maze->currentTileX][maze->currentTileY] = createTile();
	}
	maze->currentTile = maze->tiles[maze->currentTileX][maze->currentTileY];
	// Update current tile
	add(maze, -direction);
	return maze->currentTile; // remove this line if not needed
}

/**
 * Creates a tile
 * @return a pointer to the new tile
 */
Tile createTile() {
	Tile t = (Tile)malloc(sizeof(Node));
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
