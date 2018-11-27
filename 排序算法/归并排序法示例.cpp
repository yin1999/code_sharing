//来自《算法导论》 2.3.1
//分治法
/*
分解：分解待排序的n个元素的序列成各具n/2个元素的两个子序列
解决：使用归并排序递归地排序两个子序列
合并：合并已排序的子序列以产生已排序的答案
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
//定义数组最大值及数组长度（可修改）
#define MAX 1000     //定义数组最大值（取合适大小，比数组长度大一些，别太大）
#define NUM 200       //定义数组长度

using namespace std;

void inti(int *a, int L)   //初始化数组（随机生成数据）
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < L; i++)
		a[i] = rand() % MAX;
}

void MERGE(int *a, int p, int q, int r)    //向数组插入排序完成的两组数据(最小情况为2个数插入原数组)，分别接收数组首地址，左下标，中间值下标，右下标
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1 + 1];    //分配出 储存左支 的空间
	int *R = new int[n2 + 1];    //分配出 储存右支 的空间

	if (L == NULL || R == NULL)   //考虑分配空间出错的情况
		return;

	for (int t = 0; t < n1; t++)    //将左右支储存到分配的空间中去
		L[t] = a[t + p];
	for (int t = 0; t < n2; t++)
		R[t] = a[q + 1 + t];

	L[n1] = MAX;     //无穷大标志符，不会被取到
	R[n2] = MAX;

	int i = 0, j = 0;
	for (int k = p; k <= r; k++)    //选择插入数据
	{
		if (L[i] < R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
	}

	delete[]L;   //释放分配的空间
	delete[]R;
}

void MERGE_SORT(int *a, int p, int r)    //归并排序，将数组切成两段，分别接收数组首地址，数组左下标与右下标
{
	if (p < r)
	{
		int q = (p + r) / 2;    //将数组从中间分成两段，分别递归排序
		MERGE_SORT(a, p, q);
		MERGE_SORT(a, q + 1, r);
		MERGE(a, p, q, r);
	}
}

int main()
{
	int a[NUM];
	inti(a, NUM);   //初始化数组
	MERGE_SORT(a, 0, NUM - 1);     //归并排序
	for (int i = 0; i < NUM; i++)   //输出排序后结果
		cout << a[i] << '\t';
    
	cout << endl;
  
	return 0;
}
