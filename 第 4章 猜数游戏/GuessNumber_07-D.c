#include <stdio.h>
int main()
{
	int max = 5;
	int object = 38;
	int guess;
	int i;
	printf( "猜数游戏：目标整数在1~100之间\n" ); 
	for( i = 1; i <= max; i++ ){
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
			printf( "猜对了！一共猜测%d次。\n", i );
			break; 
		}
	}
	if( i > max ){		
		printf( "抱歉，只允许猜测%d次，再见！\n",  max);
	}
	return 0;	
}
