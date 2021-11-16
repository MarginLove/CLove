#include <stdio.h>

int main()
{
	int number1[5] = {36, 23, 47, 7, 19};
	int number2[5] = {25,  8, 29, 16, 6};
	char opt[5] = {'+', '-', '-', '+', '+'};
	int input[5];
	int i;
	
	for(i = 0;i < 5;i++){
		printf("第%d题：%d %c %d = ", i + 1, number1[i], opt[i], number2[i]);
		scanf("%d", &input[i]);
		if(opt[i] == '+'){
			if(input[i] == (number1[i] + number2[i])){
				printf("回答正确！\n");
			}else{
				printf("回答错误！\n");
			}
		}else{
			if(input[i] == (number1[i] - number2[i])){
				printf("回答正确！\n");
			}else{
				printf("回答错误！\n");
			}
		}	
	}
	
	return 0;
}
