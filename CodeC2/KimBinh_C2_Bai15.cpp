#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100
int a[MAX], b[MAX],c[MAX], d[MAX], n, m, count=0, count1=0, k=0, p=0;

void Nhap1(int a[], int &n)
{
	cout <<"Nhap vao so phan tu mang 1: ";
	cin >> n;
	cout <<"Nhap vao cac phan tu: \n";
	for(int i=0; i<n; i++)
	{
		cout <<" a[" <<i << "]=";
		cin >>a[i];
	}
}
void Nhap2(int b[], int &m)
{
	cout <<"Nhap vao so phan tu: ";
	cin >> m;
	cout <<"Nhap vao cac phan tu: \n";
	for(int i=0; i<m; i++)
	{
		cout <<" b[" <<i << "]=";
		cin >>b[i];
	}
}
void Xuat2mang(int a[], int b[])
{
	cout <<"Phan tu cua hai mang: \n";
	for(int i=0; i<n ; i++)
	{
		cout<< a[i] << " ";
	}
	for(int i=0; i<m ; i++)
	{
		cout<< b[i] << " ";
	}
	cout << endl;
}
void Giao(int a[], int b[])
{
	cout<<"Cac Phan tu giao cua hai danh sach la: " << endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(a[i]==b[j])
				cout<< a[i] <<" ";
		}
	}
	cout<< endl;
}
void Bu(int a[], int b[], int c[], int d[])
{
	for(int i=0; i< n; i++)
        for(int j=0; j< m; j++)
		{
			if(a[i] == b[j])
			{
                c[k]=a[i];
			    k++;
            }
		}
    cout<<"\nPhan bu la: ";
	for(int i=0; i< k; i++)
		cout<< c[i] << " ";
	for(int i=0; i< m; i++)
        for(int j=0; j< n; j++)
		{
			if(b[i] != a[j])
			{
                d[p]=b[i];
			    p++;
            }
		}
	for(int i=0; i< p; i++)
		cout<< d[i] << " ";
}

int main()
{
	system("cls");
	int choice;
	cout << "=============Menu=============\n";
	cout <<"(1) Nhap danh sach a va b\n";
	cout <<"(2) Xuat cac phan tu cua danh sach a va b\n";
	cout <<"(3) Tim phan giao\n";
	cout <<"(4) Tim phan bu\n";
	cout <<"(5) Thoat\n";

	do{
		cout <<"Nhap vao lua chon cua ban";
		cin >> choice;
		if(choice <1|| choice >5)
		{
			cout <<"Nhap sai, nhap lai\n";
		}

		switch(choice)
		{
	case 1: 
		{
			Nhap1(a,n);
			Nhap2(b,m);
			break;
		};
	case 2:
		{
			Xuat2mang(a,b);
			break;
		};
	case 3:
		{
			Giao(a,b);
			break;
		};
    case 4:
		{
			Bu(a,b,c,d);
			break;
		};
	   }
	  }while(choice !=5);
	system("pause");
	return 0;
}