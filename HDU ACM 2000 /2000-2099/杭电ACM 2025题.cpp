#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char a[100];
	while (cin >> a)
	{
	    int lenth=strlen(a);    //获取字符串长度
	    char temp_str=a[0];
	    for(int i = 1;i < lenth;i++)
        {
            if(a[i] > temp_str)
                temp_str=a[i];
        }
        for(int j=0;j<lenth;j++)
        {
            cout<<a[j];
            if(a[j]==temp_str)
                cout<<"(max)";
        }
        cout<<endl;
	}
	return 0;
}
