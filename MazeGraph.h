// MazeGraph.h, an interface for a Rescue Maze Graph

// include guard - prevents #including more than once
#ifndef MAZEGRAPH_H
#define MAZEGRAPH_H

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Graph {
    Tile** tiles; // matrix of 2D tiles
    Tile currentTile;
    int currentTileX;
    int currentTileY;
} Graph;
typedef Graph *Maze; // a maze is a graph

typedef struct Node {
	short up; // true or false - i.e. a wall or not a wall
	short left;
	short down;
	short right;
	int flags[4]; // Flags
	// TODO: define the flags (e.g. 'flag[0] = has a victim')
} Node;
typedef Node *Tile;

// Create a maze and a starting tile
Maze createMaze(int size, int x, int y); 
// Probably create a matrix of pointers to structs, because it would otherwise be hard to track new joins = prevent loops
// Print current maze
void printMaze();

// Get current tile
Tile getCurrentTile(Maze maze);
// Update status of current tile (flag ID from 0 to 3)
Tile updateCurrentTile(Maze maze, int flagid, int status);
// Add a possible path from the current position
Tile addPath(Maze maze, int direction);
// Move current position to an adjacent tile
Tile move(Maze maze, int direction);

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
	Maze maze = malloc(sizeof(Graph));
	assert(maze != NULL);
	maze->tiles = calloc(size * size, sizeof(Tile*));
	assert(maze->tiles != NULL);
	// No need to actually make space for tiles - will do when
	// we find them, to save space
	maze->tiles[x][y] = createTile();
	maze->currentTile = maze->tiles[x][y];
	maze->currentTileX = x;
	maze->currentTileY = y;
	return maze;
}

void printMaze() {
	// Fill in this function
}

Tile getCurrentTile(Maze maze) {
	return maze->currentTile;
}

Tile updateCurrentTile(Maze maze, int flagid, int status) {
	Tile t = maze->currentTile;
	if (t != NULL) {
		t->flags[flagid] = status;
	}
	return t;
}

Tile addPath(Maze maze, int direction) {
	// Fill in this function
	return NULL;
}

Tile move(Maze maze, int direction) {
	// Fill in this function
	return NULL;
}

// Helper functions
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
