#include "manage.h"

void manage(user& User_data)
{
	int temp;
	system("cls");
	cout << "��ӭ " << User_data.Username << '!' << endl;
	if (User_data.Primer)
	{
		while (1)
		{
			cout << "ѡ��һ����ȷ������\n";
			cout << "1.�û�����\n";
			cout << "2.�豸��Ϣ����/��ѯ\n";
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
		cout << "����˻���δͨ����ˣ�����ϵ����Ա����\n";
}