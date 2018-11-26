//链表小测试
#include<iostream>
using namespace std;

typedef struct dataline
{
	int a[3];
	dataline * next;   //记录下一个结构体的地址
} datatype;

int main()
{
	datatype* head = new datatype;   //分配空间，并把地址存入head
	datatype* q = head;
	if (head == NULL)
		return -1;
	int count1 = -1, temp;

	cout << "请输入一个数组，输入Ctrl+z终止输入流" << endl;
	while (cin >> temp)
	{
		if (count1++ == 2)   //如果输入了3个数而又要继续输入了，则new一个新的结构体
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
	while (q != 0)   //判断指向地址是否为0，若为零，则说明delete完成（这个循环连起来看）
	{
		datatype* next = q->next;   //先储存下一个结构体的首地址
		delete q;   //delete
		q = next;    //使q指向下一个结构体地址
	}
	return 0;
}
