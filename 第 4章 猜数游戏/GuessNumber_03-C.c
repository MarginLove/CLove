#include <stdio.h>
int main()
{
	int object = 38;
	int guess;
	printf( "猜数游戏：目标整数在1~100之间\n" ); 
	printf( "请猜测一个整数：");
	scanf( "%d", &guess );
	printf( "你猜的整数是：%d, ", guess );
	if( guess > object ){
		printf( "偏大了！\n" ); 
	}else if( guess < object ){
		printf( "偏小了！\n" ); 
	}else{
		printf( "猜对了！\n" ); 
	}
	return 0;	
}
