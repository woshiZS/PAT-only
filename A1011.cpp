#include<cstdio>
int main()
{
    char symbol[3] = { 'W','T','L' };
	int pos[3];
	double sum = 1;
	for (int i = 0; i < 3; i++)
	{
		double a, b, c;
		scanf("%lf%lf%lf", &a, &b, &c);
		if (a > b&&a > c)
		{
			pos[i] = 0;
			sum *= a;
		}
		else if (b > a&&b > c)
		{
			pos[i] = 1;
			sum *= b;
		}
		else if (c > a&&c > b)
		{
			pos[i] = 2;
			sum *= c;
		}
	}
	sum = (sum*0.65 - 1) * 2;
	printf("%c %c %c %.2f", symbol[pos[0]], symbol[pos[1]], symbol[pos[2]], sum);
	return 0;
}
