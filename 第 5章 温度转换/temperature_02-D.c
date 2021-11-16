//	修改自源代码temperature_02_B.c 
#include <stdio.h>
int main()
{
	double cels;		// Celsius, 摄氏温度 
	double fahr;		// Fahrenheit, 华氏温度	
	fahr = 100.2;
	cels = (fahr - 32) * 5 / 9;
	printf("华氏温度%f度相当于摄氏温度%f度。\n", fahr, cels);
	return 0; 
}
