#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int list[100000];
bool leftmax[100000];
bool rightmin[100000];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &list[i]);
	//如果遍历到的这个数是从左数最大的，从右边数最小的，那么就满足作为主元的条件
	int max = list[0];
	int min = list[n - 1] + 1;//如果测试数据没有给到2的31次方减1才可以这么写
	leftmax[0] = true;
	rightmin[n - 1] = true;
	int count = 0;
	for (int i = 1; i < n; i++)
	{
		if (list[i] > max)
		{
			max = list[i];
			leftmax[i] = true;
		}
		else
			leftmax[i] = false;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (list[i] < min)
		{
			min = list[i];
			rightmin[i] = true;
			if (leftmax[i])
				count++;
		}
		else
			rightmin[i] = false;
	}
	printf("%d\n", count);
	for (int i = 0; i < n; i++)
	{
		if (rightmin[i] && leftmax[i])
		{
			count--;
			printf("%d", list[i]);
			if (count)
				printf(" ");
		}
	}
	printf("\n");
	return 0;
}
