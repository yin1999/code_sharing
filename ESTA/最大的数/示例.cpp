#include <stdio.h>
#include <string.h>

int main() {
	char num[105], ans[105];
	int n, del;
	int length_old, length_new, index, i, j;
	scanf("%d", &n);
	while (n--) {
		scanf("%s%d", num, &del);
		length_old = strlen(num);
		length_new = length_old - del;
		index = 0;
		for (i = 0; length_new; i++) {
			for (j = index + 1; j <= length_old - length_new; j++) {
				if (num[j] > num[index]) {
					index = j;
				}
			}
			ans[i] = num[index];
			++index;
			--length_new;
		}
		ans[i] = 0;
		printf("%s\n", ans);
	}
}
