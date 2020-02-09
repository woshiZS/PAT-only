#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int p[100];
int hashtable[100] = { 0 };
int n;
void generate(int index)
{
	if (index == n + 1)
	{
		for (int i = 1; i <= n; i++)
			printf("%d", p[i]);
		printf("\n");
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (hashtable[i] == 0)
			{
				p[index] = i;
				hashtable[i] = 1;
				generate(index + 1);
				hashtable[i] = 0;
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	generate(1);
	return 0;
}
