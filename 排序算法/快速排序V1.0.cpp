#include<iostream>
#include<stdlib.h>
using namespace std;

int a[1000];


void quicksort(int left, int right)
{
	int i, j, t, temp;
	if (left > right)
		return;
	if (right - left <= 6)
	{
		for (i = left; i < right; i++)
		{
			t = i;
			for (j = i + 1; j <= right; j++)
			{
				if (a[t] > a[j])
					t = j;
			}
			temp = a[i];
			a[i] = a[t];
			a[t] = temp;
		}
	}
	else
	{
		temp = a[left];
		i = left;
		j = right;
		while (i != j)
		{
			while (a[j] >= temp && i < j)
				j--;
			while (a[i] <= temp && i < j)
				i++;
			if (i < j)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		a[left] = a[i];
		a[i] = temp;

		quicksort(left, i - 1);
		quicksort(i + 1, right);
	}
}

int main()
{
	cout << "生成1000个随机数" << endl;
	for (int i = 0; i < 1000; i++)
	{
		a[i] = rand() % 1000;
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "排序结果:" << endl;
	quicksort(0, 999);
	for (int i = 0; i < 1000; i++)
		cout << a[i] << " ";
}
