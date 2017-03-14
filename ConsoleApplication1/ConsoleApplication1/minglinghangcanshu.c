# include<stdio.h>

int minglinghangcanshu(int argc, char *argv[])
{
	int i = 0;
	printf("命令行中可执行文件为：%s\n", argv[0]);
	printf("总共有%d个参数\n", argc);

	getchar();

	return 0;
}