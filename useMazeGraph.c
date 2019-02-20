#include <stdio.h>
#include "MazeGraph.h"

int main() {
	// make a maze
	Maze maze = createMaze(5, 0, 0);
	// possible paths: down and left at [0, 0]
	printf("Current location: [%d, %d]\n", maze->currentTileX, maze->currentTileY);
	add(maze, DOWN);
	add(maze, RIGHT);
	Tile curr = getCurrentTile(maze);
	if (curr != NULL) {
		// should print that down and right are available
		printf("Current status (u,d,l,r): %d, %d, %d, %d\n", curr->up, curr->down, curr->left, curr->right);
	}
	// move to [1, 0]
	move(maze, RIGHT);
	printf("Current location: [%d, %d]\n", maze->currentTileX, maze->currentTileY);
	// possible paths: left and right at [1, 0]
	add(maze, LEFT);
	add(maze, RIGHT);
	curr = getCurrentTile(maze);
	if (curr != NULL) {
		// should print that left and right are available
		printf("Current status (u,d,l,r): %d, %d, %d, %d\n", curr->up, curr->down, curr->left, curr->right);
	}
	// print the maze
	printMaze(maze);

	return 0;
}