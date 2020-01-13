#include <stdio.h>

int map[10000][100][2] = {};
int num[10000] = {};
int room;

inline int getRoomNum(int floor, int now) {
	int i = (map[floor][now][1]-1) % num[floor];
	int n = now;
	while (map[floor][n][0] == 0) {
		if (++n == room) {
			n = 0;
		}
	}
	while (i) {
		if (++n == room) {
			n = 0;
		}
		if (map[floor][n][0]) {
			--i;
		}
	}
	return n;
}

int main() {
	int n, now;
	scanf("%d%d", &n, &room);
	int i = 0, j;
	for (; i < n; ++i) {
		for (j = 0; j < room; ++j) {
			scanf("%d%d", map[i][j], map[i][j] + 1);
			num[i] += map[i][j][0];
		}
	}
	int roomNum, ans = 0;
	scanf("%d", &roomNum);
	for (i = 0; i < n; ++i) {
		ans = (ans+map[i][roomNum][1]) % 20123;
		roomNum = getRoomNum(i, roomNum);
	}
	printf("%d\n", ans);
	return 0;
}
