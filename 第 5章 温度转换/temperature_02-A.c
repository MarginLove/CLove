//	修改自源代码temperature_01_A.c 
#include <stdio.h>
int main()
{
	float cels;		// Celsius, 摄氏温度 
	int fahr;		// Fahrenheit, 华氏温度
	fahr = 100;
	cels = (fahr - 32) * 5 / 9.0;
	printf("华氏温度%d度相当于摄氏温度%f度。\n", fahr, cels);
	return 0; 
}
