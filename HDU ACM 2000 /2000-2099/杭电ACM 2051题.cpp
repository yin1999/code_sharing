#include<iostream>
using namespace std;

int main()
{
	int base_ten;    //储存10进制数
	while (cin >> base_ten)
	{
		int base_two = 0;    //储存二进制数
		int bit = 1;   //储存现在到第几位了，二进制第一位为1，第二位为10，以此类推

		while (base_ten)
		{
			base_two += base_ten % 2 * bit;
			bit *= 10;
			base_ten /= 2;
		}
    
		cout << base_two << endl;   //输出
	}
	return 0;
}
