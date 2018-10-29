#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdbool.h>

int main()
{
	char a[1010], b[1010];
	int i, length_a, length_b;
	bool flag = false;
	scanf("%s", a);
	scanf("%s", b);
	if (strlen(a) < strlen(b))
	{
		char temp[1010];
		strcpy(temp, a);
		strcpy(a, b);
		strcpy(b, temp);
	}

	length_a = strlen(a);
	length_b = strlen(b);
	for (i = 1; i <= length_b; i++)
	{
		a[length_a-i] = a[length_a-i] + b[length_b-i] - '0';
		if (a[length_a - i] > '9'&&length_a-i-1>=0)
		{
			a[length_a - i -1] = a[length_a - i - 1] + 1;
			a[length_a - i] = a[length_a - i] - 10;
		}
	}
	if (a[0] >'9')
	{
		a[0] = a[0] - 10;
		flag = true;
	}
	if (flag)
		printf("1");
	printf("%s\n",a);
}
