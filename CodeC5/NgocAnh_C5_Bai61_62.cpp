#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX]; // mang 2 chieu
int n; // so dinh cua do thi
char vertex[MAX]; // ten dinh

// DSLK su dung cho STACK va QUEUE
struct Node
{
	int info;
	Node *link;
};

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
void inputGraphFromText()
{
	string line;
	ifstream myfile("matranke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
		}
	}
}

// cau 6.1: Nhap ma tran ke cua do thi
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap ten dinh: ";
		cin >> vertex[i];
		cout << " Nhap vao dong thu: " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}

// cau 6.2: Xuat ma tran ke cua do thi
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}