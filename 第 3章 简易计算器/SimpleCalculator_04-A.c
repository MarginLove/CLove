#include <stdio.h>
int main()
{
	char opt;
	int number1;
	int number2;
	int result;
	printf("���㣺");
	scanf("%c", &opt);
	printf("��1������");
	scanf("%d", &number1);
	printf("��2������");
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
		printf("�Ƿ����㣡");
	}
	return 0;	
}
