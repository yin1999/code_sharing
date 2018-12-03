//字符串处理问题，不要忘记赋值是可以在两个变量之间进行的就行
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int a[3] = { 0 };
	cin >> str;
	for (unsigned int i = 0; i < str.size(); i += 5)
	{
		if (str[i + 3] >= '0' && str[i + 3] <= '9')
			a[int(str[i] - 'a')] = int(str[i + 3] - '0');
		else
			a[int(str[i] - 'a')] = a[int(str[i + 3] - 'a')];
	}
	cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
	return 0;
}
