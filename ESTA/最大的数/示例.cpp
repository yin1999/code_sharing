#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int c;
	cin >> c;     //输入需要处理几个数
  
	while (c--)    //while+自减 进行两次循环
	{
		char a[101], b[101];    //a数组储存输入的数，b数组储存处理后的结果
		int m, count = 0;    //count用来储存现在该在b数组的哪一个位置储存字符了，在内层while循环中初始化为0
		cin >> a >> m;
		int length = strlen(a), temp = -1;   //temp=-1的原因参考第20行注释，自己理解
		m = length - m;    //用m来储存该找出几个数（这样做比删去数组中的数简单）
    
		while (m--)   //m自减循环
		{
			for (int i = ++temp ; i <= length - m; i++)    //i=++temp需要好好理解，应为在进行第二次以上的内层循环时，a的下标应向后进一，不能将之前用过的数再用一次
			{    //i<=length-m 是因为不能找最大数找到这个下标后面，会导致不能找出该有的数的位数（有少一位及以上的风险）
				if (a[temp] < a[i])
					temp = i;
			}
			b[count++] = a[temp];
		}
    
		b[count] = '\0';    //字符数组结束符不要忘记
		cout << b << endl;
	}
  
	return 0;
}
