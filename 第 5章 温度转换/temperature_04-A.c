#include <stdio.h>
int main()
{
	double cels;		// Celsius, 摄氏温度 
	int fahr;			// Fahrenheit, 华氏温度
	int lower = 0;		// 温度表的下限
	int upper = 300;	// 温度表的上限
	int step = 20;		// 步长 
	fahr = lower;
	while(fahr <= upper){
		cels = (fahr - 32) * 5 / 9.0;
		printf("%d  %.2f\n", fahr, cels);
		fahr = fahr + step;
	}
	return 0; 
}
