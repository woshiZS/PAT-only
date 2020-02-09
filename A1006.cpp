#include<cstdio>
struct student
{
	char name[20];
	int sh, sm, ss;
	int lh, lm, ls;
};
int main()
{
    int m;
	scanf("%d", &m);
	student* list = new student[m];
	int first = 235959, last = 0;
	int first_pos = 0, last_pos = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%s %d:%d:%d", (list + i)->name, &(list + i)->sh, &(list + i)->sm, &(list + i)->ss);
		scanf("%d:%d:%d", &(list + i)->lh, &(list + i)->lm, &(list + i)->ls);
		int temp1 = (list + i)->sh * 10000 + (list + i)->sm * 100 + (list + i)->ss;
		int temp2 = (list + i)->lh * 10000 + (list + i)->lm * 100 + (list + i)->ls;
		if (temp1 < first)
		{
			first = temp1;
			first_pos = i;
		}
		if (temp2 > last)
		{
			last = temp2;
			last_pos = i;
		}
		//printf("%02d:%02d:%02d %02d:%02d:%02d\n", (list + i)->sh, (list + i)->sm, (list + i)->ss, (list + i)->lh, (list + i)->lm, (list + i)->ls);
	}
	printf("%s %s\n", (list + first_pos)->name, (list + last_pos)->name);
	return 0;
}
