#include <iostream>
#include <cstring>
using namespace std;

void printtop(int length) //打印顶层和底层
{
	cout << '.';
	for (int i = 1; i <= length; i++)
	{
		if (i % 3 == 0)
			cout << ".*..";
		else
			cout << ".#..";
	}
	cout << endl;
}

void printsecondlen(int length)   //打印第二层和倒数第二层
{
	cout << '.';
	for (int i = 1; i <= length; i++)
	if (i % 3 == 0)
		cout << "*.*.";
	else
		cout << "#.#.";
	cout << endl;
}

int main()
{
	char str[16];
	cin >> str;
	int length = strlen(str);
	printtop(length);
	printsecondlen(length);
	cout << '#';
	for (int i = 1; i <= length; i++)   //打印中间层，注意控制格式即可
	{
		if (i % 3 == 0)
			cout << "*." << str[i - 1] << ".*";
		else if (i % 3 == 1)
			cout << '.' << str[i - 1] << ".#";
		else
			cout << '.' << str[i - 1] << '.';
	}
	if (length % 3 == 2)
		cout << '#';
	cout << endl;
	printsecondlen(length);
	printtop(length);
	return 0;
}
