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
	printf("��%d��[ ", step);
	show_moveable(puzzle, ROW);
	printf("]��");
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
			if(puzzle[row][col] == 0){	// �ҵ��հ�λ������Ӧ�������±� 
				if(row-1 >= 0){		// �հ�λ�õ��Ϸ� 
					printf("%d ", puzzle[row-1][col]);
				} 
				if(row+1 < n){		// �հ�λ�õ��·� 
					printf("%d ", puzzle[row+1][col]);
				} 
				if(col-1 >= 0){		// �հ�λ�õ����
					printf("%d ", puzzle[row][col-1]);
				} 
				if(col+1 < COL){	// �հ�λ�õ��ұ� 
					printf("%d ", puzzle[row][col+1]);
				} 
				return;
			}
		}
	}
}
