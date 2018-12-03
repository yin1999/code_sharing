#include <iostream>
using namespace std;

bool a[10];    //用于标记相应的数是否被使用
int b[10];    //用于按顺序储存已经用过的数（如3 1 2）
int count1;   //用于标记b数组下标

void lists(int all, int remain)    //定义全排列生成函数，输入量分别为全排列的长度和剩余数个数
{
	if (remain == 0)    //若剩余数个数为0，则已经找到一个全排列数，它被储存在b数组中，下面使用循环输出
	{
		for (int i = 0; i < all; i++)
			cout << b[i];
		cout << endl;
	}
	else    //若剩余个数不为0，则说明仍有数没使用，使用循环遍历a数组，找出标记仍然为真的数
		for (int i = 1; i <= all; i++)
		{
			if (a[i])    //如果标记为真，则找到一个数
			{
				a[i] = false;   //先标记为使用过该数
				b[count1++] = i;    //将它储存到b数组中
				lists(all, remain - 1);   //继续探索下一位数
				a[i] = true;   //回溯，回到当前层时，需要给它标记为true（没使用过）
				count1--;    //也是回溯
			}
		}
}
int main()
{
	int n;
	cout << "请输入1-9之间的任意整数，输入Ctrl+z终止输入流" << endl;
	while (cin >> n)    //输入全排列长度
	{
		count1 = 0;    //初始化
		for (int i = 1; i < 10; i++)    //初始化
			a[i] = true;
		lists(n, n);
	}
	return 0;
}
