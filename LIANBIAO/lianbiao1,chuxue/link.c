# include<stdio.h>
# include<stdlib.h>
# include"linklist.h"

int link()
{
	node *phead = NULL;						//头节点不分配内存
	//init(phead);			//头节点不需要初始化
	phead = addback(phead, 1);
	phead = addback(phead, 2);
	phead = addback(phead, 3);
	phead = addback(phead, 4);
	phead = addback(phead, 5);

	findfirst(phead, 3, 15);

	showall(phead);

	system("pause");

	return 0;
}
