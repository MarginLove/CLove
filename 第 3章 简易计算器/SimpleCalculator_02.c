#include <stdio.h>
int main()
{
	int number1;
	int number2;
	int result;
	printf("��1������");
	scanf("%d", &number1);
	printf("��2������");
	scanf("%d", &number2);
	result = number1 + number2;
	printf("%d + %d = %d", number1, number2, result);
	return 0;	
}
