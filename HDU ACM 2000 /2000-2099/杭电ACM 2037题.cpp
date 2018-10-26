/*算法的实现：
贪心算法，将结束时间从小到大排一遍，然后比较上一个节目的结束时间和下一个节目的开始时间
若结束时间小于开始时间，则观看完整节目数加一；
若没能完整观看，则不看这个节目（防止时间被浪费）
*/
#include<iostream>
using namespace std;

void swap(int& a, int& b)  //交换数组函数
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int N;
	int Ti_s[100], Ti_e[100];

	while (cin >> N && N)
	{
		for (int i = 0; i < N; i++)
			cin >> Ti_s[i] >> Ti_e[i];
      
		for (int i = 0; i < N; i++)    //按结束时间从小到大排序
		{
			int temp = i;
			for (int j = i+1; j < N; j++)
			{
				if (Ti_e[temp] > Ti_e[j])
					temp = j;
			}
			swap(Ti_e[temp], Ti_e[i]);
			swap(Ti_s[temp], Ti_s[i]);
		}
    
		int tempi = 0, sum =1;     //tempi储存能够完整观看的节目，仅储存已知的最后一个
		for (int k = 1; k < N; k++)
		{
			if (Ti_s[k] >= Ti_e[tempi])
			{
				tempi = k;
				sum++;
			}
		}
		cout << sum << endl;
    }
}
