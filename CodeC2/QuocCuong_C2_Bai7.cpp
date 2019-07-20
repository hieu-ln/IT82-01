//#include <iostream>
//#include <stdio.h>
//using namespace std;
//#define max 100
//int a[max], truoc, sau;
//void start(int a[], int &truoc, int &sau)
//{
//	truoc = -1;
//	sau	 = -1;
//}
//void xuat(int a[], int truoc, int sau)
//{
//	cout << " <==< ";
//	if (front <= sau && truoc != -1)
//	{
//		for (int i = truoc; i < sau +1; i++)
//			cout << a[i] << " ";
//	}
//	cout << " <==< ";
//	cout << endl;
//}
//int day(int a[], int truoc, int sau)
//{
//	if (sau - truoc == max - 1)
//		return 1;
//	return 0;
//}
//int rong(int a[], int truoc, int sau)
//{
//	if (truoc == -1)
//		return 1;
//	return 0;
//}
//int ptt(int a[], int &truoc, int &sau, int x)
//{
//	if (sau - truoc == max - 1)
//		return 0;
//	else
//	{
//		if (truoc == -1)
//			truoc = 0;
//		if (sau == max - 1)
//		{
//			for (int i = truoc ; i <= sau ; i++)
//				a[i - truoc] = a[truoc];
//			sau = max - 1 - truoc;
//			truoc = 0;
//		}
//		a[++sau] = x;
//		return 1; 
//	}
//}
//
//int ptt(int a[], int &truoc, int &sau,int &x)
//{
//	if (truoc == -1)
//		return 0;
//	else
//	{
//		x = a[truoc++];
//		if (truoc > sau)
//		{
//			truoc = -1;
//			sau = -1;
//		}
//		return 1;
//		
//	}
//}
//int pv(int a[], int &truoc, int &sau, int x)
//{
//	if (sau - truoc == max - 1)
//		return 0;
//	else
//	{
//		if (truoc == -1)
//			truoc = 0;
//		if (sau == max-1)
//		{
//			sau = -1;
//		}
//		a[++sau] = x;
//		return 1;
//	}
//}
//int pv(int a[], int &truoc, int &sau, int &x)
//{
//	if (truoc == -1)
//		return 0;
//	else
//	{
//		x = a[truoc++];
//		if (sau == truoc)
//		{
//			sau = -1;
//			truoc = -1;
//		}
//		if (truoc > max - 1)
//			truoc = 0;
//		return 1;
//	}
//}
//int main()
//{
//	int tam, x, i;
//	do {
//		cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
//		cout << "++++++++++++ << Moi chon >> ++++++++++++" << endl;
//		cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
//		cout << "++ <1> Tao danh sach"<<endl;
//		cout << "++ <2> Kiem tra rong" << endl;
//		cout << "++ <3> Kiem tra day" << endl;
//		cout << "++ <4> Them bang phuong phap tinh tien"<<endl;
//		cout << "++ <5> Them bang phuong phap vong" << endl;
//		cout << "++ <6> Xoa phan tu bang phuong phap tinh tien"<<endl;
//		cout << "++ <7> xoa phan tu bang phuong phap vong"<<endl;
//		cout << "++ <8> End"<<endl;
//		cout << "+++++++++++++++++++++++++++++++++++++++++" << ednl;
//		cout << "MOI LUA CHON: ";
//		cin >> tam;
//		switch (tam)
//		{
//		case 1:
//		{
//			init(a, truoc, sau);
//			cout << "Success"<<endl;
//			break;
//		}
//		case 2:
//		{
//			i = rong(a, truoc, sau);
//			if (i == 1)
//				cout << "rong"<<endl;
//			else
//				cout << "Normal"<<endl;
//			break;
//		}
//		case 3:
//		{
//			i = day(a, truoc, sau);
//			if (i == 1)
//				cout << "Day"<<endl;
//			else
//				cout << "Normal"<<endl;
//			break;
//		}
//		case 4: 
//		{
//			cout << "Nhap X can them ";
//			cin >> x;
//			i = ptt(a, truoc, sau, x);
//			if (i == 1)
//				cout << "success"<<endl;
//			else
//				cout << "fail";
//			cout << "Danh sach"<<endl;
//			xuat(a, truoc, sau);
//			break;
//		}
//		case 5:
//		{
//			cout << "Nhap X can them: ";
//			cin >> x;
//			i = pv(a, truoc, sau, x);
//			if (i == 1)
//				cout << "success"<<endl;
//			else
//				cout << "Fail"<<endl;
//			cout << "Danh sach:"<<endl;
//			xuat(a, truoc, sau);
//			break;
//		}
//		case 6:
//		{
//			i = ptt(a, truoc, sau, x);
//			if (i == 1)
//				cout << "Success"<<endl;
//			else
//				cout << "Fail"<<endl;
//			xuat(a, truoc, sau);
//			break;
//		}
//		case 7:
//		{
//			i = pv(a, truoc, sau, x);
//			if (i == 1)
//				cout << "success"<<endl;
//			else
//				cout << "fail"<<endl;
//			xuat(a, truoc, sau);
//			break;
//		}
//		default:
//			cout << "fail chon lai"<<endl;
//		}
//		
//	} while (tam != 8);
//	system("pause");
//	return 0;
//} 