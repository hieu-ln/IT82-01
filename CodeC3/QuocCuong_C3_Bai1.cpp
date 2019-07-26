//#include<iostream>
//#include<ctime>
//#include<stdio.h>
//using namespace std;
//#define max 5000
//int x[max], y[max], n;
//void taomang(int x[], int& n)
//{
//	cout << "nhap so phan tu: ";
//	cin >> n;
//	srand(time(NULL));
//	for (int i = 0; i < n; i++)
//		x[i] = rand() % 1000 + 1;
//}
//void nhap(int x[], int& n)
//{
//	cout << "Nhap so luong gia tri: "<<endl;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cout << "x[" << i << "]: ";
//		cin >> x[i];
//	}
//}
//void saochep(int x[], int y[], int n)
//{
//	for (int i = 0; i < n; i++)
//		y[i] = x[i];
//}
//void output	(int x[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << x[i] << " ";
//	}
//	cout << endl;
//}
//void sschen(int a[], int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		int x, j;
//		x = a[i];
//
//		j = i - 1;
//		while (j >= 0 && a[j] > x)
//		{
//			a[j + 1] = a[j];
//			j--;
//		}
//		a[j + 1] = x;
//	}
//}
//
//void swap(int& x, int& y)
//{
//	int tam;
//	tam = x;
//	x = y;
//	y = tam;
//}
//
//void lcss(int x[], int n)
//{
//	int min;
//	for (int i = 0; i < n - 1; i++)
//	{
//		min = i;
//		for (int j = i + 1; j < n; j++)
//		{
//			if (x[j] < x[min])
//				swap(x[i], x[min]);
//		}
//	}
//}
//
//void traodoi(int x[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//		for (int j = i + 1; j < n; j++)
//			if (x[j] < x[i])
//				swap(x[i], x[j]);
//}
//
//void noibot(int x[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = n - 1; j > i; j--)
//		{
//			if (x[j - 1] > x[j])
//				swap(x[j - 1], x[j]);
//		}
//	}
//}
//
//void quicksort(int x[], int trai, int phai	)
//{
//	int m = x[(trai + phai) / 2];
//	int i = trai;
//	int j = phai;
//	while (i < j)
//	{
//		while (x[i] < m)
//			i++;
//		while (x[j] > m)
//			j--;
//		if (i <= j)
//		{
//			swap(x[i], x[j]);
//			i++; j--;
//		}
//		if (trai < j)
//			quicksort(x, trai, j);
//		if (i < phai)
//			quicksort(x, i, phai);
//	}
//}
//void doicho	(int x[], int n, int i)
//{
//	int j = 2 * i + 1;
//	if (j >= n)
//		return;
//	if (j + 1 < n)
//		if (x[j] < x[j + 1])
//			j++;
//
//	if (x[i] >= x[j])
//		return;
//	else
//	{
//		int m = x[i];
//		x[i] = x[j];
//		x[j] = m;
//		doicho(x, j, n);
//	}
//
//}
//void heapsort(int x[], int n)
//{
//	int i = n / 2 - 1;
//	while (i >= 0)
//	{
//		doicho(x, i, n - 1);
//		i--;
//	}
//	int phai = n - 1;
//	while (phai > 0)
//	{
//		traodoi(x[0], x[phai]);
//		phai--;
//		if (phai > 0)
//			doicho(x, 0, phai);
//	}
//}
//int timkiem_tt(int x[], int n, int m)
//{
//	int i = 0;
//	while (i < n && x[i] != m)
//		i++;
//	if (i < n)
//		return 1;
//	return 0;
//}
//int timkiem_np(int x[], int n, int m)
//{
//	int trai = 0, phai = n - 1, giua;
//	while (trai < phai)
//	{
//		giua = (trai + phai) / 2;
//		if (x[giua] == m) return 1;
//		if (m < x[mid]) phai = giua - 1;
//		else
//			trai = giua + 1;
//	}
//	return -1;
//}
//void heap(int x[], int n, int i)
//{
//	int lonnhat = i;
//	int l = 2 * i + 1;
//	int r = 2 * i + 2;
//
//	if (l< n && x[l] > x[lonnhat])
//		lonnhat = l;
//	if (r< n && x[r] > x[lonnhat])
//		lonnhat = r;
//
//	if (lonnhat != i)
//		doicho(x[lonnhat], x[i]);
//	heap(x, n, lonnhat);
//
//}
//int main()
//{
//	clock_t start;
//	double duration;
//	int choice, x, i;
//	system("cls");
//	cout << "++++++++++++ << MOI LUA CHON >> ++++++++++++"<<endl;
//	cout << "++++++++++++++++++++++++++++++++++++++++++++"<<endl;
//	cout << "+ 0-> Khoi tao danh sach"<<endl;
//	cout << "+ 1-> Nhap"<<endl;
//	cout << "+ 2-> Xuat"<<endl;
//	cout << "+ 3-> InsertionSort"<<endl;
//	cout << "+ 4-> SelectionSort"<<endl;
//	cout << "+ 5-> InterchangeSort"<<endl;
//	cout << "+ 6-> BubbleSort"<<endl;
//	cout << "+ 7-> QuickSort\n";
//	cout << "+ 8-> HeapSort\n";
//	cout << "+ 9-> Tim tuan tu\n";
//	cout << "+ 10-> Tim nhi phan\n";
//	cout << "+ 11-> End\n";
//
//
//	do {
//
//		do {
//			cout << "Moi nhap lua chon: ";
//			cin >> choice;
//		} while (choice < 0 || choice >11);
//		switch (choice)
//		{
//		case 0:
//		{
//
//			taomang(x, n);
//			cout << "mang: \n";
//			(x, n);
//			break;
//		}
//		case 1:
//		{
//			nhap(x, n);
//			break;
//		}
//		case 2:
//		{
//			cout << "Mang: \n";
//			output(x, n);
//			break;
//		}
//		case 3:
//		{
//			saochep(a, b, n);
//			start = clock();
//			sschen(a, n);
//			duration = (clock() - start) / double(CLOCKS_PER_SEC);
//			if (n < 100)
//			{
//				cout << "Mang sau khi sap xep la: \n";
//				output(x, n);
//			}
//			cout << "Thoi gian SELECTION = " << duration * 100000 << endl;
//			break;
//
//		}
//		case 4:
//		{
//			saochep(x, y, n);
//			start = clock();
//			lcss(x, n);
//			duration = (clock() - start) / double(CLOCKS_PER_SEC);
//			if (n < 100)
//			{
//				cout << "Mang sau khi sap xep la: \n";
//				output(x, n);
//			}
//			cout << "Thoi gian SELECTION = " << duration * 1000000 << endl;
//			break;
//
//		}
//		case 5:
//		{
//			saochep(x, y, n);
//			start = clock();
//			traodoi(x, n);
//			duration = (clock() - start) / double(CLOCKS_PER_SEC);
//			if (n < 100)
//			{
//				cout << "Mang sau khi sap xep la: \n";
//				output(x, n);
//			}
//
//			cout << "Thoi gian SELECTION = " << duration * 1000000 << endl;
//			break;
//		}
//		case 6:
//		{
//			saochep(x, y, n);
//			start = clock();
//			noibot(x, n);
//			duration = (clock() - start) / double(CLOCKS_PER_SEC);
//			if (n < 100)
//			{
//				cout << "Mang sau khi sap xep la: \n";
//				output(x, n);
//			}
//			cout << "Thoi gian SELECTION = " << duration * 1000000 << endl;
//			break;
//		}
//		case 7:
//		{
//			int left, right;
//			left = 0;
//			right = n - 1;
//			saochep(x, y, n);
//			start = clock();
//			quicksort(x, left, right);
//			duration = (clock() - start) / double(CLOCKS_PER_SEC);
//			if (n < 100)
//			{
//				cout << "Mang sau khi sap xep la: \n";
//				xuat(x, n);
//			}
//			cout << "Thoi gian SELECTION = " << duration * 1000000 << endl;
//			break;
//		}
//		case 8:
//		{
//			saochep(x, y, n);
//			start = clock();
//			heapsort(x, n);
//			duration = (clock() - start) / double(CLOCKS_PER_SEC);
//			if (n < 100)
//			{
//				cout << "Mang sau khi sap xep la: \n";
//				output(x, n);
//			}
//			cout << "Thoi gian SELECTION = " << duration * 1000000 << endl;
//			break;
//		}
//		case 9:
//		{
//			cout << "Nhap vao gia tri can tim: ";
//			cin >> x;
//			i = timkiem_tt(a, n, x);
//			if (i > 0)
//				cout << "Tim thay x\n";
//			else
//				cout << "Khong tim thay x\n";
//			break;
//		}
//		case 10:
//		{
//			cout << "Nhap vao gia tri can tim: ";
//			cin >> x;
//			i = timkiem_np(a, n, x);
//			if (i > 0)
//				cout << "Tim thay x\n";
//			else
//				cout << "Khong tim thay x\n";
//			break;
//		}
//		}
//
//	} while (choice != 11);
//	system("pause");
//	return 0;
//
//}