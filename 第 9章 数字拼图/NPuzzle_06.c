#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void shuffle_puzzle(int puzzle[][COL], int n, int level);
int get_rand_number(int min, int max);
void show_puzzle(int puzzle[][COL], int n);
int is_win(int puzzle[][COL], int n);
void show_moveable(int puzzle[][COL], int n);
int * get_moveable(int puzzle[][COL], int n);
int move(int puzzle[][COL], int n, int number);
void swap(int * x, int * y);

int main()
{
	int puzzle[ROW][COL];
	int step = 1;
	int number;
	
	shuffle_puzzle(puzzle, ROW, 5);
	while(1){
		show_puzzle(puzzle, ROW);
		if(is_win(puzzle, ROW)){
			printf("拼图成功！\n");
			break;
		}
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

void shuffle_puzzle(int puzzle[][COL], int n, int level)
{
	int * p = &puzzle[0][0];
	int * moveable;
	int number;
	int prev_number = 0;
	int i;
	srand(time(NULL));
	for(i = 0;i < COL*n;i++){
		p[i] = (i + 1) % (COL * n); 
	}
	i = 0;
	while(i < level){
		moveable = get_moveable(puzzle, n);
		do{
			number = moveable[get_rand_number(0, 3)];
		}while((number == prev_number)||(number == -1));
		free(moveable);	
		if(move(puzzle, n, number)){
			i++;
			prev_number = number;
		}		
	}
}

int get_rand_number(int min, int max)
{
	int n = rand() % (max - min + 1) + min;
	return n;
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

int is_win(int puzzle[][COL], int n) 
{
	int i;
	int * p = &puzzle[0][0];	
	for(i = 0;i < COL*n;i++){
		if( p[i] != (i + 1) % (COL *n) ){
			return 0;
		}
	}
	return 1;
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
