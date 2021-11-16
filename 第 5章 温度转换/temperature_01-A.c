/*
	C = (F - 32) * (5/9)
	F = C * (9/5) + 32
*/
#include <stdio.h>
int main()
{
	int cels;	// Celsius, 摄氏温度 
	int fahr;	// Fahrenheit, 华氏温度
	fahr = 100;
	cels = (fahr - 32) * 5 / 9;
	printf("华氏温度%d度相当于摄氏温度%d度。\n", fahr, cels);
	return 0; 
}
