#include <stdio.h>
int main()
{
	char opt;
	long long number1;
	long long number2;
	long long result;
	printf("���롰0 0 0�������˳���������\n");
	while(1){
		printf(">>>");
		scanf("%lld %c %lld", &number1, &opt, &number2);
		if((number1 == 0)&&(opt == '0')&&(number2 ==0)){
			break;
		} 
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
			printf("�Ƿ����㣡\n");
			continue;
		}
		printf("%lld %c %lld = %lld\n", number1, opt, number2, result);
	}
	printf("�Ѿ��˳���������\n");
	return 0;	
}
