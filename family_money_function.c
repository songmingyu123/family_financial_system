#include"family_money_head.h"

int cover_function(char(*names_present)[20])//���˵����溯��
{
	int select = -1;//ѡ����
	int i;
	while (1){
		system("cls");
		printf("\t------------------------           ��ͥ�������ϵͳ         ----------------------\n\n");
		printf("\t-----------------            ����                 ֧��           -----------------\n\n");
		printf("\t-----------------        1.�������           5.���֧��         -----------------\n");
		printf("\t-----------------        2.ɾ������           6.ɾ��֧��         -----------------\n");
		printf("\t-----------------        3.��ѯ����           7.��ѯ֧��         -----------------\n");
		printf("\t-----------------        4.�޸�����           8.�޸�֧��         -----------------\n\n");
		printf("\t-----------------                   9.����վ                     -----------------\n");
		printf("\t-----------------                  10.����ͳ��                   -----------------\n");
		printf("\t-----------------                  11.��Աģʽ                   -----------------\n");
		printf("\t-----------------                  12.ע���˻�                   -----------------\n");
		printf("\t-----------------                  13.��������                   -----------------\n");
		printf("\t-----------------                  14.����                       -----------------\n");
		printf("\t-----------------                  15.�˳�����                   -----------------\n");
		printf("\n\t��ǰΪ��");//��Աģʽ˵��������
		for (i = 0; strlen(names_present[i]) != 0; i++){
			printf("%s   ", names_present[i]);
		}
		printf("ģʽ");
		printf("\n\n\t��ѡ��:");
		scanf("%d", &select);
		if (select >= 1 && select <= 14)
			return select;
		else{
			printf("\n\tѡ������������������롣\n\t");
			system("pause");
			continue;
		}

	}

}

struct person *load_data(struct person *head_person, char *account_name)   //��ȡ������Ϣ����
{
	FILE *fp_data;
	struct person *p1, *p2;
	fp_data = fopen(account_name, "ab+");
	if (fp_data == NULL){
		printf("�ļ��򿪴���load_data�����С���������˳�����\n");
		system("pause");
		exit(0);
	}
	head_person = (struct person *)malloc(LEN_person);
	// TODO (Leo#1#): ��ȡ�ļ�ʱ�ᷢ�����󣬿���ʱaccount_nameû��Ū�ã����ڿ����Ѿ�Ū���ˣ�account_name�Ѿ�ת��Ϊ�ַ�ָ��
	head_person->next_person = NULL;
	while (p1 = (struct person *)malloc(LEN_person), fread(p1, LEN_person, 1, fp_data) == 1){
		if (head_person->next_person == NULL){
			head_person->next_person = p1;
		}
		else{
			p2->next_person = p1;
		}
		p2 = p1;
	}
	p1->next_person = NULL;
	fclose(fp_data);
	if (head_person->next_person == NULL){
		printf("\n\t��ǰû�в�������\n\t");
		system("pause");
		return head_person;
	}
	else{
		printf("\n\t��ȡ���ݳɹ���\n");
		return head_person;
	}
}

struct person *add_data(struct person *head_person, char(*names_present)[20], enum Type flag) //�����֧����
{
	struct person *p, *p0;
	char style[2][10] = { "����", "֧��" };
	char nowtime[20] = { 0 };
	char ch;
	int t;//�ж�:0.income  1.payout
	int i = 0, j = 0;//j �����жϺ������ؽ����0����1��ȷ
	int select;//ѡ��Ҫ��ӳ�Ա�����
	int select_add = 0;//�ж��Ƿ������Ӳ�����֧����
	double money;
	if (flag == income)
		t = 0;
	else
		t = 1;
	while (1){
		system("cls");
		printf("\n\t-----------------------  ���%s   --------------------------\n", style[t]);
		printf("\n\t��ǰ��Աģʽ��");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("ģʽ\n");
		printf("\n\tEsc:���ز˵�\n\t�����������\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_person;
		}
		system("cls");
		printf("\n\t-----------------------  ���%s   --------------------------\n", style[t]);
        printf("\n\t��ǰ��Աģʽ��");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("ģʽ\n");
		p = head_person;
		SYSTEMTIME stLocal;
		GetLocalTime(&stLocal);
		wsprintf(nowtime,TEXT("%u-%u-%u"),stLocal.wYear,stLocal.wMonth,stLocal.wDay);
		printf("\n\t%s���ڣ�%s", style[t], nowtime);
		printf("\n\t�Ƿ�ʹ�ø����ڣ�\n\t1.��\n\t2.��\n\t");
		scanf("%d", &i);
		while (1){
			if (i == 2){
				system("cls");
				printf("\n\t-----------------------  ���%s   --------------------------\n", style[t]);
                printf("\n\t��ǰ��Աģʽ��");
                for(i=0;strlen(names_present[i]) != 0;i++){
                    printf(" %s\t",names_present[i]);
                }
                printf("ģʽ\n");
				printf("\n\t��ʽ�ο���2017-5-1");
				printf("\n\t���������ڣ�");
				fflush(stdin);
				gets(nowtime);
				j = judge_time(nowtime);
				if (j == 0){
					printf("\n\t���������������������롣\n\t");
					system("pause");
					continue;
				}
			}
			else
				break;
		}
		p0 = (struct person *)malloc(LEN_person);
		system("cls");
		printf("\n\t-----------------------  ���%s   --------------------------\n", style[t]);
        printf("\n\t��ǰ��Աģʽ��");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("ģʽ\n");
		printf("\n\t%s���ڣ�%s", style[t], nowtime);
		strcpy(p0->date, nowtime);
		p0->genre = flag;
		printf("\t��ѡ��Ҫ��ӵĳ�Ա���֣�");
		for (i = 0; strlen(names_present[i]) != 0; i++){
			printf("\n\t%d.%s  ", i, names_present[i]);
		}
		printf("\n\t������ţ�");
		scanf("%d", &select);
		strcpy(p0->name, names_present[select]);
		printf("\n\t�������");
		scanf("%lf", &money);
		p0->money = money;
		printf("\n\t�����뱸ע��");
		fflush(stdin);
		gets(p0->remarks);
		for (; p->next_person != NULL;){
			p = p->next_person;
		}
		if (p->next_person == NULL){
			p->next_person = p0;
			p0->next_person = NULL;
			printf("\n\t��ӳɹ���\n");
			system("pause");
		}
		printf("\n\t�Ƿ���������֧?\n\t1.��\n\t2.��\n\t");
		scanf("%d", &select_add);
		if (select_add == 1)
			continue;
		else
			break;
	}
	return head_person;
}

