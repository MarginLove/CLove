/*
	文件名	：GuessNumber_05-A.c
	功能	：在上一个版本GuessNumber_04-B.c的基础上，使用 
		 	  while循环语句允许用户反复猜测。
	作者	：3857917@qq.com 
	时间	：2017-07-10 
*/
#include <stdio.h>
int main()
{
	int object = 38;
	int guess;
	int is_right = 0;	// 0: 猜错， 1：猜对
	printf( "猜数游戏：目标整数在1~100之间\n" ); 
	while(!is_right){
		printf( "请猜测一个整数：");
		scanf( "%d", &guess );
		printf( "你猜的整数是：%d, ", guess );
		if( (guess < 1)||(guess > 100) ){
			printf( "超出区间[1, 100]！\n" ); 
		}else if( guess > object ){
			printf( "偏大了！\n" ); 
		}else if( guess < object ){
			printf( "偏小了！\n" ); 
		}else{
			printf( "猜对了！\n" );
			is_right = 1; 
		}
	}
	return 0;	
}
