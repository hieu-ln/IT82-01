//#include <iostream>
//#include<stdio.h>
//#include<iomanip>
//using namespace std;
//# define max 100
//int a[max], n;
//
//void input(int a[], int &n)
//{
//	cout <<"Nhap so phan tu cua mang: ";
//	cin >> n;
//	cout <<"Nhap mang: \n";
//	for(int i=0; i<n; i++)
//	{
//		cout <<" a[" <<i << "]=";
//		cin >>a[i];
//	}
//}
//
//void output(int a[], int n)
//{
//	cout <<"Xuat mang:  "<<endl;
//	for(int i=0; i<n ; i++)
//	{
//		cout <<"a[" << i << "]= " << a[i];
//	}
//	cout << endl;
//}
//
//int timkiem(int a[], int n, int x)
//{
//	int i = 0;
//	while(i < n && a[i] != x)
//	{
//		i++;
//		if(i == n)
//			return -1;
//	}
//	return i;
//}
//
//int themcuoi(int a[], int &n, int x)
//{
//	if(n < max)
//	{
//		a[n] = x;
//		n++ ;
//		return 1;
//	}
//	return 0;
//}
//
//int xoacuoi(int a[], int &n)
//{
//	if(n < 1)
//		return -1;
//	else
//	{
//		n--;
//		return 1;
//	}
//}
//
//int xoa_i(int a[], int &n, int x)
//{
//	int i = x;
//	if(n < -1)
//		return -1;
//	else
//	{
//		if(i >= n)		
//			return 0;
//		else
//		{
//			while (i<n)
//				a[i] = a[i++];
//			n--;
//			return 1;
//		}
//	}
//}
//
//int xoa_x(int a[], int &n, int x)
//{
//	if(timkiem(a,n,x) <0)
//		return -1;
//	else
//	{
//		if(xoa_i(a,n,timkiem(a,n,x) == 0))
//					return 0;
//				else
//					return 1;
//	}
//
//}
//int main()
//{
//	system("cls");
//	int choice;
//	cout << "++++++++++++ <<< Danh sach lua chon >>> ++++++++++++"<<endl;
//	cout <<"<1> -> Nhap"<<endl;
//	cout <<"<2> -> Xuat"<<endl;
//	cout <<"<3> -> Tim kiem x"<<endl;
//	cout <<"<4> -> Them 1 phan tu vao cuoi"<<endl;
//	cout <<"<5> -> Xoa 1 phan tu o cuoi"<<endl;
//	cout <<"<6> -> Xoa tai vi tri i"<<endl;
//	cout <<"<7> -> Xoa phan tu x"<<endl;
//	cout <<"<8> -> End"<<endl;
//
//	do{
//		cout <<"Moi ban lua chon";
//		cin >> choice;
//		if(choice <1|| choice >8)
//		{
//			cout <<"Khong co lua chon, moi ban chon lai"<<endl;
//		}
//
//		switch(choice)
//		{
//	case 1: 
//		{
//			input(a,n);
//			break;
//		};
//	case 2:
//		{
//			output(a,n);
//			break;
//		};
//	case 3:
//		{
//			int x;
//			cout <<"Moi ban nhap gia tri can tim: ";
//			cin >> x;
//			if(timkiem(a,n,x) <0)
//				cout <<"Khong tim thay gia tri ban yeu cau "<<endl;
//			else
//				cout <<"Tim thay gia tri ban can tim o vi tri: " <<timkiem(a,n,x) <<endl;
//			break;
//		};
//	case 4:
//		{
//			int x;
//			cout <<"Moi ban nhap gia tri can them vao cuoi danh sach: ";
//			cin >> x;
//			if(themcuoi(a,n,x) <0)
//				cout <<"Warning: unachievable"<<endl;
//			else
//				cout <<"Success!!!"<<endl;
//			break;
//		};
//	case 5:
//		{
//			if(xoacuoi(a,n) <0)
//				cout <<"Warning: unachievable"<<endl;
//			else
//				cout <<"Success!!!"<<endl;
//			break;
//		};
//	case 6:
//		{
//			int x;
//			cout <<"Moi ban nhap vi tri can xoa: ";
//			cin >> x;
//			if(xoa_i(a,n,x) == -1)
//				cout <<"Warning: unachievable"<<endl;
//			else
//				if(xoa_i(a,n,x) == 0)
//					cout << "Warning: unachievable"<<endl;
//				else
//					cout <<"Success!!!"<<endl;
//			break;
//		};
//	case 7:
//		{
//			int x;
//			cout <<"Moi ban nhap gia tri can : ";
//			cin >> x;
//			if (xoa_x(a, n, x) == -1 || xoa_x(a, n, x) == 0)
//				cout << "Warning: unachievable" << endl;
//			else
//				cout <<"Success!!!!"<<endl;
//			break;
//		};
//	case 8:
//		cout << "Goodbye!!! Thank you <3";
//			break;
//		}
//
//
//	} while(choice !=8);
//	system("pause");
//	return 0;
//} 