#include <stdio.h>
#include <math.h>
int main()
{
	double cels;	// Celsius, 摄氏温度 
	int fahr;		// Fahrenheit, 华氏温度
	int begin;		// 温度表的起始值
	int end;		// 温度表的结束值
	int step;		// 步长 	
	printf("温度表的起始值和结束值[华氏]：");
	scanf("%d %d", &begin, &end);
	printf("步长：");
	scanf("%d", &step);
	if(step == 0){
		printf("非法数据");
		return 1;
	}
	if(begin < end){
		step = abs(step);
	}else{
		step = -abs(step);
	}
	for(fahr = begin;abs(fahr - end - step) >= abs(step);fahr += step){
		cels = (fahr - 32) * 5 / 9.0;
		printf("%10d%12.2f\n", fahr, cels);
	}	
	return 0; 
}
