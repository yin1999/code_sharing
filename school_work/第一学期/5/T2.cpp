#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	cout << "请选择A.手动输入10个数或者B.系统自动生成10个数" << endl << "请输入A or B" << endl;
	char choose;
	cin >> choose;
	int a[10];
	if (choose == 'A')
	{
		for (int i = 0; i < 10; i++)
			cin >> a[i];
	}
	if (choose == 'B')
	{
		srand(time(NULL));
		cout << "输出随机数" << endl;
		for (int i = 0; i < 10; i++)
		{
			a[i] = rand() % 1000;
			cout << a[i] << " ";
		}
	}

	for (int i = 0; i < 9; i++)
	{
		int temp = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (a[temp] > a[j])
				temp = j;
		}
		int t = a[i];
		a[i] = a[temp];
		a[temp] = t;
	}

	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
                return 0;
}