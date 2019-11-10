#include <stdio.h>

int main()
{
	int a0, a1, n;
	scanf("%d%d%d", &a0, &a1, &n);
	long long d = a1 - a0;
	long long ans = (a0 + a0 + d * n - d) * n / 2;
	printf("%lld\n", ans);
	return 0;
}
