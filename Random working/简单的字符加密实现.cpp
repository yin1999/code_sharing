#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main()
{
	int seed_temp;
	cout<<"请输入加密钥匙(整型数字)"<< endl;
	cin>>seed_temp;
	srand(seed_temp);
	string str;
	cout<<"请输入你要加密的文本"<< endl;
	cin>>str;
	for(int i=0;str[i]!='\0';i++)
	{
		str[i]=str[i]-rand()%50;
	}
	cout<<str;
	return 0;
}
