#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class dict
{
public:
    int id;
    int count;
    dict() { id = 0; count = 0; }
};


void sort(dict* array)
{
    int i, j;
    dict temp;
    for (i = 1; i < 26; i++)
    {
        temp = array[i];
        for (j = i - 1; j >= 0; j--)
        {
          //排序按计数次数从大到小排，在计数次数一样的情况下考虑id从小到大排
            if ((array[j].count < temp.count) || (array[j].count == temp.count && array[j].id > temp.id))
                array[j + 1] = array[j];
            else
                break;
        }
        array[j + 1] = temp;
    }
}

int main()
{
    char str[101];
    dict array[26];
    for (int i = 0; i < 26; i++)
        array[i].id = i;
    for (int i = 0; i < 4; i++)
    {
        cin.getline(str, 101);
        for (unsigned j = 0; j < strlen(str); j++)
        {
            if (str[j] >= 'A' && str[j] <= 'Z')
                array[int(str[j] - 'A')].count++;
        }
    }
    sort(array);
    int same = 1;
    for (; same < 26; same++)
    {
        if (array[same].count != array[same - 1].count)
            break;
    }
    int i, id, max_num;
    bool flag;
    while (array[0].count)
    {
        id = 0;    //记录，现在对char('A' + id)进行输出
        for (i = 0; i < same; i++)
        {
            for (; id < array[i].id; id++)  //若当前需要输出星号的id小于当前输出的id，则用两个空格占位
                printf("  ");
                
            array[i].count--;
            if (i != 25 && id != 25)  //判断输出的是否为一行的末尾
                printf("* ");      //不是末尾，星号后面加空格
            else
                printf("*");   //末尾，星号后面不能有空格
            id++;
        }
        max_num = array[0].count;
        flag = false;
        for (; i < 26; i++)
        {
            if (max_num == array[i].count)
            {
                same++;
                flag = true;
            }
            else
                break;
        }
        if (flag)
            sort(array);
        printf("\n");
    }
    printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
    return 0;
}
