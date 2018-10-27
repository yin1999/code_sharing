#include<iostream>
#include<cmath>
using namespace std;

void swap( int &a, int &b )   //交换数组
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int N;
	while( cin >> N && N )
	{
		int a[100];
		for ( int i = 0; i < N; i++ )
		    cin >> a[i];
		    
		for ( int j = 0; j < N; j++ )  //选择排序
		{
			int temp = j;
			for ( int k = j + 1; k < N; k++ )
			{
				if( abs( a[temp] ) < abs( a[k] ) )
				    temp = k;
			}
			swap( a[temp], a[j] );
		}
    
		cout << a[0];
		for ( int i = 1; i < N; i++ )
		    cout <<" " << a[i];
		cout << endl;
	}
}
