#ifndef __GLOBAL_H__
#define __GLOBAL_H__

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

#endif

