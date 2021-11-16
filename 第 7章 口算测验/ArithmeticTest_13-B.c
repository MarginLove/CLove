#include <stdio.h>
#define N 5

int get_input(int number1, char opt, int number2);
int summary(int number1, char opt, int number2, int input);
int check_answer(int number1, char opt, int number2, int input);

int main()
{
	int number1[N] = {36, 23, 47, 7, 19};
	int number2[N] = {25,  8, 29, 16, 6};
	char opt[N] = {'+', '-', '-', '+', '+'}; 
	int input[N];
	int counter = 0;
	int i;
	
	for(i = 0;i < N;i++){
		printf("第%02d题：", i + 1);
		input[i] = get_input(number1[i], opt[i], number2[i]);
	}
	
	printf("\n成绩汇总：\n");
	for(i = 0;i < N;i++){
		counter += summary(number1[i], opt[i], number2[i], input[i]);
	}
	printf("题目总数：%6d\n答对数量：%6d\n", N, counter); 
	printf("正确率：%7.2f%%\n", counter * 100.0 / N);
	
	return 0;
}

int get_input(int number1, char opt, int number2)
{
	int input;
	printf("%2d %c %2d = ", number1, opt, number2);
	scanf("%d", &input);
	return input;
}

int summary(int number1, char opt, int number2, int input)
{
	int is_right = 0;	// 0：回答错误，1：回答正确
	printf("%2d %c %2d = ", number1, opt, number2);
	printf("%2d", input);
	is_right = check_answer(number1, opt, number2, input);
	if(is_right){
		printf("\n");
	}else{
		printf(" [答案：");
		if(opt == '+'){
			printf("%2d]\n", number1 + number2);
		}else{
			printf("%2d]\n", number1 - number2);
		}
	}	
	return is_right;
}

int check_answer(int number1, char opt, int number2, int input)
{
	int is_right = 0;	// 0：回答错误，1：回答正确	
	if(opt == '+'){
		if(input == (number1 + number2)){
			is_right = 1;
		}
	}else{
		if(input == (number1 - number2)){
			is_right = 1;
		}
	}	
	return is_right;
}
