# include<stdio.h>
# include<stdlib.h>

struct data {
	unsigned b0 : 1;
	unsigned b1 : 1;
	unsigned b2 : 1;
	unsigned b3 : 1;
	unsigned b4 : 1;
	unsigned b5 : 1;
	unsigned b6 : 1;
	unsigned b7 : 1;
}*sp;

int weiyu()
{
	char ai[] = "a";
	char *p;
	p = ai;
	sp = (struct data*)p;		//将字符a强制转换为struct data 类型

	printf("%d %d %d %d %d %d %d %d", sp->b7, sp->b6, sp->b5, sp->b4, sp->b3, sp->b2, sp->b1, sp->b0);

	return 0;
}