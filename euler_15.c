//Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
//How many such routes are there through a 20×20 grid?

//Grid paths: 137846528820
//Should have started at GRIDSIZE-1, would remove the two if's in the inner loop

#include <stdio.h>
#include <stdlib.h>

#define GRIDSIZE 20

int main(void){
	long int grid[GRIDSIZE+1][GRIDSIZE+1], currow, curcol;
	
	memset(grid, 0, sizeof(grid));
	grid[GRIDSIZE][GRIDSIZE] = 1;
	
	for(currow = GRIDSIZE; currow >= 0; currow--){
			for(curcol = GRIDSIZE; curcol >= 0; curcol--){
				if(curcol < GRIDSIZE)
					grid[currow][curcol] += grid[currow][curcol+1];
				if(currow < GRIDSIZE)
					grid[currow][curcol] += grid[currow+1][curcol];
			}
	}
	
	printf("Grid paths: %ld\n", grid[0][0]);

	return 1;
}
	
