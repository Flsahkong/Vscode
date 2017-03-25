# include<stdio.h>
# include<stdlib.h>
# include"linklist.h"

void init(node*phead)
{
	phead = NULL;
}

void addhead(node **pphead, int data)
{
	node *pnew = (node*)malloc(sizeof(node));
	pnew->data = data;
	pnew->pNext = NULL;

	if (*pphead = NULL) {
		*pphead = pnew;
	}
	else {
		pnew->pNext = *pphead;
		*pphead = pnew;
	}
}

node *addback(node *phead, int data)
{
	node *pnew = (node*)malloc(sizeof(node*));
	pnew->data = data;
	pnew->pNext = NULL;
	if (phead == NULL) {
		phead = pnew;
	}
	else {
		node *ptem = phead;

		while (ptem->pNext != NULL) {
			ptem = ptem->pNext;
		}
		ptem->pNext = pnew;
		return phead;
	}
}

void showall(node *phead)
{
	if (phead == NULL) {
		return;
	}
	else {
		printf("%d\t%p\t%p\n", phead->data, phead, phead->pNext);
		showall(phead->pNext);
	}
}

void revshowall(node *phead)
{
	if (phead == NULL) {
		return;
	}
	else {
		showall(phead->pNext);
		printf("%d\t%p\t%p\n", phead->data, phead, phead->pNext);
	}
}

node*insertfirst(node* phead, int finddata,int insertdata)						//找到某一个数，并在这个数字前面插入
{
	node *pnew = (node*)malloc(sizeof(node*));
	pnew->data = insertdata;
	pnew->pNext = NULL;

	node *p1, *p2;
	p1 = NULL;
	p2 = phead;
	while (p2 != NULL) {
		if (p2->data != finddata) {
			p1 = p2;
			p2 = p2->pNext;
		}
		else {
			break;
		}
	}
	if (phead == p2) {
		pnew->pNext = phead;
		phead = pnew;
	}
	else {
		pnew->pNext = p2;
		p1->pNext = pnew;
	}
	return phead;

}

node*changefirst(node*phead, int finddata,int newdata)
{
	node*ptemp = (node*)malloc(sizeof(node));
	ptemp = phead;
	while (ptemp != NULL) {
		if (ptemp->data == finddata) {
			ptemp->data = newdata;
			return ptemp;
		}
		ptemp = ptemp->pNext;
	}
	return NULL;
}

node* deletfirst(node*phead, int deletdata)
{
	node *p1, *p2;
	p1 =NULL;
	p2 = phead;
	while (p2 != NULL) {
		if (p2->data != deletdata) {
			p1 = p2;
			p2 = p2->pNext;
		}
		else {
			break;
		}
	}
	if (p2  != phead) {									//中间删除，但是中间删除的方法也包含了尾部删除。
		p1->pNext = p2->pNext;
		free(p2);
	}
	else {													//头部删除
		phead = phead->pNext;
		free(p2);
	}
	return phead;
}


//冒泡排序法
void bubblesprt(node *phead)
{
	for (node *p1 = phead; p1 != NULL; p1 = p1->pNext) {
		for (node *p2 = phead; p2 != NULL; p2 = p2->pNext) {
			if (p1->data < p2->data) {
				int temp;
				temp = p1->data;
				p1->data = p2->data;
				p2->data = temp;
			}
		}
	}
}

//链表的快速排序法
 void myqsort(node *phead, node* pback)
{
	if (phead == pback) {
		return;
	}
	else {
		int key = phead->data;
		node *p1 = phead;
		for (node * p2 = phead->pNext; p2 != pback; p2 = p2->pNext) {
			if (p2->data < key) {
				p1 = p1->pNext;
				int temp = p1->data;
				p1->data = p2->data;
				p2->data = temp;
			}
		}

		int temp = p1->data;
		p1->data = phead->data;
		phead->data = temp;


		myqsort(phead, p1);
		myqsort(p1->pNext, pback);
	}
}