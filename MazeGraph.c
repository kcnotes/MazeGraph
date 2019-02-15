// MazeGraph.c, an implementation for a Rescue Maze Graph

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "MazeGraph.h"

typedef struct Graph {
    Tile** tiles; // matrix of 2D tiles
    Tile currentTile;
    int currentTileX;
    int currentTileY;
} Graph;

/**
 * Creates a maze and allocates memory for it
 * @param  size the maximum square size of the maze
 * @param  x    x-axis start location of maze
 * @param  y    y-axis start location of maze
 * @return      the maze
 */
Maze createMaze(int size, int x, int y) {
	Graph maze = malloc(sizeof(Graph));
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
	
}

Tile move(Maze maze, int direction) {
	
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
