#include <stdio.h>

int main()
{
	struct arithmetic{
		int number1;
		int number2;
		int input;
	};
	struct arithmetic test = {36, 25};
	
	printf("%d + %d = ", test.number1, test.number2);
	scanf("%d", &test.input);
	
	if(test.input == (test.number1 + test.number2)){
		printf("�ش���ȷ��\n");
	}else{
		printf("�ش����\n");
	}
	
	return 0;
}
