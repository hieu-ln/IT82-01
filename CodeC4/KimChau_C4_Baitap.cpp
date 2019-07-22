// BAI 1 - CHUONG 4 (CAY NHI PHAN )
#include <iostream>
#include <stdio.h>
using namespace std;

#define COUNT 8

// Cau 1.1 : khai bao cau truc cay NPTK
struct Node{
	int info;
	Node *left;
	Node *right;
};
Node *root;

//Cau 1.2: khoi tao cay rong
void Init()
{
	root = NULL;
}

//cau 1.3: Them mot phan tu su dung DE QUY,
//khong su dung dia chi con tro
void InsertNode(Node *&p, int x)
{
	if(p == NULL)
	{
		p=new Node;
		p->info =x;
		p->left =NULL;
		p->right = NULL;
	}
	else 
	{
		if( p->info == x)
			return;// da co node co gia tri x
		else if(p-> info >x)
			return InsertNode(p->left,x);
		else
			return InsertNode(p->right,x);
	}
}
//cau1.4: tim 1 phan tu dung DE QUY
Node *Search(Node *p, int x)
{
	if(p!=NULL)
	{
		if( p->info ==x )
			return p;
		else
			if(x > p ->info)
				return Search (p ->right , x);
			else 
				return Search (p -> left , x);
	}
	return NULL;
}

//CAU 1.5: Xoa 1 nut trong cay dung DE QUY
void SearchStandFor(Node *&p , Node *&q)
{
	if(q->left == NULL)
	{
		p->info = q->info;
		p=q;
		q=q->right;
	}
	else
		SearchStandFor(p,q->left);
}

int Delete(Node *&T, int x) // tim x r moi xoa
{
	if (T == NULL) return 0;
	if (T ->info == x)
	{
		Node*p = T;
		if (T -> left == NULL) // Bac 1  // neu T tro den left null , thi T bang right
			T=T->right;
		else if(T -> right == NULL)
			T=T->left;
		else // bac 2
			SearchStandFor(p,T->right); // de quy
		delete p;
		return 1;
	}
	if(T->info<x)
		return Delete(T->right , x);
	else
		return Delete(T->left , x);
}

//Cau 1.6 :Duyet cay theo LNR dung de quy
void DuyetLNR(Node *p)
{
	if( p != NULL )
	{
		DuyetLNR(p->left);
		cout<<p->info <<" ";
		DuyetLNR(p->right);
	}
}
//cau 1.7 : Duyet theo NLR dung DEQUY
void DuyetNLR(Node *p)
{
	if( p!= NULL)
	{
		cout<<p->info<<" ";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}

//cau1.8: Duyet cay theo LRN dung DE QUY
void DuyetLRN(Node *p)
{
	if( p!= NULL)
	{
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout<<p->info<<" " ;
	}
}

void print2DUtil(Node *p , int space)
{
	//Base case
	if (p == NULL)
		return;
	//Increase distance between levels
	space += COUNT;
	//Process right child first
	print2DUtil(p->right, space);
	//Print current node after space
	//count
	cout << endl;
	for (int i= COUNT; i < space ; i++ )
		cout<<" ";
	cout<< p-> info << "\n";
	//Process left child
	print2DUtil(p->left, space);
}

//Wrapper over print2DUtil()
void Process_Tree()
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
}

int main()
{
	int choice = 0;
	int x,i;
	Node *p;
	system("cls");
	cout<<"------------------BAI TAP 1 - CHUONG 4 -----" <<endl;
	cout<<"1.Khoi tao cay NPTK rong" << endl;
	cout<<"2.Them phan tu vao cay NPTK"<<endl;
	cout<<"3.Tim phan tu co gia tri x trong cay NPTK"<<endl;
	cout<<"4.Xoa phan tu co gia tri x trong cay NPTK "<<endl;
	cout<<"5.Duyet cay NPTK theo LNR"<<endl;
	cout<<"6.Duyet cay NPTK theo NLR"<<endl;
	cout<<"7.Duyet cay NPTK theo LRN"<<endl;
	cout<<"8.Xuat cay NPTK"<<endl;
	cout<<"9.THOAT"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1: 
				Init();
				cout<<"Ban vua khoi tao Cay NPTK thanh cong! \n";
				break;
			case 2:
				cout<< "Vui long nhap gia tri x can them";
				cin >> x;
				InsertNode(root ,x);
				cout << "Cay NPTK sau khi them la: ";
				Process_Tree();
				break;
			case 3:
				cout<<"Vui long nhap gia tri x can tim";
				cin >> x;
				p= Search(root,x);
				if(p!=NULL)
					cout<<"Tim thay x="<<x<< "trong CAY NPTK"<<endl;
				break;
			case 4:
				cout << "Vui long nhap gia tri x can xoa";
				cin>>x;
				i = Delete(root,x);
				if(i==0)
					cout<<"Khong tim thay x="<<x<<" de xoa!"<<x<<endl;
				else
				{
					cout << "Da xoa thanh cong phan tu x= "<<x<<"trong CAY NPTK"<<endl;
					cout<<"Cay NPTK sau khi xoa la :";
					Process_Tree();
				}
				break;
			case 5:
				cout<<"CAY NPTK duyet theo LNR la: ";
				DuyetLNR(root);
				break;
			case 6:
				cout<<"CAY NPTK duyet theo NLR la: ";
				DuyetNLR(root);
				break;
			case 7:
				cout<<"CAY NPTK duyet theo LRN la: ";
				DuyetLRN(root);
				break;

			case 8:
				cout<<"CAY NPTK nhu sau: ";
				Process_Tree();
				break;
			case 9:
				cout<<"Goodbye ....!"<<endl;
				break;
			default:
			break;
		}
	}
	while(choice!=9);
	system("pause");
	return 0;
}