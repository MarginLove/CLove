#ifndef __DATA_MANAGER_H__
#define __DATA_MANAGER_H__

#include "global.h"

int list_student();
int search_by_sid(Student * stu, char * sid);
Bool write_student(Student stu);
Bool modify_student(Student stu, int index);

#endif

