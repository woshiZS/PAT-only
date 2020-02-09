#include<cstdio>
#include<cstring>
int main()
{
	char name[10][10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	char target[150];
	scanf("%s", target);
	int sum = 0;
	int len = strlen(target);
	for (int i = 0; i < len; i++)
		sum += (target[i] - '0');
	if (sum == 0)
		printf("zero");
	int ans[5];
	int count = 0;
	while (sum)
	{
		ans[count++] = sum % 10;
		sum /= 10;
	}
	for (int i = count - 1; i >= 0; i--)
	{
		printf("%s", name[ans[i]]);
		if (i != 0)
			printf(" ");
	}
	printf("\n");
	return 0;
}
