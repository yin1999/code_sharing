#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int a = 1;
		for (int i = 1; i <= n / 2; i++)   //除被除数本身外，取余为0只能到它本身的一半
		{
			if (n % i == 0)
				a = abs(a - 1);   //实现0-1之间的变换
		}
		cout << a << endl;
	}
  return 0;
}
