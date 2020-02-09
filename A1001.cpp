#include<cstdio>
#include<cstring>
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int c = a + b;
	if (c < 0)
	{
		printf("-");
		c = -c;
	}
    if (c == 0)
		printf("0");
	//现在有一个思路是把每一位都存储到字符数组里面，然后reverse一下，每三个就加一个逗号。
	char target[15];
	char ans[15];
	int count = 0;
	while (c)
	{
		target[count++] = (c % 10) + 48;
		c /= 10;
	}
	int pos = 0;
	for (int i = 0; i < count; i++)
	{
		//printf("%c", target[i]);
		ans[pos++] = target[i];
		if (i % 3 == 2 && i != count - 1)
			ans[pos++] = ',';
	}
	for (int i = pos - 1; i >= 0; i--)
		printf("%c", ans[i]);
	printf("\n");
	return 0;
}
