#include<iostream>
#include<cstdlib>   //包含rand()函数
#include<ctime>   //包含time()函数
using namespace std;

int main()
{
	cout << "请选择A.手动输入10个数或者B.系统自动生成10个数" << endl << "请输入A or B" << endl;
	char choose;
	cin >> choose;
	int a[10];
	if (choose == 'A')   //判断选择了哪一种产生10个数的方式
	{
		for (int i = 0; i < 10; i++)
			cin >> a[i];
	}
	else if (choose == 'B')
	{
		srand(time(NULL));   //给rand()函数添加种子(使用计算机时间)
		cout << "输出随机数" << endl;
		for (int i = 0; i < 10; i++)
		{
			a[i] = rand() % 1000;   //产生随机数
			cout << a[i] << " ";  //输出一边随机数
		}
	}
	else
		return 0;    //若不是A也不是B则结束程序

	for (int i = 0; i < 9; i++)   //选择排序
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

	for (int i = 0; i < 10; i++)  //输出结果
		cout << a[i] << " ";
	cout << endl;
                return 0;
}
