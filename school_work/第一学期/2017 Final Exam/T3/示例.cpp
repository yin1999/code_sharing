#include <iostream>
#include <cstring>
using namespace std;

class Test
{
    char *str;
public:
    Test(char *pstr = 0)
    {
        if (pstr != 0)
        {
            str = new char[strlen(pstr) + 1];
            strcpy(str, pstr);
        }
        else
            str = 0;
    }
    Test(Test &);
    ~Test()
    {
        if (str)
            delete[] str;
    }
    Test operator=(Test &);
    void show();
};

Test::Test(Test & t)
{
    if(t.str)
    {
        str = new char[strlen(t.str) + 1];
        strcpy(str, t.str);
    }
    else
        str = 0;
}

Test Test::operator=(Test & t)
{
    if (str)
    {
        str = new char[strlen(t.str) + 1];
        strcpy(str, t.str);
    }
    else
        str = 0;
    return *this;
}

void Test::show()
{
    cout << "str=" << str << endl;
}

int main()
{
    Test obj1((char *)"This is the First Object");
    Test obj2((char *)"This is the Second Object");
    Test obj3;
    Test * p = new Test(obj1);
    obj3 = obj2;
    p->show();
    delete p;
    return 0;
}
