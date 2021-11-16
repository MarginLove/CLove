#include <stdio.h>
#define N 5

struct arithmetic{
	int number1;
	int number2;
	char opt;
	int input;
};
typedef struct arithmetic Arithmetic;
	
void get_input(Arithmetic * test);
void check_answer(Arithmetic test);

int main()
{
	Arithmetic test[N] = {
		{36, 25, '+'}, 
		{23,  8, '-'},
		{47, 29, '-'},
		{ 7, 16, '+'},
		{19,  6, '+'}
	};
	int i;
	
	for(i = 0;i < N;i++){
		printf("第%d题：", i + 1);
		get_input(&test[i]);
		check_answer(test[i]);
	}
	
	return 0;
}

void get_input(Arithmetic * test)
{
	printf("%d %c %d = ", test->number1, test->opt, test->number2);
	scanf("%d", &test->input);
}

void check_answer(Arithmetic test)
{
	int is_right = 0;	// 0：回答错误，1：回答正确
	if(test.opt == '+'){
		if(test.input == (test.number1 + test.number2)){
			is_right = 1;
		}
	}else{
		if(test.input == (test.number1 - test.number2)){
			is_right = 1;
		}
	}	
	if(is_right){
		printf("回答正确！\n");
	}else{
		printf("回答错误！\n");
	}
}
