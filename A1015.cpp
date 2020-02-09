#include<cstdio>
#include<cstring>
bool isprime(int a)
{
	if (a == 1)
		return false;
	else if (a == 2)
		return true;
	else
	{
		for (int i = 2; i < a; i++)
		{
			if (a%i == 0)
				return false;
		}
		return true;
	}
}
int main()
{
	int n, d;
	while (true)
	{
		scanf("%d", &n);
		if (n < 0)
			break;
		scanf("%d", &d);
        int temp=n;
		//主要是进制转换的问题
		int target[100];
		int count = 0;
		while (n)
		{
			target[count++] = n%d;
			n /= d;
		}
		int sum = 0;
		for (int i = 0; i < count; i++)
		{
			sum = sum*d + target[i];
		}
		if (isprime(temp) && isprime(sum))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
