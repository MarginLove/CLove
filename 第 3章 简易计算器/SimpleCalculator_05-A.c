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
	}else if(opt == '-'){
		result = number1 - number2;
	}else if(opt == '*'){
		result = number1 * number2;
	}else if( (opt == '/')&&(number2 != 0) ){
		result = number1 / number2;
	}else if( (opt == '%')&&(number2 != 0) ){
		result = number1 % number2;
	}else{
		printf("�Ƿ����㣡");
		return 1;
	}
	printf("%d %c %d = %d", number1, opt, number2, result);
	return 0;	
}