struct person *delete_data(struct person *head_person, char(*names_present)[20], enum Type flag, struct person *head_recycle_bin)//ɾ����֧
{
	while (1){
		char style[2][10] = { "����", "֧��" };
		struct person *a[30];//���սṹ��ָ������
		struct person *p1, *p2;
		int select;//Ҫɾ����ѡ����
		int t;//�ж������֧��
		int i;
		char ch;
		if (flag == income)
			t = 0;
		else
			t = 1;
		system("cls");
		printf("\n\t-----------------------  ɾ��%s   --------------------------\n", style[t]);
        printf("\n\t��ǰ��Աģʽ��");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("ģʽ\n");
		printf("\tEsc:���ز˵�\n\t�����������\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_person;
		}
		system("cls");
		printf("\n\t-----------------------  ɾ��%s   --------------------------\n", style[t]);
		printf("\n\t��ǰ��Աģʽ��");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("ģʽ\n");
		just_search(head_person, names_present, flag, a);//���Ҳ�չʾ���ݣ��ҷ��ؽṹ��ָ������
		printf("\n\t������Ҫɾ�������ݵı��(�ɶ�ѡ��ÿ��ѡ���ÿո���������롰-1������)��\n\t");

		while (scanf("%d", &select), select != -1){
			p1 = head_person;
			p2 = head_person;
			for (p1 = p1->next_person; p1 != NULL; p1 = p1->next_person){
				if (a[select] == p1){
					p2->next_person = p1->next_person;
					recycle(p1, head_recycle_bin);
					break;
				}
				else{
					p2 = p1;
				}
			}
			if (p1 == NULL){
				printf("\n\t���������Ŵ��ڴ���ɾ��������ֹ���������ݿ����Ѿ�ɾ������������ʵ��\n\t");
				system("pause");
				break;
			}
		}
		printf("\n\t�Ƿ����ɾ��?\n\t1.��\n\t2.��\n\t");
		fflush(stdin);
		scanf("%d", &select);
		if (select == 1){
			continue;
		}
		else
			break;
	}
	return head_person;
}

