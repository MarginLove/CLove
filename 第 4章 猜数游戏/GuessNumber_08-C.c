#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int max = 5;
	int object;
	int guess;
	int i;
	srand(time(NULL));
	object = rand() % 100 + 1;
	printf( "������Ϸ��Ŀ��������1~100֮��\n" ); 
	for( i = 1; i <= max; i++ ){
		printf( "��²�һ��������");
		scanf( "%d", &guess );
		printf( "��µ������ǣ�%d, ", guess );
		if( (guess < 1)||(guess > 100) ){
			printf( "��������[1, 100]��\n" ); 
		}else if( guess > object ){
			printf( "ƫ���ˣ�\n" ); 
		}else if( guess < object ){
			printf( "ƫС�ˣ�\n" ); 
		}else{
			printf( "�¶��ˣ�һ���²�%d�Ρ�\n", i );
			break; 
		}
	}
	if( i > max ){
		printf( "Ŀ��������%d��\n", object );		
		printf( "��Ǹ��ֻ����²�%d�Σ��ټ���\n",  max);
	}
	return 0;	
}
