#include "menu.h"

void Main_menu()
{
	user user_msg;
	bool flag = false;
	cout << "1.登陆账户(默认选项)\n";
	cout << "2.注册账户(普通账户)\n";
	int temp;
	cin >> temp;
	if (temp == 2)
	{
		while (1)
		{
			user_msg.GetUserMsg(0);
			node<user>* q = user_head.next;
			while (q)
			{
				if (strcmp(q->data.Username, user_msg.Username) != 0)
					continue;
				else
				{
					flag = true;
					cout << "用户名重复，请重新选择\n";
				}
			}
			if (flag)
				continue;
			user_head.Store(user_msg);
			q = user_head.next;
			ofstream outfile ("User_msg.txt", ios::out);
			while (q)
			{
				outfile << q->data.Username << ' ' << q->data.Passwd << ' ' << q->data.name << ' ' << q->data.area << q->data.Primer << ' ' << q->data.judged;
				q = q->next;
			}
			outfile.close();
			cout << "注册成功，请等待管理员审批\n按任意键退出程序\n";
			system("pause");
			break;
		}
	}
	else
	{
		flag = false;
		while (1)
		{
			user_msg.GetUserMsg(0);
			node<user>* q = user_head.next;
			while (q)
			{
				if (q->data.Username == user_msg.Username)
				{
					if (q->data.deleted == false && q->data.Passwd == user_msg.Passwd)
					{
						flag = true;
						cout << "登录成功\n";
						manage(q->data);
					}
				}
				if (flag)
					break;
				q = q->next;
			}
			if (flag == false)
			{
				cout << "用户名或密码错误，请重新输入\n";
			}
			else
				break;
		}
	}
}
