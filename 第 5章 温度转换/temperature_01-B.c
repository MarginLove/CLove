#include <stdio.h>
int main()
{
	int cels;	// Celsius, 摄氏温度 
	int fahr;	// Fahrenheit, 华氏温度
	printf("请输入华氏温度(整数)：");
	scanf("%d", &fahr);
	cels = (fahr - 32) * 5 / 9;
	printf("华氏温度%d度相当于摄氏温度%d度。\n", fahr, cels);
	return 0; 
}
