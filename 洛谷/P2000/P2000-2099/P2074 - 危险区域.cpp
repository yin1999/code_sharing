/*
根据题目样例，其没有考虑街区点被重复计数的问题，而且对距离的概念也不清晰，问题比较大。
我选择了记录每一个节点存在的可能危险的区域的位置信息，然后进行排序，筛掉所有重复的点，输出结果
当然，它有一个比较大的问题，当T = 300时，单个爆炸点造成的危险位置点的数量达到了70000，在目前的能力水平之下，当前的算法不可避免地会碰到超时的问题
由于题目到2019/4/13还没有修改数据，这题在我的能力水平下还没有能够解决的算法(当然，题目不改也没有正确解)
*/
#include <iostream>
#include <cmath>
using namespace std;

struct point
{
    int x, y;
};

point* Dis_P;
int (*func)(point&);

int de_space(int T)
{
    int i = 0, j, _count = 0;
    for (; i < T; i++)
    {
        for (j = 0; j < T; j++)
        {
            if (sqrt((T - i) * (T - i) + (T - j) * (T - j)) <= T)
                _count++;
        }
    }
    return _count;
}

void Find_point(int T)
{
    int _count = 0;
    for (int i = 1; i <= T; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            if (sqrt(i * i + j * j) <= T)
                Dis_P[_count++] = { i, j };
            else
                break;
        }
    }
}

int Get_x(point& T)
{
    return T.x;
}

int Get_y(point& T)
{
    return T.y;
}

void Sort(point s[], int length)
{
	if (length <= 7)
	{
		int i = 1, j;
		point temp;
		for (; i < length; i++)
		{
			temp = s[i];
			for (j = i - 1; j >= 0 && func(s[j]) > func(temp); j--)
				s[j + 1] = s[j];
			s[j + 1] = temp;
		}
		return;
	}
	if (func(*(s + length / 2 - 1)) > func(*(s + length - 1)))
		swap(*(s + length / 2 - 1), *(s + length - 1));
	if (func(*s) > func(*(s + length - 1)))
		swap(*s, *(s + length - 1));
	if (func(*s) < func(*(s + length / 2 - 1)))
		swap(*s, *(s + length / 2 - 1));
	point key = *s;
	int left = 0, right = length - 1;
	int high = right, low = 0;
	while (left < right)
	{
		while (left < right && func(s[right]) >= func(key))
		{
			if (func(s[right]) == func(key))
			{
				swap(s[right], s[high]);
				high--;
			}
			right--;
		}
		s[left] = s[right];
		while (left < right && func(s[left]) <= func(key))
		{
			if (func(s[left]) == func(key))
			{
				swap(s[low], s[left]);
				low++;
			}
			left++;
		}
		s[right] = s[left];
	}
	s[left] = key;
	int i = left - 1, j = 0;
	while (j < low && func(s[i]) != func(key))
	{
		swap(s[j], s[i]);
		i--;
		j++;
	}
	Sort(s, left - low);
	i = left + 1;
	j = length - 1;
	while (j > high && func(s[i]) != func(key))
	{
		swap(s[j], s[i]);
		j--;
		i++;
	}
	Sort(s + right + length - high, high - right);
}

int main()
{
    int N, M, K, T;
    cin >> N >> M >> K >> T;
    int Dis_num = de_space(T);
    Dis_P = new point[Dis_num];
    Find_point(T);
    point* P = new point[K * (4 * (Dis_num + T) + 1)];   //最多有K * (4 * (Dis_num + T) + 1)个街区受到威胁
    int x, y, i, tx1, ty1, tx2, ty2, _count = 0;
    while (K--)
    {
        cin >> x >> y;
        for (i = 0; i < Dis_num; i++)
        {
            tx1 = Dis_P[i].x + x;
            ty1 = Dis_P[i].y + y;
            tx2 = x - Dis_P[i].x;
            ty2 = y - Dis_P[i].y;
            if (tx1 > 0 && tx1 <= N)
            {
                if (ty1 > 0 && ty1 <= M)
                    P[_count++] = { tx1, ty1 };
                if (ty2 > 0 && ty2 <= M)
                    P[_count++] = { tx1, ty2 };
            }
            if (tx2 > 0 && tx2 <= N)
            {
                if (ty1 > 0 && ty1 <= M)
                    P[_count++] = { tx2, ty1 };
                if (ty2 > 0 && ty2 <= M)
                    P[_count++] = { tx2, ty2 };
            }
        }
        for (i = max(x - T, 1); i <= min(N, x + T); i++)
            P[_count++] = { i, y };
        for (i = max(y - T, 1); i < y; i++)
            P[_count++] = { x, i };
        for (i = y + 1; i < min(y + T, M); i++)
            P[_count++] = { x, i };
    }
    func = Get_x;
    Sort(P, _count);
    int t, j;
    func = Get_y;
    for (i = 0; i < _count; i++)
    {
        t = P[i].x;
        for (j = i + 1; j < _count; j++)
        {
            if (P[j].x == t)
                continue;
            else
            {
                Sort(P + i, j - i + 1);
            }
        }
        i = j;
    }
    if (t == P[_count - 1].x)
        Sort(P + i, _count - i);
    point temp = { 0, 0 };
    int MAXNUM = _count;
    for (i = 0; i < _count; i++)
    {
        if (func(temp) == P[i].x && temp.y == P[i].y)
            MAXNUM--;
        else
            temp = P[i];
    }
    cout << MAXNUM << endl;
    delete[] P;
    delete[] Dis_P;
    return 0;
}
