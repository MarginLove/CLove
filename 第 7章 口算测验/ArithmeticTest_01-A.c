#include <stdio.h>

int main()
{
	int number1 = 36;
	int number2 = 25;
	int input;
	
	printf("%d + %d = ", number1, number2);
	scanf("%d", &input);
	
	if(input == (number1 + number2)){
		printf("回答正确！\n");
	}else{
		printf("回答错误！\n");
	}
	
	return 0;
}
