#include <stdio.h>
int main()
{
	float cels;		// Celsius, �����¶� 
	float fahr;		// Fahrenheit, �����¶�
	printf("�����뻪���¶ȣ�");
	scanf("%f", &fahr);
	cels = (fahr - 32) * 5 / 9;
	printf("�����¶�%f���൱�������¶�%f�ȡ�\n", fahr, cels);
	return 0; 
}
