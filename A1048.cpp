#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int coins[1001] = { 0 };
int main()
{
	int n, payment;
	scanf("%d%d", &n, &payment);
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		coins[num]++;
	}
	int v1 = 0, v2;
	for (int i = 1; i <= payment; i++)
	{
		if (coins[i] && coins[payment - i]&&2*i!=payment)
		{
			v1 = i;
			v2 = payment - v1;
			break;
		}
		else if(coins[i]>=2&&2*i==payment)
		{
			v1 = i;
			v2 = i;
			break;
		}
	}
	if (v1)
		printf("%d %d\n", v1, v2);
	else
		printf("No Solution\n");//注意solution要大写
	return 0;
}
