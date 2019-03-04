#include "main.h"

int main()
{
	cout << "欢迎使用设备管理系统\n";
	int i = 3;
	while (i--)
	{
		node<user> user_head;
		user T;
		T.GetUserMsg(0);
		user_head.Store(T);
	}
	return 0;
}
