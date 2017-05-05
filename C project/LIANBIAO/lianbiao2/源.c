#include<stdio.h>
int main()
{
	int i, j, n, count;
	char s[1000];
	while (scanf_s("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%s", s);
			count = 0;
			for (j = 0; s[j] != '\0'; j++) {
				if ((s[j] >= '0') && (s[j] <= '9')) {
					count++;
				}
			}
			printf("%d\n", count);
		}
	}
	return 0;
}
