#include <stdio.h>

#define ADD         1            // 菜单选项[录入学生信息] 
#define DELETE      2            // 菜单选项[删除学生信息]
#define MODIFY      3            // 菜单选项[修改学生信息]
#define SEARCH      4            // 菜单选项[查询学生信息]
#define LIST        5            // 菜单选项[列出所有学生]
#define QUIT        0            // 菜单选项[退出系统]

int get_choice();
void show_menu();

int main()
{
	int choice;

	while( (choice = get_choice()) != QUIT ){
		switch(choice){
			case ADD:
				printf("add()...\n");
				break;
			case DELETE:
				printf("delete()...\n");
				break;
			case MODIFY:
				printf("modify()...\n");
				break;
			case SEARCH:
				printf("search()...\n");
				break;
			case LIST:
				printf("list()...\n");
				break;
			default:
				printf("非法输入，请重新选择\n");
		}
	}
	printf("已退出程序。\n");
	
	return 0;
}

int get_choice()
{
	int select;
	show_menu();
	scanf("%d", &select);
	return select;
}

void show_menu()
{
	printf("\n\t\t\t           功能菜单\n");
	printf("\t\t\t==============================\n");
	printf("\t\t\t\t%d. 录入学生信息\n", ADD);
	printf("\t\t\t\t%d. 删除学生信息\n", DELETE);
	printf("\t\t\t\t%d. 修改学生信息\n", MODIFY);
	printf("\t\t\t\t%d. 查询学生信息\n", SEARCH);
	printf("\t\t\t\t%d. 列出所有学生\n", LIST);
	printf("\t\t\t\t%d. 退出系统\n", QUIT);
	printf("\t\t\t==============================\n");
	printf("\t\t\t请选择: ");
}

