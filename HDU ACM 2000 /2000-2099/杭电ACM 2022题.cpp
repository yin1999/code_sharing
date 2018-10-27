#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int M, N, row, col;   //分别储存行，列，绝对值最大数的行与列
	while (cin >> M >> N)
	{
		int temp1, temp2, tempi = 0;
		cin >> temp1;
		for (int i = 1; i < N*M; i++)    //比较获取绝对值最大数及其所在位置
		{
			cin >> temp2;
			if (abs(temp2) > abs(temp1))
			{
				temp1 = temp2;
				tempi = i;
			}
		}
    
		col = (tempi + 1) % N;   //计算所在列
		if (col == 0)     //如果列的结果为0，则表明它应该在上一行的最后一个，列为N
		{
			col = N;
			row = (tempi + 1) / N;    //行的计算结果
		}
		else
			row = (tempi + 1) / N + 1;   //若列不为0，则行的计算结果要+1（因为整除）
      
		cout << row << " " << col << " " << temp1 << endl;  //输出
	}
	return 0;
}
