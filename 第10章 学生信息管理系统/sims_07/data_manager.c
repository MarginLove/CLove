#include <stdio.h>
#include <string.h>
#include "global.h"
#include "data_manager.h"

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
