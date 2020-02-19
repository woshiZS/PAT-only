#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char list[100001];
int leftp[100000];
int rightt[100000];
const int maxnum = 1000000007;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%s", list);
	int count = 0;
	int index = strlen(list);
	for(int i=0;i<index;i++)
	{
		if (list[i] == 'P')
			count++;
		leftp[i] = count;
	}
	count = 0;
	for (int i = index-1; i >= 0; i--)
	{
		if (list[i] == 'T')
			count++;
		rightt[i] = count;
	}
	//预处理结束
	int sum = 0;
	for (int i = 0; i < index; i++)
	{
		if (list[i] == 'A')
		{
			sum = (sum + leftp[i] * rightt[i]) % maxnum;
		}
	}
	printf("%d\n", sum);
	return 0;
}
