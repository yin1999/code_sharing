//使用二维数组构建棋谱
#include<iostream>
using namespace std;


int main()
{
	char maze[3][3] = { 0 };
	int i = 0, temp_int;
	char winner = 0, temp[10];
	cin >> temp;
	while (temp[i])
	{
		temp_int = int(temp[i] - '0');
		if (i & 1)
		{
			maze[(temp_int - 1) / 3][temp_int - (temp_int - 1) / 3 * 3 - 1] = 'u';
		}
		else
			maze[(temp_int - 1) / 3][temp_int - (temp_int - 1) / 3 * 3 - 1] = 'a';
		i++;
	}
	for (int j = 0; j < 3; j++)
	{
		if (maze[j][0] && maze[j][0] == maze[j][1] && maze[j][1] == maze[j][2])
				winner = maze[j][0];
		if (maze[0][j] && maze[0][j] == maze[1][j] && maze[1][j] == maze[2][j])
				winner = maze[0][j];
	}
	if (maze[0][0] && maze[0][0] == maze[1][1] && maze[1][1] == maze[2][2])
		winner = maze[0][0];
	if (maze[2][0] && maze[2][0] == maze[1][1] && maze[1][1] == maze[0][2])
		winner = maze[2][0];
	if (winner == 'a')
	{
		cout << "xiaoa wins." << endl;
		return 0;
	}
	else if (winner == 'u')
	{
		cout << "uim wins." << endl;
		return 0;
	}
		
	if (i == 9 && winner == 0)
		cout << "drew." << endl;
	return 0;
}
