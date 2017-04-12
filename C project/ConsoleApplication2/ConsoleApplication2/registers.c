# include<stdio.h>
# include<stdlib.h>

int sum(int n);

 int registers(){

	int n;
	scanf("%d", &n);
	printf("%d", sum(n));
	return 0;
}

int sum(int n)
{
	register long  director=0,s=0;
	for (int i = 0; i < n; i++) {
		s = s + director;

	}
	return s;
}