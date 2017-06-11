#include"family_money_head.h"

int cover_account()   //注册登录界面函数
{
	int select = -1;//选择功能
	printf("\t------------------------           家庭财务管理系统           ------------------------\n\n");
	printf("\t-----------------                      1.注册                        -----------------\n");
	printf("\t-----------------                      2.登录                        -----------------\n");
	printf("\t-----------------                      3.密码修改                    -----------------\n");
	printf("\t-----------------                      4.密码找回                    -----------------\n");
	printf("\n\t请输入选项：");
	scanf("%d", &select);
	return select;
}

struct user *load_account(struct user *head_user)
{
	FILE *fp_account;
	struct user *p1, *p2;
	fp_account = fopen("account_information", "ab+");
	if (fp_account == NULL){
		printf("文件开失败，在load_account函数中。按任意键退出程序。\n");
		system("pause");
		exit(0);
	}
	head_user = (struct user *)malloc(LEN_user);
	head_user->next_user = NULL;
	while (p1 = (struct user *)malloc(LEN_user), fread(p1, LEN_user, 1, fp_account) == 1){
		if (head_user->next_user == NULL){
			head_user->next_user = p1;
		}
		else{
			p2->next_user = p1;
		}
		p2 = p1;
	}
	p1->next_user = NULL;
	fclose(fp_account);
	if (head_user->next_user == NULL){
		printf("当前无注册用户\n");
		system("pause");
		return head_user;
	}
	else{
		printf("账户数据读取成功\n");
		return head_user;
	}
}


struct user *enroll(struct user *head_user)
{
	char ch;
	struct user *p1, *p, *q;;
	char account[ACCOUNT_NUMBER] = { 0 };//保存账号
	char password[PASSWORD] = { 0 };//保存密码
	char question[QUESTION] = { 0 };//密码找回问题
	char answer[ANSWER] = { 0 };//密码找回答案
	int i = 0, j = 0, k = 0, quit = 0;
	/*创建账号模块*/
	while (1){
		system("cls");
		printf("\t------------------------           账号注册           ------------------------\n\n");
		printf("\tEsc:返回菜单\n\t任意键：进入\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_user;
		}
		system("cls");
		printf("\t------------------------           账号注册           ------------------------\n\n");
		printf("\t请输入要注册的账号：");
		fflush(stdin);
		gets(account);
		if (strlen(account) == 0 || strlen(account)>20){
			printf("\t账号长度错误，按任意键返回重新输入账号。");
			system("pause");
			continue;
		}

		for (q = head_user->next_user; q != NULL; q = q->next_user){
			if (strcmp(q->account, account) == 0){
				printf("\t该账号已经存在");
				system("pause");
				return head_user;
			}
		}
		printf("\t您要注册的账号为：%s  \n\t确认请按“1”，重新输入请按“2”\n\t", account);
		fflush(stdin);
		ch = getch();
		if (ch == '2')
			continue;
		else
			break;
	}
	/*创建账号模块结束*/

	/*注册密码开始*/
	while (1){
		system("cls");
		printf("\t------------------------           账号注册           ------------------------\n\n");
		printf("\n\t请输入密码\n\t(15位以内，按空格可显示输入的密码，请在*号模式下输入密码)：");
		fflush(stdin);
		while (1){
			ch = getch();
			if (ch == '\r'){
				quit = 1;
				break;
			}
			if (ch == ' '){
				if (k == 0){
					for (j = i - 1; j >= 0; j--){
						printf("\b \b");
					}
					for (j = 0; j<i; j++){
						printf("%c", password[j]);
					}
					k = 1;
					continue;
				}
				else if (k == 1){
					for (j = i - 1; j >= 0; j--){
						printf("\b \b");
					}
					for (j = 0; j<i; j++){
						printf("*");
					}
					k = 0;
					continue;
				}
			}
			if (ch == '\b'){
				if (i == 0)
					continue;
				printf("\b \b");
				i--;
			}
			else{
				password[i++] = ch;
				printf("*");
			}
			password[i] = '\0';
		}//输入密码while结束
		if (strlen(password) == 0 || strlen(password)>15){
			printf("密码长度错误，请重新输入。\n\t");
			system("pause");
			i = 0;
			j = 0;
			k = 0;
			quit = 0;
			continue;
		}
		if (quit == 1){
			break;
		}
	}
	/*密码注册完成*/

