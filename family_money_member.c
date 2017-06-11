#include"family_money_head.h"
int save_member(char(*names)[20], char(*account_name_member))//保存成员函数
{
	FILE *fp;
	int i = 0;
	fp = fopen(account_name_member, "wb");
	if (fp == NULL){
		printf("文件打开错误，save_member函数中。\n");
		system("pause");
		exit(0);
	}
	for (i = 0; strlen(names[i]) != 0; i++){
		fwrite(names[i], sizeof(names[i]), 1, fp);
	}
	printf("文件保存成功。");
	fclose(fp);
	return 0;
}

int load_member(char(*names)[20], char(*account_name_member), char(*names_present)[20])//读取成员函数
{
	FILE *fp;
	int i = 0;
	fp = fopen(account_name_member, "a+b");
	if (fp == NULL){
		printf("文件打开错误，load_member函数中。\n\t");
		system("pause");
		exit(0);
	}
	while (fread(names[i], 20, 1, fp) == 1){
		i++;
	}
	printf("读取结束。\n");
	for (i = 0; strlen(names[i]) != 0; i++){
		strcpy(names_present[i], names[i]);
	}
	return 0;
}



char *member(char(*names)[20], char(*names_present)[20],struct person *head_recycle_bin,struct person *head_person)  //成员函数
{
	while (1){
		int i = 0;
		int number;
		int j = 0, k = 0;//j记录当前账号中所有的成员个数,k记录当前成员模式中的成员个数
		char ch;
		for (i = 0; strlen(names[i]) != 0;){
			i++;
		}
		j = i;
		for (k = 0; strlen(names_present[k]) != 0;){
			k++;
		}
		system("cls");
		printf("\t----------------------    成员模式     -----------------------------\n");
		if (j == 0){//这个if，当账号中没有成员时才执行
			printf("\n\t当前账号没有家庭成员。\n\t");
			system("pause");
			for (i = 0;; i++){
				system("cls");
				printf("\t----------------------    成员模式     -----------------------------\n");
				printf("\n\t请添加家庭成员：");
				gets(names[i]);
				printf("\n\n\t是否继续添加家庭成员：\n\t1.是\n\t2.否\n\t");
				ch = getch();
				if (ch == '1')
					continue;
				else if (ch == '2')
					break;
			}
			printf("\n\t当前账号的所有家庭成员为：");
			for (i = 0; strlen(names[i]) != 0; i++){
				printf("%s  ", names[i]);
			}
			for (i = 0; strlen(names[i]) != 0; i++){
				strcpy(names_present[i], names[i]);
			}
			printf("\n\n\t当前为全成员模式。\n");
		}//无成员情况if结束
		//进入member函数，且有成员的情况执行以下
		printf("\n\t当前账号的所有家庭成员为：");
		for (i = 0; strlen(names[i]) != 0; i++){
			printf("%s  ", names[i]);
		}
		//以下代码，若为刚打开程序，在执行load_member函数时，默认把names_present设为全成员。
		printf("\n\t当前的成员模式：");
		for (i = 0; strlen(names_present[i]) != 0; i++){
			printf("%s  ", names_present[i]);
		}
		printf("\n");
		printf("\n\t1.确认使用当前模式\n\t2.修改成员模式\n\t3.修改成员\n\t");
		ch = getch();
		if (ch == '1'){
			return *names_present;
		}
		else if (ch == '2'){
			printf("\n\t当前账号的所有家庭成员为：");
			for (i = 0; strlen(names[i]) != 0; i++){
				printf("\n\t%d.%s  ", i, names[i]);
			}
			printf("\n\t选择您当前需要的家庭成员编号\n\t(可多选,输入的每个编号用空格隔开，所有数字输入完后输入“-1”结束)：");
			i = 0;
			while (scanf("%d", &number), number >= 0){
				strcpy(names_present[i], names[number]);
				i++;
			}
			names_present[i][0] = '\0';
			printf("\n\t当前的成员模式为：");
			for (i = 0; strlen(names_present[i]) != 0; i++){
				printf("%s   ", names_present[i]);
			}
			while (1){
				printf("\n\n\t是否确认使用当前成员模式?\n");
				printf("\n\t1.是\n\t2.重新选择成员模式\n");
				ch = getch();
				if (ch == '1')
					return *names_present;
				else if (ch == '2')
					break;
				else{
					printf("\n\t选项输入错误，请重新输入。\n");
					system("pause");
					continue;
				}
			}
			if (ch == '2')
				continue;
		}
		else if (ch == '3'){
			update_member(names,head_recycle_bin,head_person);
			for (i = 0; strlen(names[i]) != 0; i++){
				strcpy(names_present[i], names[i]);
			}
			names_present[i][0] = '\0';
		}
	}
}


