#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	getchar();   //每一行输入都有一个换行符，第一行输入后得先用getchar接收换行符
	while (n--)
	{
		char str;
		int num_a = 0, num_e = 0, num_i = 0, num_o = 0, num_u = 0;
		for (int i = 0; str = getchar(), str !='\n'; i++)    //遇到换行符时结束输入
		{
			if (str == 'a' || str == 'A')
				num_a++;
			else if (str == 'e' || str == 'E')
				num_e++;
			else if (str == 'i' || str == 'I')
				num_i++;
			else if (str == 'o' || str == 'O')
				num_o++;
			else if (str == 'u' || str == 'U')
				num_u++;
		}
		cout << "a:" << num_a << endl;
		cout << "e:" << num_e << endl;
		cout << "i:" << num_i << endl;
		cout << "o:" << num_o << endl;
		cout << "u:" << num_u << endl;
		if (n)     //最后一次输入只要换行，不需要留空行
			cout << endl;
	}
	return 0;
}
