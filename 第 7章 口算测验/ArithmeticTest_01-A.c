#include <stdio.h>

int main()
{
	int number1 = 36;
	int number2 = 25;
	int input;
	
	printf("%d + %d = ", number1, number2);
	scanf("%d", &input);
	
	if(input == (number1 + number2)){
		printf("�ش���ȷ��\n");
	}else{
		printf("�ش����\n");
	}
	
	return 0;
}
