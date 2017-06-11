#ifndef FAMILY_MONEY_HEAD_H_INCLUDED
#define FAMILY_MONEY_HEAD_H_INCLUDED
//以下定义头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
//以下进行了宏定义

#define NAME 20
#define DATE 20
#define MONEY 10
#define REMARKS 50
#define ACCOUNT_NUMBER 20
#define PASSWORD 20
#define QUESTION 50
#define ANSWER 50
typedef enum Type{ income = 1, payout = -1 }type; //声明枚举类型

//以下是保存收支信息的结构体
struct person{
	type genre;
	char name[NAME]; //姓名
	char date[DATE]; //日期
	double money; //金额
	char remarks[REMARKS]; //备注
	struct person *next_person;
};

//以下是保存账号信息的结构体
struct user{
	char account[ACCOUNT_NUMBER];  //账号
	char password[PASSWORD];     //密码
	char question[QUESTION];        //密保问题
	char answer[ANSWER];        //密保答案
	struct user *next_user;
};

#define LEN_person sizeof(struct person)
#define LEN_user sizeof(struct user)

struct user *load_account(struct user *head_user);  //读取账号密码文件
void save_account(struct user *head_user);   //保存账号密码数据到文件
struct user *enroll(struct user *head_user);  //注册函数
char *login(struct user *head_user, char *account_name);      //登录函数
int cover_account();   //注册登录界面函数
int find_password(struct user *head_user);//密码找回函数
struct user *modify_password(struct user *head_user);//密码修改函数
char *member(char(*names)[20], char(*names_present)[20], struct person *head_recycle_bin,struct person *head_person);  //成员函数
void update_member(char(*names)[20], struct person *head_recycle_bin,struct person *head_person);//修改成员函数
int save_member(char(*names)[20], char(*account_name_member));//保存成员函数
int load_member(char(*names)[20], char(*account_name_member), char(*names_present)[20]);//读取成员函数
int cover_function(char(*names_present)[20]);   //主菜单界面函数
int search_data(struct person *head_person, char(*names_present)[20], enum Type flag);//查询函数
struct person *add_data(struct person *head_person, char(*names_present)[20], enum Type flag);  //添加收支函数
struct person *delete_data(struct person *head_person, char(*names_present)[20], enum Type flag, struct person *head_recycle_bin);//删除收支
struct person *update_data(struct person *head_person, char(*names_present)[20], enum Type flag);//修改收支
void calculate(struct person *head_person, char(*names_present)[20],char(*names)[20]);        //计算
void compute(struct person *head_person,char (*names_present)[20]);//计算节点中的数据
struct person *just_search(struct person *head_person, char(*names_present)[20], enum Type flag, struct person *a[]);//只能查找数据，并把找到的节点地址给数组，返回地址
int judge_time(char *nowtime);//判断用户自己输入的日期
void print_all(struct person *head_person);  //展示所有链表数据
int save_data(struct person *head_person, char *account_name);//保存函数，每次从功能函数返回到主菜单之前，需要保存的就调用
struct person *load_data(struct person *head_person, char *account_name);   //读取财务信息函数
struct person *recycle_bin(struct person *head_person, struct person *head_recycle_bin); //回收站
struct person *recycle(struct person *p, struct person *head_recycle_bin);//回收节点函数
struct person *load_recycle(struct person *head_recycle_bin, char(*account_name_recycle));//读取文件中的回收站数据
int save_recycle(struct person *head_recycle_bin, char(*account_name_recycle));//读取文件中的回收站数据
void free_space(struct person *p); //释放空间
void save_excel(struct person *head_person,char (*account_name));//保存到excel
struct person *sort_data(struct person *head_person,char (*names_present)[20]);//排序函数


#endif // FAMILY_MONEY_HEAD_H_INCLUDED
