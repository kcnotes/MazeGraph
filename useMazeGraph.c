#include <stdio.h>
#include "MazeGraph.h"

int main() {
	// make a maze
	Maze maze = createMaze(5, 0, 0);
	// possible paths: down and left at [0, 0]
	add(maze, DOWN);
	add(maze, RIGHT);
	// move to [1, 0]
	move(maze, RIGHT);
	// possible paths: left and right at [1, 0]
	add(maze, LEFT);
	add(maze, RIGHT);
	// print the maze
	printMaze(maze);
}