#include <stdio.h>
int main()
{
	double cels;	// Celsius, 摄氏温度 
	int fahr;		// Fahrenheit, 华氏温度
	int lower;		// 温度表的下限
	int upper;		// 温度表的上限
	int step;		// 步长 	
	printf("温度表的下限和上限[华氏]：");
	scanf("%d %d", &lower, &upper);
	printf("步长：");
	scanf("%d", &step);
	if((lower > upper)||(step <= 0)){
		printf("非法数据");
		return 1;
	}
	for(fahr = lower;fahr <= upper;fahr += step){
		cels = (fahr - 32) * 5 / 9.0;
		printf("%10d%12.2f\n", fahr, cels);
	}	
	return 0; 
}
