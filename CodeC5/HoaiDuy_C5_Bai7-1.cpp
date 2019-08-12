#include"pch.h"
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
// QUEUE
void InitQueue()
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
void PushQ(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int PopQ(int &x)
{
	if (front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
// end QUEUE
void InitGraph()
{
	n = 0;
}
void InsertLast(Node *&first, Node *p)
{
	if (first == NULL)
		first = p;
	else
	{
		Node * q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
void inputGraphFromText()
{
	string line;
	ifstream myfile("danhsachke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		string str;
		int i = 0;
		while (getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while (ss >> u)
			{
				// Dinh u
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i - 1], p);
			}
			i++;
		}
	}
}

// cau 7.1: Nhap ma tran ke cua do thi
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	cout << " Nhap ten dinh: ";
	for (int i = 0; i < n; i++)
		cin >> vertex[i];
	for (int i = 0; i < n + 1; i++)
	{
		if (i > 0)
			cout << " Nhap DSK cua dinh thu " << i - 1 << " (" << vertex[i - 1] << ") : ";
		int u;
		string str;
		while (getline(cin, str))
		{
			istringstream ss(str);
			while (ss >> u)
			{
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i - 1], p);
			}
			break;
		}
	}
}
