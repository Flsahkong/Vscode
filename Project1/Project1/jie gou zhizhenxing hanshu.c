# include<stdio.h>
# include<math.h>

# define n 19

 struct complex
{
	double x;
	double y;
};

struct complex *findmax(struct complex *p, int m);

int main()
{
	struct complex num[n], *maxnum, *p = num;
	for (int i = 0; i < n; i++) {
			scanf("%lf%lf\n", p->x, p->y);
			printf("你输入的是：%lf+%lfi\n", p->x, p->y);
			p = p + i;
	}

	maxnum = findmax(num,n);
	printf("模最大的数是：%lf+%lfi\n", maxnum->x, maxnum->y);

	return 0;
}

struct complex *findmax(struct complex *p, int m) {
	double z = sqrt((p->x*p->x)+(p->y*p->y));
	int k = 0;

	for (int i = 0; i < m; i++) {
		double s = sqrt((p->x*p->x) + (p->y*p->y));
			if (s>z) {
				z = s;
				k = i;
			}
	}
	return p + k;
}