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

node* findfirst(node*phead, int finddata,int newdata)
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