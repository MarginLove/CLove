#include <stdio.h>
int main()
{
	float cels;		// Celsius, 摄氏温度 
	float fahr;		// Fahrenheit, 华氏温度
	fahr = 100.2;
	cels = (fahr - 32) * 5 / 9;
	printf("华氏温度%f度相当于摄氏温度%f度。\n", fahr, cels);
	return 0; 
}
