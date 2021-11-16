#include <stdio.h>

#define ROW 3
#define COL 3

void show_puzzle(int puzzle[][COL], int n);
void show_moveable(int puzzle[][COL], int n);

int main()
{
	int puzzle[ROW][COL] = { 
		{1, 0, 3}, 
		{4, 2, 6}, 
		{7, 5, 8} 
	};
	int step = 1;
	show_puzzle(puzzle, ROW);
	printf("第%d步[ ", step);
	show_moveable(puzzle, ROW);
	printf("]：");
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

void show_moveable(int puzzle[][COL], int n) 
{
	int row, col;
	for(row = 0;row < n;row++){
		for(col = 0;col < COL;col++){
			if(puzzle[row][col] == 0){	// 找到空白位置所对应的行列下标 
				if(row-1 >= 0){		// 空白位置的上方 
					printf("%d ", puzzle[row-1][col]);
				} 
				if(row+1 < n){		// 空白位置的下方 
					printf("%d ", puzzle[row+1][col]);
				} 
				if(col-1 >= 0){		// 空白位置的左边
					printf("%d ", puzzle[row][col-1]);
				} 
				if(col+1 < COL){	// 空白位置的右边 
					printf("%d ", puzzle[row][col+1]);
				} 
				return;
			}
		}
	}
}
