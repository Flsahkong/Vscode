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
node* findfirst(node*phead, int finddata, int newdata);