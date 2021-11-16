#ifndef __USER_INTERFACE_H__
#define __USER_INTERFACE_H__

#include "global.h"

int get_choice();
void show_menu();
void input_student(Student * stu);
void edit_student(Student * stu);
void print_header();
void print_student(Student stu);
int input_string(char * string, int n);

#endif

