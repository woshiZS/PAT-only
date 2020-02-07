#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct individual
{
	int betnum;
	int count = 0;
	int order = 999999;
};
individual target[10001];
//这里我们需要记录开始的输入顺序，按照输入顺序排列并且个数为1来判定输出。
bool cmp(individual a, individual b)
{
	return a.order < b.order;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		target[num].count++;
		target[num].order = i;
		target[num].betnum = num;
	}
	sort(target + 1, target + 10001, cmp);
	int flag = 0;
	for (int i = 1; i <= 10000; i++)
	{
		if (target[i].count == 1)
		{
			printf("%d\n", target[i].betnum);
			flag = 1;
			break;
		}
	}
	if (!flag)
		printf("None\n");
	return 0;
}
