//此题过水
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int X[100], Y[100];
	int i;
	for (i = 0; i < n; i++)
		cin >> X[i];
	for (i = 0; i < n; i++)
		cin >> Y[i];
    
	sort(X, X + n);   //排序
	sort(Y, Y + n);
  
	bool flag = true;
	for (i = 0; i < n; i++)
	{
		if (X[i] > Y[i])
		{
			cout << "NE" << endl;
			flag = false;
			break;
		}
	}
  
	if (flag)
		cout << "DA" << endl;
    
	return 0;
}
