#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main()
{
	string str;
	int seed_temp;
	cin>>seed_temp;
	srand(seed_temp);
	cin>>str;
	for(int i=0;str[i]!='\0';i++)
	str[i]=str[i]+rand()%50;
	cout<<str<<endl;
	return 0;
}
