#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Account
{
public:
	string username;
	string passwd;
	Account operator =(Account&);
	bool operator ==(Account&);
	bool GetAccount();
};

class user
{
public:
	Account account;
	string name;
	string area;
	bool primer;
	bool judged;
	bool deleted;
	user() { primer = false, judged = false, deleted = false; }
	user(user&);
	void operator= (user&);
	void GetUserMsg(int);
	friend ifstream& operator >> (ifstream&, user&);
	friend ofstream& operator << (ofstream&, user&);
	friend ostream& operator << (ostream&, user&);
};
