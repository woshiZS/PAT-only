#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int list[100];
int temp[100];
int change[100];
bool Is_thesame(int* a, int* b, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &list[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &change[i]);
	//这里比较直观的想法就是把插入排序和归并排序的函数都写出来，然后对两种方法
	//逐步进行排序，每一轮的结果和chang数组中的数据进行比较，若相同则确定答案。
	//插入排序就是前多少多少个是有序的；归并排序则是两两分组，问题在于如何做出一步一步的排序，现在
	//建议采用非递归方式.首先是插入排序版本
	int flag = 0;
	for (int i = 0; i < n; i++)
		temp[i] = list[i];
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (temp[j] < temp[j - 1])
			{
				int tep = temp[j];
				temp[j] = temp[j - 1];
				temp[j - 1] = tep;
			}
			else
				break;
		}
		//这里就进行完一轮
		if (flag)
		{
			for (int i = 0; i < n; i++)
			{
				printf("%d", temp[i]);
				if (i != n - 1)
					printf(" ");
			}
			printf("\n");
			return 0;
		}
		if (Is_thesame(temp, change, n))
		{
			printf("Insertion Sort\n");
			flag = 1;
		}
	}
	//插入排序部分已经完成,接下来完成归并排序
	for (int i = 0; i < n; i++)
		temp[i] = list[i];
	int step = 2;
	while (n > step / 2)
	{
		for (int i = 0; i < n; i += step)
		{
			int index = i + step < n ? i + step : n;
			sort(temp + i, temp + index);
		}
		step *= 2;
		if (flag)
		{
			for (int i = 0; i < n; i++)
			{
				printf("%d", temp[i]);
				if (i != n - 1)
					printf(" ");
			}
			printf("\n");
			return 0;
		}
		if (Is_thesame(temp, change, n))
		{
			printf("Merge Sort\n");
			flag = 1;
		}
	}
}
