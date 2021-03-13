#include<iostream>
using namespace std;


int main()
{
	int n, r;    //分别表示十进制数和转换为多少进制的
	while (cin >> n >> r)
	{
		char str[1024];   //储存转换后的数
		bool flag = false;   //标记是否为负数，true表示其是负数
		int i = 0, temp;
		if (n < 0)
		{
			flag = true;
			n = -n;
		}
    
		while (n)
		{
			temp = n % r;
			if (temp > 9)
				str[i] = 'A' + temp - 10;   //大于十则将数转换为字母来表示
			else
				str[i] = temp + '0';
			i++;
			n /= r;
		}
    
		if (flag)
			cout << "-";
		for (int j = i - 1; j >= 0; j--)
			cout << str[j];
		cout << endl;
	}
	return 0;
}
