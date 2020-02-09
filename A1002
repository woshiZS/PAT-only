#include<cstdio>
#include<cstring>
int main()
{
    double exponents[1001];
	memset(exponents, 0, sizeof(exponents));
	//printf("%lf %.1lf\n", exponents[0], exponents[1]);
	int n, count = 0;
	scanf("%d", &n);
	while (n)
	{
		int exp;
		double coe;
		scanf("%d%lf", &exp, &coe);
		//printf("%d%lf\n", exp, coe);
		exponents[exp] += coe;
		n--;
	}
	//printf("%lf %.1lf\n", exponents[0], exponents[1]);
	scanf("%d", &n);
	while (n)
	{
		int exp;
		double coe;
		scanf("%d%lf", &exp, &coe);
		exponents[exp] += coe;
		n--;
	}
	for (int i = 0; i <= 1000; i++)
	{
		if (exponents[i] != 0)
			count++;
	}
	if (count == 0)
		printf("0");
	else
		printf("%d ", count);
	int step = 1;
	for (int i = 1000; i >= 0; i--)
	{
		if (exponents[i] != 0 && step != count)
		{
			printf("%d %.1lf ", i, exponents[i]);
			step++;
		}
		else if (exponents[i] != 0 && step == count)
			printf("%d %.1lf", i, exponents[i]);
	}
	printf("\n");
	return 0;
}
