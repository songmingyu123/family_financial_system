#include"family_money_head.h"

struct person *recycle_bin(struct person *head_person, struct person *head_recycle_bin)//����վ
{

	while(1){
        char ch;
		int select=-1;
		int i,j;//j ��¼��ǰ�Ľڵ�������������ʱ��֤������ȷ
		struct person *p, *p1;
		struct person *q;
		struct person *a[30];
		system("cls");
		printf("\n\t-------------------    ����վ    --------------------------\n\t");
		printf("Esc:���ز˵�\n\t1.��ջ���վ\n\t2.�ָ�����\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_person;
		}
		else if (ch == '1'){

			q = p = head_recycle_bin->next_person;
			while (p) {
				q = p;
				p = q->next_person;
				free(q);
				q = NULL;
			}
			head_recycle_bin->next_person = NULL;
			printf("����վ������");
			system("pause");
		}
		else if (ch == '2'){
			system("cls");
			printf("\n\t-------------------    ����վ    --------------------------\n\t");
			p = head_recycle_bin->next_person;
			for (i = 0; p != NULL; p = p->next_person){
				a[i] = p;//�������еĽڵ�ŵ��ṹ��ָ��������
				i++;
			}
			j = i;
			i = 0;
			for (p = head_recycle_bin->next_person; p!=NULL && i<j; p = p->next_person){
				printf("\n\t%d. ", i);
				if (p->genre == 1){
					printf("����");
				}
				else
					printf("֧��");
				printf("\t%s\t%s\t%.1lf\t%s", p->name, p->date, p->money, p->remarks);
				i++;
			}
			printf("\n\t������Ҫ�ָ�������ѡ��\n\t���ɶ�ѡ��ÿ��ѡ���ÿո�ֿ�����������ԡ�-1����β����");
			while (scanf("%d", &select), select >= 0){
				q = head_person;
				p = head_recycle_bin->next_person;
				p1 = head_recycle_bin;
				for (; p != NULL;p=p->next_person){
					if (a[select] == p){
                        p1->next_person = p->next_person;
						for (; q->next_person != NULL;){
							q = q->next_person;
						}
						q->next_person = (struct person *)malloc(LEN_person);
						q->next_person->genre = p->genre;
						strcpy(q->next_person->date,p->date);
						strcpy(q->next_person->name,p->name);
						q->next_person->money = p->money;
						strcpy(q->next_person->remarks,p->remarks);
                        q->next_person->next_person = NULL;
						printf("\n\t���ݻָ����\n");
                        system("pause");
						break;
					}
					p1 = p;
				}
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

struct person *recycle(struct person *p, struct person *head_recycle_bin)//���սڵ㺯��
{
	struct person *p1;
	p1 = head_recycle_bin;
	for (; p1->next_person != NULL;){
		p1 = p1->next_person;
	}
	if (p1->next_person == NULL){
		p1->next_person = p;
		p1->next_person->next_person = NULL;
		//14:39��   p->next_person = NULL;
	}
	printf("\n\tɾ���ɹ���\n\t");
	system("pause");
	return head_recycle_bin;
}
void free_space(struct person *p) //�ͷſռ�
{

}

struct person *load_recycle(struct person *head_recycle_bin, char(*account_name_recycle))//��ȡ�ļ��еĻ���վ����
{
	FILE *fp;
	struct person *p1, *p2;
	fp = fopen(account_name_recycle, "a+b");
	if (fp == NULL){
		printf("�ļ��򿪴���load_recycle�����С�\n\t");
		system("pause");
		exit(0);
	}
	head_recycle_bin = (struct person *)malloc(LEN_person);
	head_recycle_bin->next_person = NULL;
	while (p1 = (struct person *)malloc(LEN_person), fread(p1, LEN_person, 1, fp) == 1){
		if (head_recycle_bin->next_person == NULL){
			head_recycle_bin->next_person = p1;
		}
		else{
			p2->next_person = p1;
		}
		p2 = p1;
	}
	p1->next_person = NULL;
	fclose(fp);
	printf("\n\t����վ���ݶ�ȡ�ɹ�");
	if(head_recycle_bin->next_person == NULL){
        printf("\n\t��ǰ����վû������\n\t");
	}
	system("pause");
	return head_recycle_bin;
}


int save_recycle(struct person *head_recycle_bin, char(*account_name_recycle))//��ȡ�ļ��еĻ���վ����
{
	FILE *fp;
	struct person *p;
	p = head_recycle_bin;
	fp = fopen(account_name_recycle, "wb");
	if (fp == NULL){
		printf("\n\t�ļ���ʧ�ܣ���save_recycle�ļ��С������˳�����\n\t");
		system("pause");
		exit(0);
	}
	for (p = p->next_person; p != NULL;){
		fwrite(p, LEN_person, 1, fp);
		p = p->next_person;
	}
	printf("����վ���ݱ���ɹ���\n");
	fclose(fp);
	return 0;
}






