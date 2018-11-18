#include<iostream>
using namespace std;

void insert_sort(int temp[], int num)   //插入排序：输入数组并完成排序（从大到小）
{
	int i, j, t;
	cin >> temp[0];
	for (i = 1; i < num; i++)
	{
		cin >> t;
		for (j = i; j > 0; j--)
		{
			if (t > temp[j - 1])
				temp[j] = temp[j - 1];
			else
				break;
		}
		temp[j] = t;
	}
}

void bubble_sort(int temp[], int num)  //冒泡排序：输入数组并完成排序
{
	for (int i = 0; i < num; i++)
		cin >> temp[i];
	for (int i = 0; i <num; i++)
	{
		for (int j = num - 1; j > i; j--)
		{
			if (temp[j] > temp[j - 1])
			{
				int t = temp[j];
				temp[j] = temp[j - 1];
				temp[j - 1] = t;
			}
		}
	}
}

void select_sort(int temp[], int num)
{
	for (int i = 0; i < num; i++)
		cin >> temp[i];
	for (int i = 0; i < num; i++)
	{
		int max = i;
		for (int j = i + 1; j < num; j++)
		{
			if (temp[j] > temp[max])
				max = j;
		}
		int t = temp[i];
		temp[i] = temp[max];
		temp[max] = t;
	}
}

int quick_search(int temp[], int key,int length)
{
	int start = 0, end = length - 1, mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (temp[mid] > key)
			end = mid - 1;
		else if (temp[mid] < key)
			start = mid + 1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	int a[1000], n, key;
	cout << "请输入需要输入的数据个数（限制为整型）" << endl;
	cin >> n;
	//insert_sort(a, n);     //插入排序
	bubble_sort(a, n);    //冒泡排序
	//select_sort(a, n);      //选择排序
	cout << "请输入想要查找的数" << endl;
	cin >> key;
	int outcome = quick_search(a, key, n);
	if (outcome >= 0)
		cout << "找到该数！" << endl << "位置  " << outcome << endl;
	else
		cout << "没找到该数" << endl;
}
