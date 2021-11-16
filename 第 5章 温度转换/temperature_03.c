#include <stdio.h>
int main()
{
	double cels;	// Celsius, 摄氏温度 
	double fahr;	// Fahrenheit, 华氏温度
	printf("请输入华氏温度：");
	scanf("%lf", &fahr);
	cels = (fahr - 32) * 5 / 9;
	printf("华氏温度%.2f度相当于摄氏温度%.2f度。\n", fahr, cels);
	return 0; 
}
