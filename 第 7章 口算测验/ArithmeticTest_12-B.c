#include <stdio.h>
#define N 5

int get_input(int number1, char opt, int number2);
int check_answer(int number1, char opt, int number2, int input);

int main()
{
	int number1[N] = {36, 23, 47, 7, 19};
	int number2[N] = {25,  8, 29, 16, 6};
	char opt[N] = {'+', '-', '-', '+', '+'};
	int is_right[N];	// 0���ش����1���ش���ȷ 
	int input[N];
	int i;
	
	for(i = 0;i < 5;i++){
		printf("��%d�⣺", i + 1);
		input[i] = get_input(number1[i], opt[i], number2[i]);
		is_right[i] = check_answer(number1[i], opt[i], number2[i], input[i]);
		if(is_right[i]){
			printf("�ش���ȷ��\n");
		}else{
			printf("�ش����\n");
		}
	}
	
	return 0;
}

int get_input(int number1, char opt, int number2)
{
	int input;
	printf("%d %c %d = ", number1, opt, number2);
	scanf("%d", &input);
	return input;
}

int check_answer(int number1, char opt, int number2, int input)
{
	int is_right = 0;	// 0���ش����1���ش���ȷ	
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
