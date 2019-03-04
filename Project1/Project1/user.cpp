#include "user.h"

Account Account::operator= (Account& T)
{
	username = T.username;
	passwd = T.passwd;
	return *this;
}

bool Account::GetAccount()
{
	char temp[100] = { 0 };
	cout << "用户名:";
	cin >> username;
	cout << "密码(不多于15个字符):";
	char ch;
	int i = 0;
	while ((ch = _getch()) != '\r')
	{
		if (ch == 8 && i != 0)
		{
			cout << char(8) << ' ' << char(8);
			i--;
		}
		else
		{
			cout << '*';
			temp[i++] = ch;;
		}
	}
	if (i > 15)
	{
		cout << "密码输入过长\n";
		Sleep(1000);
		return false;
	}
	else
	{
		for (int j = 0; j < i; j++)
			passwd += temp[j];
		return true;
	}
}

bool Account::operator ==(Account& T)
{
	if (username == T.username && passwd == T.passwd)
		return true;
	else
		return false;
}

user::user(user& T)
{
	account = T.account;
	name = T.name;
	area = T.area;
	primer = T.primer;
	judged = T.judged;
	deleted = T.deleted;
}

void user::operator= (user& T)
{
	account = T.account;
	name = T.name;
	area = T.area;
	primer = T.primer;
	judged = T.judged;
	deleted = T.deleted;
}

void user::GetUserMsg(int flag)
{
	while (1)
	{
		system("cls");
		cout << "输入用户信息\n";
		if (!account.GetAccount())
			continue;
		else
		{
			if (flag)
				primer = true;
			else
				primer = false;
			return;
		}
	}
}

ifstream& operator >>(ifstream& input, user& T)
{
	input >> T.account.username >> T.account.passwd >> T.primer >> T.judged;
	return input;
}

ofstream& operator <<(ofstream& output, user& T)
{
	if (T.deleted == false)
		output << T.account.username << ' ' << T.account.passwd << ' ' << T.primer << ' ' << T.judged << '\n';
	return output;
}

ostream& operator <<(ostream& output, user& T)
{
	output << T.account.username << '\t' << T.account.passwd << '\t';
	if (T.primer)
		output << "是\t";
	else
		output << "否\t";
	if (T.judged)
		output << "是\t";
	else
		output << "否\t";
	if (T.deleted)
		output << "是\n";
	else
		output << "否\n";
}
