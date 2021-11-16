/*
	 识别 0 不能当除数 
*/ 
#include <stdio.h>
int main()
{
	char opt;
	int number1;
	int number2;
	int result;
	printf(">>>");
	scanf("%d %c %d", &number1, &opt, &number2);
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
		printf("非法运算！");
		return 1;
	}
	printf("%d %c %d = %d", number1, opt, number2, result);
	return 0;	
}
