#include"family_money_head.h"

int cover_function(char(*names_present)[20])//主菜单界面函数
{
	int select = -1;//选择功能
	int i;
	while (1){
		system("cls");
		printf("\t------------------------           家庭财务管理系统         ----------------------\n\n");
		printf("\t-----------------            收入                 支出           -----------------\n\n");
		printf("\t-----------------        1.添加收入           5.添加支出         -----------------\n");
		printf("\t-----------------        2.删除收入           6.删除支出         -----------------\n");
		printf("\t-----------------        3.查询收入           7.查询支出         -----------------\n");
		printf("\t-----------------        4.修改收入           8.修改支出         -----------------\n\n");
		printf("\t-----------------                   9.回收站                     -----------------\n");
		printf("\t-----------------                  10.财务统计                   -----------------\n");
		printf("\t-----------------                  11.成员模式                   -----------------\n");
		printf("\t-----------------                  12.注销账户                   -----------------\n");
		printf("\t-----------------                  13.导出数据                   -----------------\n");
		printf("\t-----------------                  14.排序                       -----------------\n");
		printf("\t-----------------                  15.退出程序                   -----------------\n");
		printf("\n\t当前为：");//成员模式说明待完善
		for (i = 0; strlen(names_present[i]) != 0; i++){
			printf("%s   ", names_present[i]);
		}
		printf("模式");
		printf("\n\n\t请选择:");
		scanf("%d", &select);
		if (select >= 1 && select <= 14)
			return select;
		else{
			printf("\n\t选项输入错误，请重新输入。\n\t");
			system("pause");
			continue;
		}

	}

}

struct person *load_data(struct person *head_person, char *account_name)   //读取财务信息函数
{
	FILE *fp_data;
	struct person *p1, *p2;
	fp_data = fopen(account_name, "ab+");
	if (fp_data == NULL){
		printf("文件打开错误，load_data函数中。按任意键退出程序\n");
		system("pause");
		exit(0);
	}
	head_person = (struct person *)malloc(LEN_person);
	// TODO (Leo#1#): 读取文件时会发生错误，可能时account_name没有弄好，现在可能已经弄好了，account_name已经转化为字符指针
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
		printf("\n\t当前没有财务数据\n\t");
		system("pause");
		return head_person;
	}
	else{
		printf("\n\t读取数据成功。\n");
		return head_person;
	}
}

struct person *add_data(struct person *head_person, char(*names_present)[20], enum Type flag) //添加收支函数
{
	struct person *p, *p0;
	char style[2][10] = { "收入", "支出" };
	char nowtime[20] = { 0 };
	char ch;
	int t;//判断:0.income  1.payout
	int i = 0, j = 0;//j 日期判断函数返回结果，0错误，1正确
	int select;//选择要添加成员的序号
	int select_add = 0;//判断是否继续添加财务收支数据
	double money;
	if (flag == income)
		t = 0;
	else
		t = 1;
	while (1){
		system("cls");
		printf("\n\t-----------------------  添加%s   --------------------------\n", style[t]);
		printf("\n\t当前成员模式：");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("模式\n");
		printf("\n\tEsc:返回菜单\n\t任意键：进入\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_person;
		}
		system("cls");
		printf("\n\t-----------------------  添加%s   --------------------------\n", style[t]);
        printf("\n\t当前成员模式：");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("模式\n");
		p = head_person;
		SYSTEMTIME stLocal;
		GetLocalTime(&stLocal);
		wsprintf(nowtime,TEXT("%u-%u-%u"),stLocal.wYear,stLocal.wMonth,stLocal.wDay);
		printf("\n\t%s日期：%s", style[t], nowtime);
		printf("\n\t是否使用该日期？\n\t1.是\n\t2.否\n\t");
		scanf("%d", &i);
		while (1){
			if (i == 2){
				system("cls");
				printf("\n\t-----------------------  添加%s   --------------------------\n", style[t]);
                printf("\n\t当前成员模式：");
                for(i=0;strlen(names_present[i]) != 0;i++){
                    printf(" %s\t",names_present[i]);
                }
                printf("模式\n");
				printf("\n\t格式参考：2017-5-1");
				printf("\n\t请输入日期：");
				fflush(stdin);
				gets(nowtime);
				j = judge_time(nowtime);
				if (j == 0){
					printf("\n\t日期输入有误，请重新输入。\n\t");
					system("pause");
					continue;
				}
			}
			else
				break;
		}
		p0 = (struct person *)malloc(LEN_person);
		system("cls");
		printf("\n\t-----------------------  添加%s   --------------------------\n", style[t]);
        printf("\n\t当前成员模式：");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("模式\n");
		printf("\n\t%s日期：%s", style[t], nowtime);
		strcpy(p0->date, nowtime);
		p0->genre = flag;
		printf("\t请选择要添加的成员名字：");
		for (i = 0; strlen(names_present[i]) != 0; i++){
			printf("\n\t%d.%s  ", i, names_present[i]);
		}
		printf("\n\t输入序号：");
		scanf("%d", &select);
		strcpy(p0->name, names_present[select]);
		printf("\n\t请输入金额：");
		scanf("%lf", &money);
		p0->money = money;
		printf("\n\t请输入备注：");
		fflush(stdin);
		gets(p0->remarks);
		for (; p->next_person != NULL;){
			p = p->next_person;
		}
		if (p->next_person == NULL){
			p->next_person = p0;
			p0->next_person = NULL;
			printf("\n\t添加成功。\n");
			system("pause");
		}
		printf("\n\t是否继续添加收支?\n\t1.是\n\t2.否\n\t");
		scanf("%d", &select_add);
		if (select_add == 1)
			continue;
		else
			break;
	}
	return head_person;
}

