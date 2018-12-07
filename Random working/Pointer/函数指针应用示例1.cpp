#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool cmp(int a, int b)   //返回比较结果
{
	return a < b;
}

void initial(int *a, int high)   //初始化数组，随机生成
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i <= high; i++)
		a[i] = rand() % 20;
}

void show(int *a, int high)    //输出数组
{
	for (int i = 0; i <= high; i++)
		cout << a[i] << '\t';
	cout << endl;
}

void sort(int *a, int high, bool(*cmp)(int, int))    //分别输入数组首地址，数组最大下标，及比较函数cmp(compare)
{
	int key, i, j;
	for (i = 0; i <= high; i++)
	{
		key = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (cmp(key, a[j]))
				a[j + 1] = a[j];
			else
				break;
		}
		a[j + 1] = key;
	}
}

int main()
{
	int a[10];
	initial(a, 9);
	show(a, 9);
	sort(a, 9, cmp);
	show(a, 9);
	return 0;
}
