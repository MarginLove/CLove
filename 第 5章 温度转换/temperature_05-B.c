#include <stdio.h>
int main()
{
	double cels;		// Celsius, 摄氏温度 
	int fahr;			// Fahrenheit, 华氏温度
	int lower = 0;		// 温度表的下限
	int upper = 300;	// 温度表的上限
	int step = 20;		// 步长 
	for(fahr = lower;fahr <= upper;fahr += step){
		cels = (fahr - 32) * 5 / 9.0;
		printf("%10d%12.2f\n", fahr, cels);
	}
	return 0; 
}
