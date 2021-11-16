#include <stdio.h>

#define ROW 3
#define COL 3

void show_puzzle(int puzzle[][COL], int n);

int main()
{
	int puzzle[ROW][COL] = { 
		{1, 0, 3}, 
		{4, 2, 6}, 
		{7, 5, 8} 
	};
	
	show_puzzle(puzzle, ROW);
	
	return 0;
}

void show_puzzle(int puzzle[][COL], int n)
{
	int row, col;
	for(row = 0;row < n;row++){
		for(col = 0;col < COL;col++){
			printf("+-----");
		}
		printf("+\n");
		for(col = 0;col < COL;col++){
			if(puzzle[row][col] == 0){
				printf("|%5c", ' ');
			}else{
				printf("|%4d ", puzzle[row][col]);
			}
		}
		printf("|\n");
	}
	for(col = 0;col < COL;col++){
		printf("+-----");
	}
	printf("+\n\n");
}
