# include<stdio.h>

_declspec(dllexport) void go()				//其中declspec(dllexport 是接口)，插入别的代码中
{
	go();

}