//Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
//How many such routes are there through a 20×20 grid?

//Grid paths: 137846528820

#include <stdio.h>
#include <stdlib.h>

#define GRIDSIZE 20

int main(void){
	long int grid[GRIDSIZE+1][GRIDSIZE+1], currow, curcol;
	
	memset(grid, 0, sizeof(grid));
	for(currow = 0; currow <= GRIDSIZE; currow++){
		grid[currow][0] = 1;
		grid[0][currow] = 1;
	}
	
	for(currow = 1; currow <= GRIDSIZE; currow++){
		for(curcol = 1; curcol <= GRIDSIZE; curcol++)
			grid[currow][curcol] = grid[currow-1][curcol] + grid[currow][curcol-1];
	}
	
	printf("Grid paths: %ld\n", grid[GRIDSIZE][GRIDSIZE]);

	return 1;
}
	
