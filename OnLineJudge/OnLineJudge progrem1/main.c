# include<stdio.h>
# include<string.h>
# include<stdlib.h>
#include<malloc.h>


int main()
{
	int num;
	while (scanf("%d",&num) == 1) {
		if (num == 0)	break;
		char *p;
		p = (char *)malloc(sizeof(char)*num);
		for (int i = 0; i < num; i++) {
			scanf("%c", &p[i]);
		
		}
		printf("%d", strlen(p));
		int numR=0;
		int numY=0;
		int first = 0;
		//printf("%d", strlen(p));
		for (int i = 0; i < strlen(p); i++) {
			if (p[0] == 'R')	first = 1;
			if (p[i] == 'Y')	numY++;
			if (p[i] == 'R')		numR++;
			if (p[i] == 'B')	break;
		}
		if (numY == 7 && numR < 7) {
			printf("Yellow\n");
		}
		else if (numR == 7 && numY < 7) {
			printf("Red\n");
		}
		else if (numY < 7 && numR < 7) {
			if (strlen(p) % 2 == 0) {
				if (first == 1)		printf("Red\n");
				else	printf("Yellow\n");
			}
			else
			{
				if (first == 1)		printf("Yellow\n");
				else	printf("Red\n");
			}

		}

	}
	return 0;
	system("pause");
}