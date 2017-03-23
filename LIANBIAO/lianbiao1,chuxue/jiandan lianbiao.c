# include<stdio.h>
# include<stdlib.h>

struct Mystruct {
	int date;
	struct Mystruct *Nextstruct;
};

void show(struct Mystruct*p)
{
	if (p == NULL) {
		return;
	}
	else {
		printf("%d\t%p", p->date, p);
		show(p->Nextstruct);
	}

}
int jiandalianbiao()
{
	struct Mystruct *p;
	struct Mystruct s1;
	struct Mystruct s2;
	struct Mystruct s3;
	struct Mystruct s4;
	struct Mystruct s5;
	p = &s1;
	s1.date = 1;								//已经分好了，只需要链接起来
	s2.date = 2;
	s3.date = 3;
	s4.date = 4;
	s5.date = 5;

	/*p = (struct Mystruct *)malloc(sizeof(struct Mystruct));					
	p->date = 1;
	p->Nextstruct = (struct Mystruct *)malloc(sizeof(struct Mystruct));
*/
	for (struct Mystruct *px = p; p != NULL; px = px->Nextstruct) {
		printf("%d,%p\n", px->date, px);
	}
	
	system("pause");

}