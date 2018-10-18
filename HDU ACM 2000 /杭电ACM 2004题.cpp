#include<iostream>
using namespace std;

int main()
{
	double num;
	while (cin >> num)
	{
		if (num > 100)
			cout << "Score is error!" << endl;
		else if (num >= 90 && num <= 100)
			cout << "A" << endl;
		else if (num >= 80)
			cout << "B" << endl;
		else if (num >= 70)
			cout << "C" << endl;
		else if (num >= 60)
			cout << "D" << endl;
		else if (num >= 0)
			cout << "E" << endl;
		else
			cout<< "Score is error!" << endl;
	}
}
