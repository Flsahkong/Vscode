# include<stdio.h>
# include<stdlib.h>

void show(int  *p, int length)
{
	printf("\n");
	for (int i = 0; i <= length; i++) {
		printf("%4d", p[i]);
	}
}

//��ʵҲ����˫��ð��		�������򷨣���ʵ����qsort
void qsort(int *p, int start, int end)
{
	if (start < end) {
		int i = start;														//i���������С��p[start]����������±꣬j�������ҵ���С��p[start]����С����
		for (int j = i+ 1; j <= end; j++) {					
			if (p[j] < p[start]) {										//������˫ָ���λ�ķ���
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