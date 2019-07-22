//  Bai  10,  chuong  2  :  DS  han  che,  hang  doi,  STACK
//  STACK  su  dung  DSLK  DON
#include  <stdio.h>
#include  <iostream>
using namespace  std;

//  Cau  10.1:  Khai  bao  cau  truc  STACK
struct  Node {
	int  info;
	Node  *link;
};
Node  *sp;
// Cau 10.2: khoi tao STACK rong
void init()
{
	sp = NULL;
}
//  Cau  10.3:  Ktra  STACK  rong
int  isEmpty()
{
	if (sp == NULL)
		return  1;
	return  0;
}

//  Cau  10.4:  them  phan  tu  vao  STACK
void  Push(int  x) {
	Node  *p = new  Node;
	p->info = x;
	p->link = sp;
	s[=  p;
}

//  Cau  10.5:  lay  phan  tu  ra  khoi  STACK
int  Pop(int  &x) {
	if (sp != NULL) {
		Node  *p = sp;
		x = p->info;
		sp = p->link;
		delete  p;
		return  1;
	}
	return  0;
}

//  Xuat  STACK
void  Process_stack()
{
	Node  *p = sp;
	do {
		cout << p->info << "	";
		p = p->link;
	} while (p != NULL);
	cout << end1;
}
int  main()
{
	int  choice, x, i;
	system("cls");
	cout << "-------- - BAI  TAP  10, CHUONG  2, STACK(NGAN  XEP - DSLK)------ - " << end1;
	cout << "1.Khoi  tao  STACK  rong" << end1;
	cout << "2.Them  phan  tu  vao  STACK  "<< end1;
	cout << "3.Lay  phan  tu  ra  khoi  STACK  " << end1;
	cout << "4.Xuat  STACK" << end1;
	cout << "5.Thoat"<< end1;
	do
	{
		cout << "\nVui  long  chon  so  de  thuc  hien : ";
		cin >> choice;
		switch (choice)
		{
		case  1:
			init();
			cout << "Ban  vua  khoi  tao  STACK  rong  thanh  cong!\n";
			break;
		case  2:
			cout << "Vui  long  nhap  gia  tri  x = ";
			cin >> x;
			Push(x);
			cout << "STACK  sau  khi  them  la : ";
			Process_stack();
			break;
		case  3:
			Pop(x);
			cout << "Phan  tu  lay  ra  tu  STACK  la  x = " << x << endl;
			cout << "STACK  sau  khi  lay  ra  la :";
			Process_stack();
			break;
		case  4:
			cout <<"STACK  hien  tai  la : ";
			Process_stack();
			break;

		case  5:
			cout << "Goodbye  . . . . . !" << endl;
			break;
		default:
			break;
		}
	} while (choice != 5);
	system("pause");
	return  0;
}

