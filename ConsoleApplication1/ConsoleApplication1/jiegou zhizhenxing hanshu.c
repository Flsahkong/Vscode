# include<stdio.h>
# include<stdlib.h>
# include<math.h>

# define n 3

struct complext
{
	double x;
	double y;
};

struct complext *findmax(struct complext *p, int m);

int main()
{

	struct complext num[n], *maxnum, *p = num;
	for (int i = 0; i < n; i++) {
		scanf_s("%lf%lf\n",&(p + i)->x, &(p + i)->y);
		printf("你输入的是：%lf+%lfi\n", (p + i)->x, (p + i)->y);
	
	}

	maxnum = findmax(num, n);
	printf("模最大的数是：%lf+%lfi\n", maxnum->x, maxnum->y);

	getchar();
	//system("pause");

	return 0;
	system("pause");
}

struct complext *findmax(struct complext *p, int m) {
	double z = sqrt((p->x*p->x) + (p->y*p->y));
	int k = 0;

	for (int i = 0; i < m; i++) {
		double s = sqrt(((p + i)->x*(p + i)->x) + ((p + i)->y*(p + i)->y));
		if (s>z) {
			z = s;
			k = i;
		}
	}
	return p + k;
}