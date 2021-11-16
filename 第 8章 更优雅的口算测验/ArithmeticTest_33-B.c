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
int summary(Arithmetic test);
int check_answer(Arithmetic test);

int main()
{
	Arithmetic test[N] = {
		{36, 25, '+'}, 
		{23,  8, '-'},
		{47, 29, '-'},
		{ 7, 16, '+'},
		{19,  6, '+'}
	};
	int counter = 0;
	int i;
	
	for(i = 0;i < N;i++){
		printf("��%02d�⣺", i + 1);
		get_input(&test[i]);
	}
	
	printf("\n�ɼ����ܣ�\n");
	for(i = 0;i < N;i++){
		counter += summary(test[i]);
	}
	printf("��Ŀ������%6d\n���������%6d\n", N, counter); 
	printf("��ȷ�ʣ�%7.2f%%\n", counter * 100.0 / N);
	
	return 0;
}

void get_input(Arithmetic * test)
{
	printf("%2d %c %2d = ", test->number1, test->opt, test->number2);
	scanf("%d", &test->input);
}

int summary(Arithmetic test)
{
	int is_right;
	printf("%2d %c %2d = ", test.number1, test.opt, test.number2);
	printf("%2d", test.input);
	is_right = check_answer(test);
	if(is_right){
		printf("\n");
	}else{
		printf(" [�𰸣�");
		if(test.opt == '+'){
			printf("%2d]\n", test.number1 + test.number2);
		}else{
			printf("%2d]\n", test.number1 - test.number2);
		}
	}	
	return is_right;
}

int check_answer(Arithmetic test)
{
	int is_right = 0;	// 0���ش����1���ش���ȷ
	if(test.opt == '+'){
		if(test.input == (test.number1 + test.number2)){
			is_right = 1;
		}
	}else{
		if(test.input == (test.number1 - test.number2)){
			is_right = 1;
		}
	}	
	return is_right;
}
