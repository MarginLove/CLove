#include <stdio.h>
int main()
{
	double cels;		// Celsius, �����¶� 
	int fahr;			// Fahrenheit, �����¶�
	int lower = 0;		// �¶ȱ������
	int upper = 300;	// �¶ȱ������
	int step = 20;		// ���� 
	for(fahr = lower;fahr <= upper;fahr += step){
		cels = (fahr - 32) * 5 / 9.0;
		printf("%d  %.2f\n", fahr, cels);
	}
	return 0; 
}
