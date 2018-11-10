/*
思路介绍：
到第i个块的放法有两种类型，第一是前一个竖放，则有到第i-1块的方法，第二种是前面横放，则有到第i-2块的方法，加起来就是到第i块的方法
*/
#include<iostream>
using namespace std;

int main()
{
	int length;
	while (cin >> length)
	{
		long long room[50] = { 1,2,3 };
		for (int i = 3; i < length; i++)
			room[i] = room[i - 1] + room[i - 2];
      
		cout << room[length - 1] << endl;
	}
	return 0;
}
