# include<stdio.h>
# include<stdlib.h>
# include"stdafx.h"

int foopen()
{
	FILE *fp;

	char *s = NULL;

	fp = fopen("E:\\Hotwind\\����\\vs\\Vscode\\MIGONG\\migong1\\fopen.txt", "r");

	s = fgets(s, 13, fp);			// char *fgets(char *s, int size, FILE *stream);		����fgets���ص�ֵ��char*���ͣ���Ҫ��s������
											// char *gets(char *s);	gets�������ص�Ҳ��char*���ͣ�ͬ����Ҫ����ֵ������Ҳ���Բ����ء�

	printf("%s", s);

	putchar(fgetc(fp));

	fgets(s, 20, fp);

	puts(s);

	return 0;
}