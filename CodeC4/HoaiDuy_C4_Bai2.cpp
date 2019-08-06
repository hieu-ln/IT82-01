#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
	int data; 
	struct node *pLeft; 
	struct node *pRight; 
typedef struct node NODE;
typedef NODE* TREE;

// khởi tạo cây
void KhoiTaoCay(TREE &t)
{
	t = NULL; 
}

void ThemNodeVaoCay(TREE &t, int x)
{
	if (t == NULL)
	{
		NODE *p = new NODE; 
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;//
	}
	else 
 	{
		if (t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x); 
		}
		else if (t->data < x) 
		{
			ThemNodeVaoCay(t->pRight, x); 
		}
	}
}

void Duyet_NLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << " "; 
		Duyet_NLR(t->pLeft);
		Duyet_NLR(t->pRight); 
	}
}
void Menu(TREE &t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Nhap du lieu";
		cout << "\n2. Xuat du lieu cay NLR";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ============================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 2)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			int x;
			cout << "\nNhap so nguyen x: ";
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\n\t\t DUYET CAY THEO NLR\n";
			Duyet_NLR(t);
			system("pause");
		}
		else
		{
			break;
		}
	}
	
}

int main()
{
	TREE t;
	KhoiTaoCay(t);
	Menu(t);

	system("pause");
	return 0;
}