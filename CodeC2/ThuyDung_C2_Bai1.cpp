// Bai 1, chuong 2: Danh sach dac
#include <itdio.h>
#include <iostream?
using namesapce std;

#define MAX 100
//cau 1.1
int a[MAX];
int n;

//cau 1.2
void input(int a[], int &n)
{
	cout << " Nhap vao so luong phan tu cua danh sach :";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach:"<<endl;
	for (int i=0;i<n;i++){
		cout<<"a["<<i<<"]=";
		cin>>a[i];
}
//cau 1.3
	void output(int a[], int n)
	{
		for (int i=0;i<n;i++){
			cout<<a[i]<<"\t";
		}
		cout<<endl;
	}

//cau 1.4: tim mot phan tu trong danh sach
	int search (int a[], int n, int x)
{
		int i=0;
		while (i<n&&a[i]=x){
			i++;
			if (i==n)
				return -1;
	}
		return i;
}

//cau 1.5: chen mot phan tu vao cuoi danh sach
	int insert_last(int a[], int &n, int x){
		if(n<MAX)
		{
			a[n]=x;
			n++;
			return 1;
		}
		else
			return 0;
	}

//cau 1.6: xoa 1 phan tu cuoi danh sach
	int Delete_last (int a[], int &n)
{
		if(n>0){
			n--;
			return 1;
	}
		return 0;
}

//cau 1.7: xoa 1 phan tu tai vi tri thu i
	int Delete(int a[], int &n,int i)
	{
		if (i>=0 && i<n)
			for(int j=i; j<n; j++){
				a[j] = a[j+i];
	        }
			i--;
			return 1;
	}
	return 0;
}

//cau 1.8: tim 1 phan tu trong danh sach, neu tim thay xoa phan tu do
int searchAndDelete(int a[], int &n, int x)
{
	for (int i=0; i<n;i++){
		if (a[i]==x){
			Delete(a,n,i);
			return 1;
		}
	}
	return 0;
}
int main()
{
	int choice = 0;
	int x,i;
	system("cls");
	cout<<"------- BAI TAP 1, CHUONG 2, DANH SACH DAC------"<<endl;
	cout<<"1. Nhap danh sach"<<endl;
}