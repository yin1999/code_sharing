#include<iostream>
using namespace std;

void print_width(int width)   //打印横行
{
	cout << "+";
	for (int i = 0; i < width; i++)
		cout << "-";
	cout << "+" << endl;
}

void print_height(int width)   //打印竖列
{
	cout << "|";
	for (int i = 0; i < width; i++)
		cout << " ";
	cout << "|" << endl;
}

int main()
{
	int width, height;
	while (cin >> width >> height)
	{
		print_width(width);
		for (int i = 0; i < height; i++)
			print_height(width);
		print_width(width);
		cout << endl;
	}
	return 0;
}
