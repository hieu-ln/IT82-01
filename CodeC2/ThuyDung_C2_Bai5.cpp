//#include <iostream>
//using namespace std;
//
//#define max 100
//int a[max], sp;
//
//void init()
//{
//	sp = -1;
//}
//
//int IsEmpty(int a[], int sp)
//{
//	if (sp = -1)
//		return 1;
//	return 0;
//}
//
//int IsFull(int a[], int sp)
//{
//	if (sp == max)
//		return 1;
//	return 00;
//}
//
//int push(int a[], int &sp, int x)
//{
//	if (sp < max - 1)
//	{
//		a[++sp] = x;
//		return 1;
//	}
//	return 0;
//}
//
//int pop(int a[], int &sp, int &x)
//{
//	if (sp == -1)
//		return 0;
//	else
//	{
//		x = a[sp--];
//		return 1;
//	}
//}
//
//int main()
//{
//	int temp,x,i;
//	do
//	{
//		cout << "==============Menu==============\n";
//		cout << " 1.Khoi tao stack rong\n";
//		cout << " 2.Kiem tra stack rong\n";
//		cout << " 3. Kiem tra stack day\n";
//		cout << " 4. Them mot phan tu vao stack\n";
//		cout << " 5. Xoa mot phan tu trong stack\n";
//		cout << " 6. thoat\n";
//
//		do {
//			cout << "Nhap vao lua chon: ";
//			cin >> temp;
//		} while (temp < 1 || temp > 6);
//
//		switch (temp)
//		{
//		case 1:
//		{
//			init();
//			cout << "Khoi tao thanh cong\n";
//			break;
//		}
//		case 2:
//		{
//			 i = IsEmpty(a, sp);
//			 if (i == 1)
//				 cout << "stack rong\n";
//			 else
//				 cout << "stack khong rong\n";
//			 break;
//		}
//		case 3:
//		{
//			i = IsFull(a, sp);
//			if (i == 1)
//				cout << "Stack day\n";
//			else
//				cout << "Stack khong day\n";
//			break;
//		}
//		case 4:
//		{
//			cout << "Nhap vao phan tu can them: ";
//			cin >> x;
//			i = push(a, sp, i);
//			if (i == 1)
//			{
//				cout << "Them thanh cong\n";
//			}
//			else
//				cout << "Them khong thanh cong\n";
//		}
//		case 5:
//		{
//			i = pop(a, sp, x);
//			if (i == 1)
//				cout << "Xoa thanh cong\n";
//			else
//				cout << "Xoa khong thanh cong\n";
//		}
//		}
//	} while (temp != 6);
//	system("pause");
//	return 0;
//
//}
//