struct person *update_data(struct person *head_person, char(*names_present)[20], enum Type flag)//�޸���֧
{
	while (1){
		char style[2][10] = { "����", "֧��" };
		char date[20];
		struct person *a[30];//���սṹ��ָ������
		struct person *p1;
		double money;
		int select;//Ҫ�޸ĵ�ѡ����
		int t;//�ж������֧��
		int i;
		char ch;
		if (flag == income)
			t = 0;
		else
			t = 1;
		system("cls");
		printf("\n\t-----------------------  �޸�%s   --------------------------\n", style[t]);
		printf("\n\t��ǰ��Աģʽ��");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("ģʽ\n");
		printf("\tEsc:���ز˵�\n\t�����������\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_person;
		}
		system("cls");
		printf("\n\t-----------------------  �޸�%s   --------------------------\n", style[t]);
		printf("\n\t��ǰ��Աģʽ��");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("ģʽ\n");
		just_search(head_person, names_present, flag, a);//���Ҳ�չʾ���ݣ��ҷ��ؽṹ��ָ������
		printf("\n\t������Ҫ�޸ĵ����ݵı��(��ѡ)��\n\t");
		while (scanf("%d", &select), select >= 0){
			p1 = head_person;
			for (p1 = p1->next_person; p1 != NULL; p1 = p1->next_person){
				if (a[select] == p1){
					system("cls");
					printf("\n\t-----------------------  �޸�%s   --------------------------\n", style[t]);
					printf("\n\t��ǰ��Աģʽ��");
                    for(i=0;strlen(names_present[i]) != 0;i++){
                        printf(" %s\t",names_present[i]);
                    }
                    printf("ģʽ\n");
					printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p1->date, p1->name, p1->money, p1->remarks);
					printf("\n\t������Ҫ�޸ĵ�ѡ�1.���� 2.���� 3.��� 4.��ע\n\t(ÿ������һ��ѡ��ԡ�-1������)");
					printf("\n\t������Ҫ�޸ĵ�ѡ��(��ѡ)��");
					while (scanf("%d", &select), select>0){
						if (select == 1){
							while (1){
								printf("\n\t�������µ�����(��ʽ��2017-5-6)��");
								fflush(stdin);
								gets(date);
								if (judge_time(date) == 0){
									printf("\n\t���ڸ�ʽ����������ϸ��ո�ʽ�������ڣ�����Ϊ����á�����\n\t");
									system("pause");
									system("cls");
									printf("\n\t-----------------------  �޸�%s   --------------------------\n", style[t]);
									printf("\n\t��ǰ��Աģʽ��");
                                    for(i=0;strlen(names_present[i]) != 0;i++){
                                        printf(" %s\t",names_present[i]);
                                    }
                                    printf("ģʽ\n");
									printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p1->date, p1->name, p1->money, p1->remarks);
									printf("\n\t������Ҫ�޸ĵ�ѡ�1.���� 2.���� 3.��� 4.��ע\n\t(ÿ������һ��ѡ��ԡ�-1������)");
									printf("\n\t������Ҫ�޸ĵ�ѡ��(��ѡ)��");
									continue;
								}
								else{
									strcpy(p1->date, date);
									printf("\n\t�����޸ĳɹ�\n\t");
									system("pause");
									system("cls");
									printf("\n\t-----------------------  �޸�%s   --------------------------\n", style[t]);
									printf("\n\t��ǰ��Աģʽ��");
                                    for(i=0;strlen(names_present[i]) != 0;i++){
                                        printf(" %s\t",names_present[i]);
                                    }
                                    printf("ģʽ\n");
									printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p1->date, p1->name, p1->money, p1->remarks);
									printf("\n\t������Ҫ�޸ĵ�ѡ�1.���� 2.���� 3.��� 4.��ע\n\t(ÿ������һ��ѡ��ԡ�-1������)");
									printf("\n\t������Ҫ�޸ĵ�ѡ��(��ѡ)��");
									break;
								}
							}
						}
						if (select == 2){
							printf("\n\t�������µ���������ţ�");
							for (i = 0; strlen(names_present[i]) != 0; i++){
								printf("\n\t%d.%s  ", i, names_present[i]);
							}
							printf("\n\t");
							scanf("%d", &select);
							strcpy(p1->name, names_present[select]);
							printf("\n\t�����޸ĳɹ���\n\t");
							system("pause");
							system("cls");
							printf("\n\t-----------------------  �޸�%s   --------------------------\n", style[t]);
							printf("\n\t��ǰ��Աģʽ��");
                            for(i=0;strlen(names_present[i]) != 0;i++){
                                printf(" %s\t",names_present[i]);
                            }
                            printf("ģʽ\n");
							printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p1->date, p1->name, p1->money, p1->remarks);
							printf("\n\t������Ҫ�޸ĵ�ѡ�1.���� 2.���� 3.��� 4.��ע\n\t(ÿ������һ��ѡ��ԡ�-1������)");
							printf("\n\t������Ҫ�޸ĵ�ѡ��(��ѡ)��");
						}
						if (select == 3){
							printf("\n\t�������µĽ�");
							scanf("%lf", &money);
							p1->money = money;
							printf("\n\t����޸ĳɹ���\n\t");
							system("pause");
							system("cls");
							printf("\n\t-----------------------  �޸�%s   --------------------------\n", style[t]);
							printf("\n\t��ǰ��Աģʽ��");
                            for(i=0;strlen(names_present[i]) != 0;i++){
                                printf(" %s\t",names_present[i]);
                            }
                            printf("ģʽ\n");
							printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p1->date, p1->name, p1->money, p1->remarks);
							printf("\n\t������Ҫ�޸ĵ�ѡ�1.���� 2.���� 3.��� 4.��ע\n\t(ÿ������һ��ѡ��ԡ�-1������)");
							printf("\n\t������Ҫ�޸ĵ�ѡ��(��ѡ)��");
						}
						if (select == 4){
							printf("\n\t�������µı�ע��");
							scanf("%s", p1->remarks);
							printf("\n\t��ע�޸ĳɹ���\n\t");
							system("pause");
							system("cls");
							printf("\n\t-----------------------  �޸�%s   --------------------------\n", style[t]);
							printf("\n\t��ǰ��Աģʽ��");
                            for(i=0;strlen(names_present[i]) != 0;i++){
                                printf(" %s\t",names_present[i]);
                            }
                            printf("ģʽ\n");
							printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p1->date, p1->name, p1->money, p1->remarks);
							printf("\n\t������Ҫ�޸ĵ�ѡ�1.���� 2.���� 3.��� 4.��ע\n\t(ÿ������һ��ѡ��ԡ�-1������)");
							printf("\n\t������Ҫ�޸ĵ�ѡ��(��ѡ)��");
						}
					}//�޸��ҵ��ڵ��ѡ��wihle����
					if (select < 0)
						break;//���ѡ��-1������޸�
				}//�ҵ�if����
				if (select < 0)
					break;//���ѡ��-1������޸�
			}//�뿪ѡ���Ա��while
			if (select < 0)
				break;//���ѡ��-1������޸�
			if (p1 == NULL){
				printf("\n\t���������Ŵ��ڴ����޸ı�����ֹ���������ݿ����Ѿ��޸ģ����ʵ��\n\t");
				system("pause");
				break;
			}
		}
		printf("\n\t�Ƿ��������?\n\t1.��\n\t2.��\n\t");
		fflush(stdin);
		scanf("%d", &select);
		if (select == 1){
			system("cls");
			continue;
		}
		else
			break;
	}
	return head_person;
}

