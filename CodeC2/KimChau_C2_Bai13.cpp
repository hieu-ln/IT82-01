// Bài 13: Dùng cấu trúc danh sách đặc quản lý một đa thức.

// 13.1 Khai báo cấu trúc danh sách.
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

struct DonThuc
{
	float heso;
	int somu;
};

struct node
{
	DonThuc info;
	node *next;
};

struct DaThuc
{
	node *head;
	node *tail;
};

node * getnode(DonThuc x)
{
	node *p;
	p = new node;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho.";
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void Khoitao(DaThuc &L)
{
	L.head = NULL;
	L.tail = NULL;
}


void themdau(DaThuc &L, DonThuc x)
{
	node *p;
	p = getnode(x);
	Addhead(L, p);
}

void Nhap(DonThuc &x)
{
	cout << "\nNhap vao don thuc";
	cout << "\nNhap vao he so: ";
	cin >> x.heso;
	cout << "\nNhap vao so mu: ";
	cin >> x.somu;
}

void Addhead(DaThuc &L, node *p)
{
	if (L.tail == NULL)
	{
		L.head = p;
		L.tail = p;
	}
	else
	{
		p->next = L.head;
		L.head = p;
	}
}

// 13.2. Nhập đa thức
void NhapDaThuc(DaThuc &L)
{
	int n;
	DonThuc x;
	node *p;
	p = L.head;
	cout << "\nNhap vao da thuc: ";
	cout << "\nNhap vao so luong don thuc: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nDon thuc." << i << " = ";
		Nhap(x);
		themdau(L, x);
	}
}

// 13.4. Xuất đa thức
void xuatDaThuc(DaThuc L)
{
	cout << "\n";
	node *p;
	p = L.head;
	while (p != NULL)
	{
		cout << (p->info).heso << "x^" << (p->info).somu;
		if (p->next != NULL)
			cout << "+";
		p = p->next;
	}
}

// Cộng đa thức.
void congdathuc(DaThuc L, DaThuc L1, DaThuc &T)
{
	node *p, *q;
	int flag;
	p = L.head;
	while (p != NULL)
	{
		themdau(T, p->info);
		p = p->next;
	}
	p = L1.head;
	q = T.head;
	while (q != NULL)
	{
		p = L1.head;
		while (p != NULL)
		{
			if (p->info.somu == q->info.somu)
			{
				q->info.heso += p->info.heso;
			}
			p = p->next;
		}
		q = q->next;
	}
	p = L1.head;
	while (p != NULL)
	{
		flag = 0;
		q = T.head;
		while (q != NULL)
		{
			if (q->info.somu == p->info.somu)
				flag = 1;
			q = q->next;
		}
		if (flag == 0)
			themdau(T, p->info);
		p = p->next;
	}
}

// Trừ đa thức.
void trudathuc(DaThuc &L, DaThuc &L1, DaThuc &H)
{
	node *p, *q;
	int flag;
	p = L.head;
	while (p != NULL)
	{
		themdau(H, p->info);
		p = p->next;
	}
	p = L1.head;
	q = H.head;
	while (q != NULL)
	{
		p = L1.head;
		while (p != NULL)
		{
			if (p->info.somu == q->info.somu)
				q->info.heso -= p->info.heso;
			p = p->next;
		}
		q = q->next;
	}
	p = L1.head;
	while (p != NULL)
	{
		flag = 0;
		q = H.head;
		while (q != NULL)
		{
			if (q->info.somu == p->info.somu)
				flag = 1;
			q = q->next;
		}
		if (flag == 0)
		{
			p->info.heso *= -1;
			themdau(H, p->info);
			p->info.heso *= -1;
		}
		p = p->next;
	}
}

// Nhân đa thức
void nhandathuc(DaThuc &L, DaThuc &L1, DaThuc &Ti)
{
	node *p, *q;
	int flag;
	p = L.head;
	while (p != NULL)
	{
		themdau(Ti, p->info);
		p = p->next;
	}
	p = L1.head;
	q = Ti.head;
	while (q != NULL)
	{
		p = L1.head;
		while (p != NULL)
		{
			q->info.heso *= p->info.heso;
			q->info.somu += p->info.somu;
			p = p->next;
		}
		q = q->next;
	}
}


void main()
{
	DaThuc L, L1, T, H, Ti;
	Khoitao(L);
	Khoitao(L1);
	Khoitao(T);
	Khoitao(H);
	Khoitao(Ti);
	DonThuc(x);
	NhapDaThuc(L);
	cout << "\n Da thuc can cong ";
	NhapDaThuc(L1);
	cout << "\n Hai da thuc ";
	xuatDaThuc(L);
	cout << "\n";
	xuatDaThuc(L1);
	congdathuc(L, L1, T);
	xuatDaThuc(T);
	cout << "\nDa thuc 1 tru da thuc 2:";
	trudathuc(L, L1, H);
	xuatDaThuc(H);
	cout << "\n Da thuc tich \n";
	nhandathuc(L, L1, Ti);
	xuatDaThuc(Ti);
}