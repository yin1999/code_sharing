#include<iostream>
using namespace std;

void addup( int &sum, int &money,int val)
{
	while ( money >= val )
	{
		sum += money / val;
		money %= val;
	}
}

int main()
{
	int n;
	while( cin >> n && n )
	{
		int sum = 0;
		for ( int i = 0; i < n; i++ )
		{
			int money;
			cin >> money;
			addup( sum, money, 100 );
			addup( sum, money, 50 );
			addup( sum, money, 10 );
			addup( sum, money, 5 );
			addup( sum, money, 2 );
			sum += money;
		}
		cout << sum << endl;
	}
	return 0;
}