struct person *delete_data(struct person *head_person, char(*names_present)[20], enum Type flag, struct person *head_recycle_bin)//删除收支
{
	while (1){
		char style[2][10] = { "收入", "支出" };
		struct person *a[30];//接收结构体指针数组
		struct person *p1, *p2;
		int select;//要删除的选项编号
		int t;//判断收入或支出
		int i;
		char ch;
		if (flag == income)
			t = 0;
		else
			t = 1;
		system("cls");
		printf("\n\t-----------------------  删除%s   --------------------------\n", style[t]);
        printf("\n\t当前成员模式：");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("模式\n");
		printf("\tEsc:返回菜单\n\t任意键：进入\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_person;
		}
		system("cls");
		printf("\n\t-----------------------  删除%s   --------------------------\n", style[t]);
		printf("\n\t当前成员模式：");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("模式\n");
		just_search(head_person, names_present, flag, a);//查找并展示数据，且返回结构体指针数组
		printf("\n\t请输入要删除的数据的编号(可多选，每个选项用空格隔开，输入“-1”结束)：\n\t");

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
				printf("\n\t你输入的序号存在错误，删除被迫终止，部分数据可能已经删除，请主动核实。\n\t");
				system("pause");
				break;
			}
		}
		printf("\n\t是否继续删除?\n\t1.是\n\t2.否\n\t");
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

