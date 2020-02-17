#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int list[100001];
//这里还有待商榷，可以设置一个类似与之前高速公路距离的那样一个数组
int main()
{
	list[0] = 0;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		list[i + 1] = list[i] + num;
	}
	int num = 0;
	int min = 100000;
	int* flag = new int[n + 1];
	memset(flag, 0, (n + 1) * sizeof(int));
	int* pos = new int[n + 1];
	memset(pos, 0, (n + 1) * sizeof(int));
	for (int i = 1; i <= n; i++)
	{
		int left = i;
		int right = n;
		int mid;
		while (left <= right)
		{
			mid= (left + right) / 2;
			int sum = list[mid] - list[i-1];
			if (sum == m)
			{
				printf("%d-%d\n", i, mid);
				num++;
				break;
			}
			else if (sum > m)
				right = mid - 1;
			else
				left = mid + 1;
		}
		int temp = list[left] - list[i - 1] - m;
		if (!num&&temp<=min&&temp>0)
		{
			pos[i] = left;
			min = temp;
			flag[i] = 1;
		}
	}
	if (!num)
	{
		for (int i=1; i <= n; i++)
		{
			if (flag[i]&&list[pos[i]]-list[i-1]-m==min)
			{
				printf("%d-%d\n", i, pos[i]);
			}
		}
	}
	return 0;
}
