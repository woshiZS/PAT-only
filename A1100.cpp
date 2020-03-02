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
int change(string num)
{
	int len = num.size();
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum = sum * 10 + num[i] - '0';
	}
	return sum;
}
string sec_digit[13] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string fst_digit[13] = { "tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	map<string, int> mp[2];
	for (int i = 0; i < 13; i++)
	{
		mp[1][fst_digit[i]] = i;//十位数字所对应
		mp[0][sec_digit[i]] = i;//个位数字所对应
	}
	for (int i = 0; i < n; i++)
	{
		string target;
		getline(cin, target);
		if (target[0] >= '0'&&target[0] <= '9')
		{
			int sum = change(target);
			//转化成了数字，接下来要进行进制转换，设置十位数字和个位数字
			int first = sum / 13;
			int second = sum % 13;
			//得出两个位置的数字之后，按照对应表输出即可
			if (first == 0)
			{
				printf("%s\n", sec_digit[second].c_str());
			}
			else if(second==0)
			{
				printf("%s\n", fst_digit[first].c_str());
			}
			else
			{
				printf("%s %s\n", fst_digit[first].c_str(), sec_digit[second].c_str());
			}
		}
		else
		{//处理火星数字，找得到空格的就是两个单词，如果找不到就是一个
			if (target.find(" ") == string::npos)
			{//找不到数字为单个,这里又分为仅有十位数和仅有个位数的情况
				if (mp[1].find(target) != mp[1].end())
				{//十位数字
					printf("%d\n", mp[1][target] * 13);
				}
				else
				{//个位数字
					printf("%d\n", mp[0][target]);
				}
			}
			else
			{//有两个数
				int tail = target.size();
				int space = target.find(" ");
				int sum = mp[1][target.substr(0, space)] * 13 + mp[0][target.substr(space + 1, tail)];
				printf("%d\n", sum);
			}
		}
	}
	return 0;
}
