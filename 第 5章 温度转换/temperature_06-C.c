#include <stdio.h>
#include <math.h>

int main()
{
	double cels;	// Celsius, �����¶� 
	int fahr;		// Fahrenheit, �����¶�
	int begin;		// �¶ȱ����ʼֵ
	int end;		// �¶ȱ�Ľ���ֵ
	int step;		// ���� 		
	
	printf("�¶ȱ����ʼֵ�ͽ���ֵ[����]��");
	scanf("%d %d", &begin, &end);
	printf("������");
	scanf("%d", &step);
	if(step == 0){
		printf("�Ƿ�����");
		return 1;
	}
	if(begin < end){
		step = abs(step);
	}else{
		step = -abs(step);
	}
	
	fahr = begin;
	while(1){
		cels = (fahr - 32) * 5 / 9.0;
		printf("%10d%12.2f\n", fahr, cels);
		if(abs(fahr - end) < abs(step)){
			break;
		}
		fahr += step;
	}
	
	return 0; 
}
