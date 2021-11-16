#ifndef __GLOBAL_H__
#define __GLOBAL_H__

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
#define DELETED   "deleted"      // “已删除”标记 
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

#endif

