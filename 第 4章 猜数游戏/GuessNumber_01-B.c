#include <stdio.h>
int main()
{
	int guess;
	printf( "猜数游戏：目标整数在1~100之间\n" ); 
	printf( "请猜测一个整数：");
	scanf( "%d", &guess );
	printf( "你猜的整数是：%d\n", guess );
	return 0;	
}
