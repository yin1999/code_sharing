#include <iostream>
using namespace std;


class NODE
{
private:
    int data;
    NODE *next = 0;
public:
    void insertdata();
    void createnode();
    void clear();
    void sort(int);
    void show();
};

void NODE::createnode()   //创建链表
{
    if (this->next)
    {
        cout << "You have already created a NODE" << endl;
        return;
    }
    else
    {
        int n;
        cout << "Please input an integer" << endl;
        cin >> n;
        NODE *t = new NODE;
        t->data = n;
        this->next = t;
    }
}

void NODE::insertdata()   //插入数据
{
    if (this->next == 0)
    {
        cout << "You haven't created a NODE yet" << endl;
        return;
    }
    else
    {
        cout << "Please input how many integer do you want to input, then the integers" << endl;
        int n, temp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            NODE *t = new NODE;
            if (t == 0)
            {
                cout << "The RAM space is not enough to store the ingeger" << endl;
                return;
            }
            t->data = temp;
            NODE *p = this;
            while (p->next != 0)
            {
                p = p->next;
            }
            p->next = t;
        }
    }
}

void NODE::clear()   //删除链表
{
    NODE *p, *q;
    p = this->next;
    while (p != 0)
    {
        q = p->next;
        delete p;
        p = q;
    }
    cout << "The NODE has been cleared" << endl;
}

void NODE::sort(int length)   //排序（从第一个到第length个）
{
    NODE *q = this->next, *k, *end = q;
    int t;
    for (int i = 1; i < length; i++)
    {
        if (end->next != 0)
            end = end->next;
    }
    while (1)
    {
        k = q->next;
        while (1)
        {
            if (k->data < q->data)
            {
                t = k->data;
                k->data = q->data;
                q->data = t;
            }
            if (k == end)
                break;
            k = k->next;
        }
        if (q->next == end)
            break;
        q = q->next;
    }
}

void NODE::show()   //输出链表内所有数据
{
    NODE *p = this->next;
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
    a.createnode();
    a.insertdata();
    cout << "The initial NODE data" << endl;
    a.show();
    a.sort(10);
    cout << endl << "The sorted NODE data" << endl;
    a.show();
    a.clear();
    return 0;
}
