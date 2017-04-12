#pragma once
# include<stdio.h>
# include<stdlib.h>

struct LinkNode 
{
	int data;
	struct LinkNode*pNext;
};

typedef struct LinkNode node;

void init(node *phead);
node *addblack(node *phead, int data);
void showall(node*phead);
void revshowall(node*phead);
node*changefirst(node*phead, int finddata, int newdata);
node* deletfirst(node*phead, int deletdata);
node*insertfirst(node* phead, int finddata, int insertdata);
void bubblesprt(node *phead);
void myqsort(node *phead, node* pback);