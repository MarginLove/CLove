#include <stdio.h>
int main()
{
	double cels;		// Celsius, �����¶� 
	int fahr;			// Fahrenheit, �����¶�
	int lower = 0;		// �¶ȱ������
	int upper = 300;	// �¶ȱ������
	int step = 20;		// ���� 
	fahr = lower;
	while(fahr <= upper){
		cels = (fahr - 32) * 5 / 9.0;
		printf("%d  %.2f\n", fahr, cels);
		fahr = fahr + step;
	}
	return 0; 
}
