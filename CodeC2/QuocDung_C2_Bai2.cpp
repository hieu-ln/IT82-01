//#include <iostream>
//#include <stdio.h>
//using namespace std; 
//
//#define max 100
//int a[max], n;
//
//void input(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Nhap a[" << i << "]: ";
//		cin >> a[i];
//	}
//}
//
//void output(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//}
//
//void swap(int &x, int &y)
//{
//	int temp;
//	temp = x;
//	x = y;
//	y = temp;
//}
////hàm kiểm tra tăng dần hay giảm dần
//void check_t(int a[], int n, bool &t)
//{
//	for (int i = 0; i < n - 1; i++)
//		if (a[i] < a[i + 1])
//			t = true;
//		else
//		{
//			t = false;
//			break;
//		}
//}
//void check_g(int a[], int n, bool &g)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		if (a[i] > a[i + 1])
//			g = true;
//		else
//		{
//			g = false;
//			break;
//		}
//	}
//}
//
//
//int add(int a[], int &n, int x)
//{
//	bool tang,giam;
//	check_t(a, n, tang);
//	check_g(a, n, giam);
//	//cout << tang << " " << giam << endl;
//	if (n < max)
//	{
//		n = n+1;
//		//trường hợp tăng dần
//		if (tang == 1 && giam == 0)
//			{
//				a[n - 1] = x;
//				for (int i = 0; i < n; i++)
//				{
//					if (a[n-1] < a[i])
//						swap(a[n-1], a[i]);
//				}
//			}
//		else
//			//trường hợp giảm dần
//			if (giam == 1 && tang == 0)
//			{
//				a[n - 1] = x;
//				for (int i = 0; i < n; i++)
//				{
//					if (a[n-1] > a[i])
//						swap(a[n-1], a[i]);
//				}
//				
//			}
//			else
//			{
//				//trường hợp không có thứ tự
//				a[n - 1] = x;
//			}
//		cout << endl;
//		return 1;
//	}
//	return -1;
//}
//
//int find_tt(int a[], int n, int x)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == x)
//		{
//			return i ;
//			break;
//		}
//	}
//	return -1;
//}
//
//int find_np(int a[], int n, int x)
//{
//	int left = 0, right = n-1,mid;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (a[mid] == x)
//			return mid;
//		if (a[mid] < x)
//			left = mid + 1;
//		else
//			right = mid - 1;
//	}
//
//	return -1;
//}
//
//int find_delete(int a[], int &n, int x)
//{
//	if (find_np(a, n, x) > -1)
//	{
//		int b = find_np(a, n, x);
//		for (int i = b; i < n; i++)
//		{
//			a[i] = a[i + 1];
//		}
//		n--;
//		return 1;
//	}
//	else
//		return -1;
//}
//
//int main()
//{
//	int temp;
//	do {
//
//		cout << "=================Menu===================\n";
//		cout << " 1. Nhap danh sach\n";
//		cout << " 2. Xuat danh sach\n";
//		cout << " 3. Them phan tu vao danh sach\n";
//		cout << " 4. Tim mot phan tu trong danh sach bang pp tim tuan tu\n";
//		cout << " 5. TIm mot phan tu trong danh sach bang pp tim nhi phan\n";
//		cout << " 6. Tim va xoa phan tu torng danh sach\n";
//		cout << " 7. Thoat\n";
//		
//		do {
//			cout << "Nhap vao lua chon: ";
//			cin >> temp;
//			if (temp > 7 || temp < 1)
//				cout << "Nhap sai, nhap lai\n";
//		} while (temp > 7 || temp < 1);
//
//		switch (temp)
//		{
//		case 1:
//		{
//			cout << "Nhap vao n: ";
//			cin >> n;
//			input(a, n);
//			cout << "Nhap thanh cong\n";
//			break;
//		}
//		case 2:
//		{
//			cout << "Danh sach: \n";
//			output(a, n);
//			cout << endl;
//			break;
//		}
//		case 3:
//		{
//			int x;
//			cout << "Nhap vao phan tu can them: ";
//			cin >> x;
//			if (add(a, n, x) > 0)
//			{
//				cout << "Them thanh cong\n";
//				output(a, n);
//			}
//			else
//				cout << "Them khong thanh cong\n";
//			break;
//		}
//		case 4:
//		{
//			int x;
//			cout << "Nhap vao phan tu can tim: ";
//			cin >> x;
//			if (find_tt(a, n, x) > -1)
//			{
//				cout << "Tim thay tai vi tri " << find_tt(a, n, x) << endl;
//			}
//			else
//				cout << " Khong tim thay\n";
//			break;
//		}
//		case 5:
//		{
//			int x;
//			cout << "Nhap vao phan tu can tim: ";
//			cin >> x;
//			if (find_np(a, n, x) > -1)
//			{
//				cout << "Tim thay tai vi tri " << find_np(a, n, x) << endl;
//			}
//			else
//				cout << " Khong tim thay\n";
//			break;
//		}
//		case 6:
//		{
//			int x;
//			cout << "Nhap vao phan tu can tim: ";
//			cin >> x;
//			if (find_delete(a, n, x) > -1)
//			{
//				cout << "Tim thay va xoa thanh cong\n";
//			}
//			else
//				cout << " Khong tim thay\n";
//			break;
//		}
//		}
//	} while (temp != 7);
//
//		int t = true;
//		cout << t;
//	system("pause");
//	return 0;
//}
//
//
//
//
