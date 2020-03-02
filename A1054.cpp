#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<stack>
using namespace std;
int main()
{
	int n, m;
	scanf("%d%d", &m, &n);
	map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num;
			scanf("%d", &num);
			if (mp.find(num) == mp.end())
			{
				mp[num] = 1;
			}
			else
				mp[num]++;
		}
	}
	int max = 0;
	int dom_color;
	map<int, int>::iterator it = mp.begin();
	for (it; it != mp.end(); it++)
	{
		if (it->second > max)
		{
			max = it->second;
			dom_color = it->first;
		}
	}
	printf("%d\n", dom_color);
	return 0;
}
