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
	struct arithmetic test[5] = {
		{36, 25}, 
		{23,  8},
		{47, 29},
		{ 7, 16},
		{19,  6}
	};
	int i;
	
	for(i = 0;i < 5;i++){
		printf("第%d题：", i + 1);
		get_input(&test[i]);
		check_answer(test[i]);
	}
	
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
