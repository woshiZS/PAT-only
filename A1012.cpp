#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct student
{
	char reg_num[7];
	int c;
	int m;
	int e;
	int a;
	int b_r = 2000;
	char sub = 'E';
}list[2000];
bool cmp1(student a, student b)
{
	return a.e > b.e;
}
bool cmp2(student a, student b)
{
	return a.m > b.m;
}
bool cmp3(student a, student b)
{
	return a.c > b.c;
}
bool cmp4(student a, student b)
{
	return a.a > b.a;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d%d%d", list[i].reg_num, &list[i].c, &list[i].m, &list[i].e);
		float sum = (float)(list[i].c + list[i].m + list[i].e);
		list[i].a = round(sum / 3);
	}
		//现在就是排序四次，按照四种排序函数，先从EMCA的顺序，保证后面的可以覆盖前面的
		//然后按照排名的方法赋给b_r，如果有小于等于的的就覆盖掉。
	sort(list, list + n, cmp1);
	int r = 1;
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && list[i].e != list[i - 1].e)
			r = i + 1;
		if (r <= list[i].b_r)
		{
			list[i].b_r = r;
		}
	}
	sort(list, list + n, cmp2);
	r = 1;
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && list[i].m != list[i - 1].m)
			r = i + 1;
		if (r <= list[i].b_r)
		{
			list[i].b_r = r;
			list[i].sub = 'M';
		}
	}
	sort(list, list + n, cmp3);
	r = 1;
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && list[i].c != list[i - 1].c)
			r = i + 1;
		if (r <= list[i].b_r)
		{
			list[i].b_r = r;
			list[i].sub = 'C';
		}
	}
	sort(list, list + n, cmp4);
	r = 1;
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && list[i].a != list[i - 1].a)
			r = i + 1;
		if (r <= list[i].b_r)
		{
			list[i].b_r = r;
			list[i].sub = 'A';
		}
	}
	for (int i = 0; i < m; i++)
	{
		char num[7];
		scanf("%s", num);
		for (int j = 0; j < n; j++)
		{
			if (strcmp(list[j].reg_num, num) == 0)
			{
				printf("%d %c\n", list[j].b_r, list[j].sub);
				break;
			}
			else if (j == n - 1 && strcmp(list[j].reg_num, num) != 0)
				printf("N/A\n");
		}
	}
	return 0;
}
