#include <iostream>
#include <stdio.h>
using namespace std;
//Cau 1.1
#define MAX 5000
int a[MAX], b[MAX], n;
void init (int a[], int &n)
{
	cout <<" Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i]= rand() % 10000 +1;
	}
	cout << " Danh sach da duoc nhap ngau nhien nhu sau: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//Cau 1.2
void Nhap(int a[], int &n)
{
	cout <<"Nhap vao so phan tu cua mang: ";
	cin >> n;
	cout <<"Nhap vao cac phan tu: \n"<< endl;
	for(int i=0; i<n; i++)
	{
		cout <<" a[" <<i << "]=";
		cin >>a[i];
	}
}
//Cau 1.3
void Xuat(int a[], int n)
{
	cout<<"Cac phan tu trong danh sach: \n";
	for(int i=0; i<n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
void CopyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}
// hoan doi hai phan tu
void Swap(int &a,int &b)
{
	int t = a; 
	a=b;
	b=t;
}
//Cau 1.4
void InsertionSort(int a[], int n)
{
	for(int i=1; i<n;i++)
	{
		int x,j;
		x = a[i];

		j=i-1;
		while(j>=0 && a[j] > x)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}
//Cau 1.5
void SelectionSort(int a[], int n)
{
	int min;
	for(int i=0; i<n-1; i++)
	{
		min = i;
		for(int j= i+1; j< n; j++)
		{
			if(a[j] < a[min])
				swap(a[i],a[min]);
		}
	}
}
//Cau 1.6
void InterchangeSort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[j] < a[i])
				swap(a[i],a[j]);
}
//Cau 1.7
void BubbleSort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j= n-1; j>i; j--)
		{
			if(a[j-1] > a[j])
				swap(a[j-1],a[j]);
		}
	}
}
//Cau 1.8
void quickSort(int a[],int left, int right)
{
	int x =a[(left + right)/2];
	int i=left;
	int j = right;
	while( i<j)
	{
		while(a[i] < x)
			i++;
		while(a[j] > x)
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++; j--;
		}
		if(left <j) 
			quickSort(a,left,j);
		if(i<right)
			quickSort(a,i,right);
	}
}
//Cau 1.9
void shift(int a[], int n, int i)
{
	int j= 2*i+1;
	if( j>= n)
		return;
	if(j+1 <n)
		if(a[j] < a[j+1])
			j++;

	if(a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a,j,n);
	}

}
void heapSort(int a[],int n)
{
	int i = n/2 -1;
	while( i>=0)
	{
		shift(a,i,n-1);
		i--;
	}
	int right = n-1;
	while(right >0)
	{
		swap(a[0], a[right]);
		right --;
		if(right >0)
			shift(a,0,right);
	}
}
//Cau 1.10
int Search(int a[], int n, int x)
{
	int i=0;
	while(i<n && a[i] !=x)
		i++;
	if(i<n)
		return 1;
	return 0;
}
//Cau 1.12
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n-1, mid;
	while(left < right)
	{
		mid = (left+right)/2; 
		if(a[mid] == x) return 1;
		if(x < a[mid]) right = mid -1;
		else 
			left = mid +1;
	}
	return -1;
}
int main()
{
	int choice,x,i;
	system("cls");
	
	cout <<"==========Menu==========\n";
	cout <<"0.Khoi tao danh sach ngau nhien\n";
	cout <<"1. Nhap danh sach\n";
	cout <<"2. Xuat danh sach\n";
	cout <<"3. InsertionSort\n";
	cout <<"4. SelectionSort\n";
	cout <<"5. InterchangeSort\n";
	cout <<"6. BubbleSort\n";
	cout <<"7. QuickSort\n";
	cout <<"8. HeapSort\n";
	cout <<"9. Tim tuan tu\n";
	cout <<"10. Tim nhi phan\n";
	cout <<"11. Thoat\n";
	

	do{

		do{
				cout <<"Nhap vao lua chon cua ban: ";
				cin >> choice;
		}while(choice <0 || choice >11);
		switch(choice)
		{
		case 0:
			{

				init(a,n);
				cout <<"Mang: \n";
				Xuat(a,n);
				break;
			}
		case 1:
			{
				Nhap(a,n);
				break;
			}
		case 2:
			{
				cout << "Mang: \n";
				Xuat(a,n);
				break;
			}
		case 3:
			{
				CopyArray(a,b,n);
				InsertionSort(a,n);
				if(n<100)
				{
					cout <<"Mang sau khi sap xep la: \n";
					Xuat(a,n);
				}
				cout<<endl;
				break;
			
			}
		case 4:
			{
				CopyArray(a,b,n);
				SelectionSort(a,n);
				if( n<100)
				{
					cout <<"Mang sau khi sap xep la: \n";
					Xuat(a,n);
				}
				cout<<endl;
				break;
			
			}
		case 5:
			{
				CopyArray(a,b,n);
				InterchangeSort(a,n);
				if( n<100)
				{
					cout <<"Mang sau khi sap xep la: \n";
					Xuat(a,n);
				}
				
				cout<< endl;
				break;
			
			}
		case 6:
			{
				CopyArray(a,b,n);
				BubbleSort(a,n);
				if( n<100)
				{
					cout <<"Mang sau khi sap xep la: \n";
					Xuat(a,n);
				}
				cout<< endl;
				break;
			
			}
		case 7:
			{
				int left,right;
				left = 0;
				right = n-1;
				CopyArray(a,b,n);
				quickSort(a,left,right);
				if( n<100)
				{
					cout <<"Mang sau khi sap xep la: \n";
					Xuat(a,n);
				}
				cout<< endl;
				break;
			
			}
		case 8:
			{
				CopyArray(a,b,n);
				heapSort(a,n);
				if( n<100)
				{
					cout <<"Mang sau khi sap xep la: \n";
					Xuat(a,n);
				}
				cout<< endl;
				break;
			
			}
		case 9:
			{
				cout <<"Nhap vao gia tri can tim: ";
				cin >> x;
				i = Search(a,n,x);
				if(i>0)
					cout <<"Tim thay x\n";
				else
					cout <<"Khong tim thay x\n";
				break;
			}
		case 10:
			{
				cout <<"Nhap vao gia tri can tim: ";
				cin >> x;
				i = BinarySearch(a,n,x);
				if(i>0)
					cout <<"Tim thay x\n";
				else
					cout <<"Khong tim thay x\n";
				break;
			}
		}
		
	}while(choice!=11);

	system("pause");
	return 0;
		
}