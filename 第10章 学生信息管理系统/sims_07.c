#include <stdio.h>
#include <string.h>

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
#define NOT_FOUND  -1            // �������[�Ҳ���] 
#define DELETED   "deleted"      // ����ɾ������� 
#define STU_FILE  "student.dat"  // �����ļ� 

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
void delete();
void modify();
void search();
void list();
int list_student();
int search_by_sid(Student * stu, char * sid);
void input_student(Student * stu); 
void edit_student(Student * stu);
void print_header();
void print_student(Student stu);
Bool write_student(Student stu);
Bool modify_student(Student stu, int index);
int input_string(char * string, int n);

int main()
{
	int choice;
	
	while( (choice = get_choice()) != QUIT ){
		switch(choice){
			case ADD:
				add();
				break;
			case DELETE:
				delete();
				break;
			case MODIFY:
				modify();
				break;
			case SEARCH:
				search();
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
		if(strcmp(stu.sid, DELETED) != 0){
			print_student(stu);
			count++;
		}	
	}
	fclose(fp);
	return count;
}

int search_by_sid(Student * stu, char * sid)
{
	int index = 0;
	FILE * fp = fopen(STU_FILE, "rb");
	if(fp == NULL){
		return NOT_FOUND;
	}
	while(1){
		fread(stu, sizeof(Student), 1, fp);
		if(feof(fp)){
			 break;
		}
		if((strcmp(stu->sid, DELETED) != 0)&&(strcmp(stu->sid, sid) == 0)){
			fclose(fp);
			return index;
		}
		index++;
	}
	fclose(fp);
	return NOT_FOUND;
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

Bool modify_student(Student stu, int index)
{
	int count;
	FILE * fp = fopen(STU_FILE, "rb+");
	if(fp == NULL){
		return FALSE; 
	}
	fseek(fp, sizeof(Student) * index, SEEK_SET);
	count = fwrite(&stu, sizeof(Student), 1, fp); 
	fclose(fp);
	if(count == 1){
		return TRUE; 
	}else{
		return FALSE;
	}	
}

int input_string(char * string, int n)
{
	char format[80];
	sprintf(format, "%%%ds", n - 1);
	return scanf(format, string);
}
