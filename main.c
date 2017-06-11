#include"family_money_head.h"
int main()
{
    system("color 3F");
	while (1){
		int cover_account_select = -1;//在注册登录界面的选项
		int cover_function_select = -1;//在功能主菜单的选项
		struct user *head_user = NULL;//账号信息头节点
		char *account_name = NULL;//当前账户名，用于读取和创建财务数据文件建立的名字
		char account_name_member[30] = "member_";//保存当前账户名，并在开头添加一个member字符串
		char account_name_recycle[30] = "recycle_";//保存当前账户名，并在开头添加一个recyc字符串
		struct person *head_person = NULL;//财务信息头节点
		struct person *head_recycle_bin = NULL;//被删除的节点保存
		char names[20][20] = {0};//保存当前家庭所有成员名字
		char names_present[20][20] = { 0 };//保存当前成员模式的成员名字
		int logoff_judge = 0;//是否注销账户
		head_user = load_account(head_user);//读取文件中账号信息函数
		/*以下while为登录注册界面*/
		while (1){
			system("cls");
			cover_account_select = cover_account();//返回注册登录界面的选项
			if (cover_account_select == 1){
				head_user = enroll(head_user);//进入注册函数
				save_account(head_user);   //保存账号密码数据到文件
			}
			else if (cover_account_select == 2){
				account_name = login(head_user, account_name);//进入登录函数,并返回账号名
				if (account_name == NULL){//如果account_name为“1234”，说明没有成功登录，需要重新回到cover_account函数
					continue;
				}
				else{
					head_person = load_data(head_person, account_name);//读取账号对应文件的财务数据
					break;//登录成功，退出当前while循环
				}
			}
			else if (cover_account_select == 3){
				head_user = modify_password(head_user);//进入密码修改函数
				save_account(head_user);   //保存账号密码数据到文件
			}
			else if (cover_account_select == 4){
				find_password(head_user);//进入密码找回函数
			}
		}
		/*离开登录注册函数*/
		strcat(account_name_member, account_name);
		strcat(account_name_recycle, account_name);
		head_recycle_bin = load_recycle(head_recycle_bin, account_name_recycle);//读取回收站数据
		load_member(names, account_name_member, names_present);//读取成员函数
		while (1){
			if (logoff_judge == 1){
				break;
			}
			/*进入成员模式*/
			member(names, names_present,head_recycle_bin,head_person);//成员模式
			save_member(names, account_name_member);//保存成员
			/*离开成员模式*/

			/*进入功能主菜单*/
			while(1){
				cover_function_select = cover_function(names_present);   //主菜单界面函数
				switch (cover_function_select)
                {
				case 1:
				    head_person = add_data(head_person, names_present, income);//添加收入
				    break;
				case 2:
				    head_person = delete_data(head_person, names_present, income, head_recycle_bin);//删除收入
				    break;
				case 3:
				    search_data(head_person, names_present, income);//查询收入
				    break;
				case 4:
				    head_person = update_data(head_person, names_present, income);//修改收入
				    break;
				case 5:
				    head_person = add_data(head_person, names_present, payout);//添加支出
				    break;
				case 6:
				    head_person = delete_data(head_person, names_present, payout, head_recycle_bin);//删除支出
				    break;
				case 7:
				    search_data(head_person, names_present, payout);//查询支出
				    break;
				case 8:
				    head_person = update_data(head_person, names_present, payout);//修改支出
				    break;
                case 9:
                    recycle_bin(head_person,head_recycle_bin);//回收站
                    break;
                case 10:
                    calculate(head_person, names_present,names);//财务统计
                    break;
                case 11:
                    break;//成员函数
                case 12:
                    logoff_judge = 1;//注销账户待完善
                    break;
                case 13:
                    save_excel(head_person,account_name);//导出到excel
                    break;
                case 14:
                    sort_data(head_person,names_present);//排序函数
                    break;
                case 15:
                    printf("退出程序\n");
					save_data(head_person, account_name);//保存函数
					exit(0);
				default:
				    printf("输入选项错误。\n");
				    break;
				}

				save_recycle(head_recycle_bin,account_name_recycle);
				save_data(head_person, account_name);//保存函数
			}//功能函数while结束

		}
	}
	return 0;
}

