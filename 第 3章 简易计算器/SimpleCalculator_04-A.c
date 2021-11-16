#include <stdio.h>
int main()
{
	char opt;
	int number1;
	int number2;
	int result;
	printf("运算：");
	scanf("%c", &opt);
	printf("第1个数：");
	scanf("%d", &number1);
	printf("第2个数：");
	scanf("%d", &number2);
	if(opt == '+'){
		result = number1 + number2;
		printf("%d + %d = %d", number1, number2, result);
	}else if(opt == '-'){
		result = number1 - number2;
		printf("%d - %d = %d", number1, number2, result);
	}else if(opt == '*'){
		result = number1 * number2;
		printf("%d * %d = %d", number1, number2, result);
	}else{
		printf("非法运算！");
	}
	return 0;	
}
