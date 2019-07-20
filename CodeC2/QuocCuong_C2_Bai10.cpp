//#include <iostream>
//#include<stdio.h>
//using namespace std;
//struct node 
//{
//	int thongtin;
//	node *link;
//};
//node *sp;
//void start()
//{
//	sp = NULL;
//}
//int rong()
//{
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//void danhsach()
//{
//	node *p = sp;
//	while (sp != NULL)
//	{
//		cout << p->thongtin << " ";
//		p = p->link;
//	}
//	cout << endl;
//}
//int pp()
//{
//	if (sp == NULL)
//		return 0;
//	else
//	{
//		int x;
//		node *p = sp;
//		x = p->thongtin;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//}
//
//void pu(int x)
//{
//	node *p;
//	p = new node;
//	p->thongtin = x;
//	p->link = sp;
//	sp = p;
//}
//
//void DB(int &x)
//{
//	int sd,tam;
//	tam = x;
//	cout << "Bin " << x << "la: ";
//	while (tam > 0)
//	{
//		sd = tam % 2;
//		pu(sd);
//		tam = tam / 2;
//	}
//	while (sp != NULL)
//	{
//		int x;
//		node *p;
//		x = sp->thongtin;
//		p = sp;
//		sp = sp->link;
//		delete p;
//		cout << x;
//	}
//}
//int main()
//{	
//	int tam,x,i;
//	do
//	{
//		cout << "++++++++++++MOI CHON++++++++++++"<<endl;
//		cout << "+ <1> Khoi tao"<<endl;
//		cout << "+ <2> Kiem tra rong"<<endl;
//		cout << "+ <3> Them vao stack"<<endl;
//		cout << "+ <4> Xoa 1 pt stack"<<endl;
//		cout << "+ <5> Doi thap phan -> bin"<<endl;
//		cout << "+ <7> End"<<endl;	
//		cout << "Moi lua chon: ";
//		cin >> tam;
//	
//		switch(tam)
//		{
//			case 1:
//			{
//				start();
//				cout << "success"<<endl;
//				break;
//			}
//			case 2:
//			{
//				i = rong();
//				if (i > 0)
//					cout << "Rong"<<endl;
//				else
//					cout << "Normal"<<endl;
//			}
//			case 3:
//			{
//				cout << "Nhap X can them: ";
//				cin >> x;
//				pu(x);
//				cout << "Success"<<endl;
//				danhsach();
//
//			}
//			case 4:
//			{
//				int i = pp();
//				if (i > 0)
//				{
//					cout << "Success\n";
//					cout << "Danh sach: ";
//					danhsach();
//				}
//				else
//					cout << "fail\n";
//			}
//			case 5:
//			{
//				cout << "Nhap vao so can doi sang nhi phan: ";
//				cin >> x;
//				DB(x);
//				cout << endl;
//			}
//		}
//	} while (tam != 7);
//	system("pause");
//	return 0;
//} 