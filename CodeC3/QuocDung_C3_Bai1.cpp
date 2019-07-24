#include <iostream>
#include <ctime>
#include <stdio.h>
using namespace std;

#define max 5000
int a[max],b[max], n;

void Khoi_tao(int a[], int &n)
{
	cout <<"Nhap vao so luong phan tu\n";
	cin >> n;
	//thay doi seed (gia tri phan tu trong cung 1 lan chay)
	srand(time(NULL));
	for(int i=0; i<n; i++)
		a[i] = rand()%10000 +1;
}
void nhap(int a[], int &n)
{
	cout <<"Nhap vao so luong gia tri: ";
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
}

void copy_array(int a[], int b[], int n)
{
	for(int i=0; i<n; i++)
		b[i]=a[i];
}
void xuat(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout <<a[i] <<" " ;
	}
	cout << endl;
}

void insertionSort(int a[], int n)
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

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void selectionSort(int a[], int n)
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

void interchangeSort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[j] < a[i])
				swap(a[i],a[j]);
}

void bubbleSort(int a[], int n)
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

int find_tt(int a[], int n, int x)
{
	int i=0;
	while(i<n && a[i] !=x)
		i++;
	if(i<n)
		return 1;
	return 0;
}

int find_np(int a[], int n, int x)
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

void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2*i +1;
	int r = 2*i +2;

	if( l< n && a[l] > a[largest])
		largest = l;
	if( r< n && a[r] > a[largest])
		largest = r;

	if(largest != i)
		swap(a[largest],a[i]);
	heapify(a,n,largest);

}

int main()
{
	clock_t start;
	double duration;
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

				Khoi_tao(a,n);
				cout <<"Mang: \n";
				xuat(a,n);
				break;
			}
		case 1:
			{
				nhap(a,n);
				break;
			}
		case 2:
			{
				cout << "Mang: \n";
				xuat(a,n);
				break;
			}
		case 3:
			{
				copy_array(a,b,n);
				start = clock();
				insertionSort(a,n);
				duration = (clock() - start)/double(CLOCKS_PER_SEC);
				if(n<100)
				{
					cout <<"Mang sau khi sap xep la: \n";
					xuat(a,n);
				}
				cout <<"Thoi gian SELECTION = " << duration*1000000 << endl;
				break;
			
			}
		case 4:
			{
				copy_array(a,b,n);
				start = clock();
				selectionSort(a,n);
				duration = (clock() - start)/double(CLOCKS_PER_SEC);
				if( n<100)
				{
					cout <<"Mang sau khi sap xep la: \n";
					xuat(a,n);
				}
				cout <<"Thoi gian SELECTION = " << duration*1000000 << endl;
				break;
			
			}
		case 5:
			{
				copy_array(a,b,n);
				start = clock();
				interchangeSort(a,n);
				duration = (clock() - start)/double(CLOCKS_PER_SEC);
				if( n<100)
				{
					cout <<"Mang sau khi sap xep la: \n";
					xuat(a,n);
				}
				
				cout <<"Thoi gian SELECTION = " << duration*1000000 << endl;
				break;
			
			}
		case 6:
			{
				copy_array(a,b,n);
				start = clock();
				bubbleSort(a,n);
				duration = (clock() - start)/double(CLOCKS_PER_SEC);
				if( n<100)
				{
					cout <<"Mang sau khi sap xep la: \n";
					xuat(a,n);
				}
				cout <<"Thoi gian SELECTION = " << duration*1000000 << endl;
				break;
			
			}
		case 7:
			{
				int left,right;
				left = 0;
				right = n-1;
				copy_array(a,b,n);
				start = clock();
				quickSort(a,left,right);
				duration = (clock() - start)/double(CLOCKS_PER_SEC);
				if( n<100)
				{
					cout <<"Mang sau khi sap xep la: \n";
					xuat(a,n);
				}
				cout <<"Thoi gian SELECTION = " << duration*1000000 << endl;
				break;
			
			}
		case 8:
			{
				copy_array(a,b,n);
				start = clock();
				heapSort(a,n);
				duration = (clock() - start)/double(CLOCKS_PER_SEC);
				if( n<100)
				{
					cout <<"Mang sau khi sap xep la: \n";
					xuat(a,n);
				}
				cout <<"Thoi gian SELECTION = " << duration*1000000 << endl;
				break;
			
			}
		case 9:
			{
				cout <<"Nhap vao gia tri can tim: ";
				cin >> x;
				i = find_tt(a,n,x);
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
				i = find_np(a,n,x);
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