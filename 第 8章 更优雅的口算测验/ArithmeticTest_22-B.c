#include <stdio.h>
#define N 5

int main()
{
	struct arithmetic{
		int number1;
		int number2;
		char opt;
		int is_right;	// 0���ش����1���ش���ȷ
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
	int i;
	
	for(i = 0;i < N;i++){
		printf("��%d�⣺%d %c %d = ", i + 1, test[i].number1, test[i].opt, test[i].number2);
		scanf("%d", &test[i].input);
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
			printf("�ش���ȷ��\n");
		}else{
			printf("�ش����\n");
		}	
	}
		
	return 0;
}
