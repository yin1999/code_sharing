#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <cstdio>
using namespace std;

class user
{
public:
	char Username[16];
	char Passwd[16];
	string name;
	string area;
	bool Primer;
	bool judged;
	bool deleted;
	user() { Username[0] = 0, Passwd[0] = 0, Primer = false, judged = false, deleted = false; }
	user(user&);
	user operator= (user&);
	void GetUserMsg(int);
	friend istream& operator >> (istream&, user&);
};

user::user(user& T)
{
	strcpy_s(Username, T.Username);
	strcpy_s(Passwd, T.Passwd);
	name = T.name;
	area = T.area;
	Primer = T.Primer;
	judged = T.judged;
	deleted = T.deleted;
}

user user::operator=(user& T)
{
	strcpy_s(Username, T.Username);
	strcpy_s(Passwd, T.Passwd);
	name = T.name;
	area = T.area;
	Primer = T.Primer;
	judged = T.judged;
	deleted = T.deleted;
	return *this;
}

void user::GetUserMsg(int flag)
{
	cout << "用户名(长度限制15个字符):";
	char temp;
	int i = 0;
	while ((temp = getchar()) != '\n')
	{
		if (i > 14)
		{
			i = 0;
			while ((temp = getchar()) != '\n');
			cout << "用户名不合法，请重新输入\n";
		}
		else
			Username[i++] = temp;
	}
	Username[i] = 0;
	cout << "密码(长度限制15个字符):";
	i = 0;
	while ((temp = _getch()) != '\r')
	{
		if (temp == 8)
		{
			if (i != 0)
			{
				cout << char(8) << ' ' << char(8);
				i--;
			}
		}
		else
		{
			putchar('*');
			if (i > 14)
			{
				while ((temp = getchar()) != '\n');
				cout << "输入密码不合法，请重新输入\n";
			}
			else
				Passwd[i++] = temp;
		}
	}
	Passwd[i] = 0;
	if (flag)
	{
		Primer = true;
		judged = true;
	}
	else
	{
		Primer = false;
		judged = false;
	}
	deleted = false;
	putchar('\n');
}

istream& operator >>(istream& input, user& T)
{
	input >> T.Username >> T.Passwd >> T.name >> T.area >> T.Primer >> T.judged;
	return input;
}