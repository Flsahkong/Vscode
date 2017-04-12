# include<stdio.h>
# include<stdlib.h>

int swap(int *a, int *b);
int main()
{
	int a = 1, b = 10;
	int num=swap(&a, &b);
	printf("%d %d %d\n", a, b,num);
	system("pause");
	return 0;
}

int swap(int *a1, int *b1)
{
	int temp = *a1;
	*a1 = *b1;
	*b1 = temp;
	return 1;
}