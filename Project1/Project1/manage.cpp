#include "manage.h"

void manage(user& User_data)
{
	int temp;
	system("cls");
	cout << "欢迎 " << User_data.Username << '!' << endl;
	if (User_data.Primer)
	{
		while (1)
		{
			cout << "选择一个数确定操作\n";
			cout << "1.用户管理\n";
			cout << "2.设备信息管理/查询\n";
			cin >> temp;
			if (temp == 1)
			{

			}
			else if (temp == 2)
			{

			}
		}
	}
	else if (User_data.judged == true)
	{
		
	}
	else
		cout << "你的账户尚未通过审核，请联系管理员审批\n";
}