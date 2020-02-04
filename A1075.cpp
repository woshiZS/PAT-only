#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct candidate
{
	int id;
	int s[5] = { -2,-2,-2,-2,-2 };
	//int rank;
	int num_pft = 0;
	int sum = 0;
	int flag = 0;
}list[10000];
bool cmp(candidate a, candidate b)
{
	if (a.flag != b.flag)
		return a.flag > b.flag;
	else if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.num_pft != b.num_pft)
		return a.num_pft > b.num_pft;
	else
		return a.id < b.id;
}
int main()
{
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	int* p = new int[k];
	for (int i = 0; i < k; i++)
		scanf("%d", p + i);
	for (int i = 0; i < m; i++)
	{
		int id;
		int p_n, score;
		scanf("%d %d %d", &id, &p_n, &score);
		//先是哪个id就放在哪个下表减1下面，然后分数按照之前一样的去判定
		list[id - 1].id = id;
		if (score > list[id - 1].s[p_n - 1])
		{
			list[id - 1].s[p_n - 1] = score;
			if (score == p[p_n - 1])
				list[id - 1].num_pft++;
			if (score >= 0)
				list[id - 1].flag = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (list[i].s[j] >= 0)
				list[i].sum += list[i].s[j];
		}
	}
	sort(list, list + n, cmp);
	int r = 1;
	for (int i = 0; i < n; i++)
	{
		if (!list[i].flag)
			break;
		if (i > 0 && list[i].sum != list[i - 1].sum)
			r = i + 1;
		printf("%d %05d %d", r, list[i].id, list[i].sum);
		for (int j = 0; j < k; j++)
		{
			if (list[i].s[j] >= 0)
				printf(" %d", list[i].s[j]);
			else if (list[i].s[j] == -2)
				printf(" -");
			else
				printf(" 0");
		}
		printf("\n");
	}
	return 0;
}
