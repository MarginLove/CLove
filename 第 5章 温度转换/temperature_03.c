#include <stdio.h>
int main()
{
	double cels;	// Celsius, �����¶� 
	double fahr;	// Fahrenheit, �����¶�
	printf("�����뻪���¶ȣ�");
	scanf("%lf", &fahr);
	cels = (fahr - 32) * 5 / 9;
	printf("�����¶�%.2f���൱�������¶�%.2f�ȡ�\n", fahr, cels);
	return 0; 
}
