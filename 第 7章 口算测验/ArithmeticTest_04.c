#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main()
{
	int number1[N];
	int number2[N];
	char opt[N];
	int is_right[N] = {0};	// 0���ش����1���ش���ȷ 
	int input[N];
	int counter = 0;
	int temp;
	int i;
	
	srand(time(NULL));
	for(i = 0;i < N;i++){
		number1[i] = rand() % 100;	
		if(rand() % 2 == 0){
			opt[i] = '+';
			number2[i] = rand() % (100 - number1[i]);
		}else{
			opt[i] = '-';
			number2[i] = rand() % 100;
			if(number1[i] < number2[i]){
				temp = number1[i];
				number1[i] = number2[i];
				number2[i] = temp;
			}
		}
	}
	
	for(i = 0;i < N;i++){
		printf("��%02d�⣺%2d %c %2d = ", i + 1, number1[i], opt[i], number2[i]);
		scanf("%d", &input[i]);
	}
	
	printf("\n�ɼ����ܣ�\n");
	for(i = 0;i < N;i++){
		printf("%2d %c %2d = ", number1[i], opt[i], number2[i]);
		printf("%2d", input[i]);
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
				printf("%2d]\n", number1[i] + number2[i]);
			}else{
				printf("%2d]\n", number1[i] - number2[i]);
			}
		}	
	}
	printf("��Ŀ������%6d\n���������%6d\n", N, counter); 
	printf("��ȷ�ʣ�%7.2f%%\n", counter * 100.0 / N);
	
	return 0;
}
