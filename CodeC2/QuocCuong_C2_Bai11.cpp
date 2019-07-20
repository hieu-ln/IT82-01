//#include <iostream>
//#include<stdio.h>
//using namespace std;
//struct node
//{
//	int thongtin;
//	node *link;
//};
//node *truoc, *sau;
//void start()
//{
//	truoc = NULL;
//	sau = NULL;
//}
//int rong()
//{
//	if (truoc == NULL)
//		return 1;
//	return 0;
//}
//void pu(int x)
//{
//	node *p;
//	p = new node;
//	p->thongtin = x;
//	p->link = NULL;
//	if (truoc == NULL)
//		truoc = p;
//	else
//		sau->link = p;
//	sau = p;
//}
//int pp(int &x)
//{
//	node *p=truoc;
//	if (truoc != NULL)
//	{
//		truoc = p->link;
//		x = p->thongtin;
//		if (truoc == NULL)
//			sau = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void danhsach()
//{
//	node *p;
//	cout << " <-- ";
//	p = truoc;
//	do
//	{
//		cout << p->thongtin << " ";
//		p = p->link;
//	}  while (p != NULL);
//	cout << endl;
//}
//int main()
//{
//	int tam	, x, i;
//	do
//	{
//		cout << "++++++++++++MOI CHON++++++++++++"<<endl;
//		cout << " <1> Khoi tao"<<endl;
//		cout << " <2> Kiem rong"<<endl;
//		cout << " <3> Them mot phan tu"<<endl;
//		cout << " <4> Xoa mot phan tu"<<endl;
//		cout << " <5> End"<<endl;
//		do {
//			cout << "Moi lua chon: ";
//			cin >> tam;
//		} while (tam < 1 || tam > 5);
//
//		switch (tam)
//		{
//		case 1:
//		{
//			start();
//			cout << "success"<<endl;
//			break;
//		}
//		case 2:
//		{
//			i = rong();
//			if (i > 0)
//				cout << "rong"<<endl;
//			else
//				cout << "Normal"<<endl;
//			break;
//		}
//		case 3:
//		{
//			cout << "Nhap X can them";
//			cin >> x;
//			pu(x);
//			cout << "Queue: ";
//			danhsach();
//		}
//		case 4:
//		{
//			pp(x);
//			cout << "Phan tu lay ra tu queue: ";
//			cout << "Queue: ";
//			danhsach();
//		}
//		}
//	} while (tam != 5);
//	system("pause");
//	return 0;
//}