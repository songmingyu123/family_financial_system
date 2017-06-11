#include"family_money_head.h"

struct person *recycle_bin(struct person *head_person, struct person *head_recycle_bin)//回收站
{

	while(1){
        char ch;
		int select=-1;
		int i,j;//j 记录当前的节点个数，在输出的时候保证数量正确
		struct person *p, *p1;
		struct person *q;
		struct person *a[30];
		system("cls");
		printf("\n\t-------------------    回收站    --------------------------\n\t");
		printf("Esc:返回菜单\n\t1.清空回收站\n\t2.恢复数据\n\t");
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
			printf("回收站清空完成");
			system("pause");
		}
		else if (ch == '2'){
			system("cls");
			printf("\n\t-------------------    回收站    --------------------------\n\t");
			p = head_recycle_bin->next_person;
			for (i = 0; p != NULL; p = p->next_person){
				a[i] = p;//把链表中的节点放到结构体指针数组中
				i++;
			}
			j = i;
			i = 0;
			for (p = head_recycle_bin->next_person; p!=NULL && i<j; p = p->next_person){
				printf("\n\t%d. ", i);
				if (p->genre == 1){
					printf("收入");
				}
				else
					printf("支出");
				printf("\t%s\t%s\t%.1lf\t%s", p->name, p->date, p->money, p->remarks);
				i++;
			}
			printf("\n\t请输入要恢复的数据选项\n\t（可多选，每个选项用空格分开，输入完成以“-1”结尾）：");
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
						printf("\n\t数据恢复完成\n");
                        system("pause");
						break;
					}
					p1 = p;
				}
			}
		}
		printf("\n\t是否继续查找?\n\t1.是\n\t2.否\n\t");
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

struct person *recycle(struct person *p, struct person *head_recycle_bin)//回收节点函数
{
	struct person *p1;
	p1 = head_recycle_bin;
	for (; p1->next_person != NULL;){
		p1 = p1->next_person;
	}
	if (p1->next_person == NULL){
		p1->next_person = p;
		p1->next_person->next_person = NULL;
		//14:39分   p->next_person = NULL;
	}
	printf("\n\t删除成功。\n\t");
	system("pause");
	return head_recycle_bin;
}
void free_space(struct person *p) //释放空间
{

}

struct person *load_recycle(struct person *head_recycle_bin, char(*account_name_recycle))//读取文件中的回收站数据
{
	FILE *fp;
	struct person *p1, *p2;
	fp = fopen(account_name_recycle, "a+b");
	if (fp == NULL){
		printf("文件打开错误，load_recycle函数中。\n\t");
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
	printf("\n\t回收站数据读取成功");
	if(head_recycle_bin->next_person == NULL){
        printf("\n\t当前回收站没有数据\n\t");
	}
	system("pause");
	return head_recycle_bin;
}


int save_recycle(struct person *head_recycle_bin, char(*account_name_recycle))//读取文件中的回收站数据
{
	FILE *fp;
	struct person *p;
	p = head_recycle_bin;
	fp = fopen(account_name_recycle, "wb");
	if (fp == NULL){
		printf("\n\t文件打开失败，在save_recycle文件中。即将退出程序\n\t");
		system("pause");
		exit(0);
	}
	for (p = p->next_person; p != NULL;){
		fwrite(p, LEN_person, 1, fp);
		p = p->next_person;
	}
	printf("回收站数据保存成功。\n");
	fclose(fp);
	return 0;
}






