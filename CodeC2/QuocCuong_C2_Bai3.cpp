//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//#define max 100
//
//struct node
//{
//	int thongtin;
//	node *link;
//};
//
//node *first;
//
//void start()
//{
//	first = NULL;
//}
//
//void danhsach()
//{
//	node *p = first;
//	while (p != NULL)
//	{
//		cout << p->thongtin << " ";
//		p = p->link;
//	}
//	cout << endl;
//}
//
//int timkiem(int x)
//{
//	node *p = first; 
//	int i = 0;
//	while (p != NULL && p->thongtin!=x )
//	{
//		p = p->link;
//		i++;
//	}
//	if (p != NULL)
//		return i;
//	else
//		return 0;
//}
//
//void them_dau(int x)
//{
//	node *p;
//	p = new node;
//	p->thongtin = x;
//	p->link = first;
//	first = p;
//}
//
//void them_cuoi(int x)
//{
//	node *p;
//	p = new node;
//	p->thongtin = x;
//	p->link = NULL;
//	 
//	if (first == NULL)
//	{
//		first = p;
//	}
//	else
//	{
//		node *q = first;
//		while (q->link != NULL)
//		{
//			q = q->link;
//		}
//		q->link = p;
//	}	
//}
//
//int xoa_dau()
//{
//	while (first != NULL)
//	{
//		node *p = first;
//		first = first->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
//int xoa_cuoi()
//{
//	node *q, *p;
//	p = first;
//	q = first;
//	if (first != NULL)
//	{
//		while (p != NULL)
//		{
//			q = p;
//			p = p->link;
//		}
//		if (p != first)
//		{
//			q->link = NULL;
//		}
//		else
//			first = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
//int xoa_x(int x)
//{
//	if (first != NULL)
//	{
//		node *p, *q;
//		p = first;
//		q = first;
//		while (p->thongtin != x && p->link != NULL)
//		{
//			q = p;
//			p = p->link;
//		}
//		if (p != first && p->link != NULL)
//		{
//			q->link = p->link;
//			return 1;
//		}
//		else
//			if (p == first)
//			{
//				first = p->link;
//				delete p;
//				return 1;
//			}
//			else
//				if (p->link == NULL)
//				{
//					q->link = NULL;
//					delete p;
//					return 1;
//				}
//				else
//					return 0;
//	}
//	return 0;
//}
//void doi(node *a, node *b)
//{
//	int tam;
//	tam = a->thongtin;
//	a->thongtin = b->thongtin;
//	b->thongtin = tam;
//}
//void tangdan()
//{
//	node *p, *q, *min;
//	p = first;
//	while (p != NULL)
//	{
//		min = p;
//		q = p->link;
//
//		while (q != NULL)
//		{
//			if (q->thongtin < p->thongtin)
//			{
//				min = q;
//			}
//			q = q->link;
//		}
//		doi(min, p);
//
//		p = p->link;
//	}
//}
//void giamdan()
//{
//	node *p, *q, *min;
//	p = first;
//	while (p != NULL)
//	{
//		min = p;
//		q = p->link;
//
//		while (q != NULL)
//		{
//			if (q->thongtin > p->thongtin)
//			{
//				min = q;
//			}
//			q = q->link;
//		}
//		doi(min, p);
//
//		p = p->link;
//	}
//}
//
//int main()
//{
//	node *p;
//	int tam,x,i;
//	do {
//		cout << "+++++++++++++ << Moi lua chon >> +++++++++++"<<endl;
//		cout << " <1> Nhap"<<endl;
//		cout << " <2> Xuat"<<endl;
//		cout << " <3> Tim kiem"<<endl;
//		cout << " <4> Them vao dau danh sach"<<endl;
//		cout << " <5> Xoa dau danh sach"<<endl;
//		cout << " <6> Them vao cuoi danh sach"<<endl;
//		cout << " <7> Xoa cuoi danh sach"<<endl;
//		cout << " <8> Xoa X"<<endl;
//		cout << " <9> Danh sach tang dan"<<endl;
//		cout << " <10> Danh sach giam dan"<<endl;
//		cout << " <11> End" << endl;
//		do {
//			cout << "Nhap vao lua chon cua ban: ";
//			cin >> tam;
//			if (tam < 1 || tam >11)
//				cout << "Not found! nhap lai";
//		} while (tam < 1 || tam >11);
//
//		switch (tam)
//		{
//		case 1:
//		{
//			start();
//			cout << "Success!"<<endl;
//			break;
//		}
//		case 2:
//		{
//			danhsach();
//			break;
//		}
//		case 3:
//		{
//			cout << "Nhap X can tim: ";
//			cin >> x;
//			i = timkiem(x);
//			if (i>0)
//				cout << "Tim thay"<<endl;
//			else
//				cout << "Not found"<<endl;
//			break;
//		}
//		case 4:
//		{
//			cout << "Nhap gia tri them vao dau danh sach: ";
//			cin >> x;
//			them_dau(x);
//			cout << "Danh sach: "<<endl;
//			danhsach();
//			cout << endl;
//			break;
//		}
//		case 5:
//		{
//			i = xoa_dau();
//			if (i == 0)
//				cout << "Khong the xoa"<<endl;
//			else
//			{
//				cout << "Success"<<endl;
//				cout << "Danh sach"<<endl;
//				danhsach();
//				cout << endl;
//			}
//			break;
//		}
//		case 6: 
//		{
//			cout << "Nhap gia tri can them vao cuoi danh sach: ";
//			cin >> x;
//			them_cuoi(x);
//			cout << "Danh sach:"<<endl;
//			danhsach();
//			cout << endl;
//			break;
//		}
//		case 7:
//		{
//			i = xoa_cuoi();
//			if (i == 0)
//				cout << "Khong the xoa"<<endl;
//			else
//			{
//				cout << "Success"<<endl;
//				cout << "Danh sach:"<<endl;
//				danhsach();
//				cout << endl;
//			}
//			break;
//		}
//		case 8:
//		{
//			cout << "Nhap gia tri can xoa X: ";
//			cin >> x;
//			i = xoa_x(x);
//			if (i == 0)
//				cout << "Khong the xoa\n ";
//			else
//			{
//				cout << "Success\n";
//				cout << "Danh sach: \n";
//				danhsach();
//				cout << endl;
//			}
//			break;
//		}
//		case 9:
//		{
//			tangdan();
//			cout << "Danh sach: \n";
//			danhsach();
//			cout << endl;
//			break;
//		}
//		case 10:
//		{
//			giamdan();
//			cout << "Danh sach: \n";
//			danhsach();
//			cout << endl;
//			break;
//		}
//		}
//	} while (tam != 11);
//
//	system("pause");
//	return 0;
//} 