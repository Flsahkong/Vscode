# include<stdio.h>
# include<stdlib.h>
# include<string.h>
struct date {
	long long QQ;
	char *pstr;
	int strlength;
};

struct Array {
	struct date*pst;
	int length;
};
int zhizhenyujiegoutibuchong()
{
	struct Array *p = (Array *)malloc(sizeof(struct Array));
	p->length = 12;
	p->pst = (date*)malloc(sizeof(struct date)*p->length);

	 p->pst->QQ = 376355969;
	 p->pst->strlength = 10;
	 p->pst->pstr = (char*)malloc(10);
	 strcpy(p->pst[0].pstr, "huigaa");

	 //结构体的位置再堆上；
	 //链表的内存不是连续的，所以访问时只能一个一个访问；


	
	getchar();

	return 0;
}