int search_data(struct person *head_person, char(*names_present)[20], enum Type flag)//��ѯ����
{
	while (1){
		char style[2][10] = { "����", "֧��" };
		char remark[50] = { 0 };
		char name[20] = { 0 };
		char ch;
		int i;
		int have_date = 0, have_name = 0, have_money = 0, have_remark = 0, have_flag = 1;//�ж��Ƿ�ѡ����ѡ�
		int judge_date = 0, judge_name = 0, judge_money = 0, judge_remark = 0, judge_flag = 0;//�ж��Ƿ��ҵ��ڵ�
		int t;//�ж�:0.income  1.payout
		int select;//ѡ���ѯ���������
		int select_serch = 0;//�ж��Ƿ�������Ҳ�����֧����
		int select_member = 0;//ѡ��Ҫ��ѯ�ĳ�Ա���
		double money_min = 0, money_max = 999999999;
		char date[20] = { 0 };//��ȡ����
		struct person *p;
		struct person *q;
		if (flag == income)
			t = 0;
		else
			t = 1;
		p = head_person;

		system("cls");
		printf("\n\t-----------------------  ��ѯ%s   --------------------------\n", style[t]);
		printf("\n\t��ǰ��Աģʽ��");
        for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
        }
        printf("ģʽ\n");
		printf("\tEsc:���ز˵�\n\t�����������\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_person;
		}
		system("cls");
		printf("\n\t-----------------------  ��ѯ%s   --------------------------\n", style[t]);
        printf("\n\t��ǰ��Աģʽ��");
        for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
        }
        printf("ģʽ\n");
		printf("\n\t��ѡ���ѯ����\n\t(�ɶ�ѡ,ÿ������һ����ź�س�����������������������������롰-1������)):");
		printf("\n\t1.����\t2.����\t3.���\t4.��ע\t5.��ʾȫ������\n\t");
		printf("������һ��ѡ�");
		fflush(stdin);
		while (scanf("%d", &select), select>0){
			//��������������ѯ��ʼ
			if (select == 1){
				have_date = 1;
				printf("\n\t����������  (��ʽ 2017-5-1 �� 2017-5)��");
				fflush(stdin);
				gets(date);
				printf("\n\t������һ��ѡ�");
			}
			//��������������ѯ����
			//��������������ѯ��ʼ
			else if (select == 2){
				have_name = 1;
				printf("\n\t��ѡ���Ա��\n");
				printf("\n\t");
				for (i = 0; strlen(names_present[i]) != 0; i++){
					printf("%d.%s  ", i, names_present[i]);
				}
				printf("\n\t");
				scanf("%d", &select_member);//names_present[select_member]���ڲ�������
				strcpy(name, names_present[select_member]);
				printf("\n\t������һ��ѡ�");
			}
			//��������������ѯ����
			//���ݽ�Χ���ҿ�ʼ
			else if (select == 3){
				have_money = 1;
				printf("\n\t�������Χ(��ʽ:200~1000)��");
				scanf("%lf~%lf", &money_min, &money_max);
				printf("\n\t������һ��ѡ�");
			}
			//���ݽ�Χ���ҽ���
			else if (select == 4){
				have_remark = 1;
				printf("\n\t�����뱸ע��Ϣ��");
				fflush(stdin);
				gets(remark);
				printf("\n\t������һ��ѡ�");
			}
			else if (select == 5){
				q = head_person;
				for(q=q->next_person;q!=NULL;q=q->next_person){
                    if(q->genre == 1){
                        printf("\n\t���룺");
                    }
                    else{
                        printf("\n\t֧����");
                    }
                    printf("\t%s\t%s\t%.1lf\t%s\n\t",q->date,q->name,q->money,q->remarks);
                }
                system("pause");
                printf("\n\t������һ��ѡ�");
            }   //������ѯwhile����,�õ�����Ҫ��������������������Ѱ�������У��������������нڵ�
       }        //�������в��ҷ��������Ľڵ�

        //Ѱ�ҽڵ�
        judge_remark = 0;
        judge_money = 0;
        judge_date = 0;
        judge_name = 0;
        p = head_person;
        printf("\n\t------------------    ��ѯ���     -----------------------\n");
        int judge_member1 = 0;//����ѯʱ������������������ϵͳ�Զ��ж��ҵ���������������Ľڵ㣬�Ƿ����ڵ�ǰ��Աģʽ�еĳ�Ա
        while (1){
            judge_member1 = 0;
            p = p->next_person;
            while (1){
                if (have_flag == 1){
                    for (; p != NULL; p = p->next_person){
                        if (p->genre == flag){
                            judge_flag = 1;
                            break;
                        }
                        else{
                            judge_money = 0;
                            judge_date = 0;
                            judge_name = 0;
                            judge_remark = 0;
                            judge_flag = 0;
                        }
                    }
                }
                if (have_money == 1){
                    for (; p != NULL; p = p->next_person){
                        if (p->money >= money_min && p->money <= money_max){
                            judge_money = 1;
                            break;
                        }
                        else{
                            judge_money = 0;
                            judge_date = 0;
                            judge_name = 0;
                            judge_remark = 0;
                            judge_flag = 0;
                        }
                    }
                }
                if (have_date == 1){
                    for (; p != NULL; p = p->next_person){
                        if (strstr(p->date, date)){
                            judge_date = 1;
                            break;
                        }
                        else{
                            judge_money = 0;
                            judge_date = 0;
                            judge_name = 0;
                            judge_remark = 0;
                            judge_flag = 0;
                        }
                    }
                }

                if (have_name == 1){
                    for (; p != NULL; p = p->next_person){
                        if (strcmp(p->name, name) == 0){
                            judge_name = 1;
                            break;
                        }
                        else{
                            judge_money = 0;
                            judge_date = 0;
                            judge_name = 0;
                            judge_remark = 0;
                            judge_flag = 0;
                        }
                    }
                }
                if (have_remark == 1){
                    for (; p != NULL; p = p->next_person){
                        if (strstr(p->remarks, remark)){
                            judge_remark = 1;
                            break;
                        }
                        else{
                            judge_money = 0;
                            judge_date = 0;
                            judge_name = 0;
                            judge_remark = 0;
                            judge_flag = 0;
                        }
                    }
                }
                if (judge_money + judge_date + judge_name + judge_remark + judge_flag == have_date + have_name + have_money + have_remark + have_flag){
                    break;//�����������в��ҷ��������Ľڵ㣬֪�����if������������ѭ�����룬�����һֱѭ���� p == NULL ����ѭ��
                }

                if (p == NULL){
                    break;
                }
            }
            //����һ���ڵ����ݽ���

            if (p != NULL){
                for (i = 0; strlen(names_present[i]) != 0; i++){
                    if (strcmp(names_present[i], p->name) == 0){
                        judge_member1 = 1;//�ж��Ƿ����뵱ǰ��Աģʽ�ĳ�Ա
                        break;
                    }
                }
                if (judge_member1 == 0){
                    continue;
                }
                printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p->date, p->name, p->money, p->remarks);
            }
            else
                break;
        }
        printf("\n\t�Ƿ��������?\n\t1.��\n\t2.��\n\t");
        scanf("%d", &select_serch);
        if (select_serch == 1){
            continue;
        }
        else
            break;
    }
    return 0;
}

