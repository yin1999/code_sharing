//实现功能，链表创建，插入，删除数据，删除链表，显示数据
#include <iostream>
using namespace std;

class NODE   //NODE a
{
private:
	int data;
	NODE *next = NULL;
public:
	void deletedata(int);    //删除数据
	void insertdata(int);    //插入数据
	void createnode(int);    //创建链表
	void clear();            //删除链表
	void showdata();         //显示链表当前包含数据
};

void NODE::deletedata(int x)
{
	NODE *p = this;
	NODE *q, *t;
	while (p->next)
	{
		if ((p->next)->data < x)
			p = p->next;
		else
			break;
	}
	q = p->next;
	if (q)
	{
		bool flag = true;
		while (q->data == x)
		{
			t = q->next;
			delete q;
			p->next = t;
			flag = false;
			q = t;
		}
		if(flag)
			cout << "没有找到该数" << endl;
	}
	else
		cout << "没有找到该数" << endl;
}

void NODE::insertdata(int x)
{
	if (this->next == NULL)
	{
		cout << "尚未创建链表" << endl;
		return;
	}
	NODE *p = this;
	while (p->next)
	{
		if (x > (p->next)->data)
			p = p->next;
		else
			break;
	}
	NODE *t = new NODE;
	if (t == NULL)
	{
		cout << "插入链表失败" << endl;
		return;
	}
	t->data = x;
	t->next = p->next;
	p->next = t;
}

void NODE::createnode(int x)
{
	if (this->next)
		cout << "已经创建了此链表" << endl;
	else
	{
		NODE *t = new NODE;
		if (t == NULL)
		{
			cout << "无法创建链表" << endl;
			return;
		}
		t->data = x;
		this->next = t;
	}
}

void NODE::clear()
{
	NODE *p, *q;
	p = this->next;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	cout << "链表已清除" << endl;
}

void NODE::showdata()
{
	NODE *p = this->next;
	cout << "链表当前包含值为" << endl;
	while (p)
	{
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl;
}

int main()
{
	NODE a;
	int n, t;
	cout << "请输入n来确定创建链表的长度" << endl;
	cin >> n;
	cin >> t;
	a.createnode(t);
	for (int i = 1; i < n; i++)
	{
		cin >> t;
		a.insertdata(t);
	}
	cout << "请输入想删除的值" << endl;
	while (cin >> t)
	{
		a.deletedata(t);
	}
	a.showdata();
	a.clear();
	return 0;
}
