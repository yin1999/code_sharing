#include "manage.h"

int GetUserNum(int);
void GetUserMsg();
void UserManage();
int GetNum(string);
void choose(user&);
bool change_passwd(user&);
bool DeviceManage(user&);

extern bool user_change = false;
extern bool device_change = false;

void manage(user& User_data)
{
	int temp;
	if (User_data.Primer)
	{
		while (1)
		{
			system("cls");
			cout << "欢迎 " << User_data.Username << '!' << endl;
			cout << "选择一个数确定操作\n";
			cout << "1.用户管理\n";
			cout << "2.设备信息管理/查询\n";
			cout << "3.密码修改\n";
			cout << "4.返回上一级\n";
			cin >> temp;
			switch (temp)
			{
			case 1:
				{
					system("cls");
					cout << "用户管理:\n";
					node<user>* q = user_head.next;
					cout << "1.用户信息查看\n";
					cout << "2.注册用户审核\n";
					cin >> temp;
					if (temp == 1)
						GetUserMsg();
					else if (temp == 2)
						UserManage();
				}
				break;
			case 2:
				{
					system("cls");
					cout << "设备信息管理/查询:\n";

				}
				break;
			case 3:
				{
					system("cls");
					cout << "密码修改:\n";
					if (change_passwd(User_data))
					{
						user_change = true;
						cout << "修改成功\n";
					}
					else
						cout << "密码未改动\n";
				}
				break;
			case 4:
				return;
			}
		}
	}
	else if (User_data.judged == true)
	{
		while (1)
		{
			system("cls");
			cout << "欢迎 " << User_data.Username << '!' << endl;
			cout << "选择一个数确定操作\n";
			cout << "1.设备信息管理/查询\n";
			cout << "2.密码修改\n";
			cout << "3.返回上一级\n";
			cin >> temp;
			switch (temp)
			{
			case 1:
			{
				system("cls");
				cout << "设备信息管理/查询:\n";

			}
			break;
			case 2:
			{
				system("cls");
				cout << "密码修改:\n";
				if (change_passwd(User_data))
				{
					user_change = true;
					cout << "修改成功\n";
				}
				else
					cout << "密码未改动\n";
			}
			break;
			case 3:
				return;
			}
		}
	}
	else
		cout << "你的账户尚未通过审核，请联系管理员审批\n";
}

int GetUserNum(int flag)
{
	node<user>* q = user_head.next;
	int i = 0;
	if (flag)
	{
		while (q)
		{
			if (q->data.judged == false)
				i++;
			q = q->next;
		}
	}
	else
	{
		while (q)
		{
			if (q->data.judged == true)
				i++;
			q = q->next;
		}
	}
	return i;
}

void GetUserMsg()
{
	int UserNum = GetUserNum(0);
	int SumPage = (UserNum - 1) / 10 + 1;
	node<user>* q = user_head.next;
	node<node<user>*> node_head, *p;
	p = node_head.next;
	for (int i = 0; i < UserNum; i += 10)
	{
		for (int j = 0; j < 10;)
		{
			if (q->data.judged == true)
			{
				if (j == 0)
				{
					p->data = q;
					p->next = new node<node<user>*>;
					p = p->next;
				}
				j++;
			}
			q = q->next;
		}
	}
	int page = 1;
	while (1)
	{
		string temp;
		system("cls");
		cout << "用户信息查看\n";
		cout << "当前第" << page << "页\t共" << SumPage << "页\n";
		cout << "用户名\t姓名\t所属学院\t管理员\t注册\t删除\n\n";
		p = node_head.next;
		for (int j = 1; j < page; j++)
			p = p->next;
		q = p->data;
		for (int j = 0; j < 10;)
		{
			if (q->data.judged == true)
			{
				cout << q->data;
				j++;
			}
			q = q->next;
		}
		cout << "\n\n" << "w.上一页\ns.下一页\n数字n.跳转至第n页\n";
		cout << "E.返回上一级\n";
		cin >> temp;
		if (temp[0] == 'w' || temp[0] == 'W')
		{
			if (page > 1)
				page--;
		}
		else if (temp[0] == 's' || temp[0] == 'S')
		{
			if (page < SumPage)
				page++;
		}
		else if (temp[0] == 'e' || temp[0] == 'E')
			return;
		else
		{
			int z = GetNum(temp);
			if (z > 0 && z <= SumPage)
				page = z;
		}
	}
}

int GetNum(string temp)
{
	int num = 0;
	for (unsigned i = 0; i < temp.size(); i++)
	{
		if (temp[i] >= '0' && temp[i] <= '9')
			i = i * 10 + int(temp[i] - '0');
		else
			return -1;
	}
	return num;
}

