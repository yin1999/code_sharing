#include<iostream>
#include<iomanip>
using namespace std;

int A[1000001];

int main()
{
	int n;
	double x;
	cin >> n >> x;
	for (int i = 0; i <= n; i++)
	{
		cin >> A[i];
	}
	int count = 0;
	double ans = 0;
  
	while (n)                     //秦九韶乘法算导数
	{
		ans = ans*x + n*A[count];
		n--;
		count++;
	}
  
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}
