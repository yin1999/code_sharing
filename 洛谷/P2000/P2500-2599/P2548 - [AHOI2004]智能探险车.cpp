#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    char (*str)[11] = new char[N][11];
    char temp[11];
    for (int i = 0; i < N; i++)
        cin >> str[i];
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> temp;
            if (strcmp(temp, str[j]))
                str[j][0] = '*';
        }
    }
    if (str[0][0] == '*')
        cout << '*';
    else
        cout << str[0];
    for (int i = 1; i < N; i++)
    {
        cout << ' ';
        if (str[i][0] == '*')
            cout << '*';
        else
            cout << str[i];
    }
    delete[] str;
    return 0;
}
