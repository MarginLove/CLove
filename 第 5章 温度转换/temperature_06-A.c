#include <stdio.h>
int main()
{
	double cels;	// Celsius, �����¶� 
	int fahr;		// Fahrenheit, �����¶�
	int lower;		// �¶ȱ������
	int upper;		// �¶ȱ������
	int step;		// ���� 	
	printf("�¶ȱ�����޺�����[����]��");
	scanf("%d %d", &lower, &upper);
	printf("������");
	scanf("%d", &step);
	if((lower > upper)||(step <= 0)){
		printf("�Ƿ�����");
		return 1;
	}
	for(fahr = lower;fahr <= upper;fahr += step){
		cels = (fahr - 32) * 5 / 9.0;
		printf("%10d%12.2f\n", fahr, cels);
	}	
	return 0; 
}
