#include <iostream>
using namespace std;

int main()
{
	int sum = 0;  //统计圆括号是否配对，配对则最终值为0
	char str[256];
	bool flag = true;
	cin >> str;
	int i = 0;
	while (str[i] != '@')
	{
		if (str[i] == '(')   //出现左括号则加一
			sum++;
		else if (str[i] == ')')   //出现右括号则减一
			sum--;
		if (sum < 0)    //如果中间结果出现负数，则说明有右括号在该配对的左括号左边出现了
		{
			flag = false;
			break;
		}
		i++;
	}
	if (flag && sum == 0)   //只有两个条件都满足，才配对正确
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
