#include<iostream>
using namespace std;

int main()
{
	int N;
	while (cin >> N)
	{
		for (int i = 0; i < N; i++)
		{
			int a[3];   //a数组0,1,2分别储存时分秒
			for (int j = 0; j < 3; j++)
			{
				cin >> a[j];
			}
			for (int j = 0; j < 3; j++)
			{
				int temp;
				cin >> temp;
				a[j] += temp;
			}
			while (a[2] > 59)
			{
				a[2] -= 60;
				a[1]++;
			}
			while (a[1] > 59)
			{
				a[1] -= 60;
				a[0]++;
			}
			cout << a[0] << " " << a[1] << " " << a[2] << endl;
		}
	}
	return 0;
}
