#include<iostream>
using namespace std;
// Khai Bao cau truc cay nhi phan tim kiem
struct node
{
	int data;
	struct  node *pLeft;
	struct  node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
// Khoi tao cay
void Khoitaocay(TREE &t)
{
	t = NULL;
}
// Them phan tu vao cay

void Themnodevaocay(TREE &t, int x)
{
	// Neu cay rong
	if (t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else // cay ton tai phan tu
	{

		if (t->data > x)
		{
			Themnodevaocay(t->pLeft, x);
		}
		else if (t->data < x)
		{
			Themnodevaocay(t->pRight, x);
		}
	}
}
// Tim phan tu trong cay
NODE *Timkiem(TREE t, int x)
{
	// Neu cay rong 
	if ( t == NULL)
	{
		return NULL;
	}
	else
	{
		if (x < t->data)
		{
			Timkiem(t->pLeft, x);
		}
		else if (x > t->data)
		{
			Timkiem(t->pLeft, x);
	    }
		else
		{
			return t;
		}
	}
}
// Xoa node bat ki trong cay
void Xoanode(TREE &t, int data)// data la gia tri node can xoa
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (data < t->data)
		{
			Xoanode(t->pLeft, data);
		}
		else if (data > t->data)
		{
			Xoanode(t->pRight, data);
		}
		else
		{
			NODE *X = t;// X la node the mang , se xoa sau
			if (t->pLeft == NULL)// day la cay con phai
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)// day la cay con trai
			{
				t = t->pLeft;
			}
			delete X;
		}
	}
}
// Duyet NLR
void DuyetNLR(TREE &t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		DuyetNLR(t->pLeft);
		DuyetNLR(t->pRight);
	}
}
// Duyet LNR
void DuyetLNR(TREE &t)
{
	if (t != NULL)
	{
		DuyetLNR(t->pLeft);
		cout << t->data << " ";
		DuyetLNR(t->pRight);
	}
}
// Duyet LRN
void DuyetLRN(TREE &t)
{
	if (t != NULL)
	{
		DuyetLRN(t->pLeft);
		DuyetLRN(t->pRight);
		cout << t->data << " ";
	}
}
void Menu(TREE &t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ================ MENU ================";
	    cout << "\n1. Them phan tu vao cay.";
	    cout << "\n2. Tim kiem.";
	    cout << "\n3. Xoa node.";
	    cout << "\n4. Duyet NLR.";
	    cout << "\n5. Duyet LNR.";
	    cout << "\n6. Duyet LRN.";
		cout << "\n\n\t\t ======================================" << endl;
		int Luachon, x;
		cin >> Luachon;
		cout <<"Nhap vao lua chon cua ban: ";
		cin >> Luachon;
		if(Luachon <0||Luachon >7)
		{
			cout << "\n Lua chon khong hop le";
			system("pause");
		}
		else if (Luachon == 1)
		{
			int x;
			cout <<"Nhap vao x: ";
			cin >> x;
			Themnodevaocay(t, x);
		}
		else if (Luachon == 2)
		{
			cout <<"Nhap vao x: ";
			cin >> x;
			NODE *p = Timkiem(t, x);
			if(p = NULL)
				cout <<"\n Phan tu "<< x <<" khong ton tai trong cay." << endl;
			else
				cout <<"\n Phan tu "<< x <<" ton tai trong cay." << endl;
			system("pause");
		}
		else if (Luachon == 3)
		{
			cout <<"Nhap vao x: ";
			cin >> x;
			Xoanode(t, x);
		}
		else if (Luachon == 4)
		{
			cout << "Cay nhi phan: ";
			DuyetNLR(t);
			system("pause");
		}
		else if (Luachon == 5)
		{
			cout << "Cay nhi phan: ";
			DuyetLNR(t);
			cout << endl;
			system("pause");
		}
		else if (Luachon == 6)
		{
			cout << "Cay nhi phan: ";
			DuyetLRN(t);
			cout << endl;
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
	Khoitaocay(t);
	Menu(t);
	system("pause");
	return 0;
}
