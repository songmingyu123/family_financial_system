#include"family_money_head.h"
int main()
{
    system("color 3F");
	while (1){
		int cover_account_select = -1;//��ע���¼�����ѡ��
		int cover_function_select = -1;//�ڹ������˵���ѡ��
		struct user *head_user = NULL;//�˺���Ϣͷ�ڵ�
		char *account_name = NULL;//��ǰ�˻��������ڶ�ȡ�ʹ������������ļ�����������
		char account_name_member[30] = "member_";//���浱ǰ�˻��������ڿ�ͷ���һ��member�ַ���
		char account_name_recycle[30] = "recycle_";//���浱ǰ�˻��������ڿ�ͷ���һ��recyc�ַ���
		struct person *head_person = NULL;//������Ϣͷ�ڵ�
		struct person *head_recycle_bin = NULL;//��ɾ���Ľڵ㱣��
		char names[20][20] = {0};//���浱ǰ��ͥ���г�Ա����
		char names_present[20][20] = { 0 };//���浱ǰ��Աģʽ�ĳ�Ա����
		int logoff_judge = 0;//�Ƿ�ע���˻�
		head_user = load_account(head_user);//��ȡ�ļ����˺���Ϣ����
		/*����whileΪ��¼ע�����*/
		while (1){
			system("cls");
			cover_account_select = cover_account();//����ע���¼�����ѡ��
			if (cover_account_select == 1){
				head_user = enroll(head_user);//����ע�ắ��
				save_account(head_user);   //�����˺��������ݵ��ļ�
			}
			else if (cover_account_select == 2){
				account_name = login(head_user, account_name);//�����¼����,�������˺���
				if (account_name == NULL){//���account_nameΪ��1234����˵��û�гɹ���¼����Ҫ���»ص�cover_account����
					continue;
				}
				else{
					head_person = load_data(head_person, account_name);//��ȡ�˺Ŷ�Ӧ�ļ��Ĳ�������
					break;//��¼�ɹ����˳���ǰwhileѭ��
				}
			}
			else if (cover_account_select == 3){
				head_user = modify_password(head_user);//���������޸ĺ���
				save_account(head_user);   //�����˺��������ݵ��ļ�
			}
			else if (cover_account_select == 4){
				find_password(head_user);//���������һغ���
			}
		}
		/*�뿪��¼ע�ắ��*/
		strcat(account_name_member, account_name);
		strcat(account_name_recycle, account_name);
		head_recycle_bin = load_recycle(head_recycle_bin, account_name_recycle);//��ȡ����վ����
		load_member(names, account_name_member, names_present);//��ȡ��Ա����
		while (1){
			if (logoff_judge == 1){
				break;
			}
			/*�����Աģʽ*/
			member(names, names_present,head_recycle_bin,head_person);//��Աģʽ
			save_member(names, account_name_member);//�����Ա
			/*�뿪��Աģʽ*/

			/*���빦�����˵�*/
			while(1){
				cover_function_select = cover_function(names_present);   //���˵����溯��
				switch (cover_function_select)
                {
				case 1:
				    head_person = add_data(head_person, names_present, income);//�������
				    break;
				case 2:
				    head_person = delete_data(head_person, names_present, income, head_recycle_bin);//ɾ������
				    break;
				case 3:
				    search_data(head_person, names_present, income);//��ѯ����
				    break;
				case 4:
				    head_person = update_data(head_person, names_present, income);//�޸�����
				    break;
				case 5:
				    head_person = add_data(head_person, names_present, payout);//���֧��
				    break;
				case 6:
				    head_person = delete_data(head_person, names_present, payout, head_recycle_bin);//ɾ��֧��
				    break;
				case 7:
				    search_data(head_person, names_present, payout);//��ѯ֧��
				    break;
				case 8:
				    head_person = update_data(head_person, names_present, payout);//�޸�֧��
				    break;
                case 9:
                    recycle_bin(head_person,head_recycle_bin);//����վ
                    break;
                case 10:
                    calculate(head_person, names_present,names);//����ͳ��
                    break;
                case 11:
                    break;//��Ա����
                case 12:
                    logoff_judge = 1;//ע���˻�������
                    break;
                case 13:
                    save_excel(head_person,account_name);//������excel
                    break;
                case 14:
                    sort_data(head_person,names_present);//������
                    break;
                case 15:
                    printf("�˳�����\n");
					save_data(head_person, account_name);//���溯��
					exit(0);
				default:
				    printf("����ѡ�����\n");
				    break;
				}

				save_recycle(head_recycle_bin,account_name_recycle);
				save_data(head_person, account_name);//���溯��
			}//���ܺ���while����

		}
	}
	return 0;
}

