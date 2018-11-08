
#include <iostream>
#include <set>
 
using namespace std;
 
int main()
{
    int n, m, val;
    set<int> result;   //定义result集合
 
    while(cin >> n >> m) {
        if(n == 0 && m == 0)
            break;
 
        result.clear();
 
        // n个元素放进集合中
        for(int i=1; i<=n; i++) {
            cin >> val;
            result.insert(val);
        }
 
        // m个元素，如果在集合中，则删除该元素
        for(int i=1; i<=m; i++) {
            cin >> val;
 
            if(result.find(val) != result.end()) {
                result.erase(val);
            }
        }
 
        // 打印输出结果
        if(result.size() == 0)
            cout << "NULL" << endl;
        else {
            for(set<int>::iterator it = result.begin(); it != result.end(); it++)
                cout << *it << " ";
            cout << endl;
        }
    }
 
    return 0;
}
