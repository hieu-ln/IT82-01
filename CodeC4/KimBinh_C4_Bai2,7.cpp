#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

void Init()
{
	root = NULL;
}
struct Node_Stack
{
	int info;
	Node_Stack *link;
};

Node_Stack *sp;

// Khoi tao Stack rong
void Init_Stack_Empty()
{
	sp = NULL;
}

// Them mot phan tu vao Stack
void Push(int x)
{
	Node_Stack *p = new Node_Stack;
	p->info = x;
	p->link = sp;
	sp = p;
}

// Lay mot phan tu ra khoi Stack
int Pop(int &x)
{
	if (sp != NULL)
	{
		Node_Stack *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

// Duyet cay theo tu tu LNR (dung Stack)
void Process_LNR(Node *p)
{
	if (p != NULL)
	{
		Process_LNR(p->right);
		Push(p->info);
		Process_LNR(p->left);
	}
}