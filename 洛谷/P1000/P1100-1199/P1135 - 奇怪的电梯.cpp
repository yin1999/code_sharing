//使用了C++11的特性！！！，提交代码时请选择C++11以上的版本
#include <stdio.h>
#include <queue>
using namespace std;

struct kv {
	int floor;
	int step;
};

int main() {
	int map[201] = {};
	int ans[201] = {};
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int i, j, k;
	for (i = 1; i <= n; ++i) {
		scanf("%d", map + i);
	}
	kv tmp = {a, 1}, pushElem;
	ans[a] = 1;
	queue<kv> q;
	int f, step;
	q.push(tmp);
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		step = tmp.step + 1;
		f = tmp.floor + map[tmp.floor];
		if (f <= n && ans[f] == 0) {
			ans[f] = step;
			pushElem.floor = f;
			pushElem.step = step;
			q.push(std::move(pushElem));
		}
		f = tmp.floor - map[tmp.floor];
		if (f > 0 && ans[f] == 0) {
			ans[f] = step;
			pushElem.floor = f;
			pushElem.step = step;
			q.push(std::move(pushElem));
		}
	}
	printf("%d\n", ans[b] - 1);
	return 0;
}
