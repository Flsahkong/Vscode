# include<stdio.h>
# include<stdlib.h>

 int  add(int num);
 int go(int num);
 int  taijie(int num);
void diguixuexi()											//�ݹ�ľ��裬��һ����ڶ�������n���n-1֮��Ĳ��
{																		//f(n) = f(n-1)		�ǲ��
	
	//printf("%d", add(0));																		//f(0) = 1  �������󷵻ص�����
	// go(5);															//�ݹ�� return �Ƿ��صĵ���
	printf("%d", taijie(10));
	getchar();
}

 int   add(int num)
{
	if (num > 100) {											//����
		return 0;
	}
	else {
		return num + add(num + 1);					//����ֵ����
	}
}

 int go(int num)
 {
	 if (num == 0) {
		 return;
	 }
	 else
	 {
		 system("notepad");
		 go(num - 1);
	 }
 }
 //̨������
 int  taijie(int num)
 {
	 if (num == 1 || num == 2) {
		 return 1;
	 }
	 else {
		 return  taijie(num-1) + taijie(num - 2);
	 }
 }