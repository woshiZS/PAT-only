#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<stack>
using namespace std;
void prepare(string& num, int& power, int& start)
{
	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] >= '1'&&num[i] <= '9')
		{
			break;
		}
		else
		{
			start++;
		}
	}//确定开始位置,这里得考虑一下特殊情况，就是0000那种
	//传入初始值，为0
	int dot_pos = num.find(".");
	if (dot_pos == string::npos)
	{
		power = num.size() - start;
	}
	else if (dot_pos > start&&dot_pos<num.size())
	{
		power = dot_pos - start;
		num.erase(num.begin() + dot_pos);
	}
	else if (dot_pos < start&&start<num.size())
	{//这样最好power传入的初值为0
		power = dot_pos - start + 1;
		num.erase(num.begin() + dot_pos);
		start--;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	string a, b;
	cin >> a >> b;
	//真正需要获取的是，有效数字部分和10的次幂，而且有一点需要注意的是有效数字应该是向n看齐的，
	//如果数字有效位数不够，那么就用0来凑
	//有效位数应该是第一个非0数字算起
	int p_a = 0, s_a = 0, p_b = 0, s_b = 0;
	prepare(a, p_a, s_a);
	prepare(b, p_b, s_b);
	int flag = 0;
	if (p_a == p_b)
	{//这里应该是比较n位，若又一个超过了界限，则拿0相比，若相同则，设置flag为1
		int i = s_a, j = s_b;
		int tik = 0;
		for (int i = 0; i < n; i++)
		{
			char t1, t2;
			if (s_a + i >= a.size())
				t1 = '0';
			else
				t1 = a[s_a + i];
			if (s_b + i >= b.size())
				t2 = '0';
			else
				t2 = b[s_b + i];
			if (t1 != t2)
				break;
			if (i == n - 1 && t1 == t2)
				flag = 1;
		}
	}
	if (flag)
	{
		printf("YES 0.");
		for (int i = 0; i < n; i++)
		{
			char temp;
			if (s_a + i >= a.size())
				temp = '0';
			else
				temp = a[s_a + i];
			printf("%c", temp);
		}
		printf("*10^%d", p_a);
	}
	else
	{
		printf("NO 0.");
		for (int i = 0; i < n; i++)
		{
			char temp;
			if (s_a + i >= a.size())
				temp = '0';
			else
				temp = a[s_a + i];
			printf("%c", temp);
		}
		printf("*10^%d 0.", p_a);
		for (int i = 0; i < n; i++)
		{
			char temp;
			if (s_b + i >= b.size())
				temp = '0';
			else
				temp = b[s_b + i];
			printf("%c", temp);
		}
		printf("*10^%d", p_b);
	}
	printf("\n");
	return 0;
}
