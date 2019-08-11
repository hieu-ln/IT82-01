#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
using namespace std;
#define MAX 20

// DSLK su dung cho STACK va QUEUE, va DS Ke
struct Node
{
	int info;
	Node *link;
};

Node *First[MAX]; // DS cac DSK
int n; // so dinh cua do thi
char vertex[MAX]; // ten dinh

Node *sp;
Node *front, *rear;

// STACK
void InitStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int PopS(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

// end STACK
//CAY 7.4:
int dfs[100]; // cai nay ham void duoi kia. 
//coi lai cho nay o
// uhm code loi nha
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int u = s;
	Node *v = NULL;
	while (isEmptyS() == 0)
	{
		if (v == NULL)
			PopS(u);
		v = First[u];
		while (v != NULL)
		{
			if (C[v->info] == 1)
			{
				PushS(u);
				PushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}
	}
}

//cAU7.5: Nhap X kiem tra theo phep duyet DFS
void dfs(int s)
{
	push(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (!isEmpty())
	{
		if (v == n)

			pop(u);
		for (v = 0; v < v; v++)
			if (a[u][v] != 0 && C[v] == 1)
			{
				push(u);
				push(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;

			}
	}
}