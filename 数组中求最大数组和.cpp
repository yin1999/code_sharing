#include <iostream>
//杭电ACM1003题
using namespace std;
int a[100010];
bool flag;
int main()
{
	int t;
	cin >> t;      //输入case数
	int c = 1;
	while (t--)    //记录case数，做完则停止
	{
		int n;
		cin >> n;    //输入数组个数
		for (int i = 0; i < n; i++)     //输入数组
		{
			cin >> a[i];
		}
		int maxsum = a[0], tempsum = a[0];   //定义数组最大和与temp最大为a0
		int start = 0, end = 0, itemp = 0;
		for (int i = 1; i < n; i++)
		{
			if (tempsum < 0)
			{
				tempsum = 0;
				itemp = i;
			}
			tempsum += a[i];
			if (tempsum > maxsum)
			{
				maxsum = tempsum;
				start = itemp;
				end = i;
			}
		}
		cout << "Case " << c++ << ":" << endl;
		cout << maxsum << " " << start + 1 << " " << end + 1 << endl;
		if (t != 0)        //判断是不是最后一个case，若不是，则输出空行，若是，则不输出
			cout << endl;
	}
	return 0;
}
