//这题很简单，就不写额外的注释了
#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int sum = 3, a;
		cin >> a;
		for (int i = 0; i < a; i++)
			sum = 2 * sum - 2;
		cout << sum << endl;
	}
  return 0;
}
