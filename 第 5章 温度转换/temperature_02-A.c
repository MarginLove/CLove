//	�޸���Դ����temperature_01_A.c 
#include <stdio.h>
int main()
{
	float cels;		// Celsius, �����¶� 
	int fahr;		// Fahrenheit, �����¶�
	fahr = 100;
	cels = (fahr - 32) * 5 / 9.0;
	printf("�����¶�%d���൱�������¶�%f�ȡ�\n", fahr, cels);
	return 0; 
}