struct person *update_data(struct person *head_person, char(*names_present)[20], enum Type flag)//修改收支
{
	while (1){
		char style[2][10] = { "收入", "支出" };
		char date[20];
		struct person *a[30];//接收结构体指针数组
		struct person *p1;
		double money;
		int select;//要修改的选项编号
		int t;//判断收入或支出
		int i;
		char ch;
		if (flag == income)
			t = 0;
		else
			t = 1;
		system("cls");
		printf("\n\t-----------------------  修改%s   --------------------------\n", style[t]);
		printf("\n\t当前成员模式：");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("模式\n");
		printf("\tEsc:返回菜单\n\t任意键：进入\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_person;
		}
		system("cls");
		printf("\n\t-----------------------  修改%s   --------------------------\n", style[t]);
		printf("\n\t当前成员模式：");
		for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
		}
		printf("模式\n");
		just_search(head_person, names_present, flag, a);//查找并展示数据，且返回结构体指针数组
		printf("\n\t请输入要修改的数据的编号(单选)：\n\t");
		while (scanf("%d", &select), select >= 0){
			p1 = head_person;
			for (p1 = p1->next_person; p1 != NULL; p1 = p1->next_person){
				if (a[select] == p1){
					system("cls");
					printf("\n\t-----------------------  修改%s   --------------------------\n", style[t]);
					printf("\n\t当前成员模式：");
                    for(i=0;strlen(names_present[i]) != 0;i++){
                        printf(" %s\t",names_present[i]);
                    }
                    printf("模式\n");
					printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p1->date, p1->name, p1->money, p1->remarks);
					printf("\n\t请输入要修改的选项：1.日期 2.姓名 3.金额 4.备注\n\t(每次输入一个选项，以“-1”结束)");
					printf("\n\t请输入要修改的选项(单选)：");
					while (scanf("%d", &select), select>0){
						if (select == 1){
							while (1){
								printf("\n\t请输入新的日期(格式：2017-5-6)：");
								fflush(stdin);
								gets(date);
								if (judge_time(date) == 0){
									printf("\n\t日期格式输入错误，请严格按照格式输入日期，这是为了你好。。。\n\t");
									system("pause");
									system("cls");
									printf("\n\t-----------------------  修改%s   --------------------------\n", style[t]);
									printf("\n\t当前成员模式：");
                                    for(i=0;strlen(names_present[i]) != 0;i++){
                                        printf(" %s\t",names_present[i]);
                                    }
                                    printf("模式\n");
									printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p1->date, p1->name, p1->money, p1->remarks);
									printf("\n\t请输入要修改的选项：1.日期 2.姓名 3.金额 4.备注\n\t(每次输入一个选项，以“-1”结束)");
									printf("\n\t请输入要修改的选项(单选)：");
									continue;
								}
								else{
									strcpy(p1->date, date);
									printf("\n\t日期修改成功\n\t");
									system("pause");
									system("cls");
									printf("\n\t-----------------------  修改%s   --------------------------\n", style[t]);
									printf("\n\t当前成员模式：");
                                    for(i=0;strlen(names_present[i]) != 0;i++){
                                        printf(" %s\t",names_present[i]);
                                    }
                                    printf("模式\n");
									printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p1->date, p1->name, p1->money, p1->remarks);
									printf("\n\t请输入要修改的选项：1.日期 2.姓名 3.金额 4.备注\n\t(每次输入一个选项，以“-1”结束)");
									printf("\n\t请输入要修改的选项(单选)：");
									break;
								}
							}
						}
						if (select == 2){
							printf("\n\t请输入新的姓名的序号：");
							for (i = 0; strlen(names_present[i]) != 0; i++){
								printf("\n\t%d.%s  ", i, names_present[i]);
							}
							printf("\n\t");
							scanf("%d", &select);
							strcpy(p1->name, names_present[select]);
							printf("\n\t名字修改成功。\n\t");
							system("pause");
							system("cls");
							printf("\n\t-----------------------  修改%s   --------------------------\n", style[t]);
							printf("\n\t当前成员模式：");
                            for(i=0;strlen(names_present[i]) != 0;i++){
                                printf(" %s\t",names_present[i]);
                            }
                            printf("模式\n");
							printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p1->date, p1->name, p1->money, p1->remarks);
							printf("\n\t请输入要修改的选项：1.日期 2.姓名 3.金额 4.备注\n\t(每次输入一个选项，以“-1”结束)");
							printf("\n\t请输入要修改的选项(单选)：");
						}
						if (select == 3){
							printf("\n\t请输入新的金额：");
							scanf("%lf", &money);
							p1->money = money;
							printf("\n\t金额修改成功。\n\t");
							system("pause");
							system("cls");
							printf("\n\t-----------------------  修改%s   --------------------------\n", style[t]);
							printf("\n\t当前成员模式：");
                            for(i=0;strlen(names_present[i]) != 0;i++){
                                printf(" %s\t",names_present[i]);
                            }
                            printf("模式\n");
							printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p1->date, p1->name, p1->money, p1->remarks);
							printf("\n\t请输入要修改的选项：1.日期 2.姓名 3.金额 4.备注\n\t(每次输入一个选项，以“-1”结束)");
							printf("\n\t请输入要修改的选项(单选)：");
						}
						if (select == 4){
							printf("\n\t请输入新的备注：");
							scanf("%s", p1->remarks);
							printf("\n\t备注修改成功。\n\t");
							system("pause");
							system("cls");
							printf("\n\t-----------------------  修改%s   --------------------------\n", style[t]);
							printf("\n\t当前成员模式：");
                            for(i=0;strlen(names_present[i]) != 0;i++){
                                printf(" %s\t",names_present[i]);
                            }
                            printf("模式\n");
							printf("\n\t%s\t%s\t%.1lf\t%s\n\t", p1->date, p1->name, p1->money, p1->remarks);
							printf("\n\t请输入要修改的选项：1.日期 2.姓名 3.金额 4.备注\n\t(每次输入一个选项，以“-1”结束)");
							printf("\n\t请输入要修改的选项(单选)：");
						}
					}//修改找到节点的选项wihle结束
					if (select < 0)
						break;//如果选择-1则结束修改
				}//找到if结束
				if (select < 0)
					break;//如果选择-1则结束修改
			}//离开选择成员的while
			if (select < 0)
				break;//如果选择-1则结束修改
			if (p1 == NULL){
				printf("\n\t你输入的序号存在错误，修改被迫终止，部分数据可能已经修改，请核实。\n\t");
				system("pause");
				break;
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

int search_data(struct person *head_person, char(*names_present)[20], enum Type flag)//查询函数
{
	while (1){
		char style[2][10] = { "收入", "支出" };
		char remark[50] = { 0 };
		char name[20] = { 0 };
		char ch;
		int i;
		int have_date = 0, have_name = 0, have_money = 0, have_remark = 0, have_flag = 1;//判断是否选择了选项，
		int judge_date = 0, judge_name = 0, judge_money = 0, judge_remark = 0, judge_flag = 0;//判断是否找到节点
		int t;//判断:0.income  1.payout
		int select;//选择查询条件的序号
		int select_serch = 0;//判断是否继续查找财务收支数据
		int select_member = 0;//选择要查询的成员序号
		double money_min = 0, money_max = 999999999;
		char date[20] = { 0 };//获取日期
		struct person *p;
		struct person *q;
		if (flag == income)
			t = 0;
		else
			t = 1;
		p = head_person;

		system("cls");
		printf("\n\t-----------------------  查询%s   --------------------------\n", style[t]);
		printf("\n\t当前成员模式：");
        for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
        }
        printf("模式\n");
		printf("\tEsc:返回菜单\n\t任意键：进入\n\t");
		fflush(stdin);
		ch = getch();
		if (ch == 27){
			return head_person;
		}
		system("cls");
		printf("\n\t-----------------------  查询%s   --------------------------\n", style[t]);
        printf("\n\t当前成员模式：");
        for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
        }
        printf("模式\n");
		printf("\n\t请选择查询条件\n\t(可多选,每次输入一个编号后回车输入条件，所有数字输入完后输入“-1”结束)):");
		printf("\n\t1.日期\t2.姓名\t3.金额\t4.备注\t5.显示全部数据\n\t");
		printf("请输入一个选项：");
		fflush(stdin);
		while (scanf("%d", &select), select>0){
			//根据日期条件查询开始
			if (select == 1){
				have_date = 1;
				printf("\n\t请输入日期  (格式 2017-5-1 或 2017-5)：");
				fflush(stdin);
				gets(date);
				printf("\n\t请输入一个选项：");
			}
			//根据日期条件查询结束
			//根据姓名条件查询开始
			else if (select == 2){
				have_name = 1;
				printf("\n\t请选择成员：\n");
				printf("\n\t");
				for (i = 0; strlen(names_present[i]) != 0; i++){
					printf("%d.%s  ", i, names_present[i]);
				}
				printf("\n\t");
				scanf("%d", &select_member);//names_present[select_member]用于查找链表
				strcpy(name, names_present[select_member]);
				printf("\n\t请输入一个选项：");
			}
			//根据姓名条件查询结束
			//根据金额范围查找开始
			else if (select == 3){
				have_money = 1;
				printf("\n\t请输入金额范围(格式:200~1000)：");
				scanf("%lf~%lf", &money_min, &money_max);
				printf("\n\t请输入一个选项：");
			}
			//根据金额范围查找结束
			else if (select == 4){
				have_remark = 1;
				printf("\n\t请输入备注信息：");
				fflush(stdin);
				gets(remark);
				printf("\n\t请输入一个选项：");
			}
			else if (select == 5){
				q = head_person;
				for(q=q->next_person;q!=NULL;q=q->next_person){
                    if(q->genre == 1){
                        printf("\n\t收入：");
                    }
                    else{
                        printf("\n\t支出：");
                    }
                    printf("\t%s\t%s\t%.1lf\t%s\n\t",q->date,q->name,q->money,q->remarks);
                }
                system("pause");
                printf("\n\t请输入一个选项：");
            }   //条件查询while结束,得到所需要的所有条件。接下来，寻找链表中，符合条件的所有节点
       }        //从链表中查找符合条件的节点

        //寻找节点
        judge_remark = 0;
        judge_money = 0;
        judge_date = 0;
        judge_name = 0;
        p = head_person;
        printf("\n\t------------------    查询结果     -----------------------\n");
        int judge_member1 = 0;//当查询时不加入名字条件，则系统自动判断找到符合输入的条件的节点，是否属于当前成员模式中的成员
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
                    break;//在整条链表中查找符合条件的节点，知道这个if成立，就跳出循环输入，否则就一直循环到 p == NULL 跳出循环
                }

                if (p == NULL){
                    break;
                }
            }
            //查找一个节点数据结束

            if (p != NULL){
                for (i = 0; strlen(names_present[i]) != 0; i++){
                    if (strcmp(names_present[i], p->name) == 0){
                        judge_member1 = 1;//判断是否输入当前成员模式的成员
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
        printf("\n\t是否继续查找?\n\t1.是\n\t2.否\n\t");
        scanf("%d", &select_serch);
        if (select_serch == 1){
            continue;
        }
        else
            break;
    }
    return 0;
}

void calculate(struct person *head_person,char(*names_present)[20],char(*names)[20]) //计算
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
        printf("\n\t--------------------    财务统计    ------------------------");
        printf("\n\t当前成员模式：");
        for(i=0;strlen(names_present[i]) != 0;i++){
            printf(" %s\t",names_present[i]);
        }
        printf("模式\n");
        printf("\n\t当前全家结余：%.1lf",surplus);

        printf("\n\t当前为：");
        for (i = 0; strlen(names_present[i]) != 0; i++){
            printf("%s   ", names_present[i]);
        }
        printf("模式");

        printf("\n\t请选择查询条件\n\t(可多选,每次输入一个编号后回车输入条件，所有数字输入完后输入“-1”结束)):");
        printf("\n\t1.日期范围\t2.姓名\t3.显示所有");
        printf("\n\t如果不选择姓名，默认选择当前成员模式的所有成员。");
        printf("\n\t请输入一个选项：");
        fflush(stdin);
        while (scanf("%d", &select), select>0){
            //根据日期条件查询开始
            if (select == 1){
                have_date = 1;
                printf("\n\t请输入起始日期  (格式 2017-5-1 或 2017-5)：");
                fflush(stdin);
                gets(date_beginning);
                printf("\n\t请输入结束日期  (格式 2017-5-1 或 2017-5)：");
                fflush(stdin);
                gets(date_finish);

            }
            //根据日期条件查询结束
            //根据姓名条件查询开始
            else if (select == 2){
                have_name = 1;
                printf("\n\t请选择成员：\n");
                printf("\n\t");
                for (i = 0; strlen(names_present[i]) != 0; i++){
                    printf("%d.%s  ", i, names_present[i]);
                }
                printf("\n\t");
                scanf("%d", &select);//names_present[select_member]用于查找链表
                strcpy(name, names_present[select]);
            }
            //根据姓名条件查询结束
            //显示所有
            else if (select == 3){
                for(p = head_person->next_person;p!=NULL;p=p->next_person){
                    for(i = 0; strlen(names_present[i]) != 0; i++){
                        if(strcmp(p->name,names_present[i]) == 0){
                            if(p->genre == 1){
                                printf("\n\t收入  ");
                            }
                            else
                                printf("\n\t支出  ");
                            printf("\t%s\t%s\t%.1lf\t%s",p->date,p->name,p->money,p->remarks);
                        }
                    }
                }

                //当前每个成员的收支数据
                for(i = 0; strlen(names_present[i]) != 0; i++){
                    compute(head_person,names_present[i]);
                }

                //当前每个成员的收支数据结束
            }
            //显示所有结束
            printf("\n\t请输入一个选项：");
        }//条件查询while结束,得到所需要的所有条件。接下来，寻找链表中，符合条件的所有节点
        //从链表中查找符合条件的节点
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
                        printf("\n\t收入  ");
                        in = in+(p->money);
                    }
                    else{
                        printf("\n\t支出  ");
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
        printf("\n\t根据条件得出：收入：%.1lf   支出：%.1lf   结余：%.1lf\n\t",in,out,surplus);
        system("pause");
        printf("\n\t是否继续统计?\n\t1.是\n\t2.否\n\t");
        scanf("%d", &select);
        if (select == 1)
            continue;
        else
            break;
    }

}


