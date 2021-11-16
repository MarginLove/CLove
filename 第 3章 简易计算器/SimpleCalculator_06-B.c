#include <stdio.h>
int main()
{
	char opt;
	int number1;
	int number2;
	int result;
	while(1){
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
			printf("非法运算！\n");
			continue;
		}
		printf("%d %c %d = %d\n", number1, opt, number2, result);
	}
	printf("已经退出计算器！\n");
	return 0;	
}
