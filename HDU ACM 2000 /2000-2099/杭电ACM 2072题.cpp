//此代码无法AC，只供保存
//网上看到要考虑的情况有，开头有空格，全为空格，单词中间有多个空格 结尾有空格
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	string a;
	char b[100][100] = { '\0' };   //保证二维数组中每一个数组的第一位都为空字符，用于最后一位不是空格，但需要让行数进一（总的字符个数）
	bool c[100] = { false };    //储存前面是否有相同的字符串
	while (getline(cin, a) && a[0] != '#')
	{
		int r = 0, l = -1, count = 0;    //r为行，l为列，count用于不同单词计数
		for (unsigned int i = 0; i < a.size(); i++)
		{
			if (a[i] != ' ')
				b[r][++l] = a[i];
			else if (l != -1)
			{
				b[r][++l] = '\0';
				r++;
				l = -1;
			}
		}
		if (l!=-1 && b[r][l] != '\0')
		{
			b[r][++l] = '\0';
			r++;
		}

		for (int i = 0; i < r; i++)
		{
			if (c[i])    //与前面有相同的字符串则跳至下一个字符串
				continue;
			count++;    //与前面的都不同则计数
			for (int j = i + 1; j < r; j++)
			{
				if (strcmp(b[i], b[j]) == 0)    //找后面是否有相同的字符串，有的则给相应的bool型变量赋true
					c[j] = true;
			}
		}
		cout << count << endl;  //输出结果
	}
}
