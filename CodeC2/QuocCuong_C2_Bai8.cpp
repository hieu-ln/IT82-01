#include <iostream> 
#include <stdio.h>
#include<conio.h>

using namespace std;

struct Stack
{
	int data;
	Stack* next;
};

typedef Stack* ListStack;

void Init(ListStack& L) {
	L = NULL;
}

Stack* MakeNode(int x) {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = x;
	s->next = NULL;
	return s;
}

void Them(ListStack& L, int x) {
	Stack* k = NULL;
	k = MakeNode(x);
	k->next = L;
	L = k;
}

void XuLyCoSo2(ListStack& L, int n) {
	int p = 0;
	while (n != 0)
	{
		p = n % 2;
		Them(L, p);
		n /= 2;
	}
}

void XuLyCoSo16(ListStack& L, int n) {
	int ks = 0;
	while (n != 0)
	{
		ks = n % 16;
		Them(L, ks);
		n /= 16;
	}
}

void XuatHe16(ListStack L) {
	while (L != NULL)
	{
		if (L->data <= 9 && L >= 0)
		{
			cout << L->data;
			L = L->next;
		}
		else
		{
			cout<<L->data + 55;
			L = L->next;
		}
	}
	cout << endl;
}
void Xuat(ListStack L) {
	while (L != NULL)
	{
		cout << L->data << endl;     L = L->next;
	}
}

int main() {
	ListStack L;
	Init(L);
	XuLyCoSo16(L, 3295);
	XuatHe16(L);
	system("pause");
	return 0;
}