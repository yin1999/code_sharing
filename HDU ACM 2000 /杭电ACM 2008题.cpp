#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n &&n!=0)
	{
		int plus = 0, minus = 0, zero = 0;
		double a[100];  //不能使用int型，示例中输入的数有小数
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] > 0)
				plus++;
			else if (a[i] == 0)
				zero++;
			else
				minus++;
		}
		cout << minus << " " << zero << " " << plus << endl;
	}
	return 0;
}
