#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int state[37] = { 0 };
	char temp1[100];
	char temp2[100];
	scanf("%s", temp1);
	//0-9代表数字，A-Z代表10-35，_代表36
	scanf("%s", temp2);
	for (int i = 0; i < strlen(temp2); i++)
	{
		if (temp2[i] >= '0'&&temp2[i] <= '9')
			state[temp2[i] - 48] = 1;
		else if (temp2[i] >= 'A'&&temp2[i] <= 'Z')
			state[temp2[i] - 55] = 1;
		else if (temp2[i] >= 'a'&&temp2[i] <= 'z')
			state[temp2[i] - 'a' + 10] = 1;
		else
			state[36] = 1;
	}
	//这里要倒过来，因为要按照发现的顺序输出坏键，先将坏键盘输入设置为1，再按照好键盘输入对照
	//输出坏键，当然也可以设置两个迭代变量不相同就输出，直到相同再继续
	for (int i = 0; i < strlen(temp1); i++)
	{
		if (temp1[i] >= '0'&&temp1[i] <= '9')
		{
			if (state[temp1[i] - 48] == 0)
				printf("%c", temp1[i]);
			state[temp1[i] - 48] = 1;
		}
		else if (temp1[i] >= 'A'&&temp1[i] <= 'Z')
		{
			if (state[temp1[i] - 55] == 0)
				printf("%c", temp1[i]);
			state[temp1[i] - 55] = 1;
		}
		else if (temp1[i] >= 'a'&&temp1[i] <= 'z')
		{
			if (state[temp1[i] - 'a' + 10] == 0)
				printf("%c", temp1[i] - 'a' + 'A');
			state[temp1[i] - 'a' + 10] = 1;
		}
		else
		{
			if (state[36] == 0)
				printf("_");
			state[36] = 1;
		}
	}
	printf("\n");
	return 0;
}