void update_member(char(*names)[20], struct person *head_recycle_bin,struct person *head_person)//修改成员函数
{
	int select = 0, j, i;//select选择操作选项
	int select_member = -1;//选择要操作的成员序号
	struct person *p1, *p2;
	char names_name[20] = { 0 };
	printf("\t--------------------       修改成员     --------------------------\n ");
	printf("\t当前账号的所有成员：");
	for (i = 0; strlen(names[i]) != 0; i++){
		printf("%s   ", names[i]);
	}
	printf("\n\t请选择选项:\n");
	printf("\t1.添加成员\n\t2.修改成员名字\n\t3.删除成员\n\t");
	scanf("%d", &select);
	if (select == 1){
		while (1){
			printf("\n\t添加成员\n");
			printf("\t请输入要添加的成员的名字:");
			fflush(stdin);
			gets(names_name);
			strcpy(names[i], names_name);
			printf("\n\t添加成功! 请选择是否继续添加？\n");
			printf("\t1.是\n\t2.否\n\t");
			scanf("%d", &select);
			if (select == 1){
				i++;
				continue;
			}
			else
				break;
		}
	}
	else if (select == 2){
		while (1){
			printf("\n\t修改成员名字\n");
			for (i = 0; strlen(names[i]) != 0; i++){
				printf("\t%d.%s", i, names[i]);
			}
			printf("\n\t请选择要修改的成员名序号(单选)：");
			scanf("%d", &select_member);
			printf("\n\t请输入新的名字：");
			fflush(stdin);
			gets(names_name);
			if (strlen(names[select_member]) != 0){
                for(p1=head_person->next_person;p1!=NULL;p1=p1->next_person){
                    if(strcmp(names[select_member],p1->name) == 0){
                        strcpy(p1->name,names_name);
                    }
                }
                strcpy(names[select_member], names_name);
				printf("\n\t修改成功。\n\t是否继续修改其他成员的名字？\n");
				printf("\t1.是\n\t2.否\n");
				if (select == 1){
					i++;
					continue;
				}
				else
					break;
			}
			else{
				printf("\n\t未找到该成员，请重新输入。");
				continue;
			}
		}
	}
	else if (select == 3){
		while (1){
			printf("\n\t删除成员\n");
			for (i = 0; strlen(names[i]) != 0; i++){
				printf("\t%d.%s", i, names[i]);
			}

			// TODO (Leo#1#): 删除，模仿修改，选择成员序号


			printf("\n\t请选择要删除的成员名序号(单选)：");
			scanf("%d", &select_member);
			while(1){
                p1 = head_person;
                p2 = head_person;
                for (p1 = p1->next_person; p1 != NULL; p1 = p1->next_person){
                    if (strcmp(names[select_member],p1->name) == 0){
                        p2->next_person = p1->next_person;
                        recycle(p1, head_recycle_bin);
                        break;
                    }
                    else{
                        p2 = p1;
                    }
                }
                if(p1 == NULL){
                    break;
                }
			}

			if (strlen(names[select_member]) != 0){
				printf("%s ", names[select_member]);
				for (j = select_member; strlen(names[j]) != 0; j++){
					strcpy(names[j], names[j + 1]);
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
    }
}






