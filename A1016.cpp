#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct record
{
	char name[21];
	int mon, day, hour, min;
	int state;
	record operator=(const record& a)
	{
		
		strcpy(name, a.name);
		mon = a.mon;
		day = a.day;
		hour = a.hour;
		min = a.min;
		state = a.state;
		return *this;
	}
}rec_list[1000];
struct customer
{
	char name[21];
	//int mon; 
	double sum = 0;
	record ch_list[1000]; 
	int rec_num = 0;
}cus_list[500];
bool cmp1(customer a, customer b)
{
	return strcmp(a.name, b.name) < 0;
}
bool cmp2(record a, record b)
{
	if (a.day != b.day)
		return a.day < b.day;
	else if (a.hour != b.hour)
		return a.hour < b.hour;
	else
		return a.min < b.min;
}
double money(record a, record b,int& count);
int price[24];
int main()
{
	for (int i = 0; i < 24; i++)
		scanf("%d", price + i);
	int n, month;
	scanf("%d", &n);
	//这题得仔细想想，先是怎样处理输入
	for (int i = 0; i < n; i++)
	{
		char num[10];
		scanf("%s %d:%d:%d:%d %s", rec_list[i].name, &rec_list[i].mon, &rec_list[i].day, &rec_list[i].hour, &rec_list[i].min, num);
		if (num[1] == 'n')
			rec_list[i].state = 1;
		else
			rec_list[i].state = 0;
	}
	month = rec_list[0].mon;
	//根据是否存在该用户而决定是否创建新用户来存储信息。
	int cus_count = 0;
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < cus_count; j++)
		{
			if (strcmp(rec_list[i].name, cus_list[j].name)==0)
			{//如果匹配名字成功了则要将相应记录放到里边去
				cus_list[j].ch_list[++cus_list[j].rec_num] = rec_list[i];
				flag = 1;
			}
		}
		if (!flag)
		{//相当于创建这个用户,并且把相应记录存到对应用户的名字下
			strcpy(cus_list[cus_count].name, rec_list[i].name);
			cus_list[cus_count].ch_list[++cus_list[cus_count].rec_num] = rec_list[i];
			cus_count++;
		}
	}
	//按照名字的字母序排列
	sort(cus_list, cus_list + cus_count, cmp1);
	for (int i = 0; i < cus_count; i++)
	{
		int first_time = 1;
		//将每个顾客的记录排序，并且计算出money,计算money应该单独用一个函数以免篇幅过于复杂;
		sort(cus_list[i].ch_list+1, cus_list[i].ch_list + cus_list[i].rec_num+1, cmp2);
		//将信息按照时间排序
		int on = 0, off = 0;
		double re_sum = 0;
		for (int j = 1; j <= cus_list[i].rec_num; j++)
		{//这里的作用就是为了寻找pair,并且将每对匹配的记录输出出来
			int t_num = 0;
			if (cus_list[i].ch_list[j].state == 1)
				on = j;
			if (cus_list[i].ch_list[j].state == 0 && on)
				off = j;
			if (on&&off)
			{
				if (first_time)
				{
					printf("%s %02d\n", cus_list[i].name, month);
					first_time = 0;
				}
				printf("%02d:%02d:%02d %02d:%02d:%02d ", cus_list[i].ch_list[on].day, cus_list[i].ch_list[on].hour, cus_list[i].ch_list[on].min, cus_list[i].ch_list[off].day, cus_list[i].ch_list[off].hour, cus_list[i].ch_list[off].min);
				//计算money的部分，先算分钟，再算小时，再算天数
				re_sum = money(cus_list[i].ch_list[on], cus_list[i].ch_list[off], t_num) / 100;
				printf("%d $%.2f\n", t_num, re_sum);
				cus_list[i].sum += re_sum;
				on = 0, off = 0;
			}
		}
		if(cus_list[i].sum)
			printf("Total amount: $%.2f\n", cus_list[i].sum);
	}
	return 0;
}
double money(record a, record b,int& count)
{
	double sum = 0;
	while (a.day != b.day || a.hour != b.hour || a.min != b.min)
	{
		sum += price[a.hour];
		a.min++;
		count++;
		if (a.min == 60)
		{
			a.min = 0;
			a.hour = a.hour + 1;
			if (a.hour == 24)
			{
				a.hour = 0;
				a.day += 1;
			}
		}
	}
	return sum;
}
