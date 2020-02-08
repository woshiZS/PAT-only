/*
注意卡的10002的界限，10^4个字符，一个换行符，一个串尾符
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
char s1[10005];
char s2[10005];
int main()
{
	int num[128] = { 0 };
	fgets(s1, 10005, stdin);
	fgets(s2, 10005, stdin);
	int len = strlen(s2);
	for (int i = 0; i < len - 1; i++)
	{
		num[s2[i]] = 1;
	}
	len = strlen(s1);
	for (int i = 0; i < len - 1; i++)
	{
		if (num[s1[i]] == 0)
			printf("%c", s1[i]);
	}
	printf("\n");
	return 0;
}
