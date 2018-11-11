//这题是在杭电ACM 2048题的基础上略有修改，要计算N个新浪中，有M个找错，那只要计算M个人全找错的方法数与N个人中有(N-M)个人找对的找对的人的选择数的乘积
#include<iostream>
using namespace std;

int main()
{
	int c;
	cin >> c;
	long long room[21] = { 0,1 };    //计算M个人全排错的全部方法
	for (int i = 2; i < 21; i++)
		room[i] = i * (room[i - 1] + room[i - 2]);
    
	while(c--)
	{
		int N, M;
		cin >> N >> M;
    
		long long sum = N;   //组合数计算，结果存到sum中
		if (N == M)
			sum = 1;
		else
		{
			for (int i = 1; i < N - M; i++)
				sum = sum * (N - i) / (i + 1);
		}
    
		cout << room[M - 1] * sum << endl;
	}
	return 0;
}
