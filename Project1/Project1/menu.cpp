#include "menu.h"

void Main_menu()
{
	user user_msg;
	bool flag = false;
	cout << "1.��½�˻�(Ĭ��ѡ��)\n";
	cout << "2.ע���˻�(��ͨ�˻�)\n";
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
					cout << "�û����ظ���������ѡ��\n";
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
			cout << "ע��ɹ�����ȴ�����Ա����\n��������˳�����\n";
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
						cout << "��¼�ɹ�\n";
						manage(q->data);
					}
				}
			}
			if (flag == false)
			{
				cout << "�û����������������������\n";
			}
			else
				break;
		}
	}
}