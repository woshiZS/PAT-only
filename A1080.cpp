#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct student
{
	int id;
	int GE;
	int GI;
	int sum;
	int pre[5];
	int rank;
}list[40000];
bool cmp(student a, student b)
{
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else
		return a.GE > b.GE;
}
int school[100][40001] = { 0 };
int main()
{
	
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int* num = new int[m];
	int* lastrank = new int[m];
	memset(lastrank, 0, m * sizeof(int));
	for (int i = 0; i < m; i++)
		scanf("%d", num + i);
	//输入学生信息
	for (int i = 0; i < n; i++)
	{
		list[i].id = i;
		scanf("%d%d%", &list[i].GE, &list[i].GI);
		list[i].sum = list[i].GE + list[i].GI;
		for (int j = 0; j < k; j++)
			scanf("%d", list[i].pre + j);
	}
	//输入完毕，应该讲整体序列排名
	sort(list, list + n, cmp);
	//确定排名,确定的逻辑总分一样看Ge分数，Ge一样则排名相同，所以说，只有这一种情况排名相同
	//其他的情况都是i+1;
	int r = 1;
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && list[i].GE == list[i - 1].GE&&list[i].GI == list[i - 1].GI)
			r = r;
		else
			r = i + 1;
		list[i].rank = r;
	}
	//确定排名之后，要确定每个学校的录取状况，这里可以从上到下遍历一次，具体的逻辑是
	//如果对应学校的人数未满，则可以将这个人的id添加到对应的数组项当中，如果满了就换下一个志愿
	//同时这里有特殊情况，如果对应学校人满，检查他的最后一个的排名是否和当前这个人相等，如果相等，
	//则也应该被录取
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int index = list[i].pre[j];
			if (school[index][0] < num[index])
			{
				school[index][0]++;
				school[index][school[index][0]] = list[i].id;
				lastrank[index] = list[i].rank;
				break;
			}
			else if (school[index][0] >= num[index])
			{
				if (list[i].rank == lastrank[index])
				{
					school[index][0]++;
					school[index][school[index][0]] = list[i].id;
					break;
				}
			}
		}
	}
	//输出
	for (int i = 0; i < m; i++)
	{
		sort(school[i] + 1, school[i] + 1 + school[i][0]);
		for (int j = 1; j <= school[i][0]; j++)
		{
			printf("%d", school[i][j]);
			if (j != school[i][0])
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
