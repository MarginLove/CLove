/*
	C = (F - 32) * (5/9)
	F = C * (9/5) + 32
*/
#include <stdio.h>
int main()
{
	int cels;	// Celsius, �����¶� 
	int fahr;	// Fahrenheit, �����¶�
	fahr = 100;
	cels = (fahr - 32) * 5 / 9;
	printf("�����¶�%d���൱�������¶�%d�ȡ�\n", fahr, cels);
	return 0; 
}
