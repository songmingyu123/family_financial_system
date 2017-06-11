#include"family_money_head.h"

int cover_account()   //ע���¼���溯��
{
	int select = -1;//ѡ����
	printf("\t------------------------           ��ͥ�������ϵͳ           ------------------------\n\n");
	printf("\t-----------------                      1.ע��                        -----------------\n");
	printf("\t-----------------                      2.��¼                        -----------------\n");
	printf("\t-----------------                      3.�����޸�                    -----------------\n");
	printf("\t-----------------                      4.�����һ�                    -----------------\n");
	printf("\n\t������ѡ�");
	scanf("%d", &select);
	return select;
}

struct user *load_account(struct user *head_user)
{
	FILE *fp_account;
	struct user *p1, *p2;
	fp_account = fopen("account_information", "ab+");
	if (fp_account == NULL){
		printf("�ļ���ʧ�ܣ���load_account�����С���������˳�����\n");
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
		printf("��ǰ��ע���û�\n");
		system("pause");
		return head_user;
	}
	else{
		printf("�˻����ݶ�ȡ�ɹ�\n");
		return head_user;
	}
}


struct user *enroll(struct user *head_user)
{
	char ch;
	struct user *p1, *p, *q;;
	char account[ACCOUNT_NUMBER] = { 0 };//�����˺�
	char password[PASSWORD] = { 0 };//��������
	char question[QUESTION] = { 0 };//�����һ�����
	char answer[ANSWER] = { 0 };//�����һش�
	int i = 0, j = 0, k = 0, quit = 0;
	/*�����˺�ģ��*/
	while (1){
		system("cls");
		printf("\t------------------------           �˺�ע��           ------------------------\n\n");
		printf("\tEsc:���ز˵�\n\t�����������\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_user;
		}
		system("cls");
		printf("\t------------------------           �˺�ע��           ------------------------\n\n");
		printf("\t������Ҫע����˺ţ�");
		fflush(stdin);
		gets(account);
		if (strlen(account) == 0 || strlen(account)>20){
			printf("\t�˺ų��ȴ��󣬰�������������������˺š�");
			system("pause");
			continue;
		}

		for (q = head_user->next_user; q != NULL; q = q->next_user){
			if (strcmp(q->account, account) == 0){
				printf("\t���˺��Ѿ�����");
				system("pause");
				return head_user;
			}
		}
		printf("\t��Ҫע����˺�Ϊ��%s  \n\tȷ���밴��1�������������밴��2��\n\t", account);
		fflush(stdin);
		ch = getch();
		if (ch == '2')
			continue;
		else
			break;
	}
	/*�����˺�ģ�����*/

	/*ע�����뿪ʼ*/
	while (1){
		system("cls");
		printf("\t------------------------           �˺�ע��           ------------------------\n\n");
		printf("\n\t����������\n\t(15λ���ڣ����ո����ʾ��������룬����*��ģʽ����������)��");
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
		}//��������while����
		if (strlen(password) == 0 || strlen(password)>15){
			printf("���볤�ȴ������������롣\n\t");
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
	/*����ע�����*/

	/*�ܱ����⿪ʼ*/
	printf("\n\t�����������һ����⣺");
	gets(question);
	printf("\n\t����������𰸣�");
	gets(answer);
	/*�ܱ��������*/

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
			printf("\tע��ɹ���\n\t");
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
		printf("\t------------------------           ��¼           ------------------------\n\n");
		printf("\tEsc:���ز˵�\n\t�����������\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return account_name;
		}
		system("cls");
		printf("\t------------------------           ��¼           ------------------------\n\n");
		printf("\t�������˺ţ�");
		fflush(stdin);
		gets(account);
		for (p = p->next_user; p != NULL; p = p->next_user){
			if (strcmp(p->account, account) == 0)
				break;
		}
		if (p == NULL){
			printf("\t���˺Ż�û��ע�ᡣ\n");
			system("pause");
			return account_name;
		}
		else{
			int i = 0, j = 0;
			int k = 0;//�����ո��ǣ��ո������ж��Ƿ�չʾ����
			char password[PASSWORD] = { 0 };
			printf("\t���������루���ո����ʾ��������룬����*��ģʽ���������룩��");
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
			}//��������while
			password[i] = '\0';
			if (strcmp(p->password, password) != 0){
				printf("\t������˺�������������µ�¼��");
				system("pause");
				continue;
			}
			else{
				return p->account;
			}
		}//else����
	}//��¼while����
}


