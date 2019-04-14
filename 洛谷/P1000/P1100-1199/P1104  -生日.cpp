/*
可以把生日计算成一个特征值，相应的函数只要满足随时间变化单调递增或递减就可以
那就只需要对单一的值进行排序就可以了
排序结束后再对有相同特征值的姓名交换顺序
*/
#include <iostream>
#include <cstring>
using namespace std;

struct Personal_info
{
	char str[20];
	double born_time;
};

void exchange(Personal_info* _first, Personal_info* _last)  //对相同生日的交换姓名顺序
{
	Personal_info* i;
	for (i = _first; i != _last; i++)
	{
		if (i->born_time == _first->born_time)
			continue;
		else
			break;
	}
	i--;
	char str[20];
	while (_first < i)
	{
		strcpy(str, _first->str);
		strcpy(_first->str, i->str);
		strcpy(i->str, str);
		_first++;
		i--;
	}
}

int main()
{
	int n, i, j;
	cin >> n;
	int M, D;
	Personal_info array[100];
	for (i = 0; i < n; i++)
	{
		cin >> array[i].str >> array[i].born_time >> M >> D;
		array[i].born_time += M / 100. + D / 10000.;         //计算生日特征值
	}
	Personal_info t;
	for (i = 1; i < n; i++)
	{
		t = array[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j].born_time > t.born_time)
				array[j + 1] = array[j];
			else
			{
				break;
			}
		}
		array[j + 1] = t;
	}
	t = *array;
	for (i = 1; i < n;)
	{
		if (array[i].born_time == t.born_time)
		{
			exchange(array + i - 1, array + n);
			while (i < n && array[i].born_time == t.born_time)
				i++;
			if (i < n)
				t = array[i];
		}
		else
			t = array[i++];
	}
	for (i = 0; i < n; i++)
		cout << array[i].str << endl;
	return 0;
}
