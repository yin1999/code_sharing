/*
直接输入答案： 
192 384 576
219 438 657
273 546 819
327 654 981
*/

//只有三个数满足倍数关系，而且没有数字重复(不能有0)
#include <iostream>
using namespace std;

bool judge(int i)
{
	bool num[10] = { false };
	int temp = i, remain;
	while (temp)
	{
		remain = temp % 10;
		if (remain == 0)
			return false;
		else
			num[remain] = true;
		temp /= 10;
	}
	temp = i * 2;
	while (temp)
	{
		remain = temp % 10;
		if (remain == 0 || num[remain])
			return false;
		else
			num[remain] = true;
		temp /= 10;
	}
	temp = i * 3;
	while (temp)
	{
		remain = temp % 10;
		if (remain == 0 || num[remain])
			return false;
		else
			num[remain] = true;
		temp /= 10;
	}
	return true;
}

int main()
{
	for (int i = 123; i < 333; i++)
	{
		if (judge(i))
			cout << i << ' ' << i * 2 << ' ' << i * 3 << endl;
	}
	return 0;
}
