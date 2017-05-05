# include<iostream>
using namespace std;
//用链表实现

struct MyNode {
	int data;
	struct MyNode*NextpNode;
};
typedef struct MyNode Node;

void append(Node**phead, int newdata)
{
	Node* pnew = new Node;
	pnew->data = newdata;
	pnew->NextpNode = NULL;



	if (*phead == NULL) {
		*phead = pnew;
		pnew->NextpNode = NULL;
	}
	else {
		pnew->NextpNode = *phead;
		*phead = pnew;
	}
}

void showall (Node*phead)
{
	if (phead == NULL) {
		return;
	}
	else {
		cout << phead->data <<"\t"<< phead << "\t" << phead->NextpNode << endl;
		//printf("%d\t%p\t%p\n", phead->data, phead, phead->NextpNode);
		showall(phead->NextpNode);
	}
}

int queueshixian()
{
	Node*phead = NULL;
	append(&phead, 2);
	 append(&phead, 3);
	showall(phead);

	return 0;
}