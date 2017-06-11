#ifndef FAMILY_MONEY_HEAD_H_INCLUDED
#define FAMILY_MONEY_HEAD_H_INCLUDED
//���¶���ͷ�ļ�

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
//���½����˺궨��

#define NAME 20
#define DATE 20
#define MONEY 10
#define REMARKS 50
#define ACCOUNT_NUMBER 20
#define PASSWORD 20
#define QUESTION 50
#define ANSWER 50
typedef enum Type{ income = 1, payout = -1 }type; //����ö������

//�����Ǳ�����֧��Ϣ�Ľṹ��
struct person{
	type genre;
	char name[NAME]; //����
	char date[DATE]; //����
	double money; //���
	char remarks[REMARKS]; //��ע
	struct person *next_person;
};

//�����Ǳ����˺���Ϣ�Ľṹ��
struct user{
	char account[ACCOUNT_NUMBER];  //�˺�
	char password[PASSWORD];     //����
	char question[QUESTION];        //�ܱ�����
	char answer[ANSWER];        //�ܱ���
	struct user *next_user;
};

#define LEN_person sizeof(struct person)
#define LEN_user sizeof(struct user)

struct user *load_account(struct user *head_user);  //��ȡ�˺������ļ�
void save_account(struct user *head_user);   //�����˺��������ݵ��ļ�
struct user *enroll(struct user *head_user);  //ע�ắ��
char *login(struct user *head_user, char *account_name);      //��¼����
int cover_account();   //ע���¼���溯��
int find_password(struct user *head_user);//�����һغ���
struct user *modify_password(struct user *head_user);//�����޸ĺ���
char *member(char(*names)[20], char(*names_present)[20], struct person *head_recycle_bin,struct person *head_person);  //��Ա����
void update_member(char(*names)[20], struct person *head_recycle_bin,struct person *head_person);//�޸ĳ�Ա����
int save_member(char(*names)[20], char(*account_name_member));//�����Ա����
int load_member(char(*names)[20], char(*account_name_member), char(*names_present)[20]);//��ȡ��Ա����
int cover_function(char(*names_present)[20]);   //���˵����溯��
int search_data(struct person *head_person, char(*names_present)[20], enum Type flag);//��ѯ����
struct person *add_data(struct person *head_person, char(*names_present)[20], enum Type flag);  //�����֧����
struct person *delete_data(struct person *head_person, char(*names_present)[20], enum Type flag, struct person *head_recycle_bin);//ɾ����֧
struct person *update_data(struct person *head_person, char(*names_present)[20], enum Type flag);//�޸���֧
void calculate(struct person *head_person, char(*names_present)[20],char(*names)[20]);        //����
void compute(struct person *head_person,char (*names_present)[20]);//����ڵ��е�����
struct person *just_search(struct person *head_person, char(*names_present)[20], enum Type flag, struct person *a[]);//ֻ�ܲ������ݣ������ҵ��Ľڵ��ַ�����飬���ص�ַ
int judge_time(char *nowtime);//�ж��û��Լ����������
void print_all(struct person *head_person);  //չʾ������������
int save_data(struct person *head_person, char *account_name);//���溯����ÿ�δӹ��ܺ������ص����˵�֮ǰ����Ҫ����ľ͵���
struct person *load_data(struct person *head_person, char *account_name);   //��ȡ������Ϣ����
struct person *recycle_bin(struct person *head_person, struct person *head_recycle_bin); //����վ
struct person *recycle(struct person *p, struct person *head_recycle_bin);//���սڵ㺯��
struct person *load_recycle(struct person *head_recycle_bin, char(*account_name_recycle));//��ȡ�ļ��еĻ���վ����
int save_recycle(struct person *head_recycle_bin, char(*account_name_recycle));//��ȡ�ļ��еĻ���վ����
void free_space(struct person *p); //�ͷſռ�
void save_excel(struct person *head_person,char (*account_name));//���浽excel
struct person *sort_data(struct person *head_person,char (*names_present)[20]);//������


#endif // FAMILY_MONEY_HEAD_H_INCLUDED
