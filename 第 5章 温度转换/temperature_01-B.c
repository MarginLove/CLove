#include <stdio.h>
int main()
{
	int cels;	// Celsius, �����¶� 
	int fahr;	// Fahrenheit, �����¶�
	printf("�����뻪���¶�(����)��");
	scanf("%d", &fahr);
	cels = (fahr - 32) * 5 / 9;
	printf("�����¶�%d���൱�������¶�%d�ȡ�\n", fahr, cels);
	return 0; 
}
