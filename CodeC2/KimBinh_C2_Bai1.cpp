//#include <iostream>
//#include <iomanip>
//using namespace std;
//// cau 1.1
//# define MAX 100
//int a[MAX],n;
//// cau 1.2
//
//void Nhap(int a[], int &n)
//{
//	cout <<"Nhap n: ";
//	cin >> n;
//	cout <<"Nhap cac phan tu: \n";
//	for(int i=0; i<n; i++)
//	{
//		cout <<" a[" <<i << "]=";
//		cin >>a[i];
//	}
//}
//// cau 1.3
//
//void Xuat(int a[], int n)
//{
//	cout<<"Cac phan tu trong danh sach: \n";
//	for(int i=0; i<n; i++)
//	{
//		cout << a[i] << "\t";
//	}
//	cout << endl;
//}
//// cau 1.4
//
//int Search(int a[], int n, int x)
//{
//	int i=0;
//	while( i<n && a[i] != x)
//	{
//		i++;
//		if(i=n)
//			return -1;
//	}
//	return i;
//}
//int Addlast(int a[], int &n, int x)
//{
//	if( n<MAX )
//	{
//		a[n]=x;
//		n++;
//		return 1;
//	}
//	return 0;
//}
//int Deletelast(int a[], int &n)
//{
//
//	if( n>0 )
//	{
//		n--;
//		return 1;
//	}
//	return 0;
//}
//int Delete(int a[], int n, int i)
//{
//	if( i>=0 && i<n)
//	{
//		for(int j=i; j<n-1; j++)
//		{
//			a[j]=a[j+1];
//		}
//		n--;
//		return 1;
//	}
//	return 0;
//}
//int SearchAndDelete(int a[], int &n, int x)
//{
//	for(int i=0; i<n; i++)
//	{
//		if(a[i]==x)
//		{
//			Delete(a,n,i);
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int choice = 0;
//	int x,i;
//	system("cls");
//	cout<<"1. Nhap danh sach"<<endl;
//	cout<<"2. Xuat danh sach"<<endl;
//	cout<<"3. Tim phan tu co gia tri x trong danh sach"<<endl;
//	cout<<"4. Them phan tu vao cuoi danh sach"<<endl;
//	cout<<"5. Xoa phan tu cuoi danh sach"<<endl;
//	cout<<"6. Xoa phan tu tai vi tri i"<<endl;
//	cout<<"7. Tim phan tu voi gia tri x va xoa no neu co"<<endl;
//	cout<<"8. Thoat"<<endl;
//
//	do
//	{
//		cout <<"Chon so di anh oi: ";
//		cin >> choice;
//		switch(choice)
//		{
//		case 1:
//			Nhap(a,n);
//			cout<< "Anh vua nhap danh sach thanh cong! >_<\n";
//			break;
//		case 2:
//			cout<<"Danh sach da nhap la: !\n";
//			Xuat(a,n);
//			break;
//		case 3:
//			cout<< "So anh can tim : ";
//			cin>>x;
//			i = Search(a,n,x);
//			if(i == -1)
//				cout<<"Tim khong thay "<<x<<endl;
//			else
//				cout<<"Tim thay tai vi tri i="<<i<<endl;
//			break;
//		case 4:
//			cout<<"Anh can them vao cuoi danh sach so :";
//			cin>>x;
//			i = Addlast(a,n,x);
//			if(i == 0)
//				cout<<"Danh sach da day,khong the them!"<<x<<endl;
//			else
//			{
//				cout<<"Da them phan tu x="<<i<<" vao cuoi danh sach !"<<endl;
//				cout<<"Danh sach sau khi them lai:";
//				Xuat(a,n);
//			}
//			break;
//		case 5:
//			i = Deletelast(a,n);
//			if(i > 0)
//			{
//				cout<<"Xoa thanh cong !"<<endl;
//				cout<<"Danh sach sau khi xoa phan tu cuoi la: \n";
//				Xuat(a,n);
//			}
//			else
//				cout<<"Danh sach dang rong,khong co phan tu nao! !"<<endl;
//			break;
//		case 6:
//			cout<<"Vui long nhap vi tri can xoa i= ";
//			cin>>i;
//			i = Delete(a,n,i);
//			if(i=1)
//			{
//				cout<<"Xoa thanh cong !"<<endl;
//				cout<<"Danh sach sau khi xoa la:\n";
//				Xuat(a,n);
//			}
//			else
//				cout<<"Khong co phan tu nao de xoa!!"<<endl;
//			break;
//		case 7:
//			cout<<"Vui long nhap gia tri can xoa x=:";
//			cin>>x;
//			i = SearchAndDelete(a,n,x);
//			if(i==1)
//			{
//				cout<<"Xoa thanh cong phan tu co gia tri x="<<x<<endl;
//				cout<<"Danh sach sau khi xoa la:\n";
//				Xuat(a,n);
//			}
//			else
//				cout<<"Khong co phan tu nao de xoa!!"<<endl;
//			break;
//		case 8:
//			cout << "Goodbye";
//			break;
//		default:
//			break;
//		}while(choice!=8);
//	system("pause");
//	return 0;
//}