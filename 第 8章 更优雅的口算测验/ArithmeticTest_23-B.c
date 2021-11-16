#include <stdio.h>
#define N 5

int main()
{
	struct arithmetic{
		int number1;
		int number2;
		char opt;
		int is_right;	// 0：回答错误，1：回答正确
		int input;
	};
	typedef struct arithmetic Arithmetic;
	Arithmetic test[N] = {
		{36, 25, '+', 0}, 
		{23,  8, '-', 0},
		{47, 29, '-', 0},
		{ 7, 16, '+', 0},
		{19,  6, '+', 0}
	};
	int counter = 0;
	int i;
	
	for(i = 0;i < N;i++){
		printf("第%02d题：%2d %c %2d = ", i + 1, test[i].number1, test[i].opt, test[i].number2);
		scanf("%d", &test[i].input);
	}
	
	printf("\n成绩汇总：\n");
	for(i = 0;i < N;i++){
		printf("%2d %c %2d = ", test[i].number1, test[i].opt, test[i].number2);
		printf("%2d", test[i].input);
		if(test[i].opt == '+'){
			if(test[i].input == (test[i].number1 + test[i].number2)){
				test[i].is_right = 1;
			}
		}else{
			if(test[i].input == (test[i].number1 - test[i].number2)){
				test[i].is_right = 1;
			}
		}
		if(test[i].is_right){
			printf("\n");
			counter++;
		}else{
			printf(" [答案：");
			if(test[i].opt == '+'){
				printf("%2d]\n", test[i].number1 + test[i].number2);
			}else{
				printf("%2d]\n", test[i].number1 - test[i].number2);
			}
		}	
	}
	printf("题目总数：%6d\n答对数量：%6d\n", N, counter); 
	printf("正确率：%7.2f%%\n", counter * 100.0 / N);
	
	return 0;
}