int find_password(struct user *head_user)
{
	struct user *p;
	char account_name[20] = { 0 };
	char ch;
	char answer[ANSWER] = { 0 };
	while (1){
		system("cls");
		printf("\t------------------------           �����һ�           ------------------------\n\n");
		printf("\tEsc:���ز˵�\n\t�����������\n\t");
		ch = getch();
		if (ch == 27){
			return 0;
		}
		system("cls");
		printf("\t------------------------           �����һ�           ------------------------\n\n");
		printf("\n\t������Ҫ�һ�������˺�:");
		fflush(stdin);
		gets(account_name);
		for (p = head_user->next_user; p != NULL; p = p->next_user){
			if (strcmp(p->account, account_name) == 0){
				break;
			}
		}
		if (p == NULL){
			printf("\n\t���˺�δע�ᡣ\n\t");
			system("pause");
			return 0;
		}
		else{
			while (1){
				system("cls");
				printf("\n\n\t------------------------           �����һ�           ------------------------\n\n");
				printf("\t���⣺");
				printf("%s\n", p->question);
				printf("\t�ش�");
				fflush(stdin);
				gets(answer);
				if (strcmp(p->answer, answer) == 0){
					printf("\n\t�ش���ȷ��\n");
					printf("\n\t��������Ϊ��%s\n\t", p->password);
					system("pause");
					return 0;
				}
				else{
					printf("\n\t�ش����\n");
					printf("\n\t��ѡ��:\n\t1.���»ش�����\n\t2.���������˺�\n\t3.�������˵�\n");
					ch = getch();
					if (ch == '1')
						continue;
					else if (ch == '2')
						break;
					else if (ch == '3')
						return 0;
				}
			}//��������while
		}//��������else
	}//�����һش�ѭ��while


}

struct user *modify_password(struct user *head_user)//�޸����뺯��
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
		printf("\t--------------------   �޸�����    -----------------------\n");
		printf("\tEsc:���ز˵�\n\t�����������\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_user;
		}
		system("cls");
		printf("\t--------------------   �޸�����    -----------------------\n");
		printf("\t������Ҫ�޸�������˺�:");
		fflush(stdin);
		gets(account_name);
		for (p = head_user->next_user; p != NULL; p = p->next_user){
			if (strcmp(p->account, account_name) == 0)
				break;
		}
		if (p == NULL){
			printf("\t���˺�û��ע�ᡣ\n\t");
			system("pause");
			return head_user;
		}
		else{
			printf("\t������ԭ����(���ո����ʾ���룬����*��ģʽ����������)��");
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
			}//��������while
			if (strcmp(password, p->password) != 0){
				printf("\n\tԭʼ����������������롣\n\t");
				system("pause");
				continue;
			}
			else{
				printf("\n\t������������(���ո����ʾ���룬����*��ģʽ����������)��");
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
				printf("\n�����޸ĳɹ���\n");
				system("pause");
				return head_user;
			}
		}//����else����
	}//whileѭ������
}


void save_account(struct user *head_user)   //�����˺��������ݵ��ļ�
{
	FILE *fp_account;
	struct user *p;
	p = head_user;
	fp_account = fopen("account_information", "wb");
	if (fp_account == NULL){
		printf("�˺��ļ���ʧ�ܣ���save_account�����С�\n");
		system("pause");
	}
	for (p = p->next_user; p != NULL;){
		fwrite(p, LEN_user, 1, fp_account);
		p = p->next_user;
	}
	printf("�˺ű���ɹ���\n");
	fclose(fp_account);
}











