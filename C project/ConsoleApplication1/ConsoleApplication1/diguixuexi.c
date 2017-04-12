# include<stdio.h>
# include<stdlib.h>

 int  add(int num);
 int go(int num);
 int  taijie(int num);
void diguixuexi()											//递归的精髓，第一步与第二步，第n与第n-1之间的差别
{																		//f(n) = f(n-1)		是差别
	
	//printf("%d", add(0));																		//f(0) = 1  这个是最后返回的条件
	// go(5);															//递归的 return 是返回的叠加
	printf("%d", taijie(10));
	getchar();
}

 int   add(int num)
{
	if (num > 100) {											//跳出
		return 0;
	}
	else {
		return num + add(num + 1);					//返回值叠加
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
 //台阶问题
 int  taijie(int num)
 {
	 if (num == 1 || num == 2) {
		 return 1;
	 }
	 else {
		 return  taijie(num-1) + taijie(num - 2);
	 }
 }