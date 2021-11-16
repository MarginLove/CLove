#include <stdio.h>

struct arithmetic{
	int number1;
	int number2;
	int input;
};
	
void get_input(struct arithmetic * test);
void check_answer(struct arithmetic test);

int main()
{
	struct arithmetic test = {36, 25};
	
	get_input(&test);
	check_answer(test);
	
	return 0;
}

void get_input(struct arithmetic * test)
{
	printf("%d + %d = ", test->number1, test->number2);
	scanf("%d", &test->input);
}

void check_answer(struct arithmetic test)
{
	if(test.input == (test.number1 + test.number2)){
		printf("回答正确！\n");
	}else{
		printf("回答错误！\n");
	}
}
