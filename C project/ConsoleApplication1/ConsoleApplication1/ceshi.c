# include<stdio.h>							//std c语言标准，可以跨平台
# include<stdlib.h>
# include<windows.h>					//第三方库函数


//int num = 123;							//全局变量

int ceshi()								//main的类型是int的时候可以没有返回值，但是其余的函数必须有返回值
{												//函数的声明可以有多个
												//函数名代表了函数表中这个函数的地址
	char str[100];

	sprintf(str,"calc");				//sprintf是输出到字符串，输出notepad到str  而printf是输出字符串到屏幕，

	system(str);											//system可以执行字符串指令，执行的是一个变量

	//printf("%i\n", 2434);							//%i输出十进制整数
	printf("for /l %%i in (1,1,5) do start notepad");		//%i就是一个整数，从1开始依次加1，一直加到5

	//system("mspaint");									//可以打开画板，这里执行的是常量

	//Sleep(2000);							//等待2秒之后退出

	MessageBoxA(0, "锄禾日当午", "汗滴禾下土", 0);					//弹出对话框，其中前一个”“里面是内容，后一个”“里面是题目

	getchar();

	return 0;													//函数内部定义的变量，返回以后就会被销毁，内存被回收
}
//函数的返回值又副本机制，我们在这打印的是副本，原来内存的数据就被销毁了，内存会被回收
//函数的参数又副本机制，我们在这打印的是副本，原来内存的数据就被销毁了，内存会被回收
//如果返回全局变量，全局变量会一直存在
//stack 代表栈，stack overflow 表示栈溢出
//在cpu内部，返回临时变量后数据就被销毁了