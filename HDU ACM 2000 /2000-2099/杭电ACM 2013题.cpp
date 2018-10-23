#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 1;
		for (int i = 1; i < n; i++)
			sum = (sum + 1) * 2;    //从第一天向后排每一天都是sum/2-1，那么，逆向则是（sum+1）*2
		cout << sum << endl;
	}
	return 0;
}
