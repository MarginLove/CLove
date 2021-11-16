#include <stdio.h>
#include "global.h"
#include "controller.h"
#include "data_manager.h"
#include "user_interface.h"

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

