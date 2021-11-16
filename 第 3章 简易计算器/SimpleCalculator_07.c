#include <stdio.h>
int main()
{
	char opt;
	long long number1;
	long long number2;
	long long result;
	while(1){
		printf(">>>");
		scanf("%lld %c %lld", &number1, &opt, &number2);
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
		printf("%lld %c %lld = %lld\n", number1, opt, number2, result);
	}
	printf("已经退出计算器！\n");
	return 0;	
}
