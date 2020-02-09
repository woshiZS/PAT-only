/*
其实暴力法代码更好写，但是时间上就差了点
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int p[100];
int hashtable[100] = { 0 };
int n;//n皇后问题的行列数
int counter;
void generate(int index)
{
	if (index == n + 1)
	{//到达最后一步的均为合理排列
		counter++;
		return;
	}
	else
	{//应该是
		for (int i = 1; i <= n; i++)
		{
			bool flag = true;
			if (hashtable[i] == 0)
			{
				for (int pre = 1; pre < index; pre++)
				{
					if (abs(index - pre) == abs(i - p[pre]))
					{
						flag = false;
						break;
					}
				}
				//这里先别急着递归，检测一下下个是否存在合格的点
				if (flag) 
				{
					p[index] = i;
					hashtable[i] = 1;
					generate(index + 1);
					hashtable[i] = 0;
				}
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	generate(1);
	printf("%d\n", counter);
	return 0;
}
