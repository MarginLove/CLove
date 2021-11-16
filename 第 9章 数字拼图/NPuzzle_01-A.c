#include <stdio.h>

int main()
{
	int puzzle[9] = {1, 0, 3, 4, 2, 6, 7, 5, 8};
	int i;
	
	for(i = 0;i < 9;i++){
		printf("%d ", puzzle[i]);
		if((i + 1) % 3 == 0){
			printf("\n");
		}
	}
	
	return 0;
}
