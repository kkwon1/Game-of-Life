#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <chrono>
#include <thread>
#include <string>
#include <unistd.h>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;

const int R = 40;
const int C = 200;
int Sum;

void InitArray(int[R][C],int[R][C], int, int);
void PrintGrid(int[R][C], int, int);
void GetNewState(int[R][C], int[R][C]);
int CheckCell(int, int);

int main(){
	int grid[R][C];
	int buffer[R][C];
	
	InitArray(grid, buffer, R, C);
	
	int playing = 1;
	
	
	
	while(playing){
		PrintGrid(grid, R, C);
		GetNewState(buffer, grid);
		if(!Sum){
			playing = 0;
		}
	}
	
	PrintGrid(grid, R, C);
	cout << "All your cells have died" << endl;
	
	
}

void InitArray(int grid[R][C], int buffer[R][C], int rows, int cols){
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
	
	string output = "";
	string live = "#";
	string dead = ".";
	

	usleep(30000);

	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			if(grid[i][j])
				cout << live;
				//output = output + live;
			else
				cout << dead;
				//output = output + dead;
			if(j == cols-1){
				cout << endl;
				//output = output + "\n";
			}
		}
	}

	return;
}

void GetNewState(int tempMatrix[R][C], int grid[R][C]){
	// Calculate the values in cell one row above
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			tempMatrix[i][j] = 0;
			tempMatrix[i][j] += grid[(i + R - 1) % R][(j + C - 1)%C];
			tempMatrix[i][j] += grid[(i + R - 1) % R][j];
			tempMatrix[i][j] += grid[(i + R - 1) % R][(j + C + 1)%C];
		}
		
	}
	
	// Calculate for left/right
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			tempMatrix[i][j] += grid[i][(j + C - 1)%C];
			tempMatrix[i][j] += grid[i][(j + C + 1)%C];
		}
		
	}
	
	//Caclulate for bottom row
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			tempMatrix[i][j] += grid[(i + R + 1) % R][(j + C - 1)%C];
			tempMatrix[i][j] += grid[(i + R + 1) % R][j];
			tempMatrix[i][j] += grid[(i + R + 1) % R][(j + C + 1)%C];
		}
		
	}
	
	Sum = 0;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			int val = CheckCell(tempMatrix[i][j], grid[i][j]);
			Sum += val;
			grid[i][j] = val;
		}
	}
	
	return;
	
}


int CheckCell(int newCell, int oldCell){
	if(!oldCell && newCell == 3){
		return 1;
	}
	
	if(!oldCell)
		return 0;
	
	
	
	if(newCell >= 4) return 0;
	
	if(newCell < 2) return 0;
	
	return 1;
}







