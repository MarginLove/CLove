#include <stdio.h>

int get_input(int number1, int number2);
void check_answer(int number1, int number2, int input);

int main()
{
	int number1 = 36;
	int number2 = 25;
	int input;
	
	input = get_input(number1, number2);
	check_answer(number1, number2, input);
	
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
