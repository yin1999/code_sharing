#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int m;
		double	t, max;
    
		cin >> m;
    
		cin >> max;
    
		for (int i = 1; i < m; i++)
		{
    
			cin >> t;
			if (t > max)
				max = t;
        
		}
    
		cout << fixed << setprecision(2) << max << endl;
    
	}
}
