#include <stdio.h>
#include <string.h>
#include "global.h"
#include "controller.h"

void add()
{
	Student stu;
	printf("\n��¼��ѧ����Ϣ��\n");
	input_student(&stu);
	if(write_student(stu)){
		printf("\n��¼��ѧ����Ϣ��\n");
		print_header();
		print_student(stu);
	}else{
		printf("\n����ѧ����Ϣʧ�ܣ�\n");
	}
}

void delete()
{
	Student stu;
	int index;
	char sid[SID_LEN];
	printf("�������ɾ��ѧ����ѧ��[%d�ַ�]��", SID_LEN - 1);
	input_string(sid, SID_LEN);
	index = search_by_sid(&stu, sid);
	if(index == NOT_FOUND){
		printf("\nû�д�ѧ�ţ�%s��\n", sid);
	}else{
		strcpy(stu.sid, DELETED);
		if(modify_student(stu, index)){
			printf("\n��ɾ��ѧ��Ϊ%s��ѧ����Ϣ��\n", sid);
		}else{
			printf("\nɾ��ѧ����Ϣʧ�ܣ�\n");
		}
	}	
}

void modify()
{
	Student stu;
	int index;
	char sid[SID_LEN];
	printf("��������޸�ѧ����ѧ��[%d�ַ�]��", SID_LEN - 1);
	input_string(sid, SID_LEN);
	index = search_by_sid(&stu, sid);
	if(index == NOT_FOUND){
		printf("\nû�д�ѧ�ţ�%s��\n", sid);
	}else{
		edit_student(&stu);
		if(modify_student(stu, index)){
			printf("\n���޸�ѧ����ϢΪ��\n");
			print_header();
			print_student(stu);
		}else{
			printf("\n����ѧ����Ϣʧ�ܣ�\n");
		}
	}
}

void search()
{
	Student stu;
	int index;
	char sid[SID_LEN];
	printf("�����������ѧ����ѧ��[%d�ַ�]��", SID_LEN - 1);
	input_string(sid, SID_LEN);
	index = search_by_sid(&stu, sid);
	if(index == NOT_FOUND){
		printf("\nû�д�ѧ�ţ�%s��\n", sid);
	}else{
		printf("\n���ҽ����\n");
		print_header();
		print_student(stu);
	}
}

void list()
{
	int count;
	print_header();
	if((count = list_student()) > 0){
		printf("\nһ����%d��ѧ����\n", count);
	}else{
		printf("\nĿǰû��ѧ����Ϣ��\n");
	}	
}
