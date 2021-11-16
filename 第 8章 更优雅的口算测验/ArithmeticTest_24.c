#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main()
{
	struct arithmetic{
		int number1;
		int number2;
		char opt;
		int is_right;
		int input;
	};
	typedef struct arithmetic Arithmetic;
	Arithmetic test[N];
	int counter = 0;
	int temp;
	int i;
	
	srand(time(NULL));
	for(i = 0;i < N;i++){
		test[i].number1 = rand() % 100;		
		if(rand() % 2 == 0){
			test[i].opt = '+';
			test[i].number2 = rand() % (100 - test[i].number1);
		}else{
			test[i].opt = '-';
			test[i].number2 = rand() % 100;
			if(test[i].number1 < test[i].number2){
				temp = test[i].number1;
				test[i].number1 = test[i].number2;
				test[i].number2 = temp;
			}
		}
		test[i].is_right = 0; 
	}
	
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
