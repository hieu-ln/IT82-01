//#include <iostream>
//#include <stdio.h>
//using namespace std;
//int count = 8;
//struct node
//{
//	int info;
//	node* left;
//	node* right;
//};
//node* root;
//void init()
//{
//	root = NULL;
//}
//void insert(node*& p, int x)
//{
//	if (p == NULL)
//	{
//		p = new node;
//		p->info = x;
//		p->left = NULL;
//		p->right = NULL;
//	}
//	else
//	{
//		if (p->info == x)
//			return;
//		else
//			if (p->info < x)
//				return insert(p->right, x);
//			else
//				return insert(p->left, x);
//	}
//}
//node* search(node * p, int x)
//{
//	while (p != NULL)
//	{
//		if (p->info == x)
//			return p;
//		else
//			if (p->info < x)
//				return search(p->right, x);
//			else
//				return search(p->left, x);
//	}
//	return NULL;
//}
//void searchstandfor(node * &p, node * &q)
//{
//	if (q->left == NULL)
//	{
//		p->info = q->info;
//		p = q;
//		q = q->right;
//	}
//	else
//		searchstandfor(p, q->left);
//}
//int Delete(node * &T, int x)
//{
//	if (T == NULL)
//		return 0;
//	if (T->info == x)
//	{
//		node* p = T;
//		if (T->left == NULL)
//			T = T->right;
//		else
//			if (T->right == NULL)
//				T = T->left;
//			else
//				searchstandfor(p, T->right);
//		delete p;
//		return 1;
//	}
//	else
//		if (T->info < x)
//			return Delete(T->right, x);
//		else
//			return Delete(T->left, x);
//}
//void duyetLNR(node * p)
//{
//	if (p != NULL)
//	{
//		duyetLNR(p->left);
//		cout << p->info << " ";
//		duyetLNR(p->right);
//	}
//}
//void duyetNLR(node * p)
//{
//	if (p != NULL)
//	{
//		cout << p->info << " ";
//		duyetNLR(p->left);
//		duyetNLR(p->right);
//	}
//}
//void duyetLRN(node * p)
//{
//	if (p != NULL)
//	{
//		duyetLRN(p->left);
//		duyetLRN(p->right);
//		cout << p->info << " ";
//	}
//}
//
//void Print2DUtil(node * p, int space)
//{
//	if (p == NULL)
//		return;
//	space += count;
//	Print2DUtil(p->right, space);
//	cout << endl;
//	for (int i = count; i < space; i++)
//		cout << " ";
//	cout << p->info << "\n";
//	Print2DUtil(p->left, space);
//}
//void list()
//{
//	Print2DUtil(root, 0);
//	cout << endl;
//}
//int main()
//{
//	int temp, x;
//	node* p;
//	cout << "====================Menu=======================\n";
//	cout << "1. Khoi tao CNPTK\n";
//	cout << "2. Them mot phan tu vao cay\n";
//	cout << "3. Tim mot phan tu trong cay\n";
//	cout << "4. Xoa mot node trong cay\n";
//	cout << "5. Duyet cay theo LNR\n";
//	cout << "6. Duyet cay theo NLR\n";
//	cout << "7. Duyet cay theo LRN\n";
//	cout << "8. Xuat cay\n";
//	cout << "9. Thoat\n";
//	do {
//		do {
//			cout << "Nhap vao lua chon cua ban: ";
//			cin >> temp;
//			if (temp < 1 || temp >9)
//				cout << "Nhap sai, nhap lai";
//		} while (temp < 1 || temp >9);
//
//		switch (temp)
//		{
//		case 1:
//		{
//			init();
//			cout << "Khoi tao thanh cong\n";
//			break;
//		}
//		case 2:
//		{
//			cout << "Nhap vao x: ";
//			cin >> x;
//			insert(root, x);
//			cout << "Cay sau khi nhap\n";
//			list();
//			break;
//		}
//		case 3:
//		{
//			cout << "Nhap vao x: ";
//			cin >> x;
//			p = search(root, x);
//			if (p != NULL)
//				cout << "Tim thay " << x << "\n";
//			else
//				cout << "Khong tim thay x\n";
//			break;
//		}
//		case 4:
//		{
//			cout << "Nhap vao x: ";
//			cin >> x;
//			Delete(root, x);
//			cout << "Cay sau khi xoa\n";
//			list();
//			break;
//		}
//		case 5:
//		{
//			cout << "Cay nhi phan: ";
//			duyetLNR(root);
//			cout << endl;
//			break;
//		}
//		case 6:
//		{
//			cout << "Cay nhi phan: ";
//			duyetNLR(root);
//			cout << endl;
//			break;
//		}
//		case 7:
//		{
//			cout << "Cay nhi phan: ";
//			duyetLRN(root);
//			cout << endl;
//			break;
//		}
//		case 8:
//		{
//			cout << "Cay nhi phan";
//			list();
//			cout << endl;
//		}
//		}
//	} while (temp != 9);
//	cout << "Goodbye...........";
//	system("pause");
//	return 0;
//}