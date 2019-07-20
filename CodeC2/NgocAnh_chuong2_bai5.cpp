// Bai 5 chuong 2: Danh sach han che, ngan xep, stack
#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100

// cau 5.2: khoi tao STACK rong
void init(int a[], int &sp)
{
	sp = -1;
}
// cau 5.3: kiem tra ngan xep rong
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

// cau 5.4: Kiem tra ngan xep day
int isFull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}

// cau 5.5: Them phan tu vao ngan xep
int Push(int a[], int &sp, int &x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

// 5.6: xoa mot phan tu
int Pop(int a[], int &sp, int &x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

// xuat STACK
void Process_stack(int a[], int sp)
{
	for (int i = 0; i < sp + 1; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

int main()
{
	int a[MAX];
	int choice, sp, x, i;
	system("cls");
	cout << " -------- BAI TAP 5, CHUONG 2, STACK (NGAN XEP - DS DAC -------- " << endl;
	cout << "1. Khoi tao STACK rong!" << endl;
	cout << "2. Them phan tu vao STACK!" << endl;
	cout << "3. Lay phan tu ra khoi STACK!" << endl;
	cout << "4. Kiem tra STACK co rong hay khong!" << endl;
	cout << "5. Kiem tra STACK co day hay khong!" << endl;
	cout << "6. Xuat STACK!" << endl;
	cout << "7. Thoat!" << endl;
	do
	{

		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, sp);
			cout << " Ban vua khoi tao STACK rong thanh cong!" << endl;
			break;
		case 2:
			cout << " Vui long nhap gia tri x=";
			cin >> x;
			i = Push(a, sp, x);
			cout << "STACK sau khi them la: ";
			Process_stack(a, sp);
			break;
		case 3:
			i = Pop(a, sp, x);
			cout << " Phan tu lay ra tu STACK la x= " << x << endl;
			cout << " STACK sau khi lay ra la: ";
			Process_stack(a, sp);
		case 4:
			i = isFull(a, sp);
			if (i == 0)
				cout << " STACK chua day! " << x << endl;
			else
				cout << " STACK da day! " << x << endl;
			break;
		case 5:
			i = isEmpty(a, sp);
			if (i == 0)
				cout << " STACK chua day!" << x << endl;
			else
				cout << " STACK da day!" << x << endl;
			break;
		case 6:
			cout << "STACK hien tai la: ";
			Process_stack(a, sp);
			break;
		case 7:
			cout << " Goodbye.....!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 7);
	system("pause");
	return 0;
}