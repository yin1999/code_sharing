#include <stdio.h>

unsigned map[5][5] {
	{0, 0, 1, 1, 0},
	{1, 0, 0, 1, 0},
	{0, 1, 0, 0, 1},
	{0, 0, 1, 0, 1},
	{1, 1, 0, 0, 0}
};

int main() {
	int a, b, n;
	scanf("%d%d%d", &n, &a, &b);
	int arr_a[200], arr_b[200];
	int i, j = 0, k = 0;
	for (i = 0; i < a; ++i) {
		scanf("%d", arr_a+i);
	}
	for (i = 0; i < b; ++i) {
		scanf("%d", arr_b+i);
	}
	int ans_a = 0, ans_b = 0;
	for (i = 0; i < n; i++) {
		if (j == a) {
			j = 0;
		}
		if (k == b) {
			k = 0;
		}
		ans_a += map[arr_a[j]][arr_b[k]];
		ans_b += map[arr_b[k]][arr_a[j]];
		++j;
		++k;
	}
	printf("%d %d\n", ans_a, ans_b);
	return 0;
}
