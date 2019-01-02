#include <iostream>
using namespace std;

class Test
{
private:
	int n;
	int data[20];
	int num;
public:
	Test(int);
	Test() {}
	int judge(int);
	void process();
	void print();
};

Test::Test(int x)
{
	n = x;
	num = 0;
}

int Test::judge(int k)
{
	for (int i = 2; i <= k; i++)
	{
		if (k % i == 0 && n % i == 0)
			return 0;
	}
	return 1;
}

void Test::process()
{
	int MAX = n / 3;
	for (int i = n / 4; i <= MAX; i++)
	{
		if (judge(i) == 1)
			data[num++] = i;
	}
}

void Test::print()
{
	if (num)
	{
		for (int i = 0; i < num; i++)
			cout << data[i] << '/' << n << '\t';
		cout << endl;
	}
	else
		cout << "None!" << endl;
}

int main()
{
	cout << "Please input an integer" << endl;
	int x;
	cin >> x;
	Test ans(x);
	ans.process();
	ans.print();
	return 0;
}
