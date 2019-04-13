//贪心算法，先对牛奶价格进行排序，然后从小到大取相应的牛奶，直到满足要求
#include <iostream>
using namespace std;

struct P2N
{
	int Num;
	int Price;
};

void Sort(P2N s[], int length)
{
	if (length <= 7)
	{
		int i = 1, j;
		P2N temp;
		for (; i < length; i++)
		{
			temp = s[i];
			for (j = i - 1; j >= 0 && s[j].Price > temp.Price; j--)
				s[j + 1] = s[j];
			s[j + 1] = temp;
		}
		return;
	}
	if ((s + length / 2 - 1)->Price > (s + length - 1)->Price)
		swap(*(s + length / 2 - 1), *(s + length - 1));
	if (s->Price > (s + length - 1)->Price)
		swap(*s, *(s + length - 1));
	if (s->Price < (s + length / 2 - 1)->Price)
		swap(*s, *(s + length / 2 - 1));
	P2N key = *s;
	int left = 0, right = length - 1;
	int high = right, low = 0;
	while (left < right)
	{
		while (left < right && s[right].Price >= key.Price)
		{
			if (s[right].Price == key.Price)
			{
				swap(s[right], s[high]);
				high--;
			}
			right--;
		}
		s[left] = s[right];
		while (left < right && s[left].Price <= key.Price)
		{
			if (s[left].Price == key.Price)
			{
				swap(s[low], s[left]);
				low++;
			}
			left++;
		}
		s[right] = s[left];
	}
	s[left] = key;
	int i = left - 1, j = 0;
	while (j < low && s[i].Price != key.Price)
	{
		swap(s[j], s[i]);
		i--;
		j++;
	}
	Sort(s, left - low);
	i = left + 1;
	j = length - 1;
	while (j > high && s[i].Price != key.Price)
	{
		swap(s[j], s[i]);
		j--;
		i++;
	}
	Sort(s + right + length - high, high - right);
}

int main()
{
	int n, m;
	cin >> n >> m;
	P2N* A = new P2N[m];
	for (int i = 0; i < m; i++)
		cin >> A[i].Price >> A[i].Num;
	Sort(A, m);
	int SumPrice = 0;
	for (int i = 0; i < m; i++)
	{
		if (A[i].Num <= n)
		{
			n -= A[i].Num;
			SumPrice += A[i].Price * A[i].Num;
		}
		else
		{
			SumPrice += A[i].Price * n;
			break;
		}

	}
	cout << SumPrice << endl;
	delete[] A;
	return 0;
}
