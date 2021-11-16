#include <stdio.h>

#define ADD         1            // �˵�ѡ��[¼��ѧ����Ϣ] 
#define DELETE      2            // �˵�ѡ��[ɾ��ѧ����Ϣ]
#define MODIFY      3            // �˵�ѡ��[�޸�ѧ����Ϣ]
#define SEARCH      4            // �˵�ѡ��[��ѯѧ����Ϣ]
#define LIST        5            // �˵�ѡ��[�г�����ѧ��]
#define QUIT        0            // �˵�ѡ��[�˳�ϵͳ]

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

