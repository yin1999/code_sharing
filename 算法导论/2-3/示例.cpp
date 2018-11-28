#include<iostream>
#include<cstdlib>
#include<ctime>
//定义数组最大值及数组长度（可修改）
#define MAX 400     //定义数组最大值（取合适大小，比数组长度大一些，别太大）
#define NUM 100        //定义数组长度

using namespace std;

void inti(int *a, int L)    //初始化数组（随机生成数据）
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < L; i++)
		a[i] = rand() % MAX;
}

int merge(int *a, int p, int q, int r)    //向数组插入排序完成的两组数据，同时计算逆序对数(最小情况为2个数插入原数组)，分别接收数组首地址，左下标，中间值下标，右下标
{
	int count0 = 0;
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1 + 1];    //分配出 储存左支 的空间
	int *R = new int[n2 + 1];    //分配出 储存右支 的空间
	if (L == NULL || R == NULL)   //考虑空间分配出错的情况
	{
		cout << "未分配到空间，结果错误" << endl;
		return -1;
	}
	for (int i = 0; i < n1; i++)
		L[i] = a[p + i];
	for (int i = 0; i < n2; i++)
		R[i] = a[q + i + 1];
	L[n1] = MAX;     //无穷大标志符，不会被取到（哨兵）
	R[n2] = MAX;
	int j = 0, k = 0;   //记录下标
	for (int i = p; i <= r; i++)    //选择插入数据
	{
		if (L[j] <= R[k])    //等于放不放都一样
		{
			a[i] = L[j];
			j++;
		}
		else
		{
			a[i] = R[k];
			k++;
			count0 += n1 -j;    //非常重要，好好考虑下标的问题
		}
	}
	delete[] L;   //释放分配的空间
	delete[] R;
	return count0;    //返回当前排序中存在的逆序对数
}

int inversion(int *a, int p, int q)
{
	if (p < q)
	{
		int count1 = 0, count2 = 0, count3 = 0;
		int m = (p + q) / 2;
		count1 = inversion(a, p, m);
		count2 = inversion(a, m + 1, q);
		count3 = merge(a, p, m, q);
		return count1 + count2 + count3;
	}
	return 0;
}

int main()
{
	int a[NUM];
	inti(a, NUM);   //初始化数组
	for (int i = 0; i < NUM; i++)
		cout << a[i] << '\t';
	cout << endl;
	cout << "逆序对个数" << endl;
	cout << inversion(a, 0, NUM - 1) << endl;        //归并排序（计算逆序对数）
	return 0;
}
