Bài 5:
//  Bai  5,  chuong  2  :  DS  han  che,  ngan  xep,  STACK
#include  <stdio.h>
#include  <iostream>
using  namespace  std;

#define  MAX  100

//  Cau  5.2:  khoi  tao  STACK  rong
void  init(int  a[], int  &sp) {
	sp = -1;
}

//  Cau  5.3:  kiem  tra  ngan  xep  rong
int  isEmpty(int  a[], int  sp) {
	if (sp == -1)
		return  1;
	return  0;
}

//Cau  5.4  :  kiem  tra  ngan  xep  day
int  isFull(int  a[], int  sp) {
	if (sp == MAX - 1)
		return  1;
	return  0;
}

//Cau  5.5:  them  phan  tu  vao  ngan  xep
int  Push(int  a[], int  &sp, int  x) {
	if (sp < MAX - 1) {
		a[++sp] = x;
		return  1;
	}
	return  0;
}

//Cau  5.6:  xoa  1  phan  tu
int  Pop(int  a[], int  &sp, int  &x) {
	if (sp != -1) {
		x = a[sp--];
		return  1;
	}
	return  0;
}

//  Xuat  STACK
void  Process_stack(int  a[], int  sp)
{
	for (int i = 0; i < sp + 1; i++)
	{
		cout<< a[i] << "\t";
	}
	cout << endl;
}
int  main()
{
	int  a[MAX];
	int  choice, sp, x, i;
	system("cls");
	cout << "-------- - BAI  TAP  5, CHUONG  2, STACK(NGAN  XEP - DS  DAC)------ - "<< endl;
	cout << "1.Khoi  tao  STACK  rong" << end1;
	cout << "2.Them  phan  tu  vao  STACK  " << end1;
	cout << "3.Lay  phan  tu  ra  khoi  STACK  "<< end1;
	cout << "4.Kiem  tra  STACK  co  rong  hay  khong  " << end1;
	cout << "5.Kiem  tra  STACK  co  day  hay  khong"<< end1;
	cout << "6.Xuat  STACK"<< end1;
	cout << "7.Thoat"<< end1;
	do
	{
		cout << "\nVui  long  chon  so  de  thuc  hien : ";
		cin >> choice;
		switch (choice)
		{
		case  1:
			init(a, sp);
			cout << "Ban  vua  khoi  tao  STACK  rong  thanh  cong!\n";
			break;
		case  2:
			cout << "Vui  long  nhap  gia  tri  x = ";
			cin >> x;
			i = Push(a, sp, x);
			cout << "STACK  sau  khi  them  la : ";
			Process_stack(a, sp);
			break;
		case  3:
			i = Pop(a, sp, x);
			cout << "Phan  tu  lay  ra  tu  STACK  la  x = " << x << end1;
			Process_stack(a, sp);
			break;
		case  4:
			i = isFull(a, sp);
			if (i == 0)
				cout << "STACK  chua  day!" << x << end1;
			else
				cout << "STACK  da  day  !" << end1;
			break;
		case  5:
			i = isEmpty(a, sp);
			if (i == 0)
				cout << "STACK  khong  rong!" << x << end1;
			else
				cout << "STACK  rong  !" << end1;
			break;
		case  6:
			cout << "STACK  hien  tai  la : ";
			Process_stack(a, sp);;
			break;
		case  7:
			cout << "Goodbye  . . . . . !" << end1;
			break;
		default:
			break;
		}
	} while (choice != 7);
	system("pause");
	return  0;
}


