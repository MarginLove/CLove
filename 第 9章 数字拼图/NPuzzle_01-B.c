#include <stdio.h>

int main()
{
	int puzzle[9] = {1, 0, 3, 4, 2, 6, 7, 5, 8};
	int row, col;	// row�����±꣬ col����(column)�±� 
	
	for(row = 0;row < 3;row++){
		for(col = 0;col < 3;col++){
			printf("%d ", puzzle[row * 3 + col]);
		}
		printf("\n");
	}
	
	return 0;
}
