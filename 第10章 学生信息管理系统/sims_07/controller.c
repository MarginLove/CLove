#include <stdio.h>
#include <string.h>
#include "global.h"
#include "controller.h"

void add()
{
	Student stu;
	printf("\n请录入学生信息：\n");
	input_student(&stu);
	if(write_student(stu)){
		printf("\n已录入学生信息：\n");
		print_header();
		print_student(stu);
	}else{
		printf("\n保存学生信息失败！\n");
	}
}

void delete()
{
	Student stu;
	int index;
	char sid[SID_LEN];
	printf("请输入待删除学生的学号[%d字符]：", SID_LEN - 1);
	input_string(sid, SID_LEN);
	index = search_by_sid(&stu, sid);
	if(index == NOT_FOUND){
		printf("\n没有此学号：%s。\n", sid);
	}else{
		strcpy(stu.sid, DELETED);
		if(modify_student(stu, index)){
			printf("\n已删除学号为%s的学生信息。\n", sid);
		}else{
			printf("\n删除学生信息失败！\n");
		}
	}	
}

void modify()
{
	Student stu;
	int index;
	char sid[SID_LEN];
	printf("请输入待修改学生的学号[%d字符]：", SID_LEN - 1);
	input_string(sid, SID_LEN);
	index = search_by_sid(&stu, sid);
	if(index == NOT_FOUND){
		printf("\n没有此学号：%s。\n", sid);
	}else{
		edit_student(&stu);
		if(modify_student(stu, index)){
			printf("\n已修改学生信息为：\n");
			print_header();
			print_student(stu);
		}else{
			printf("\n保存学生信息失败！\n");
		}
	}
}

void search()
{
	Student stu;
	int index;
	char sid[SID_LEN];
	printf("请输入待查找学生的学号[%d字符]：", SID_LEN - 1);
	input_string(sid, SID_LEN);
	index = search_by_sid(&stu, sid);
	if(index == NOT_FOUND){
		printf("\n没有此学号：%s。\n", sid);
	}else{
		printf("\n查找结果：\n");
		print_header();
		print_student(stu);
	}
}

void list()
{
	int count;
	print_header();
	if((count = list_student()) > 0){
		printf("\n一共有%d个学生。\n", count);
	}else{
		printf("\n目前没有学生信息。\n");
	}	
}
