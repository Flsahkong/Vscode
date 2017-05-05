#include<stdio.h>
int main()
{
	int m, n;
	int i;
	while (scanf_s("%d %d", &n, &m) != EOF) {
		int sum = 0;
		int count = 0;
		int an = 2;
		for (i = 1; i <= n; i++) {
			sum += an;
			an += 2;
			if (i%m == 0) {
				count++;
				if (count != 1) {
					printf(" ");
				}
				printf("%d", sum / m);
				sum = 0;
			}
		}
		if (n%m == 0) {
			printf("\n");
		}
		else {
			printf("%d\n", sum / (n%m));
		}
	}
	return 0;
}
