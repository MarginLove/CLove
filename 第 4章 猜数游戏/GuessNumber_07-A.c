#include <stdio.h>
int main()
{
	int max = 5;
	int object = 38;
	int guess;
	int counter = 1;
	printf( "猜数游戏：目标整数在1~100之间\n" ); 
	while(1){
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
			printf( "猜对了！一共猜测%d次。\n", counter );
			break; 
		}
		if( counter == max ){
			printf( "抱歉，只允许猜测%d次，再见！\n", max );
			break;
		}
		counter = counter + 1;
	}
	return 0;	
}
