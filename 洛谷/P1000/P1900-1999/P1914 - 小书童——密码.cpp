#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	char str[51];
	cin >> n;
	cin >> str;
	int length = strlen(str);
	n = n % 26;
	for (int i = 0; i < length; i++)
	{
		if (str[i] + n > 'z')    //先判断，再求和（127不能超）
			str[i] -= 26;
		str[i] += n;
	}
	cout << str << endl;
	return 0;
}
