#include <stdio.h>

#define ADD         1            // �˵�ѡ��[¼��ѧ����Ϣ] 
#define DELETE      2            // �˵�ѡ��[ɾ��ѧ����Ϣ]
#define MODIFY      3            // �˵�ѡ��[�޸�ѧ����Ϣ]
#define SEARCH      4            // �˵�ѡ��[��ѯѧ����Ϣ]
#define LIST        5            // �˵�ѡ��[�г�����ѧ��]
#define QUIT        0            // �˵�ѡ��[�˳�ϵͳ]
#define SID_LEN    13            // ѧ�ų��ȣ�  SID_LEN - 1 
#define NAME_LEN    9            // �������ȣ� NAME_LEN - 1 
#define CLASS_LEN  14            // �༶���ȣ�CLASS_LEN - 1
#define MALE       '0'           // ���� 
#define FEMALE     '1'           // Ů�� 
#define TRUE        1            // �߼�ֵ���桱 
#define FALSE       0            // �߼�ֵ���١�
#define STU_FILE "student.dat"   // �����ļ� 

typedef struct date{
	int year;                    // �� 
	int month;                   // �� 
	int day;                     // �� 
}Date;

typedef struct student{
	char sid[SID_LEN];           // ѧ��
	char name[NAME_LEN];         // ����
	char class[CLASS_LEN];       // �༶
	Date birth;                  // �������� 
	char gender;                 // �Ա�['0'����(Male), '1'��Ů(Female)]  
	double height;               // ���[��λ����]  
}Student;

typedef int Bool;               // �߼����� 

int get_choice();
void show_menu();
void add();
void list();
int list_student();
void input_student(Student * stu); 
void print_header();
void print_student(Student stu);
Bool write_student(Student stu);

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
				list();
				break;
			default:
				printf("�Ƿ����룬������ѡ��\n");
		}
	}
	printf("���˳�����\n");
	
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

int list_student()
{
	Student stu;
	int count = 0;
	FILE * fp = fopen(STU_FILE, "rb");
	if(fp == NULL){
		return count; 
	}
	while(1){
		fread(&stu, sizeof(Student), 1, fp);
		if(feof(fp)){
			break;
		}
		print_student(stu);
		count++;
	}
	fclose(fp);
	return count;
}

void input_student(Student * stu)
{
	printf("ѧ��[%d�ַ�]��", SID_LEN - 1);
	scanf("%12s", stu->sid);
	printf("����[%d�ַ�]��", NAME_LEN - 1);
	scanf("%8s", stu->name);
	printf("�༶[%d�ַ�]��", CLASS_LEN -1);
	scanf("%13s", stu->class);
	printf("��������[��-��-��]��");
	scanf("%d-%d-%d", &stu->birth.year, &stu->birth.month, &stu->birth.day);
	printf("�Ա�[%c:�У�%c:Ů]��", MALE, FEMALE);
	scanf(" %c", &stu->gender);	// %c�������һ���ո񣬵�����һ���س��� 
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

Bool write_student(Student stu)
{
	int count;
	FILE * fp = fopen(STU_FILE, "ab");
	if(fp == NULL){
		return FALSE; 
	}
	count = fwrite(&stu, sizeof(Student), 1, fp); 
	fclose(fp);
	if(count == 1){
		return TRUE; 
	}else{
		return FALSE;
	}	
}
