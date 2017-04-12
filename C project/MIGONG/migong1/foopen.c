# include<stdio.h>
# include<stdlib.h>
# include"stdafx.h"

int foopen()
{
	FILE *fp;

	char *s = NULL;

	fp = fopen("E:\\Hotwind\\代码\\vs\\Vscode\\MIGONG\\migong1\\fopen.txt", "r");

	s = fgets(s, 13, fp);			// char *fgets(char *s, int size, FILE *stream);		函数fgets返回的值是char*类型，需要用s来接受
											// char *gets(char *s);	gets函数返回的也是char*类型，同样需要返回值，但是也可以不返回。

	printf("%s", s);

	putchar(fgetc(fp));

	fgets(s, 20, fp);

	puts(s);

	return 0;
}