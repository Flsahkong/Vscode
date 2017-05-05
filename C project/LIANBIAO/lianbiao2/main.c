# include<stdio.h>
# include<stdlib.h>

struct LinkNode {
	int data;
	struct LinkNode *pNext;
};
typedef struct LinkNode node;

node*init(node*phead)
{
	phead = NULL;
}

node*addback(node*phead, int newdata)
{
	node*pnew = (node*)malloc(sizeof(node));
	pnew->data = newdata;
	pnew->pNext = NULL;
	if (phead == NULL) {
		phead = pnew;
	}
	else {
		node*ptemp = phead;
		
		while (ptemp->pNext != NULL)
		{
			ptemp = ptemp->pNext;
		}
		ptemp->pNext = pnew;
	}
	return phead;
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

node* revit(node*phead)
{
	if (phead == NULL || phead->pNext == NULL) {
		return;
	}
	else {
		node*pre = NULL;
		node*pcur = NULL;
		node*pnext = NULL;

		pre = phead;		//preָ���1���ڵ�
		pcur = phead->pNext;		//pcurָ��ڶ����ڵ�
		while (pcur!=NULL)
		{
			pnext = pcur->pNext;		//������һ���ڵ�
			pcur->pNext = pre;			//��ת

										//ǰ��
			pre = pcur;
			pcur = pnext;
			//pnext = pnext->pNext;			��ǰ���Ѿ��ᵽ
		}
		phead->pNext = NULL;
		phead = pre;
	}
	return phead;
}
int finddata(node*phead, int finddata)
{
	int findnum=0;
	node*ptemp = phead;
	while (ptemp != NULL)
	{
		findnum++;
		if (ptemp->data == finddata) {
			return findnum;
		}
		ptemp = ptemp->pNext;
		
	}
	return -1;
}

int findsecdata(node*phead, int finddata)
{
	int findnum = 0;
	int cnt = 0;
	node*ptemp = phead;
	while (ptemp != NULL)
	{
		findnum++;
		if (ptemp->data == finddata) {
			cnt++;
			if(cnt==2){ 
				return findnum;
			}
			ptemp = ptemp->pNext;
			continue;		
		}
		ptemp = ptemp->pNext;
		
	}
	return -1;
}

int main()
{
	int number = 0;
	printf("input the number of the data\n");
	scanf("%d", &number);
	node*phead=NULL;
	init(phead);

	int newdata = 0;
	for (int i = 0; i < number; i++) {
		printf("please input the %dth number:", i);
		scanf("%d", &newdata);
		phead = addback(phead, newdata);
	}

	showall(phead);

	phead = revit(phead);
	printf("��ת֮�������\n");

	showall(phead);
	printf("\nplease input the data that you want to found:");
	int findnum = 0;
	scanf("%d", &findnum);
	
	printf("\n��һ���������ڵĽڵ��ǣ�%d\n", finddata(phead, findnum));
	
	printf("\n�ڶ����������ڵĽڵ��ǣ�%d\n", findsecdata(phead, findnum));
	system("pause");
	return 0;
}