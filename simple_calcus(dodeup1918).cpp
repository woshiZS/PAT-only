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
int string_int(string& a)
{
	int len = a.size();
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum = sum * 10 + a[i] - '0';
	return sum;
}
int main()
{	//这里首先确定一下自己要使用的数据结构，转换成后缀表达式需要一个数组和一个符号栈
	//然后进行数值计算还得将操作数压栈，所以还需要一个操作数栈；
	string curr;
	char c;
	map<string, int> pri;
	pri["+"] = 1;
	pri["-"] = 1;
	pri["*"] = 2;
	pri["/"] = 2;
	stack<string> ops;
	stack<double> nums;
	queue<double> post;//感觉还是队列好用一点，不如用队列吧
	int counter = 0;
	while (cin >> curr)
	{//这里写一个逻辑就是，如果curr是0并且c是换行符号则跳出循环，否则按照相应条件压栈计算之类
		counter++;
		c = getchar();
		if (curr == "0"&&c == '\n'&&counter == 1)
			break;
		if (curr[0] >= '0'&&curr[0] <= '9')
			post.push(string_int(curr));
		else//其余情况只能为运算符，此时应该分情况压栈
		{
			while (ops.size() != 0 && pri[curr] <= pri[ops.top()])
			{//出栈并添加到后缀表达式当中
				string temp = ops.top();
				if (temp == "+")
					post.push(-1);
				else if (temp == "-")
					post.push(-2);
				else if (temp == "*")
					post.push(-3);
				else
					post.push(-4);
				ops.pop();
			}
			ops.push(curr);
		}//到这里为止就完成了后缀表达式的转换，ops已经为空
		if (c == '\n')
		{//前面已经排除跳出循环情况了，这里应该实现后缀表达式数值的计算，注意这里的结果是浮点数
		 //数值计算就两点，操作数压栈，遇到运算符pop两个运算数字，计算完之后又压栈
			counter = 0;
			while (ops.size() != 0)
			{
				string temp = ops.top();
				if (temp == "+")
					post.push(-1);
				else if (temp == "-")
					post.push(-2);
				else if (temp == "*")
					post.push(-3);
				else
					post.push(-4);
				ops.pop();
			}
			while (post.size() != 0)
			{
				int front = post.front();
				if (front >= 0)
				{
					nums.push(front);
					post.pop();
				}
				else
				{
					double b = nums.top();
					nums.pop();
					double a = nums.top();
					nums.pop();
					if (front == -1)
						nums.push(a + b);
					else if (front == -2)
						nums.push(a - b);
					else if (front == -3)
						nums.push(a*b);
					else
						nums.push(a / b);
					post.pop();
				}
			}//这时候post已经为空，nums有一个数
			printf("%.2f\n", nums.top());
			nums.pop();
		}
	}
	return 0;
}
