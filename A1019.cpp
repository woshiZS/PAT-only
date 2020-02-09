#include<cstdio>
int main()
{
    int n, p;
	scanf("%d%d", &n, &p);
	int nums[100];
	int i = 0;
	while (n)
	{
		nums[i++] = n%p;
		n /= p;
	}
	if (i == 0)
		printf("Yes\n0");
	else
	{
		int flag=1;
		for (int j = 0; j < i / 2; j++)
		{
			if (nums[j] != nums[i - j - 1])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
		for (int j = i - 1; j >= 0; j--)
		{
			printf("%d", nums[j]);
			if (j != 0)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
