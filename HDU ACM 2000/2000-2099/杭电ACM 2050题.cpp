//关于此题的详细解释见<https://blog.csdn.net/lishuhuakai/article/details/8518245>

#include<iostream>
using namespace std;

int main()
{
	int c;
	cin >> c;
	while(c--)
	{
		int n;
		cin >> n;
		cout << 2 * n*n - n + 1 << endl;
	}
	return 0;
}