void UserManage()
{
	int UserNum = GetUserNum(1);
	int SumPage = (UserNum - 1) / 10 + 1;
	node<user> * q = user_head.next;
	node<node<user>*> node_head, *p;
	p = node_head.next;
	for (int i = 0; i < UserNum; i += 10)
	{
		for (int j = 0; j < 10;)
		{
			if (q->data.judged == false)
			{
				if (j == 0)
				{
					p->data = q;
					p->next = new node<node<user>*>;
					p = p->next;
				}
				j++;
			}
			q = q->next;
		}
	}
	int page = 1;
	while (1)
	{
		string temp;
		system("cls");
		cout << "注册用户审核\n";
		cout << "当前第" << page << "页\t共" << SumPage << "页\n";
		cout << "编号\t用户名\t姓名\t所属学院\t管理员\t注册\t删除\n\n";
		p = node_head.next;
		for (int j = 1; j < page; j++)
			p = p->next;
		q = p->data;
		for (int j = 0; j < 10 && q != p->next->data;)
		{
			if (q->data.judged == false)
			{
				cout << ++j << '\t';
				cout << q->data;
			}
			q = q->next;
		}
		cout << "\n\n" << "w.上一页\ns.下一页\n数字n.选择相应用户\n";
		cout << "E.返回上一级\n";
		cin >> temp;
		if (temp[0] == 'w' || temp[0] == 'W')
		{
			if (page > 1)
				page--;
		}
		else if (temp[0] == 's' || temp[0] == 'S')
		{
			if (page < SumPage)
				page++;
		}
		else if (temp[0] == 'e' || temp[0] == 'E')
			return;
		else
		{
			int z = GetNum(temp);
			if (page != SumPage)
			{
				if (z > 0 && z <= 10)
				{
					for (int j = 0; j = z;)
					{
						if (q->data.judged == false)
							j++;
						q = q->next;
					}
					choose(q->data);
				}
			}
			else if (z > 0 && z <= (UserNum % 10))
			{
				for (int j = 0; j = z;)
				{
					if (q->data.judged == false)
						j++;
					q = q->next;
				}
				choose(q->data);
				UserNum--;
			}
		}
	}
}

void choose(user& temp)
{
	char ch;
	system("cls");
	cout << "用户名\t姓名\t所属学院\n";
	cout << temp.Username << '\t' << temp.name << '\t' << temp.area << '\n\n';
	if (temp.deleted == false)
	{
		cout << "审核是否通过？(输入y/n)\n";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			temp.judged = true;
			ch = getchar();
			cout << "是否设置为管理员？(输入y/n，默认为否,可按回车键直接选择否)\n";
			ch = getchar();
			if (ch == 'y' || ch == 'Y')
				temp.Primer = true;
			else
				temp.Primer = false;                   //可能有问题
		}
		else if (ch == 'n' || ch == 'N')
		{
			temp.judged = true;
			temp.deleted = true;
		}
		user_change = true;
	}
	else
	{
		cout << "是否恢复当前用户信息？(输入y/n)\n";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			temp.deleted = false;
	}
}

bool change_passwd(user& User_data)
{
	system("cls");
	cout << "修改密码:\n";
	cout << "用户名:" << User_data.Username << '\n';
	char str[16];
	cout << "请输入新的密码:(不超过15个字符)\n";
	char ch;
	int i = 0;
	while (i == 0)
	{
		while ((ch = _getch()) != '\r' || i == 0)
		{
			if (i == 0)
				continue;
			if (ch == 8)
			{
				if (i != 0)
				{
					i--;
					cout << char(8) << ' ' << char(8);
				}
			}
			else
			{
				cout << '*';
				str[i++] = ch;
			}
			str[i] = 0;
		}
		char nstr[16];
		cout << "请再次输入新密码:\n";
		i = 0;
		while ((ch = _getch()) != '\r')
		{
			if (ch == 8)
			{
				if (i != 0)
				{
					i--;
					cout << char(8) << ' ' << char(8);
				}
			}
			else
			{
				cout << '*';
				nstr[i++] = ch;
			}
		}
		nstr[i] = 0;
		if (strcmp(str, nstr) != 0)
		{
			cout << "两次输入密码不同，请重新输入\n";
			i = 0;
		}
	}
	system("cls");
	if (strcmp(User_data.Passwd, str) == 0)
		return false;
	else
		return true;
}

bool DeviceManage(user& User_data)
{
	int device_num = 0;
	device device_info;
	node <device> device_head;
	if (User_data.Primer == false)
	{
		char* str = new char[16];
		strcpy_s(str, 16, User_data.Username);
		str[sizeof(User_data.Username)] = '.';
		str[sizeof(User_data.Username) + 1] = 't';
		str[sizeof(User_data.Username) + 2] = 'x';
		str[sizeof(User_data.Username) + 3] = 't';
		str[sizeof(User_data.Username) + 4] = 0;
		ifstream infile(str, ios::in);
		while (infile >> device_info)
		{
			device_num++;
			device_head.Store(device_info);
		}
		delete[] str;
	}
}
