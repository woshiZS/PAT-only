#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<string>
#include<queue>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
int hashtable[1001];
int main()
{//与其对出栈数列进行检查不如对操作进行模拟
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	int* out = new int[n];//出栈数列
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", out + j);
		//完成输入
		int pos = 0;//用pos来遍历输出队列
		stack<int> target;
		memset(hashtable, 0, (n + 1) * sizeof(int));
		int start = 1;
		int flag = 1;
		while (pos < n)
		{//如果没有在哈希表里面检测到，那么就将start位置到当前位置的数字都push到stack中
		//在检测一下栈是否超出m大小，如果在哈希表里面检测到到了，就看当前栈顶元素是否是这个元素，
			//如果不是直接输出no,如果到最后都满足并且栈为空，则输出yes.
			if (!hashtable[out[pos]])
			{//从start开始push进入栈
				while (start <= out[pos])
				{
					target.push(start);
					hashtable[start++] = 1;
				}
				//检测是否超量
				if (target.size() > m)
				{
					flag = 0;
					break;
				}
				target.pop();
			}
			else
			{//如果已经压栈，则检测栈顶和这个数是否相同
				int temp = target.top();
				if (temp != out[pos])
				{
					flag = 0;
					break;
				}//如果相同就没什么事情
				target.pop();
			}
			pos++;
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
