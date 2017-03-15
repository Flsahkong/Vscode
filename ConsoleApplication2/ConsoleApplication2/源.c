# include<stdio.h>
# include<stdlib.h>

int main()
{
	in(1,3);
	printf("%p",in);

	getchar();

	return 0;
}

int in(int a, int b)
{
	return a > b ? a : b;
}