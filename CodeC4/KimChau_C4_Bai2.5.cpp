//BAI 2.5 - CHUONG 4 (CAY NHI PHAN)
//Xoa 1 nut trong cay (dung de quy)

#include<iostream>
#include<stdio.h>
using namespace std;

#define COUNT 10

//khai bao cau truc cay NPTK
struct Node {
	int info;
	Node *left;
	Node *right;
};
Node *root;

void Init()
{
	root = NULL;
}

//XOA
void SearchStandFor(Node *p, Node *&q)
{
	if (q->left = NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		SearchStandFor(p, q->left);
}

int Delete(Node *&T, int x) // tim x r moi xoa
{
	if (T == NULL) return 0;
	if (T->info == x)
	{
		Node *p = T;
		if (T->left == NULL)//Bac1 // neu T tro den left null , thi T tro toi right
			T = T->right;
		else if (T->right = NULL)
			T = T->left;
		else//bac 2
			SearchStandFor(p, T->right);//de quy
		delete p;
		return 1;
	}
	if (T->info < x)
		return Delete(T->right, x);
	else
		return Delete(T->left, x);
}



int main()
{
	int choice = 0;
	int x , i;
	Node *p;
	system("cls");
	cout << "-----------BAI TAP 2.5 , CHUONG 4----" << endl;
	cout << "1.Khoi tao cay NPTK rong" << endl;
	cout << "2. Xoa phan tu co gia tri x trong cay NPTK" << endl;
	do
	{ 
		cout << "\Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao thanh cong cay NPTK thanh cong! \n";
			break;
		case 2:
			cout << "Vui long nhap gia tri can xoa ";
			cin >> x;
			i = Delete(root, x);
			if (i = 0)
				cout << "Khong tim thay x= " << x << "de xoa" << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu x=" << x << "de xoa!" << endl;
				//cout << "Cay nhi phan sau khi xoa la:";
				//Process_Tree();
			}
				break;
		default:
			break;
		}

	} while (choice != 2);
	system("pause");
	return 0;
	
}