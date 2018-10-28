#include<iostream>
using namespace std;

bool judge(char a)
{
	if(a>=48&&a<=57)
	return true;
	else if(a>=65&&a<=90)
	return true;
	else if(a==95)
	return true;
	else if(a>=97&&a<=122)
	return true;
	else
	return false;
}

int main()
{
	int n;
	cin >> n;
	n++;
	while(n--)
	{
		bool flag=true;
		char str[51];
		int count=0;
		for(int i=0;i<51;i++)
		{
			str[i]=getchar();
			if(str[i]=='\n')
			break;
			count++;
		}
		if(!(str[0]>='a' &&str[0]<='z')&&!(str[0]>='A'&&str[0]<='Z'))
		{
			flag=false;
			break;
		}
		for(int j=1;j<count;j++)
		{
			if(!judge(str[j]))
			{
				flag=false;
				break;
			}
		}
		if(!flag)
		break;
	    if(flag)
	    cout<<"yes"<<endl;
	    else
	    cout<<"no"<<endl;
	}
	return 0;
}
