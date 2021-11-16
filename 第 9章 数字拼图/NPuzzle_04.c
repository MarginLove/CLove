#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

void show_puzzle(int puzzle[][COL], int n);
void show_moveable(int puzzle[][COL], int n);
int * get_moveable(int puzzle[][COL], int n);
int move(int puzzle[][COL], int n, int number);
void swap(int * x, int * y);

int main()
{
	int puzzle[ROW][COL] = { 
		{1, 0, 3}, 
		{4, 2, 6}, 
		{7, 5, 8} 
	};
	int step = 1;
	int number;
	
	while(1){
		show_puzzle(puzzle, ROW);
		printf("第%d步[ ", step);
		show_moveable(puzzle, ROW);
		printf("](输入0退出)：");
		scanf("%d", &number);
		if(number == 0){
			printf("程序结束！\n");
			break;
		}else if(move(puzzle, ROW, number)){
			step ++;
		}else{
			printf("非法输入！\n");
		}
		printf("\n");
	}
	
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
	int * moveable;
	int i;
	moveable = get_moveable(puzzle, n);
	for(i = 0;i < 4;i++){
		if(moveable[i] > 0){
			printf("%d ", moveable[i]);
		}
	}
	free(moveable);
}

int * get_moveable(int puzzle[][COL], int n) 
{
	int row, col;
	int i;
	int * moveable = (int *)malloc(sizeof(int) * 4);
	if(moveable == NULL){
		printf("内存分配失败！\n");
		exit(1);
	}
	for(i = 0;i < 4;i++){
		moveable[i] = -1;
	}
	i = 0;
	for(row = 0;row < n;row++){
		for(col = 0;col < COL;col++){
			if(puzzle[row][col] == 0){	// 找到空白位置所对应的行列下标
				if(row-1 >= 0){		// 空白位置的上方 
					moveable[i++] = puzzle[row-1][col];
				} 
				if(row+1 < n){		// 空白位置的下方
					moveable[i++] = puzzle[row+1][col];
				} 
				if(col-1 >= 0){		// 空白位置的左边
					moveable[i++] = puzzle[row][col-1];
				} 
				if(col+1 < COL){	// 空白位置的右边 
					moveable[i++] = puzzle[row][col+1];
				} 
				return moveable;
			}
		}
	}
	return moveable;
}

int move(int puzzle[][COL], int n, int number) 
{
	int row, col;
	for(row = 0;row < n;row++){
		for(col = 0;col < COL;col++){
			if(puzzle[row][col] == number){ 	// 找到需要移动的数字
				if((row-1 >= 0)&&(puzzle[row-1][col] == 0) ){
					swap(&puzzle[row][col], &puzzle[row-1][col]);
				}else if((row+1 < n)&&(puzzle[row+1][col] == 0) ){
					swap(&puzzle[row][col], &puzzle[row+1][col]);
				}else if((col-1 >= 0)&&(puzzle[row][col-1] == 0) ){
					swap(&puzzle[row][col], &puzzle[row][col-1]);
				}else if((col+1 < COL)&&(puzzle[row][col+1] == 0) ){
					swap(&puzzle[row][col], &puzzle[row][col+1]);
				}else{
					return 0;
				}
				return 1;
			}
		}
	}
	return 0;
}

void swap(int * x, int * y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