int save_data(struct person *head_person, char *account_name)//保存函数，每次从功能函数返回到主菜单之前，需要保存的就调用
{
	FILE *fp;
	struct person *p;
	p = head_person;
	fp = fopen(account_name, "wb");
	if (fp == NULL){
		printf("\n\t文件打开失败，在save_data文件中。即将退出程序\n\t");
		system("pause");
		exit(0);
	}

	for (p = p->next_person; p != NULL;){
		fwrite(p, LEN_person, 1, fp);
		p = p->next_person;
	}
	printf("数据保存成功。\n");
	fclose(fp);
	return 0;
}


int judge_time(char *nowtime)//判断用户自己输入的日期
{
	int i, j = 0, time, time_zong = 0, month;
	/*
	i,用于循环。代码位置：12行
	j,用于判断当前是否为闰年。代码位置：15~19行，44~50行。是为1，否为0。
	time,保存输入字符串的每一位数字，time_zong,计算年，月，日分别的日期。35，36行。
	month,保存用户输入的月份，退出13行for语句后判断号数，要考虑月份。代码位置：30行，39~60行。
	*/
	for (i = 0; nowtime[i] != '\0'; i++){
		if (nowtime[i] == '-'){  //2017-4-29，获取‘-’前面的2017和4两个数字进行判断
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
		time_zong = time_zong * 10 + time;  //计算日期数字
	}
	/*
	以上为计算判断年份和月份是否正确
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



struct person *just_search(struct person *head_person, char(*names_present)[20], enum Type flag, struct person *a[])//只能查找数据，并把找到的节点地址给数组，返回地址
{
	char style[2][10] = { "收入", "支出" };
	char remark[50] = { 0 };
	char name[20] = { 0 };
	int i;
	int have_date = 0, have_name = 0, have_money = 0, have_remark = 0, have_flag = 1;//判断是否选择了选项，
	int judge_date = 0, judge_name = 0, judge_money = 0, judge_remark = 0, judge_flag = 0;//判断是否找到节点
	int t;//判断:0.income  1.payout
	int select;//选择查询条件的序号
	int select_member = 0;//选择要查询的成员序号
	double money_min = 0, money_max = 999999999;
	char date[20] = { 0 };//获取日期
	struct person *p;
	struct person *q;
	if (flag == income)
		t = 0;
	else
		t = 1;
	p = head_person;
	printf("\n\t-----------------------  查询%s   --------------------------\n", style[t]);
    printf("\n\t当前成员模式：");
    for(i=0;strlen(names_present[i]) != 0;i++){
        printf(" %s\t",names_present[i]);
    }
    printf("模式\n");
	printf("\n\t请选择查询条件\n\t(可多选,每次输入一个编号后回车输入条件，所有数字输入完后输入“-1”结束)):");
	printf("\n\t1.日期\t2.姓名\t3.金额\t4.备注\t5.显示全部数据\n\t");
	printf("请输入一个选项：");
	fflush(stdin);
	while (scanf("%d", &select), select>0){
		//根据日期条件查询开始
		if (select == 1){
			have_date = 1;
			printf("\n\t请输入日期  (格式 2017-5-1 或 2017-5)：");
			fflush(stdin);
			gets(date);
		}
		//根据日期条件查询结束
		//根据姓名条件查询开始
		else if (select == 2){
			have_name = 1;
			printf("\n\t请选择成员：\n");
			printf("\n\t");
			for (i = 0; strlen(names_present[i]) != 0; i++){
				printf("%d.%s  ", i, names_present[i]);
			}
			printf("\n\t");
			scanf("%d", &select_member);//names_present[select_member]用于查找链表
			strcpy(name, names_present[select_member]);
		}
		//根据姓名条件查询结束
		//根据金额范围查找开始
		else if (select == 3){
			have_money = 1;
			printf("\n\t请输入金额范围(格式:200~1000)：");
			scanf("%lf~%lf", &money_min, &money_max);
		}
		//根据金额范围查找结束
		else if (select == 4){
			have_remark = 1;
			printf("\n\t请输入备注信息：");
			fflush(stdin);
			gets(remark);
		}
		else if (select == 5){
            q = head_person;
            for(q=q->next_person;q!=NULL;q=q->next_person){
                if(q->genre == 1){
                    printf("\n\t收入：");
                }
                else{
                    printf("\n\t支出：");
                }
                printf("\t%s\t%s\t%.1lf\t%s\n\t",q->date,q->name,q->money,q->remarks);
            }
            system("pause");
            printf("\n\t请输入一个选项：");
		}
		printf("\n\t请输入一个选项：");
	}//条件查询while结束,得到所需要的所有条件。接下来，寻找链表中，符合条件的所有节点
	//从链表中查找符合条件的节点

	//寻找节点
	judge_remark = 0;
	judge_money = 0;
	judge_date = 0;
	judge_name = 0;
	p = head_person;
	//可同时删除多个数据条件准备
	int a_i = 0;


	int judge_member1 = 0;//当没有选择姓名进行查找时，系统自动判断符合条件的节点是否为当前你的成员模式中的成员
	printf("\n\t------------------    查询结果     -----------------------\n");
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
		//查找一个节点数据结束

		if (p != NULL){
			for (i = 0; strlen(names_present[i]) != 0; i++){
				if (strcmp(names_present[i], p->name) == 0){
					judge_member1 = 1;//判断是否输入当前成员模式的成员
					break;
				}
			}
			if (judge_member1 == 0){
				continue;
			}
			printf("\n\t%d. %s\t%s\t%.1lf\t%s\n\t", a_i, p->date, p->name, p->money, p->remarks);
			a[a_i] = p;//把找到的节点地址保存到数组中
			a_i++;//数组下标+1
		}
		else
			break;
	}
	return *a;
}


void compute(struct person *head_person,char (*names_present)[20])//计算节点中的数据
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
    printf("\n\t%s   收入：%.1lf   支出：%.1lf   结余：%.1lf",names_present,in,out,surplus);
}


void save_excel(struct person *head_person,char (*account_name))  //保存到excel
{
    FILE *fp;
	struct person *p1 = NULL;
	char account_num[20]={0};
	double sum_in=0,sum_out=0;
	strcpy(account_num,account_name);
	fp = fopen(strcat(account_num,".csv"),"w");
	if(fp == NULL){
		printf("保存文件时打开文件失败，在save_excel文件中。\n");
		exit(0);
	}
	p1 = head_person->next_person;
	fprintf(fp,"收支,姓名,日期,金额,备注\n");
	while(p1 != NULL){
        if(p1->genre == 1){
            fprintf(fp,"收入,");
            sum_in = sum_in+p1->money;
        }
        else{
            fprintf(fp,"支出,");
            sum_out = sum_out+p1->money;
        }
		fprintf(fp,"%s,%s,%.1lf,%s\n",p1->name,p1->date,p1->money,p1->remarks);
		p1 = p1->next_person;
	}
	fprintf(fp,"结余,%.1lf",sum_in-sum_out);
	printf("导出成功。\n");
	system("pause");
	fclose(fp);
}

struct person *sort_data(struct person *head_person,char (*names_present)[20])//排序函数
{
    char ch;
    int i;
    int select;
    struct person *p, *prep, *temp, *tail;
    struct person *show;
    system("cls");
    printf("\n\t-----------------------  排序   --------------------------\n");
    printf("\n\t当前成员模式：");
    for(i=0;strlen(names_present[i]) != 0;i++){
        printf(" %s\t",names_present[i]);
    }
    printf("模式\n");
    printf("\tEsc:返回菜单\n\t任意键：进入\n\t");
    fflush(stdin);
    ch = getch();
    if (ch == 27){
        return head_person;
    }
    system("cls");
    printf("\n\t-----------------------  排序   --------------------------\n");
    printf("\n\t当前成员模式：");
    for(i=0;strlen(names_present[i]) != 0;i++){
        printf(" %s\t",names_present[i]);
    }
    printf("模式\n");
    while(1){
        printf("\t请选择排序方式:");
        printf("\n\t1.日期");
        printf("\n\t2.金额\n\t3.退出\n\t");
        scanf("%d",&select);
        if(select == 3)
            break;
        if(select!=1 && select!=2){
            printf("\n\t选项输入错误，请重新输入");
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
                    // 节点后移
                    p = p->next_person;
                    prep = prep->next_person;
                }
                tail = p;
            }// 第一个while
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
                    // 节点后移
                    p = p->next_person;
                    prep = prep->next_person;
                }
                tail = p;
            }// 第一个while
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

























