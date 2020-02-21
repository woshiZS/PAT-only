#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	char target[101];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", target);
		int len = strlen(target);
		int numA = 0;
		int Aleft = 0, Aright = 0;
		int nump = 0, numt = 0, other = 0;
		for (int j = 0; j < len; j++)
		{
			if (target[j] == 'A')
			{//分三个阶段，第一个阶段是P左边，第二阶段是PT中间，第三阶段是右边
				if (!nump && !numt)
					Aleft++;
				else if (nump && !numt)
					numA++;
				else
					Aright++;
			}
			else if (target[j] == 'P')
			{
				if (!nump && !numt)
					nump++;
				else
					break;
			}
			else if (target[j] == 'T')
			{
				if (nump && !numt)
					numt++;
				else
					break;
			}
			else
			{
				other++;
				break;
			}
		}
		if (numA > 0 && Aright == numA*Aleft&&!other&&nump==1&&numt==1)
			//还有一种情况没有考虑到就是P和T都要有，不然不会PA也会算作答案正确
			printf("YES\n");
		else 
		{
			printf("NO\n");
		}
	}
	return 0;
}