	/*密保问题开始*/
	printf("\n\t请设置密码找回问题：");
	gets(question);
	printf("\n\t请设置问题答案：");
	gets(answer);
	/*密保问题完成*/

	p1 = (struct user *)malloc(LEN_user);
	strcpy(p1->account, account);
	strcpy(p1->password, password);
	strcpy(p1->question, question);
	strcpy(p1->answer, answer);
	if (head_user->next_user == NULL){
		head_user->next_user = p1;
		p1->next_user = NULL;
		return head_user;
	}
	else{
		p = head_user;
		for (; p->next_user != NULL;){
			p = p->next_user;
		}
		if (p->next_user == NULL){
			p->next_user = p1;
			p1->next_user = NULL;
			printf("\t注册成功。\n\t");
			system("pause");
		}
		return head_user;
	}

}


char *login(struct user *head_user, char *account_name)
{
	while (1){
		char ch;
		char account[ACCOUNT_NUMBER] = { 0 };
		struct user *p;
		p = head_user;
		system("cls");
		printf("\t------------------------           登录           ------------------------\n\n");
		printf("\tEsc:返回菜单\n\t任意键：进入\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return account_name;
		}
		system("cls");
		printf("\t------------------------           登录           ------------------------\n\n");
		printf("\t请输入账号：");
		fflush(stdin);
		gets(account);
		for (p = p->next_user; p != NULL; p = p->next_user){
			if (strcmp(p->account, account) == 0)
				break;
		}
		if (p == NULL){
			printf("\t该账号还没有注册。\n");
			system("pause");
			return account_name;
		}
		else{
			int i = 0, j = 0;
			int k = 0;//用作空格标记，空格用来判断是否展示密码
			char password[PASSWORD] = { 0 };
			printf("\t请输入密码（按空格可显示输入的密码，请在*号模式下输入密码）：");
			while (1){
				ch = getch();
				if (ch == '\r'){
					break;
				}
				if (ch == ' '){
					if (k == 0){
						for (j = i - 1; j >= 0; j--){
							printf("\b \b");
						}
						for (j = 0; j<i; j++){
							printf("%c", password[j]);
						}
						k = 1;
						continue;
					}
					else if (k == 1){
						for (j = i - 1; j >= 0; j--){
							printf("\b \b");
						}
						for (j = 0; j<i; j++){
							printf("*");
						}
						k = 0;
						continue;
					}
				}
				if (ch == '\b'){
					if (i == 0)
						continue;
					printf("\b \b");
					i--;
				}
				else{
					password[i++] = ch;
					printf("*");
				}
			}//输入密码while
			password[i] = '\0';
			if (strcmp(p->password, password) != 0){
				printf("\t密码或账号输入错误，请重新登录。");
				system("pause");
				continue;
			}
			else{
				return p->account;
			}
		}//else结束
	}//登录while结束
}


int find_password(struct user *head_user)
{
	struct user *p;
	char account_name[20] = { 0 };
	char ch;
	char answer[ANSWER] = { 0 };
	while (1){
		system("cls");
		printf("\t------------------------           密码找回           ------------------------\n\n");
		printf("\tEsc:返回菜单\n\t任意键：进入\n\t");
		ch = getch();
		if (ch == 27){
			return 0;
		}
		system("cls");
		printf("\t------------------------           密码找回           ------------------------\n\n");
		printf("\n\t请输入要找回密码的账号:");
		fflush(stdin);
		gets(account_name);
		for (p = head_user->next_user; p != NULL; p = p->next_user){
			if (strcmp(p->account, account_name) == 0){
				break;
			}
		}
		if (p == NULL){
			printf("\n\t该账号未注册。\n\t");
			system("pause");
			return 0;
		}
		else{
			while (1){
				system("cls");
				printf("\n\n\t------------------------           密码找回           ------------------------\n\n");
				printf("\t问题：");
				printf("%s\n", p->question);
				printf("\t回答：");
				fflush(stdin);
				gets(answer);
				if (strcmp(p->answer, answer) == 0){
					printf("\n\t回答正确。\n");
					printf("\n\t您的密码为：%s\n\t", p->password);
					system("pause");
					return 0;
				}
				else{
					printf("\n\t回答错误。\n");
					printf("\n\t请选择:\n\t1.重新回答问题\n\t2.重新输入账号\n\t3.返回主菜单\n");
					ch = getch();
					if (ch == '1')
						continue;
					else if (ch == '2')
						break;
					else if (ch == '3')
						return 0;
				}
			}//密码问题while
		}//密码问题else
	}//密码找回大循环while


}

