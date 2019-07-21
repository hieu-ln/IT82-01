Chuong2_Bai_6
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
#define MAX 100
int a[MAX];
int sp;
void init(int a[], int &sp)
{
	sp=-1;
}
int Push(int a[], int &sp, int x)
{
	if(sp<MAX-1)
	{
		a[++sp]=x;
		return 1;
	}
	return 0;
}
int Pop(int a[], int &sp, int &x)
{
	if(sp!=-1)
	{
		x=a[sp--];
		return 1;
	}
	return 0;
}
int isFull(int a[], int sp)
{
	if(sp == MAX-1)
		return 1;
	return 0;
}
int isEmpty(int a[], int sp)
{
	if(sp==-1)
		return 1;
	return 0;
}
int convert( int tp)
{
	int np=0;
	init(a, sp);
	while(tp!=0)
	{
		int d=tp%2;
		if(Push(a,sp,d))
			tp/=2;
		else 
			break;
	}
	while(!isEmpty(a,sp))
	{
		int n;
		if(Pop(a,sp,n))
			np=np*10+n;
		else
			break;
	}
	return np;
}
void output(int a[],int ap)
{
	cout<<"Danh sach hien tai: \n"; 
	for(int i=sp; i>=0; i--)
	{
		cout<<a[i]<<endl;
	}
	cout<<endl;
}
int main()
{
int chon;
char tt;
int x;
do
	{
	system("cls");
	cout<<"Menu:\n 1.Khoi tao\n 2.Kiem tra rong\n 3.Kiem tra day\n 4.Them 1 phan tu\n 5.Xoa 1 phan tu\n 6.Doi he nhi phan\n 7.Xuat Stack\n Chon:";
	cin>>chon;
	switch(chon)
	{
		case 1:
			init(a,sp);
			cout<<"Khoi tao thanh cong\n";
				break;
		case 2:
			if(isEmpty(a, sp))
				cout<<"Stack rong\n";
			else
				cout<<"Stack k rong\n";
				break;
		case 3: 
			if(isFull(a, sp))
				cout<<"Stack day:\n";
			else
				cout<<"Stack k day\n";
				break;
		case 4: int n;
			cout<<"gia tri can them: ";
			cin>>n;
			if(Push(a, sp, n))
				cout<<"Them thanh cong\n";
			else 
				cout<<"Khong them duoc\n";
			break;
		case 5: 
			int x;
			if(Pop(a,sp,x))
				cout<<"Xoa gia tri "<<n<<" thanh cong\n";
			else
				cout<<"xoa khong duoc\n";
			break;
		case 6:
			int TP;
			cout<<"GT thap phan can doi: ";
			cin>>TP;
			cout<<"So nhi phan cua "<<TP<<" la: "<<convert(TP)<<endl;
			break;
		case 7:
			output(a, sp);
			break;
	}
	cout<<"Ban co muon tiep tuc (y/n): ";
	cin>>tt;
	}while(tt=='y'||tt=='Y');
	system("pause");
	return 0;
}	