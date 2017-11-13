#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

const int R = 25;
const int C = 25;

void InitArray(int[R][C], int, int);
void PrintGrid(int[R][C], int, int);

int main(){
	int grid[R][C];
	
	InitArray(grid, R, C);
	PrintGrid(grid, R, C);
	
}

void InitArray(int grid[R][C], int rows, int cols){
	srand(time(NULL));
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			grid[i][j] = rand()%2;
		}
	}
	return;
}


void PrintGrid(int grid[R][C], int rows, int cols){
	int i, j;
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			if(grid[i][j])
				printf(" O ");
			else
				printf(" . ");
			if(j == cols-1)
				printf("\n");
		}
	}
	return;
}

int[][] getNewState(