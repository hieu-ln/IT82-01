#include <iostream>
#include <iomanip>
using namespace std;
# define max 100
int a[max], n;

void Nhap(int a[], int &n)
{
	cout <<"Nhap vao so phan tu: ";
	cin >> n;
	cout <<"Nhap vao cac gia tri cua mang: \n";
	for(int i=0; i<n; i++)
	{
		cout <<" a[" <<i << "]=";
		cin >>a[i];
	}
}

void xuat(int a[], int n)
{
	cout <<"Mang co cac phan tu: \n";
	for(int i=0; i<n ; i++)
	{
		cout <<setw(4) <<"a[" << i << "]= " << a[i];
	}
	cout << endl;
}

int find(int a[], int n, int x)
{
	int i = 0;
	while(i < n && a[i] != x)
	{
		i++;
		if(i == n)
			return -1;
	}
	return i;
}

int addlast(int a[], int &n, int x)
{
	if(n < max)
	{
		a[n] = x;
		n++ ;
		return 1;
	}
	return 0;
}

int DeleteLast(int a[], int &n)
{
	if(n < 1)
		return -1;
	else
	{
		n--;
		return 1;
	}
}

int Delete_i(int a[], int &n, int x)
{
	int i = x;
	if(n < -1)
		return -1;
	else
	{
		if(i >= n)		
			return 0;
		else
		{
			while (i<n)
				a[i] = a[i++];
			n--;
			return 1;
		}
	}
}

int find_delete(int a[], int &n, int x)
{
	if(find(a,n,x) <0)
		return -1;
	else
	{
		if(Delete_i(a,n,find(a,n,x) == 0))
					return 0;
				else
					return 1;
	}

}
int main()
{
	system("cls");
	int choice;
	cout << "=============Menu=============\n";
	cout <<"(1) Nhap danh sach\n";
	cout <<"(2) Xuat danh sach\n";
	cout <<"(3) Tim mot phan tu\n";
	cout <<"(4) Them mot phan tu vao cuoi \n";
	cout <<"(5) Xoa mot phan tu cuoi danh sach \n";
	cout <<"(6) Xoa mot phan tu tai vi tri thu i \n";
	cout <<"(7) Tim va xoa mot phan tu \n" ;
	cout <<"(8) Thoat\n";

	do{
		cout <<"Nhap vao lua chon cua ban";
		cin >> choice;
		if(choice <1|| choice >8)
		{
			cout <<"Nhap sai, nhap lai\n";
		}

		switch(choice)
		{
	case 1: 
		{
			Nhap(a,n);
			break;
		};
	case 2:
		{
			xuat(a,n);
			break;
		};
	case 3:
		{
			int x;
			cout <<"Nhap vao gia tri x: ";
			cin >> x;
			if(find(a,n,x) <0)
				cout <<"Tim không thay gia tri\n";
			else
				cout <<"Tim thay gia tri tai vi tri: " <<find(a,n,x) <<endl;
			break;
		};
	case 4:
		{
			int x;
			cout <<"Nhap vao gia tri can them: ";
			cin >> x;
			if(addlast(a,n,x) <0)
				cout <<"Khong the them gia tri\n";
			else
				cout <<"Them gia tri thanh cong\n";
			break;
		};
	case 5:
		{
			if(DeleteLast(a,n) <0)
				cout <<"Khong the xoa phan tu cuoi vi mang rong\n";
			else
				cout <<"Xoa thanh cong phan tu cuoi\n";
			break;
		};
	case 6:
		{
			int x;
			cout <<"Nhap vao vi tri can xoa: ";
			cin >> x;
			if(Delete_i(a,n,x) == -1)
				cout <<"Mang rong, khong the xoa\n";
			else
				if(Delete_i(a,n,x) == 0)
					cout << "Khong the xoa tai vi tri do vi khong ton tai vi tri\n";
				else
					cout <<"Xoa thanh cong\n";
			break;
		};
	case 7:
		{
			int x;
			cout <<"Nhap vao gia tri x can tim va xoa: ";
			cin >> x;
			if(find_delete(a,n,x) == -1 || find_delete(a,n,x) == 0)
				cout <<"Khong tim thay gia tri x\n";
			else
				cout <<"Tim thay gia tri va xoa thanh cong\n";
			break;
		};
	case 8:
		break;
		}


	} while(choice !=8);

	system("pause");
	return 0;
}