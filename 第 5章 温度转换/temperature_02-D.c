//	�޸���Դ����temperature_02_B.c 
#include <stdio.h>
int main()
{
	double cels;		// Celsius, �����¶� 
	double fahr;		// Fahrenheit, �����¶�	
	fahr = 100.2;
	cels = (fahr - 32) * 5 / 9;
	printf("�����¶�%f���൱�������¶�%f�ȡ�\n", fahr, cels);
	return 0; 
}
