#include<iostream>
using namespace std;

int main()
{
	int n, end, start;
	cin >> n;
	char a[1024];   //定义的字符数组大一点就OK，1024纯属为了好看
	while (n--)
	{
		bool flag = true;  //储存是否为回文，初始化为true
		cin >> a;
		end = strlen(a) - 1;   //千万不要忘记减一
		start = 0;
    
		while (start < end)
		{
			if (a[start] != a[end])  //判断对称位置上的字符是否相同，不相同则给flag赋值false并break
			{
				flag = false;
				break;
			}
			start++;
			end--;
		}
    
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
