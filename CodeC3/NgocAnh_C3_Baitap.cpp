//Bai 1 chuong 3: Xep thu tu, tim kiem
#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

#define MAX 5000
// cau 1.1
int a[MAX];
int n;

// cau 1.0: khoi tao ngau nhien (nhap tu dong)
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
// cau 1.2: nhap danh sach
void input( int a[], int &n)
{
	cout << " Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	cout << " Nhap vao cac phan tu cua danh sach: " << endl;
	for (int i=0; i < n; i++)
	{
		cout << "a[ " << i << " ] = ";
		cin >> a[i];
	}
}
// cau 1.3: xuat danh sach
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
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
// cau 1.4: insertion sort
void insertionSort(int a[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i -1;
		/* Di chuyen cac phan tu co gia tri lon hon gia tri key ve sau mot vi tri so voi vi tri key ve sau mot vi tri so voi vi tri ban dau cua no*/
		while (j >= 0 && a[j]> key)
		{
			a[j + 1] = a[j];
			j = j -1;
		}
		a[j + 1] = key;
	}
}
// ham doi cho 2 so nguyen
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
// cau 1.5: selection sort
void selectionSort(int a[], int n)
{
	int i, j, min_idx;
	//Di chuyen ranh gioi cua mang da sap xep va chua sap xep
	for (i = 0; i < n - 1; i++)
	{
		// Tim phan tu nho nhat trong mang chua sap xep
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;

		// Doi cho phan tu nho nhat voi phan tu dau tien
		swap (a[min_idx], a[i]);
	}
}
// cau 1.6:
void interchangeSort (int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			 if (a[i] > a[j])
				 swap (a[i], a[j]); // doi cho a[i] va [j]
}
// cau 1.7:: ham sap xep bubble sort
void bubbleSort (int arr[], int n)
{
	int i, j;
	bool haveSwap =  false;
	for (i = 0; i < n - 1; i++)
	{
		// i phan tu cuoi cung da duoc sap xep
		haveSwap = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
				haveSwap = true; // kiem tra lan lap nay co swap khong
			}
		}
		// neu khong co swap nao thuc hien => mang da sap xep. Khong can lap them
		if (haveSwap == false)
		{
			break;
		}
	}
}
// cau 1.8:
int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while (true)
	{
		while (left <= right && a[left] < pivot) left++;
		while (right >= left && a[right] > pivot) right--;
		if (left >= right) break;
		swap(a[left], a[right]);
		left++;
		right--;
	}
	swap(a[left], a[high]);
	return left;
}
// Ham thuc hien bang quick sort
void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(a, low, high);
		quickSort(a, low, pi -1);
		quickSort(a, pi + 1, high);
	}
}
// cau 1.9: void heapify 
void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[largest])
		largest = 1;
	if (l < n && a[1] > a[largest])
		largest = r;
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
// cau 1.10:
void searchSequence(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
	}
	if (i == n)
	{
		cout << " Khong tim thay!";
	}
	else
	{
		cout << " Tim thay tai vi tri: " << i;
	}
}
// cau 1.11
int searchBinary(int a[], int l, int r, int x)
{
	if (r >= 1)
	{
		int mid = l + (r -l) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return searchBinary(a, l, mid - 1, x);
		return searchBinary(a, mid + 1, r, x);
	}
	return -1;
}
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << " -------- BAI TAP 1, CHUONG 3, XEP THU TU VA TIM KIEM --------" <<	endl;
	cout << " 0. Khoi tao danh sach ngau nhien!" << endl;
	cout << " 1. Nhap danh sach!" << endl;
	cout << " 2. Xuat danh sach!" << endl;
	cout << " 3. Xep thu tu danh sach bang SS!" << endl;
	cout << " 4. Xep thu tu danh sach bang INSERYION SOFT!" << endl;
	cout << " 5. Xep thu tu danh sach bang BS!" << endl;
	cout << " 6. Xep thu tu danh sach bang INTERCHANGE SOFT!" << endl;
	cout << " 7. Xep thu tu danh sach bang QS!" << endl;
	cout << " 8. Xep thu tu danh sach bang HS!" << endl;
	cout << " 9. Tim kiem phan tu x bang TIM KIEM TUAN TU!" << endl;
	cout << " 10.Tim kiem phan tu x bang TIM KIEM NHI PHAN!" << endl;
	cout << " 11. Thoat!" << endl;
	do
	{
		cout << " \nVui long chon so de thuc hien! ";
		cin >> choice;
		switch(choice)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			input(a, n);
			break;
		case 2:
			cout << "Danh sach la: " << endl;
			output(a, n);
		case 3:
			CopyArray(a, b, n);
			start = clock();
			selectionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << " Danh sach sau khi xep thu tu voi SS la: " << endl;
				output (b,n);
			}
			if (duration > 0)
				cout << " Thoi gian SS: " << duration * 1000000 << " Microseconds " << endl;
			break;
		case 4:
			CopyArray(a, b, n);
			start = clock();
			insertionSort (b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;	
			if (n<100)
			{
				cout << " Danh sach sau khi xep thu tu voi INSERYION SOFT la: " << endl;
				output (b,n);
			}
			if (duration > 0)
				cout << " Thoi gian INSERYION SOFT: " << duration * 1000000 << " Microseconds " << endl;
			break;
		case 5:
			CopyArray(a, b, n);
			start = clock();
			bubbleSort (b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;	
			if (n<100)
			{
				cout << " Danh sach sau khi xep thu tu voi BS la: " << endl;
				output (b,n);
			}
			if (duration > 0)
				cout << " Thoi gian BS: " << duration * 1000000 << " Microseconds " << endl;
			break;
		case 6:
			CopyArray(a, b, n);
			start = clock();
			interchangeSort (b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;	
			if (n<100)
			{
				cout << " Danh sach sau khi xep thu tu voi INTERCHANGE SOFT la: " << endl;
				output (b,n);
			}
			if (duration > 0)
				cout << " Thoi gian INTERCHANGE SOFT: " << duration * 1000000 << " Microseconds " << endl;
			break;
		case 7:
			CopyArray(a, b, n);
			start = clock();
			quickSort (b, 0, n-1);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;	
			if (n<100)
			{
				cout << " Danh sach sau khi xep thu tu voi QS la: " << endl;
				output (b,n);
			}
			if (duration > 0)
				cout << " Thoi gian QS: " << duration * 1000000 << " Microseconds " << endl;
			break;
		case 8:
			CopyArray(a, b, n);
			start = clock();
			heapSort (b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;	
			if (n<100)
			{
				cout << " Danh sach sau khi xep thu tu voi HS la: " << endl;
				output (b,n);
			}
			if (duration > 0)
				cout << " Thoi gian HS: " << duration * 1000000 << " Microseconds " << endl;
			break;
		case 9:
			cout << " Vui long nhap gia tri x=";
			cin >> x;
			start = clock();
			searchSequence(a, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC; 
			if (duration > 0)
				cout << " Thoi gian TIM KIEM TUAN TU: " << duration * 1000000 << " Microseconds " << endl;
			break;
		case 10:
			cout << " Vui long nhap gia tri x=";
			cin >> x;
			start = clock();
			i=searchBinary(b, 0, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC; 
			if (i == -1)
				cout << " Khong tim thay x= " << x << " trong day!";
			else 
				cout << " Tim thay x=" << x << " tai vi tri i= " << i << endl;
			if (duration > 0)
				cout << " Thoi gian TIM KIEM NHI PHAN: " << duration * 1000000 << " Microseconds " << endl;
			break;
		case 11:
			cout << " Goodbye.....!!!" << endl;
			break;
		default:
			break;
		}
	}while(choice!=11);

	system("pause");
	return 0;
}