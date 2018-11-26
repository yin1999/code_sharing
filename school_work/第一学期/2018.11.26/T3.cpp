//链表小测试
#include<iostream>
using namespace std;

typedef struct dataline
{
	int a[3];
	dataline * next;
} datatype;

int main()
{
	datatype* head = new datatype;
	datatype* q = head;
	if (head == NULL)
		return -1;
	int count1 = -1, temp;

	cout << "请输入一个数组，输入Ctrl+z终止输入流" << endl;
	while (cin >> temp)
	{
		if (count1++ == 2)
		{
			datatype* t = new datatype;
			if (t == NULL)
				return -1;
			q->next = t;
			q = t;
			count1 = 0;
		}
		q->a[count1] = temp;
	}

	q->next = 0;
	q = head;

	while (q->next != 0)
	{
		for (int i = 0; i < 3; i++)
			cout << q->a[i] << '\t';
		q = q->next;
	}
	for (int i = 0; i <= count1; i++)
		cout << q->a[i] << '\t';
	cout << endl;

	q = head;
	while (q != 0)
	{
		datatype* next = q->next;
		delete q;
		q = next;
	}
	return 0;
}
