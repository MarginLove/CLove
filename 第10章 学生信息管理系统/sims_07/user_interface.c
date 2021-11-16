#include <stdio.h>
#include "global.h"
#include "user_interface.h"

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

void input_student(Student * stu)
{
	printf("学号[%d字符]：", SID_LEN - 1);
	input_string(stu->sid, SID_LEN);
	printf("姓名[%d字符]：", NAME_LEN - 1);
	input_string(stu->name, NAME_LEN);
	printf("班级[%d字符]：", CLASS_LEN -1);
	input_string(stu->class, CLASS_LEN);
	printf("出生日期[年-月-日]：");
	scanf("%d-%d-%d", &stu->birth.year, &stu->birth.month, &stu->birth.day);
	printf("性别[%c:男，%c:女]：", MALE, FEMALE);
	scanf(" %c", &stu->gender);	// %c的左边有一个空格，抵消上一个回车符 
	printf("身高[米]：");
	scanf("%lf", &stu->height);
}

void edit_student(Student * stu)
{
	printf("\n姓名[%d字符]：%s\n", NAME_LEN - 1, stu->name);
	printf("姓名[%d字符]：", NAME_LEN - 1);
	input_string(stu->name, NAME_LEN);
	printf("班级[%d字符]：%s\n", CLASS_LEN -1, stu->class);
	printf("班级[%d字符]：", CLASS_LEN -1);
	input_string(stu->class, CLASS_LEN);
	printf("出生日期[年-月-日]：");
	printf("%d-%d-%d\n", stu->birth.year, stu->birth.month, stu->birth.day);
	printf("出生日期[年-月-日]：");
	scanf("%d-%d-%d", &stu->birth.year, &stu->birth.month, &stu->birth.day);
	printf("性别：%s\n", stu->gender == MALE ? "男" : "女");
	printf("性别[%c:男，%c:女]：", MALE, FEMALE);
	scanf(" %c", &stu->gender);	// %c的左边有一个空格，抵消上一个回车符 
	printf("身高[米]：%.2f\n", stu->height);
	printf("身高[米]：");
	scanf("%lf", &stu->height);
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

int input_string(char * string, int n)
{
	char format[80];
	sprintf(format, "%%%ds", n - 1);
	return scanf(format, string);
}
