#include <stdio.h>
int main()
{
	int object = 38;
	int guess;
	printf( "������Ϸ��Ŀ��������1~100֮��\n" ); 
	printf( "��²�һ��������");
	scanf( "%d", &guess );
	printf( "��µ������ǣ�%d, ", guess );
	if( guess > object ){
		printf( "ƫ���ˣ�\n" ); 
	}else if( guess < object ){
		printf( "ƫС�ˣ�\n" ); 
	}else{
		printf( "�¶��ˣ�\n" ); 
	}
	return 0;	
}
