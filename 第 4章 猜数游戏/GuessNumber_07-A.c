#include <stdio.h>
int main()
{
	int max = 5;
	int object = 38;
	int guess;
	int counter = 1;
	printf( "������Ϸ��Ŀ��������1~100֮��\n" ); 
	while(1){
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
			printf( "�¶��ˣ�һ���²�%d�Ρ�\n", counter );
			break; 
		}
		if( counter == max ){
			printf( "��Ǹ��ֻ����²�%d�Σ��ټ���\n", max );
			break;
		}
		counter = counter + 1;
	}
	return 0;	
}
