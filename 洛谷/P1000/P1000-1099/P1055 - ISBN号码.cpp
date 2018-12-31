#include <iostream>
using namespace std;

int main()
{
	char str[15];
	cin >> str;
	int ans;
	ans = int(str[0] - '0');
	ans += int(str[2] - '0') * 2;
	ans += int(str[3] - '0') * 3;
	ans += int(str[4] - '0') * 4;
	ans += int(str[6] - '0') * 5;
	ans += int(str[7] - '0') * 6;
	ans += int(str[8] - '0') * 7;
	ans += int(str[9] - '0') * 8;
	ans += int(str[10] - '0') * 9;
	ans %= 11;
	if (ans == int(str[12] - '0') || (ans == 10 && str[12] == 'X'))
		cout << "Right" << endl;
	else
	{
		if (ans != 10)
			str[12] = '0' + ans;
		else
			str[12] = 'X';
		cout << str << endl;
	}
	return 0;
}
