// bai 11, chuong 2: DS han che, hang doi, QUEUE
// QUEUE su dung DSLK
#include <iostream>
#include <stdio.h>
using namespace std;

// cau 11.1: khia bao cau truc QUEUE
struct Node
{
	int info;
	Node *link;
};
Node *front, *rear;

// cau 11.2: Khoi tao QUEUE rong
void init()
{
	front = NULL;
	rear = NULL;
}

//Ktra QUEUE rong
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}
 // cau 11.4: Them phan tu vao QUEUE
void Push(int x)
{
	Node *p = new  Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

//cau 11.5: Lay phan tu ra khoi QUEUE
int Pop(int &x)
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

//Xuat QUEUE
void Process_queue()
{
	if (front != NULL)
	{
		Node *p = front;
		cout << "<-- ";
		do
		{
			cout << p->info << " ";
			p = p->link;
		} while (p != NULL);
		cout << "<-- " << endl;
	}
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << " -------- BAI TAP 7, CHUONG 2, QUEUE -------- " << endl;
	cout << " 1. Khi tao QUEUE rong!" << endl;
	cout << " 2. Them phan tu vao QUEUE!" << endl;
	cout << " 3. Lay phan tu ra khoi QUEUE!" << endl;
	cout << " 4. Kiem tra QUEUE co rong hay khong!" << endl;
	cout << " 5. Xuat QUEUE!" << endl;
	cout << " 6. Thoat!" << endl;
	do
	{
		cout << "\n Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << " Ban vua khoi tao QUEUE rong thanh cong!\n";
			break;
		case 2:
			cout << " Vui long nhap gia tri x= ";
			cin >> x;
			Push(x);
		case 3:
			Pop(x);
			cout << " Phan tu lay ra tu QUEUE la x= " << x << endl;
			cout << " QUEUE sau khi lay ra la: ";
			Process_queue();
			break;
		case 4:
			i = isEmpty();
			if (i == 0)
				cout << " QUEUE khong rong!" << x << endl;
			else
				cout << " QUEUE rong!" << endl;
			break;
		case 5:
			cout << " QUEUE hien tai la: ";
			Process_queue();
			break;
		case 6:
			cout << " Goodbye......!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}