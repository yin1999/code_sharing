#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdbool.h>

int main()
{
	char a[1010], b[1010];
	int i, length_a, length_b;
	bool flag = false;   //用于储存最高位是否需要进一，初始化为false（不用进1）
	scanf("%s", a);   //输入两个数（各不超过1009位），位数限定可以在定义行进行更改
	scanf("%s", b);
	
	if (strlen(a) < strlen(b))    //将位数多的数放前面，方便运算
	{
		char temp[1010];
		strcpy(temp, a);
		strcpy(a, b);
		strcpy(b, temp);
	}

	length_a = strlen(a);    //储存a和b两个字符串中字符的长度
	length_b = strlen(b);
	
	for (i = 1; i <= length_b; i++)    //记得从1开始减，字符串最后一位为结束符,不要把结束符给改了（字符串是从0开始的）
	{
		a[length_a-i] = a[length_a-i] + b[length_b-i] - '0';   //从最末位开始计算，想想你数字是怎么写的（ASCII码计算数字）
		if (a[length_a - i] > '9'&&length_a-i-1>=0)   //判断要不要进1（同时考虑是不是最高位，最高位在这里进1就要内存溢出了）
		{
			a[length_a - i -1] = a[length_a - i - 1] + 1;
			a[length_a - i] = a[length_a - i] - 10;
		}
	}
	
	if (a[0] >'9')   //判断最高位是否超过9，超过则给flag赋true
	{
		a[0] = a[0] - 10;  //减10不要忘
		flag = true;
	}
	if (flag)
		printf("1");
	printf("%s\n",a);
}
