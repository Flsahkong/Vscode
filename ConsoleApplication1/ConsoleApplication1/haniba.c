# include<stdio.h>

int move(int num, int x, int y, int z);

int hanniba()
{
	int num;
	scanf("%d", &num);
	move(num, 'a', 'b', 'c');
	getchar();
	getchar();
	return 0;

}

int move(int num, int x, int y, int z)
{
	if (num == 1) {
		printf("%c->%c\n", x, z);
	}
	else {
		move(num - 1, x, z, y);
		printf("%c->%c\n", x, z);
		move(num - 1, y, x, z);
	}
	return 0;
}