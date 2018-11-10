#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		char password[51];
		int flag_caps = 0, flag_lower = 0, flag_num = 0, flag_other = 0;  //分别储存是否有大写字母，小写字母，数字，其它字符,初始化为否(0)
		cin >> password;
		if (strlen(password) < 8 || strlen(password) > 16)  //若字符长度不符合要求，直接输出"NO"
		{
			cout << "NO" << endl;
			continue;
		}
    
		for (int i = 0; i < strlen(password); i++)
		{
			if (password[i] >= 'A' && password[i] <= 'Z')
				flag_caps = 1;
			else if (password[i] >= 'a' && password[i] <= 'z')
				flag_lower = 1;
			else if (password[i] >= '0' && password[i] <= '9')
				flag_num = 1;
			else
				flag_other = 1;
		}
    
		if (flag_caps + flag_lower + flag_num + flag_other > 2)  //计算符合的条件有几个
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
