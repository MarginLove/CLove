#include <stdio.h>

int get_input(int number1, int number2);
void check_answer(int number1, int number2, int input);

int main()
{
	int number1[5] = {36, 23, 47, 7, 19};
	int number2[5] = {25,  8, 29, 16, 6};
	int input[5];
	int i;
	
	for(i = 0;i < 5;i++){
		printf("第%d题：", i + 1);
		input[i] = get_input(number1[i], number2[i]);
		check_answer(number1[i], number2[i], input[i]);
	}
	
	return 0;
}

int get_input(int number1, int number2)
{
	int input;
	printf("%d + %d = ", number1, number2);
	scanf("%d", &input);
	return input;
}

void check_answer(int number1, int number2, int input)
{
	if(input == (number1 + number2)){
		printf("回答正确！\n");
	}else{
		printf("回答错误！\n");
	}
}
