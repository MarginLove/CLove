#include <stdio.h>

#define ADD         1            // 菜单选项[录入学生信息] 
#define DELETE      2            // 菜单选项[删除学生信息]
#define MODIFY      3            // 菜单选项[修改学生信息]
#define SEARCH      4            // 菜单选项[查询学生信息]
#define LIST        5            // 菜单选项[列出所有学生]
#define QUIT        0            // 菜单选项[退出系统]
#define SID_LEN    13            // 学号长度：  SID_LEN - 1 
#define NAME_LEN    9            // 姓名长度： NAME_LEN - 1 
#define CLASS_LEN  14            // 班级长度：CLASS_LEN - 1
#define MALE       '0'           // 男性 
#define FEMALE     '1'           // 女性 

typedef struct date{
	int year;                    // 年 
	int month;                   // 月 
	int day;                     // 日 
}Date;

typedef struct student{
	char sid[SID_LEN];           // 学号
	char name[NAME_LEN];         // 姓名
	char class[CLASS_LEN];       // 班级
	Date birth;                  // 出生日期 
	char gender;                 // 性别['0'：男(Male), '1'：女(Female)]  
	double height;               // 身高[单位：米]  
}Student;

int get_choice();
void show_menu();
void add();
void print_header();
void print_student(Student stu);

int main()
{
	int choice;
	
	while( (choice = get_choice()) != QUIT ){
		switch(choice){
			case ADD:
				add();
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

void add()
{
	Student stu = {
		"201801020304",
		"西门吹雪",
		"计算机应用181",
		{2000, 6, 1},
		'0',
		1.80
	};
	printf("\n已录入学生信息：\n");
	print_header();
	print_student(stu);
}

void print_header()
{
	int i;
	printf("\n%10s%13s%12s", "学号", "姓名", "班级");
	printf("%15s%6s%5s\n", "出生日期", "性别", "身高");
	for(i = 0;i < 61;i++){
		printf("%c",'-');
	}
	printf("\n");	 
}

void print_student(Student stu)
{
	printf("%14s%10s%15s", stu.sid, stu.name, stu.class);
	printf("%6d-%02d-%02d", stu.birth.year, stu.birth.month, stu.birth.day);
	printf("%4s", stu.gender == MALE ? "男" : "女");
	printf("%6.2f\n", stu.height);
}

