// MazeGraph.h, an interface for a Rescue Maze Graph

// include guard - prevents #including more than once
#ifndef MAZEGRAPH_H
#define MAZEGRAPH_H

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

#include <stdio.h>

// graph representation is hidden
typedef struct Graph *Maze; // a maze is a graph
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

#endif
