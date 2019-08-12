#include <iostream>
using namespace std;

#define max 100
struct node {
	int info;
	node *link;
};
node *first[max];
node *front, *rear;
int n;
//Câu 7.3

int c[100], bfs[100];
int nbfs = 0;
void InitC()
{
	for (int i = 0; i < n; i++)
		c[i] = 1;
}
void InitQ()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}
void pushQ(int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int popQ(int &x)
{
	if (front != NULL)
	{
		node *p = front;
		x = p->info;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

void BFS(int v) //V la dinh
{
	int p;
	node *w;
	pushQ(v);
	c[v] = 0;
	while (front != NULL)
	{
		popQ(p);
		bfs[nbfs] = p;
		w = first[p];
		nbfs++;
		while (w != NULL)
		{
			if (c[w->info])
			{
				pushQ(w->info);
				c[w->info] = 0;
			}
			w = w->link;
		}
	}

}