void calculate(struct person *head_person,char(*names_present)[20],char(*names)[20]) //����
{
    while(1){
        system("cls");
        int i;
        double in=0,out=0,surplus=0;
        struct person *p;
        int select;
        int have_date=0,have_name=0;
        int judge_date=0,judge_name=0;
        char date_beginning[20]={0};
        char date_finish[20]={0};
        char name[20]={0};
        p = head_person;
        for(p=p->next_person;p!=NULL;p=p->next_person){
            if(p->genre == 1){
                in = in+(p->money);
            }
            else if(p->genre == -1){
                out = out+(p->money);
            }
        }
        surplus = in-out;
        printf("\n\t--------------------    ����ͳ��    ------------------------");
        printf("\n\t��ǰ��Աģʽ��");
        for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
        }
        printf("ģʽ\n");
        printf("\n\t��ǰȫ�ҽ��ࣺ%.1lf",surplus);

        printf("\n\t��ǰΪ��");
        for (i = 0; strlen(names_present[i]) != 0; i++){
            printf("%s   ", names_present[i]);
        }
        printf("ģʽ");

        printf("\n\t��ѡ���ѯ����\n\t(�ɶ�ѡ,ÿ������һ����ź�س�����������������������������롰-1������)):");
        printf("\n\t1.���ڷ�Χ\t2.����\t3.��ʾ����");
        printf("\n\t�����ѡ��������Ĭ��ѡ��ǰ��Աģʽ�����г�Ա��");
        printf("\n\t������һ��ѡ�");
        fflush(stdin);
        while (scanf("%d", &select), select>0){
            //��������������ѯ��ʼ
            if (select == 1){
                have_date = 1;
                printf("\n\t��������ʼ����  (��ʽ 2017-5-1 �� 2017-5)��");
                fflush(stdin);
                gets(date_beginning);
                printf("\n\t�������������  (��ʽ 2017-5-1 �� 2017-5)��");
                fflush(stdin);
                gets(date_finish);

            }
            //��������������ѯ����
            //��������������ѯ��ʼ
            else if (select == 2){
                have_name = 1;
                printf("\n\t��ѡ���Ա��\n");
                printf("\n\t");
                for (i = 0; strlen(names_present[i]) != 0; i++){
                    printf("%d.%s  ", i, names_present[i]);
                }
                printf("\n\t");
                scanf("%d", &select);//names_present[select_member]���ڲ�������
                strcpy(name, names_present[select]);
            }
            //��������������ѯ����
            //��ʾ����
            else if (select == 3){
                for(p = head_person->next_person;p!=NULL;p=p->next_person){
                    for(i = 0; strlen(names_present[i]) != 0; i++){
                        if(strcmp(p->name,names_present[i]) == 0){
                            if(p->genre == 1){
                                printf("\n\t����  ");
                            }
                            else
                                printf("\n\t֧��  ");
                            printf("\t%s\t%s\t%.1lf\t%s",p->date,p->name,p->money,p->remarks);
                        }
                    }
                }

                //��ǰÿ����Ա����֧����
                for(i = 0; strlen(names_present[i]) != 0; i++){
                    compute(head_person,names_present[i]);
                }

                //��ǰÿ����Ա����֧���ݽ���
            }
            //��ʾ���н���
            printf("\n\t������һ��ѡ�");
        }//������ѯwhile����,�õ�����Ҫ��������������������Ѱ�������У��������������нڵ�
        //�������в��ҷ��������Ľڵ�
        judge_name = 0;
        judge_date = 0;
        in=0;
        out=0;
        surplus=0;
        p = head_person;
        while(1){
            judge_name = 0;
            judge_date = 0;
            p=p->next_person;
            while(1){
                if (have_date == 1){
                    for (; p != NULL; p = p->next_person){
                        if (strcmp(p->date,date_beginning)>=0 && strcmp(p->date,date_finish)<=0){
                            judge_date = 1;
                            break;
                        }
                        else{
                            judge_date = 0;
                            judge_name = 0;
                        }
                    }
                }

                if (have_name == 1){
                    for (; p != NULL; p = p->next_person){
                        if (strcmp(p->name, name) == 0){
                            judge_name = 1;
                            break;
                        }
                        else{
                            judge_date = 0;
                            judge_name = 0;
                        }
                    }
                }
                if(have_date+have_name == judge_date+judge_name){
                    if(p->genre == 1){
                        printf("\n\t����  ");
                        in = in+(p->money);
                    }
                    else{
                        printf("\n\t֧��  ");
                        out = out+(p->money);
                    }
                    printf("\t%s\t%s\t%.1lf\t%s",p->date,p->name,p->money,p->remarks);
                    break;
                }
                if(p == NULL)
                    break;
            }
            if(p == NULL)
                break;
        }
        surplus = in-out;
        printf("\n\t���������ó������룺%.1lf   ֧����%.1lf   ���ࣺ%.1lf\n\t",in,out,surplus);
        system("pause");
        printf("\n\t�Ƿ����ͳ��?\n\t1.��\n\t2.��\n\t");
        scanf("%d", &select);
        if (select == 1)
            continue;
        else
            break;
    }

}


