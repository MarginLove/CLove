#include <stdio.h>
#define N 5

int main()
{
	int number1[N] = {36, 23, 47, 7, 19};
	int number2[N] = {25,  8, 29, 16, 6};
	char opt[N] = {'+', '-', '-', '+', '+'};
	int is_right[N] = {0};	// 0���ش����1���ش���ȷ 
	int input[N];
	int counter = 0;
	int i;
	
	for(i = 0;i < N;i++){
		printf("��%d�⣺%d %c %d = ", i + 1, number1[i], opt[i], number2[i]);
		scanf("%d", &input[i]);
	}
	
	printf("\n�ɼ����ܣ�\n");
	for(i = 0;i < N;i++){
		printf("%d %c %d = ", number1[i], opt[i], number2[i]);
		printf("%d", input[i]);
		if(opt[i] == '+'){
			if(input[i] == (number1[i] + number2[i])){
				is_right[i] = 1;
			}
		}else{
			if(input[i] == (number1[i] - number2[i])){
				is_right[i] = 1;
			}
		}
		if(is_right[i]){
			printf("\n");
			counter++;
		}else{
			printf(" [�𰸣�");
			if(opt[i] == '+'){
				printf("%d]\n", number1[i] + number2[i]);
			}else{
				printf("%d]\n", number1[i] - number2[i]);
			}
		}	
	}
	printf("��Ŀ������%d\n���������%d\n", N, counter); 
	printf("��ȷ�ʣ�%.2f%%\n", counter * 100.0 / N);
	
	return 0;
}
