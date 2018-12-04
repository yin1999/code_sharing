//使用long long int会爆掉，所以使用字符串来输入，只要判断最后一位是否为偶数即可
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int last_num, n;
	char temp;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		while (temp = getchar())
		{
			if (temp != '\n')
				last_num = int(temp - '0');    //将数字接收到last_num中，直到读取到最后一位数字(后面接着一个换行符，接收到换行符则输入完毕）
			else
			{
				if (last_num & 1)
					cout << "odd" << endl;
				else
					cout << "even" << endl;
				break;
			}
		}
	}
	return 0;
}