int save_data(struct person *head_person, char *account_name)//���溯����ÿ�δӹ��ܺ������ص����˵�֮ǰ����Ҫ����ľ͵���
{
	FILE *fp;
	struct person *p;
	p = head_person;
	fp = fopen(account_name, "wb");
	if (fp == NULL){
		printf("\n\t�ļ���ʧ�ܣ���save_data�ļ��С������˳�����\n\t");
		system("pause");
		exit(0);
	}

	for (p = p->next_person; p != NULL;){
		fwrite(p, LEN_person, 1, fp);
		p = p->next_person;
	}
	printf("���ݱ���ɹ���\n");
	fclose(fp);
	return 0;
}


int judge_time(char *nowtime)//�ж��û��Լ����������
{
	int i, j = 0, time, time_zong = 0, month;
	/*
	i,����ѭ��������λ�ã�12��
	j,�����жϵ�ǰ�Ƿ�Ϊ���ꡣ����λ�ã�15~19�У�44~50�С���Ϊ1����Ϊ0��
	time,���������ַ�����ÿһλ���֣�time_zong,�����꣬�£��շֱ�����ڡ�35��36�С�
	month,�����û�������·ݣ��˳�13��for�����жϺ�����Ҫ�����·ݡ�����λ�ã�30�У�39~60�С�
	*/
	for (i = 0; nowtime[i] != '\0'; i++){
		if (nowtime[i] == '-'){  //2017-4-29����ȡ��-��ǰ���2017��4�������ֽ����ж�
			if (i<5){
				if (time_zong >= 1970 && time_zong <= 2018){
					if (time_zong % 400 == 0){
						j = 1;
					}
					else if (time_zong % 4 == 0 && time_zong % 100 != 0)
						j = 1;
					time_zong = 0;
					continue;
				}
				else{
					return 0;
				}
			}
			if (i<8){
				if (time_zong >= 1 && time_zong <= 12){
					month = time_zong;
					time_zong = 0;
					continue;
				}
				else{
					return 0;
				}
			}
		}
		time = nowtime[i] - '0';
		time_zong = time_zong * 10 + time;  //������������
	}
	/*
	����Ϊ�����ж���ݺ��·��Ƿ���ȷ
	*/
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
		if (time_zong >= 1 && time_zong <= 31){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if (month == 2){
		if (j == 1){
			if (time_zong >= 1 && time_zong <= 29){
				return 1;
			}
			else{
				return 0;
			}
		}
		else if (j == 0){
			if (time_zong >= 1 && time_zong <= 28){
				return 1;
			}
			else{
				return 0;
			}
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11){
		if (time_zong >= 1 && time_zong <= 30){
			return 1;
		}
		else{
			return 0;
		}
	}

}



struct person *just_search(struct person *head_person, char(*names_present)[20], enum Type flag, struct person *a[])//ֻ�ܲ������ݣ������ҵ��Ľڵ��ַ�����飬���ص�ַ
{
	char style[2][10] = { "����", "֧��" };
	char remark[50] = { 0 };
	char name[20] = { 0 };
	int i;
	int have_date = 0, have_name = 0, have_money = 0, have_remark = 0, have_flag = 1;//�ж��Ƿ�ѡ����ѡ�
	int judge_date = 0, judge_name = 0, judge_money = 0, judge_remark = 0, judge_flag = 0;//�ж��Ƿ��ҵ��ڵ�
	int t;//�ж�:0.income  1.payout
	int select;//ѡ���ѯ���������
	int select_member = 0;//ѡ��Ҫ��ѯ�ĳ�Ա���
	double money_min = 0, money_max = 999999999;
	char date[20] = { 0 };//��ȡ����
	struct person *p;
	struct person *q;
	if (flag == income)
		t = 0;
	else
		t = 1;
	p = head_person;
	printf("\n\t-----------------------  ��ѯ%s   --------------------------\n", style[t]);
    printf("\n\t��ǰ��Աģʽ��");
    for(i=0;strlen(names_present[i]) != 0;i++){
        printf(" %s\t",names_present[i]);
    }
    printf("ģʽ\n");
	printf("\n\t��ѡ���ѯ����\n\t(�ɶ�ѡ,ÿ������һ����ź�س�����������������������������롰-1������)):");
	printf("\n\t1.����\t2.����\t3.���\t4.��ע\t5.��ʾȫ������\n\t");
	printf("������һ��ѡ�");
	fflush(stdin);
	while (scanf("%d", &select), select>0){
		//��������������ѯ��ʼ
		if (select == 1){
			have_date = 1;
			printf("\n\t����������  (��ʽ 2017-5-1 �� 2017-5)��");
			fflush(stdin);
			gets(date);
		}
		//��������������ѯ����
		//��������������ѯ��ʼ
		else if (select == 2){
			have_name = 1;
			printf("\n\t��ѡ���Ա��\n");
			printf("\n\t");
			for (i = 0; strlen(names_present[i]) != 0; i++){
				printf("%d.%s  ", i, names_present[i]);
			}
			printf("\n\t");
			scanf("%d", &select_member);//names_present[select_member]���ڲ�������
			strcpy(name, names_present[select_member]);
		}
		//��������������ѯ����
		//���ݽ�Χ���ҿ�ʼ
		else if (select == 3){
			have_money = 1;
			printf("\n\t�������Χ(��ʽ:200~1000)��");
			scanf("%lf~%lf", &money_min, &money_max);
		}
		//���ݽ�Χ���ҽ���
		else if (select == 4){
			have_remark = 1;
			printf("\n\t�����뱸ע��Ϣ��");
			fflush(stdin);
			gets(remark);
		}
		else if (select == 5){
            q = head_person;
            for(q=q->next_person;q!=NULL;q=q->next_person){
                if(q->genre == 1){
                    printf("\n\t���룺");
                }
                else{
                    printf("\n\t֧����");
                }
                printf("\t%s\t%s\t%.1lf\t%s\n\t",q->date,q->name,q->money,q->remarks);
            }
            system("pause");
            printf("\n\t������һ��ѡ�");
		}
		printf("\n\t������һ��ѡ�");
	}//������ѯwhile����,�õ�����Ҫ��������������������Ѱ�������У��������������нڵ�
	//�������в��ҷ��������Ľڵ�

	//Ѱ�ҽڵ�
	judge_remark = 0;
	judge_money = 0;
	judge_date = 0;
	judge_name = 0;
	p = head_person;
	//��ͬʱɾ�������������׼��
	int a_i = 0;


	int judge_member1 = 0;//��û��ѡ���������в���ʱ��ϵͳ�Զ��жϷ��������Ľڵ��Ƿ�Ϊ��ǰ��ĳ�Աģʽ�еĳ�Ա
	printf("\n\t------------------    ��ѯ���     -----------------------\n");
	while (1){
		judge_member1 = 0;
		p = p->next_person;
		while (1){
			if (have_flag == 1){
				for (; p != NULL; p = p->next_person){
					if (p->genre == flag){
						judge_flag = 1;
						break;
					}
					else{
						judge_money = 0;
						judge_date = 0;
						judge_name = 0;
						judge_remark = 0;
						judge_flag = 0;
					}
				}
			}
			if (have_money == 1){
				for (; p != NULL; p = p->next_person){
					if (p->money >= money_min && p->money <= money_max){
						judge_money = 1;
						break;
					}
					else{
						judge_money = 0;
						judge_date = 0;
						judge_name = 0;
						judge_remark = 0;
						judge_flag = 0;
					}
				}
			}
			if (have_date == 1){
				for (; p != NULL; p = p->next_person){
					if (strstr(p->date, date)){
						judge_date = 1;
						break;
					}
					else{
						judge_money = 0;
						judge_date = 0;
						judge_name = 0;
						judge_remark = 0;
						judge_flag = 0;
					}
				}
			}

			if (have_name == 1){
				for (; p != NULL; p = p->next_person){
					if (strcmp(p->name, name) == 0){
						judge_name = 1;
						break;
					}
					else{
						judge_money = 0;
						judge_date = 0;
						judge_name = 0;
						judge_remark = 0;
						judge_flag = 0;
					}
				}
			}
			if (have_remark == 1){
				for (; p != NULL; p = p->next_person){
					if (strstr(p->remarks, remark)){
						judge_remark = 1;
						break;
					}
					else{
						judge_money = 0;
						judge_date = 0;
						judge_name = 0;
						judge_remark = 0;
						judge_flag = 0;
					}
				}
			}
			if (judge_money + judge_date + judge_name + judge_remark + judge_flag == have_date + have_name + have_money + have_remark + have_flag){
				break;
			}
			if (p == NULL){
				break;
			}
		}
		//����һ���ڵ����ݽ���

		if (p != NULL){
			for (i = 0; strlen(names_present[i]) != 0; i++){
				if (strcmp(names_present[i], p->name) == 0){
					judge_member1 = 1;//�ж��Ƿ����뵱ǰ��Աģʽ�ĳ�Ա
					break;
				}
			}
			if (judge_member1 == 0){
				continue;
			}
			printf("\n\t%d. %s\t%s\t%.1lf\t%s\n\t", a_i, p->date, p->name, p->money, p->remarks);
			a[a_i] = p;//���ҵ��Ľڵ��ַ���浽������
			a_i++;//�����±�+1
		}
		else
			break;
	}
	return *a;
}


void compute(struct person *head_person,char (*names_present)[20])//����ڵ��е�����
{
    struct person *p;
    double in=0,out=0,surplus=0;
    p = head_person;
    for(p=p->next_person;p!=0;p=p->next_person){
        if(strcmp(p->name,names_present)==0){
             if(p->genre == 1){
                in = in+(p->money);
            }
            else{
                out = out+(p->money);
            }
        }
    }
    surplus = in-out;
    printf("\n\t%s   ���룺%.1lf   ֧����%.1lf   ���ࣺ%.1lf",names_present,in,out,surplus);
}


void save_excel(struct person *head_person,char (*account_name))  //���浽excel
{
    FILE *fp;
	struct person *p1 = NULL;
	char account_num[20]={0};
	double sum_in=0,sum_out=0;
	strcpy(account_num,account_name);
	fp = fopen(strcat(account_num,".csv"),"w");
	if(fp == NULL){
		printf("�����ļ�ʱ���ļ�ʧ�ܣ���save_excel�ļ��С�\n");
		exit(0);
	}
	p1 = head_person->next_person;
	fprintf(fp,"��֧,����,����,���,��ע\n");
	while(p1 != NULL){
        if(p1->genre == 1){
            fprintf(fp,"����,");
            sum_in = sum_in+p1->money;
        }
        else{
            fprintf(fp,"֧��,");
            sum_out = sum_out+p1->money;
        }
		fprintf(fp,"%s,%s,%.1lf,%s\n",p1->name,p1->date,p1->money,p1->remarks);
		p1 = p1->next_person;
	}
	fprintf(fp,"����,%.1lf",sum_in-sum_out);
	printf("�����ɹ���\n");
	system("pause");
	fclose(fp);
}

struct person *sort_data(struct person *head_person,char (*names_present)[20])//������
{
    char ch;
    int i;
    int select;
    struct person *p, *prep, *temp, *tail;
    struct person *show;
    system("cls");
    printf("\n\t-----------------------  ����   --------------------------\n");
    printf("\n\t��ǰ��Աģʽ��");
    for(i=0;strlen(names_present[i]) != 0;i++){
        printf(" %s\t",names_present[i]);
    }
    printf("ģʽ\n");
    printf("\tEsc:���ز˵�\n\t�����������\n\t");
    fflush(stdin);
    ch = getch();
    if (ch == 27){
        return head_person;
    }
    system("cls");
    printf("\n\t-----------------------  ����   --------------------------\n");
    printf("\n\t��ǰ��Աģʽ��");
    for(i=0;strlen(names_present[i]) != 0;i++){
        printf(" %s\t",names_present[i]);
    }
    printf("ģʽ\n");
    while(1){
        printf("\t��ѡ������ʽ:");
        printf("\n\t1.����");
        printf("\n\t2.���\n\t3.�˳�\n\t");
        scanf("%d",&select);
        if(select == 3)
            break;
        if(select!=1 && select!=2){
            printf("\n\tѡ�������������������");
            continue;
        }

        if(select == 1){
            tail = NULL;
            while( head_person->next_person != tail ){
                prep = head_person;
                p = head_person->next_person;
                while( p->next_person != tail ){
                    if(strcmp(p->date,p->next_person->date)>0){
                        temp = p->next_person;
                        prep->next_person= p->next_person;
                        p->next_person = p->next_person->next_person;
                        prep->next_person->next_person = p;
                        p = temp;
                    }
                    // �ڵ����
                    p = p->next_person;
                    prep = prep->next_person;
                }
                tail = p;
            }// ��һ��while
            show = head_person->next_person;
            for(;show!=NULL;show=show->next_person){
                printf("\n\t%s\t%s\t%.1lf\t%s", show->date, show->name, show->money, show->remarks);
            }
        }//if select == 1
        if(select == 2){
            tail = NULL;
            while( head_person->next_person != tail ){
                prep = head_person;
                p = head_person->next_person;
                while( p->next_person != tail ){
                    if(p->money > p->next_person->money){
                        temp = p->next_person;
                        prep->next_person= p->next_person;
                        p->next_person = p->next_person->next_person;
                        prep->next_person->next_person = p;
                        p = temp;
                    }
                    // �ڵ����
                    p = p->next_person;
                    prep = prep->next_person;
                }
                tail = p;
            }// ��һ��while
            show = head_person->next_person;
            for(;show!=NULL;show=show->next_person){
                for(i=0;strlen(names_present[i]) != 0;i++){
                    if(strcmp(names_present[i],show->name) == 0)
                        printf("\n\t%s\t%s\t%.1lf\t%s", show->date, show->name, show->money, show->remarks);
                }
            }
        }//if select == 2
        system("pause");

    }



}

