struct user *modify_password(struct user *head_user)//修改密码函数
{
	while (1){
		char account_name[20] = { 0 };
		char password[20] = { 0 };
		struct user *p;
		char ch;
		int k = 0;
		int i = 0;
		int j = 0;
		system("cls");
		printf("\t--------------------   修改密码    -----------------------\n");
		printf("\tEsc:返回菜单\n\t任意键：进入\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_user;
		}
		system("cls");
		printf("\t--------------------   修改密码    -----------------------\n");
		printf("\t请输入要修改密码的账号:");
		fflush(stdin);
		gets(account_name);
		for (p = head_user->next_user; p != NULL; p = p->next_user){
			if (strcmp(p->account, account_name) == 0)
				break;
		}
		if (p == NULL){
			printf("\t该账号没有注册。\n\t");
			system("pause");
			return head_user;
		}
		else{
			printf("\t请输入原密码(按空格可显示密码，并在*号模式下输入密码)：");
			i = 0;
			while (1){
				ch = getch();
				if (ch == '\r'){
					break;
				}
				if (ch == ' '){
					if (k == 0){
						for (j = i - 1; j >= 0; j--){
							printf("\b \b");
						}
						for (j = 0; j<i; j++){
							printf("%c", password[j]);
						}
						k = 1;
						continue;
					}
					else if (k == 1){
						for (j = i - 1; j >= 0; j--){
							printf("\b \b");
						}
						for (j = 0; j<i; j++){
							printf("*");
						}
						k = 0;
						continue;
					}
				}
				if (ch == '\b'){
					if (i == 0)
						continue;
					printf("\b \b");
					i--;
				}
				else{
					password[i++] = ch;
					printf("*");
				}
			}//密码输入while
			if (strcmp(password, p->password) != 0){
				printf("\n\t原始密码错误，请重新输入。\n\t");
				system("pause");
				continue;
			}
			else{
				printf("\n\t请输入新密码(按空格可显示密码，并在*号模式下输入密码)：");
				i = 0;
				while (1){
					ch = getch();
					if (ch == '\r'){
						break;
					}
					if (ch == ' '){
						if (k == 0){
							for (j = i - 1; j >= 0; j--){
								printf("\b \b");
							}
							for (j = 0; j<i; j++){
								printf("%c", password[j]);
							}
							k = 1;
							continue;
						}
						else if (k == 1){
							for (j = i - 1; j >= 0; j--){
								printf("\b \b");
							}
							for (j = 0; j<i; j++){
								printf("*");
							}
							k = 0;
							continue;
						}
					}
					if (ch == '\b'){
						if (i == 0)
							continue;
						printf("\b \b");
						i--;
					}
					else{
						password[i++] = ch;
						printf("*");
					}
				}
				strcpy(p->password, password);
				printf("\n密码修改成功。\n");
				system("pause");
				return head_user;
			}
		}//密码else结束
	}//while循环结束
}


void save_account(struct user *head_user)   //保存账号密码数据到文件
{
	FILE *fp_account;
	struct user *p;
	p = head_user;
	fp_account = fopen("account_information", "wb");
	if (fp_account == NULL){
		printf("账号文件打开失败，在save_account函数中。\n");
		system("pause");
	}
	for (p = p->next_user; p != NULL;){
		fwrite(p, LEN_user, 1, fp_account);
		p = p->next_user;
	}
	printf("账号保存成功。\n");
	fclose(fp_account);
}











