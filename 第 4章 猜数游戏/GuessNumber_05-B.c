#include <stdio.h>
int main()
{
	int object = 38;
	int guess;
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
			printf( "�¶��ˣ�\n" );
			break; 
		}
	}
	return 0;	
}
