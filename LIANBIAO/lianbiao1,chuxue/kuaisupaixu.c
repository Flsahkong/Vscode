# include<stdio.h>
# include<stdlib.h>

void show(int  *p, int length)
{
	printf("\n");
	for (int i = 0; i <= length; i++) {
		printf("%4d", p[i]);
	}
}

//其实也就是双层冒泡		快速排序法，其实就是qsort
void qsort(int *p, int start, int end)
{
	if (start < end) {
		int i = start;														//i代表了左边小于p[start]的数的最大下标，j代表了找到的小于p[start]的最小的数
		for (int j = i+ 1; j <= end; j++) {					
			if (p[j] < p[start]) {										//运用了双指针错位的方法
				i++;
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
		int temp = p[i];
		p[i] = p[start];
		p[start] = temp;


		qsort(p, start, i - 1);
		qsort(p, i + 1, end);
	}

	
}

int kuaisuoaixu()											
{
	int a[10] = { 10,11,9,17,8,29,5,39,6,102 };
	show(a, 9);
	qsort(a, 0, 9);
	show(a, 9);
	system("pause");

	return 0;
}