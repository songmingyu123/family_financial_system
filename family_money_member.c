#include"family_money_head.h"
int save_member(char(*names)[20], char(*account_name_member))//�����Ա����
{
	FILE *fp;
	int i = 0;
	fp = fopen(account_name_member, "wb");
	if (fp == NULL){
		printf("�ļ��򿪴���save_member�����С�\n");
		system("pause");
		exit(0);
	}
	for (i = 0; strlen(names[i]) != 0; i++){
		fwrite(names[i], sizeof(names[i]), 1, fp);
	}
	printf("�ļ�����ɹ���");
	fclose(fp);
	return 0;
}

int load_member(char(*names)[20], char(*account_name_member), char(*names_present)[20])//��ȡ��Ա����
{
	FILE *fp;
	int i = 0;
	fp = fopen(account_name_member, "a+b");
	if (fp == NULL){
		printf("�ļ��򿪴���load_member�����С�\n\t");
		system("pause");
		exit(0);
	}
	while (fread(names[i], 20, 1, fp) == 1){
		i++;
	}
	printf("��ȡ������\n");
	for (i = 0; strlen(names[i]) != 0; i++){
		strcpy(names_present[i], names[i]);
	}
	return 0;
}



char *member(char(*names)[20], char(*names_present)[20],struct person *head_recycle_bin,struct person *head_person)  //��Ա����
{
	while (1){
		int i = 0;
		int number;
		int j = 0, k = 0;//j��¼��ǰ�˺������еĳ�Ա����,k��¼��ǰ��Աģʽ�еĳ�Ա����
		char ch;
		for (i = 0; strlen(names[i]) != 0;){
			i++;
		}
		j = i;
		for (k = 0; strlen(names_present[k]) != 0;){
			k++;
		}
		system("cls");
		printf("\t----------------------    ��Աģʽ     -----------------------------\n");
		if (j == 0){//���if�����˺���û�г�Աʱ��ִ��
			printf("\n\t��ǰ�˺�û�м�ͥ��Ա��\n\t");
			system("pause");
			for (i = 0;; i++){
				system("cls");
				printf("\t----------------------    ��Աģʽ     -----------------------------\n");
				printf("\n\t����Ӽ�ͥ��Ա��");
				gets(names[i]);
				printf("\n\n\t�Ƿ������Ӽ�ͥ��Ա��\n\t1.��\n\t2.��\n\t");
				ch = getch();
				if (ch == '1')
					continue;
				else if (ch == '2')
					break;
			}
			printf("\n\t��ǰ�˺ŵ����м�ͥ��ԱΪ��");
			for (i = 0; strlen(names[i]) != 0; i++){
				printf("%s  ", names[i]);
			}
			for (i = 0; strlen(names[i]) != 0; i++){
				strcpy(names_present[i], names[i]);
			}
			printf("\n\n\t��ǰΪȫ��Աģʽ��\n");
		}//�޳�Ա���if����
		//����member���������г�Ա�����ִ������
		printf("\n\t��ǰ�˺ŵ����м�ͥ��ԱΪ��");
		for (i = 0; strlen(names[i]) != 0; i++){
			printf("%s  ", names[i]);
		}
		//���´��룬��Ϊ�մ򿪳�����ִ��load_member����ʱ��Ĭ�ϰ�names_present��Ϊȫ��Ա��
		printf("\n\t��ǰ�ĳ�Աģʽ��");
		for (i = 0; strlen(names_present[i]) != 0; i++){
			printf("%s  ", names_present[i]);
		}
		printf("\n");
		printf("\n\t1.ȷ��ʹ�õ�ǰģʽ\n\t2.�޸ĳ�Աģʽ\n\t3.�޸ĳ�Ա\n\t");
		ch = getch();
		if (ch == '1'){
			return *names_present;
		}
		else if (ch == '2'){
			printf("\n\t��ǰ�˺ŵ����м�ͥ��ԱΪ��");
			for (i = 0; strlen(names[i]) != 0; i++){
				printf("\n\t%d.%s  ", i, names[i]);
			}
			printf("\n\tѡ������ǰ��Ҫ�ļ�ͥ��Ա���\n\t(�ɶ�ѡ,�����ÿ������ÿո������������������������롰-1������)��");
			i = 0;
			while (scanf("%d", &number), number >= 0){
				strcpy(names_present[i], names[number]);
				i++;
			}
			names_present[i][0] = '\0';
			printf("\n\t��ǰ�ĳ�ԱģʽΪ��");
			for (i = 0; strlen(names_present[i]) != 0; i++){
				printf("%s   ", names_present[i]);
			}
			while (1){
				printf("\n\n\t�Ƿ�ȷ��ʹ�õ�ǰ��Աģʽ?\n");
				printf("\n\t1.��\n\t2.����ѡ���Աģʽ\n");
				ch = getch();
				if (ch == '1')
					return *names_present;
				else if (ch == '2')
					break;
				else{
					printf("\n\tѡ������������������롣\n");
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


void update_member(char(*names)[20], struct person *head_recycle_bin,struct person *head_person)//�޸ĳ�Ա����
{
	int select = 0, j, i;//selectѡ�����ѡ��
	int select_member = -1;//ѡ��Ҫ�����ĳ�Ա���
	struct person *p1, *p2;
	char names_name[20] = { 0 };
	printf("\t--------------------       �޸ĳ�Ա     --------------------------\n ");
	printf("\t��ǰ�˺ŵ����г�Ա��");
	for (i = 0; strlen(names[i]) != 0; i++){
		printf("%s   ", names[i]);
	}
	printf("\n\t��ѡ��ѡ��:\n");
	printf("\t1.��ӳ�Ա\n\t2.�޸ĳ�Ա����\n\t3.ɾ����Ա\n\t");
	scanf("%d", &select);
	if (select == 1){
		while (1){
			printf("\n\t��ӳ�Ա\n");
			printf("\t������Ҫ��ӵĳ�Ա������:");
			fflush(stdin);
			gets(names_name);
			strcpy(names[i], names_name);
			printf("\n\t��ӳɹ�! ��ѡ���Ƿ������ӣ�\n");
			printf("\t1.��\n\t2.��\n\t");
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
			printf("\n\t�޸ĳ�Ա����\n");
			for (i = 0; strlen(names[i]) != 0; i++){
				printf("\t%d.%s", i, names[i]);
			}
			printf("\n\t��ѡ��Ҫ�޸ĵĳ�Ա�����(��ѡ)��");
			scanf("%d", &select_member);
			printf("\n\t�������µ����֣�");
			fflush(stdin);
			gets(names_name);
			if (strlen(names[select_member]) != 0){
                for(p1=head_person->next_person;p1!=NULL;p1=p1->next_person){
                    if(strcmp(names[select_member],p1->name) == 0){
                        strcpy(p1->name,names_name);
                    }
                }
                strcpy(names[select_member], names_name);
				printf("\n\t�޸ĳɹ���\n\t�Ƿ�����޸�������Ա�����֣�\n");
				printf("\t1.��\n\t2.��\n");
				if (select == 1){
					i++;
					continue;
				}
				else
					break;
			}
			else{
				printf("\n\tδ�ҵ��ó�Ա�����������롣");
				continue;
			}
		}
	}
	else if (select == 3){
		while (1){
			printf("\n\tɾ����Ա\n");
			for (i = 0; strlen(names[i]) != 0; i++){
				printf("\t%d.%s", i, names[i]);
			}

			// TODO (Leo#1#): ɾ����ģ���޸ģ�ѡ���Ա���


			printf("\n\t��ѡ��Ҫɾ���ĳ�Ա�����(��ѡ)��");
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


            printf("\n\t�Ƿ����ɾ��?\n\t1.��\n\t2.��\n\t");
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






