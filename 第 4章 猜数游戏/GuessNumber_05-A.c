/*
	�ļ���	��GuessNumber_05-A.c
	����	������һ���汾GuessNumber_04-B.c�Ļ����ϣ�ʹ�� 
		 	  whileѭ����������û������²⡣
	����	��3857917@qq.com 
	ʱ��	��2017-07-10 
*/
#include <stdio.h>
int main()
{
	int object = 38;
	int guess;
	int is_right = 0;	// 0: �´� 1���¶�
	printf( "������Ϸ��Ŀ��������1~100֮��\n" ); 
	while(!is_right){
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
			is_right = 1; 
		}
	}
	return 0;	
}
