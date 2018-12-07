#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>
#define MAX 200
#define LENGTH 100
using namespace std;

typedef struct subrray    //储存最大子数组的左右下标与它的和
{
	int low;
	int high;
	long long int sum;
}ms;

void initial(int *a, int high)   //初始化数组
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i <= high; i++)
		a[i] = rand() % MAX * pow(-1, rand() & 1);
}

void show(int *a, int high)   //输出数组
{
	for (int i = 0; i <= high; i++)
		cout << a[i] << '\t';
}

ms FMCS(int *a, int low, int mid, int high)   //find max crossing subrray   寻找最大中间子数列
{
	long long int sum = 0;
	long long int right_sum = -MAX * (mid - low + 1), left_sum = -MAX * (high - mid + 1);
	int max_left, max_right;
	for (int i = mid; i >= low; i--)
	{
		sum += a[i];
		if (sum > left_sum)
		{
			max_left = i;
			left_sum = sum;
		}
	}
	sum = 0;
	for (int i = mid + 1; i <= high; i++)
	{
		sum += a[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}
	return { max_left, max_right, left_sum + right_sum };
}

ms FMS(int *a, int low, int high)    //find max subrray   寻找最大子数列
{
	if (low == high)
		return { low, low, a[low] };
	int mid = (low + high) / 2;
	ms left = FMS(a, low, mid);
	ms right = FMS(a, mid + 1, high);
	ms center = FMCS(a, low, mid, high);
	if (left.sum >= right.sum && left.sum >= center.sum)
		return { left.low, left.high, left.sum };
	else if (right.sum >= left.sum && right.sum >= center.sum)
		return { right.low, right.high, right.sum };
	else
		return { center.low, center.high, center.sum };
}

int main()
{
	int a[LENGTH];
	initial(a, LENGTH - 1);
	show(a, LENGTH - 1);
	cout << endl << endl;
	ms t = FMS(a, 0, LENGTH - 1);
	cout << setw(12) << "起始下标" << setw(12) << "终止下标" << setw(12) << "最大值" << endl;
	cout << setw(12) << t.low << setw(12) << t.high << setw(12) << t.sum << endl;
	return 0;
}
