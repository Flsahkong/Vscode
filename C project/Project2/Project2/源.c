#include<stdio.h>
#include<stdlib.h>
int main()
{
	double danjia=0.8, sum=0, ave, day = 0, num;
	for (num = 2; num <= 100; num *= 2) {
		sum += danjia*num;
		day++;
	}
	ave = sum / day;
	printf("%.2f", ave);
	system("pause");
	return 0;
}