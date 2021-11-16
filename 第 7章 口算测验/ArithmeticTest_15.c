#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

void init_test(int number1[], char opt[], int number2[], int n);
void get_input(int number1[], char opt[], int number2[], int input[], int n);
void summary(int number1[], char opt[], int number2[], int input[], int n);
int check_answer(int number1, char opt, int number2, int input);
int get_rand_number(int min, int max);
char get_rand_opt();
void swap(int * x, int * y);

int main()
{
	int number1[N];
	int number2[N];
	char opt[N];
	int input[N];
	
	init_test(number1, opt, number2, N);
	get_input(number1, opt, number2, input, N);	
	summary(number1, opt, number2, input, N);
	
	return 0;
}

void init_test(int number1[], char opt[], int number2[], int n)
{
	int i;
	srand(time(NULL));
	for(i = 0;i < N;i++){
		number1[i] = get_rand_number(0, 99);
		opt[i] = get_rand_opt();
		if(opt[i] == '+'){
			number2[i] = get_rand_number(0, 99 - number1[i]);
		}else{
			number2[i] = get_rand_number(0, 99);
			if(number1[i] < number2[i]){
				swap(&number1[i], &number2[i]);
			}
		}	
	}
}

void get_input(int number1[], char opt[], int number2[], int input[], int n)
{
	int i;
	for(i = 0;i < n;i++){
		printf("第%02d题：", i + 1);
		printf("%2d %c %2d = ", number1[i], opt[i], number2[i]);
		scanf("%d", &input[i]);
	}
}

void summary(int number1[], char opt[], int number2[], int input[], int n)
{
	int is_right = 0;	// 0：回答错误，1：回答正确
	int counter = 0;
	int i;
	printf("\n成绩汇总：\n");
	for(i = 0;i < n;i++){
		printf("%2d %c %2d = ", number1[i], opt[i], number2[i]);
		printf("%2d", input[i]);
		is_right = check_answer(number1[i], opt[i], number2[i], input[i]);
		if(is_right){
			printf("\n");
			counter++;
		}else{
			printf(" [答案：");
			if(opt[i] == '+'){
				printf("%2d]\n", number1[i] + number2[i]);
			}else{
				printf("%2d]\n", number1[i] - number2[i]);
			}
		}
	}
	printf("题目总数：%6d\n答对数量：%6d\n", N, counter); 
	printf("正确率：%7.2f%%\n", counter * 100.0 / N);
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

int get_rand_number(int min, int max)
{
	int n = rand() % (max - min + 1) + min;
	return n;
}

char get_rand_opt()
{
	char opt;
	if(rand() % 2 == 0){
		opt = '+';
	}else{
		opt = '-';
	}
	return opt;
}

void swap(int * x, int * y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
