#include <stdio.h>
int main()
{
	float cels;		// Celsius, �����¶� 
	float fahr;		// Fahrenheit, �����¶�
	fahr = 100.2;
	cels = (fahr - 32) * 5 / 9;
	printf("�����¶�%f���൱�������¶�%f�ȡ�\n", fahr, cels);
	return 0; 
}
