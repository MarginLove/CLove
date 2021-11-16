#include <stdio.h>

int main()
{
	struct arithmetic{
		int number1;
		int number2;
		int input;
	};
	struct arithmetic test[5] = {
		{36, 25}, 
		{23,  8},
		{47, 29},
		{ 7, 16},
		{19,  6}
	};
	int i;
	
	for(i = 0;i < 5;i++){
		printf("第%d题：%d + %d = ", i + 1, test[i].number1, test[i].number2);
		scanf("%d", &test[i].input);
		if(test[i].input == (test[i].number1 + test[i].number2)){
			printf("回答正确！\n");
		}else{
			printf("回答错误！\n");
		}
	}
	
	return 0;
}
