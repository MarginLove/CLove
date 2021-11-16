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
				printf("非法输入，请重新选择\n");
		}
	}
	printf("已退出程序。\n");
	
	return 0;
}

