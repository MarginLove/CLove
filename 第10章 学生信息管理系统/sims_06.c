#include <stdio.h>
#include <string.h>

#define ADD         1            // 菜单选项[录入学生信息] 
#define DELETE      2            // 菜单选项[删除学生信息]
#define MODIFY      3            // 菜单选项[修改学生信息]
#define SEARCH      4            // 菜单选项[查询学生信息]
#define LIST        5            // 菜单选项[列出所有学生]
#define QUIT        0            // 菜单选项[退出系统]
#define SID_LEN    13            // 学号长度：  SID_LEN - 1 
#define NAME_LEN    9            // 姓名长度： NAME_LEN - 1 
#define CLASS_LEN  14            // 班级长度：CLASS_LEN - 1
#define MALE       '0'           // 男性 
#define FEMALE     '1'           // 女性 
#define TRUE        1            // 逻辑值“真” 
#define FALSE       0            // 逻辑值“假”
#define NOT_FOUND  -1            // 搜索结果[找不到] 
#define STU_FILE  "student.dat"  // 数据文件 

typedef struct date{
	int year;                    // 年 
	int month;                   // 月 
	int day;                     // 日 
}Date;

typedef struct student{
	char sid[SID_LEN];           // 学号
	char name[NAME_LEN];         // 姓名
	char class[CLASS_LEN];       // 班级
	Date birth;                  // 出生日期 
	char gender;                 // 性别['0'：男(Male), '1'：女(Female)]  
	double height;               // 身高[单位：米]  
}Student;

typedef int Bool;               // 逻辑类型 

int get_choice();
void show_menu();
void add();
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

int get_choice()
{
	int select;
	show_menu();
	scanf("%d", &select);
	return select;
}

void show_menu()
{
	printf("\n\t\t\t           功能菜单\n");
	printf("\t\t\t==============================\n");
	printf("\t\t\t\t%d. 录入学生信息\n", ADD);
	printf("\t\t\t\t%d. 删除学生信息\n", DELETE);
	printf("\t\t\t\t%d. 修改学生信息\n", MODIFY);
	printf("\t\t\t\t%d. 查询学生信息\n", SEARCH);
	printf("\t\t\t\t%d. 列出所有学生\n", LIST);
	printf("\t\t\t\t%d. 退出系统\n", QUIT);
	printf("\t\t\t==============================\n");
	printf("\t\t\t请选择: ");
}

void add()
{
	Student stu;
	printf("\n请录入学生信息：\n");
	input_student(&stu);
	if(write_student(stu)){
		printf("\n已录入学生信息：\n");
		print_header();
		print_student(stu);
	}else{
		printf("\n保存学生信息失败！\n");
	}
}

void modify()
{
	Student stu;
	int index;
	char sid[SID_LEN];
	printf("请输入待修改学生的学号[%d字符]：", SID_LEN - 1);
	scanf("%12s", sid);
	index = search_by_sid(&stu, sid);
	if(index == NOT_FOUND){
		printf("\n没有此学号：%s。\n", sid);
	}else{
		edit_student(&stu);
		if(modify_student(stu, index)){
			printf("\n已修改学生信息为：\n");
			print_header();
			print_student(stu);
		}else{
			printf("\n保存学生信息失败！\n");
		}
	}
}

void search()
{
	Student stu;
	int index;
	char sid[SID_LEN];
	printf("请输入待查找学生的学号[%d字符]：", SID_LEN - 1);
	scanf("%12s", sid);
	index = search_by_sid(&stu, sid);
	if(index == NOT_FOUND){
		printf("\n没有此学号：%s。\n", sid);
	}else{
		printf("\n查找结果：\n");
		print_header();
		print_student(stu);
	}
}

void list()
{
	int count;
	print_header();
	if((count = list_student()) > 0){
		printf("\n一共有%d个学生。\n", count);
	}else{
		printf("\n目前没有学生信息。\n");
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
	printf("学号[%d字符]：", SID_LEN - 1);
	scanf("%12s", stu->sid);
	printf("姓名[%d字符]：", NAME_LEN - 1);
	scanf("%8s", stu->name);
	printf("班级[%d字符]：", CLASS_LEN -1);
	scanf("%13s", stu->class);
	printf("出生日期[年-月-日]：");
	scanf("%d-%d-%d", &stu->birth.year, &stu->birth.month, &stu->birth.day);
	printf("性别[%c:男，%c:女]：", MALE, FEMALE);
	scanf(" %c", &stu->gender);	// %c的左边有一个空格，抵消上一个回车符 
	printf("身高[米]：");
	scanf("%lf", &stu->height);
}

void edit_student(Student * stu)
{
	printf("\n姓名[%d字符]：%s\n", NAME_LEN - 1, stu->name);
	printf("姓名[%d字符]：", NAME_LEN - 1);
	scanf("%8s", stu->name);
	printf("班级[%d字符]：%s\n", CLASS_LEN -1, stu->class);
	printf("班级[%d字符]：", CLASS_LEN -1);
	scanf("%13s", stu->class);
	printf("出生日期[年-月-日]：");
	printf("%d-%d-%d\n", stu->birth.year, stu->birth.month, stu->birth.day);
	printf("出生日期[年-月-日]：");
	scanf("%d-%d-%d", &stu->birth.year, &stu->birth.month, &stu->birth.day);
	printf("性别：%s\n", stu->gender == MALE ? "男" : "女");
	printf("性别[%c:男，%c:女]：", MALE, FEMALE);
	scanf(" %c", &stu->gender);	// %c的左边有一个空格，抵消上一个回车符 
	printf("身高[米]：%.2f\n", stu->height);
	printf("身高[米]：");
	scanf("%lf", &stu->height);
}

void print_header()
{
	int i;
	printf("\n%10s%13s%12s", "学号", "姓名", "班级");
	printf("%15s%6s%5s\n", "出生日期", "性别", "身高");
	for(i = 0;i < 61;i++){
		printf("%c",'-');
	}
	printf("\n");	 
}

void print_student(Student stu)
{
	printf("%14s%10s%15s", stu.sid, stu.name, stu.class);
	printf("%6d-%02d-%02d", stu.birth.year, stu.birth.month, stu.birth.day);
	printf("%4s", stu.gender == MALE ? "男" : "女");
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
