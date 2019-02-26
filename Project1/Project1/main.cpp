#include "main.h"

int main()
{
	cout << "欢迎使用资产设备管理系统!\n";
	extern node<user> user_head;
	user user_msg;
	ifstream infile("User_message.txt", ios::in);
	if (!infile)
	{
		cout << "请先注册管理员账户\n";
		user_msg.GetUserMsg(1);
		cout << "请输入姓名\n";
		cin >> user_msg.name;
		cout << "请输入学院信息\n";
		cin >> user_msg.area;
		user_head.Store(user_msg);
		ofstream outfile("User_msg.txt", ios::out);
		outfile << user_msg.Username << ' ' << user_msg.Passwd << ' '<< user_msg.name << ' ' << user_msg.area << user_msg.Primer << ' ' << user_msg.judged;
		outfile.close();
		manage(user_msg);
	}
	else
	{
		while (infile >> user_msg)
			user_head.Store(user_msg);
		infile.close();
		Main_menu();
	return 0;
}