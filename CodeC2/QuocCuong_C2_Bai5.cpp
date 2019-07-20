//#include <iostream>
//#include<stdio.h>
//using namespace std;
//#define max 100
//int a[max], s;
//void start()
//{
//	s = -1;
//}
//int IE(int a[], int s)
//{
//	if (s = -1)
//		return 1;
//	return 0;
//}
//int IF(int a[], int s)
//{
//	if (s == max)
//		return 1;
//	return 0;
//}
//int p(int a[], int &p, int x)
//{
//	if (s < max - 1)
//	{
//		a[++s] = x;
//		return 1;
//	}
//	return 0;
//}
//int pp(int a[], int &s, int &x)
//{
//	if (s == -1)
//		return 0;
//	else
//	{
//		x = a[s--];
//		return 1;
//	}
//}
//int main()
//{
//	int tam,x,i;
//	do
//	{
//		cout << "+++++++++ << Moi lua chon >> ++++++++++"<<endl;
//		cout << "+ <1> Tao danh sach"<<endl;
//		cout << "+ <2> Kiem tra rong"<<endl;
//		cout << "+ <3> Kiem tra day"<<endl;
//		cout << "+ <4> Them 1 phan tu"<<endl;
//		cout << "+ <5> Xoa 1 phan tu"<<endl;
//		cout << "+ <6> End"<<endl;
//		do {
//			cout << "Moi lua chon: ";
//			cin >> tam;
//		} while (tam < 1 || tam > 6);
//		switch (tam)
//		{
//		case 1:
//		{
//			start();
//			cout << "Success\n";
//			break;
//		}
//		case 2:
//		{
//			 i = IE(a, s);
//			 if (i == 1)
//				 cout << "Rong"<<endl;
//			 else
//				 cout << "Normal"<<endl;
//			 break;
//		}
//		case 3:
//		{
//			i = IF(a, s);
//			if (i == 1)
//				cout << "Day"<<endl;
//			else
//				cout << "Normal"<<endl;
//			break;
//		}
//		case 4:
//		{
//			cout << "Nhap X can them vao stack: ";
//			cin >> x;
//			i = p(a, s, i);
//			if (i == 1)
//			{
//				cout << "success"<<endl;
//			}
//			else
//				cout << "Fail"<<endl;
//		}
//		case 5:
//		{
//			i = pp(a, s, x);
//			if (i == 1)
//				cout << "success"<<endl;
//			else
//				cout << "fail"<<endl;
//		}
//		}
//	} while (tam != 6);
//	system("pause");
//	return 0;
//
//} 