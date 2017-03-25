# include<stdio.h>
# include<stdlib.h>
# include"linklist.h"

int link()
{
	node *phead = NULL;						//头节点不分配内存
	//init(phead);			//头节点不需要初始化
	phead = addback(phead, 10);
	phead = addback(phead, 25);
	phead = addback(phead, 3);
	phead = addback(phead, 56);
	phead = addback(phead, 2);
	phead = addback(phead, 45);
	phead = addback(phead, 6);
	phead = addback(phead, 98);
	phead = addback(phead, 1);

	showall(phead);
	printf("\n\n\n\n");
	//bubblesprt(phead);
	//phead = deletfirst(phead, 3);
	//findfirst(phead, 3, 15);
	//phead =  insertfirst(phead, 2, 87);
	//phead =  insertfirst(phead, 5, 89);

	myqsort(phead, NULL);

	showall(phead);

	system("pause");

	return 0;
}
