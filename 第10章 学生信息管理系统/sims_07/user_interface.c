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
	printf("\n\t\t\t           ���ܲ˵�\n");
	printf("\t\t\t==============================\n");
	printf("\t\t\t\t%d. ¼��ѧ����Ϣ\n", ADD);
	printf("\t\t\t\t%d. ɾ��ѧ����Ϣ\n", DELETE);
	printf("\t\t\t\t%d. �޸�ѧ����Ϣ\n", MODIFY);
	printf("\t\t\t\t%d. ��ѯѧ����Ϣ\n", SEARCH);
	printf("\t\t\t\t%d. �г�����ѧ��\n", LIST);
	printf("\t\t\t\t%d. �˳�ϵͳ\n", QUIT);
	printf("\t\t\t==============================\n");
	printf("\t\t\t��ѡ��: ");
}

void input_student(Student * stu)
{
	printf("ѧ��[%d�ַ�]��", SID_LEN - 1);
	input_string(stu->sid, SID_LEN);
	printf("����[%d�ַ�]��", NAME_LEN - 1);
	input_string(stu->name, NAME_LEN);
	printf("�༶[%d�ַ�]��", CLASS_LEN -1);
	input_string(stu->class, CLASS_LEN);
	printf("��������[��-��-��]��");
	scanf("%d-%d-%d", &stu->birth.year, &stu->birth.month, &stu->birth.day);
	printf("�Ա�[%c:�У�%c:Ů]��", MALE, FEMALE);
	scanf(" %c", &stu->gender);	// %c�������һ���ո񣬵�����һ���س��� 
	printf("���[��]��");
	scanf("%lf", &stu->height);
}

void edit_student(Student * stu)
{
	printf("\n����[%d�ַ�]��%s\n", NAME_LEN - 1, stu->name);
	printf("����[%d�ַ�]��", NAME_LEN - 1);
	input_string(stu->name, NAME_LEN);
	printf("�༶[%d�ַ�]��%s\n", CLASS_LEN -1, stu->class);
	printf("�༶[%d�ַ�]��", CLASS_LEN -1);
	input_string(stu->class, CLASS_LEN);
	printf("��������[��-��-��]��");
	printf("%d-%d-%d\n", stu->birth.year, stu->birth.month, stu->birth.day);
	printf("��������[��-��-��]��");
	scanf("%d-%d-%d", &stu->birth.year, &stu->birth.month, &stu->birth.day);
	printf("�Ա�%s\n", stu->gender == MALE ? "��" : "Ů");
	printf("�Ա�[%c:�У�%c:Ů]��", MALE, FEMALE);
	scanf(" %c", &stu->gender);	// %c�������һ���ո񣬵�����һ���س��� 
	printf("���[��]��%.2f\n", stu->height);
	printf("���[��]��");
	scanf("%lf", &stu->height);
}

void print_header()
{
	int i;
	printf("\n%10s%13s%12s", "ѧ��", "����", "�༶");
	printf("%15s%6s%5s\n", "��������", "�Ա�", "���");
	for(i = 0;i < 61;i++){
		printf("%c",'-');
	}
	printf("\n");	 
}

void print_student(Student stu)
{
	printf("%14s%10s%15s", stu.sid, stu.name, stu.class);
	printf("%6d-%02d-%02d", stu.birth.year, stu.birth.month, stu.birth.day);
	printf("%4s", stu.gender == MALE ? "��" : "Ů");
	printf("%6.2f\n", stu.height);
}

int input_string(char * string, int n)
{
	char format[80];
	sprintf(format, "%%%ds", n - 1);
	return scanf(format, string);
}
